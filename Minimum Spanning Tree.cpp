// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1/?track=md-greedy&batchId=144
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
int spanningTree(int v, int e, vector<vector<int>> &graph) {
    vector <bool> vis(v+1,false);
    vector <int> dis(v+1,INT_MAX);
    priority_queue <pi,vector<pi>,greater<pi>> pq;
    dis[1]=0;
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        int w=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(vis[u])  continue;
        vis[u]=true;
        for(int j=1;j<=v;j++){
            int weight=graph[u-1][j-1];
            if(!vis[j] && weight!=INT_MAX && dis[j]>weight){
                dis[j]=weight;
                pq.push(make_pair(dis[j],j));
            }
        }
    }
    int min_cost=0;
    for(int i=1;i<=v;i++){
        if(dis[i]!=INT_MAX)
            min_cost+=dis[i];
    }
    return min_cost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}


