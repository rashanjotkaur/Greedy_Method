// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
// https://practice.geeksforgeeks.org/problems/max-length-chain/1/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int start;
    int end;
    int index;
};
bool sortbysec(struct Node e1,struct Node e2){
    return e1.end<e2.end;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,i,x;
	    cin>>n;
	    struct Node meet[n];
	    for(i=0;i<n;i++){
	        cin>>x;
	        meet[i].start=x;
	        meet[i].index=i+1;
	    }
	    for(i=0;i<n;i++){
	        cin>>x;
	        meet[i].end=x;
	    }
	    sort(meet,meet+n,sortbysec);
	    int time_limit=meet[0].end;
	    cout<<meet[0].index<<" ";
	    i=1;
	    while(i<n){
	        if(meet[i].start>=time_limit){
	            cout<<meet[i].index<<" ";
	            time_limit=meet[i].end;
	        }
	        i++;
	    }
	    cout<<endl;
	}
	return 0;
}
