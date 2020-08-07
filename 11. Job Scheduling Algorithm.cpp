// https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0
#include<bits/stdc++.h>
using namespace std;
bool sortbydec(const pair<int,int> &a,const pair<int,int> &b){
    return a.first>b.first;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,id,deadline,profit,i;
        cin>>n;
        vector <pair<int,int>>job;
        int max_time=INT_MIN;
        for(i=0;i<n;i++){
            cin>>id;
            cin>>deadline;
            if(deadline>max_time){
                max_time=deadline;
            }
            cin>>profit;
            job.push_back(make_pair(profit,deadline));
        }
        sort(job.begin(),job.end(),sortbydec);
        int arr[max_time]={0},profit_sum=0,num=0;
        for(i=0;i<n;i++){
            int j=job[i].second-1;
            while(j>=0){
                if(arr[j]==0){
                    num++;
                    profit_sum+=job[i].first;
                    arr[j]=1;
                    break;
                }
                else{
                    j--;
                }
            }
        }
        cout<<num<<" "<<profit_sum<<endl;
    }
    return 0;
}
