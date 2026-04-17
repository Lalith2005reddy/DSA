#include<bits/stdc++.h>
using namespace std;


int f(int node,vector<vector<int>> &adj,vector<bool> &vis){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            int val = f(it,adj,vis);
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        vector<bool> vis(n,false);
        int ans = f(1,adj,vis);
    }
    return 0;
}