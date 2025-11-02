#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int i,vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> vis(n,false);
    queue<int> q;

    vis[i] = true;
    q.push(i);

    while(!q.empty()){
        int t = q.front();
        q.pop();

        cout<<t<<"->";
        for(int f : adj[t]){
            if(!vis[f]){
                vis[f] = true;
                q.push(f);
            }
        }
    }
}

void dfsUtil(int i,vector<vector<int>> adj,vector<bool> &vis){
    vis[i] = true;

    cout<<i<<"->";
    for(int nei: adj[i]){
        if(!vis[nei]){
            dfsUtil(nei,adj,vis);
        }
    }
}

void dfs(int i,vector<vector<int>> &adj){
    int n = adj.size();
    vector<bool> vis(n,false);
    dfsUtil(i,adj,vis);
}
int main(){
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3, 4};
    adj[3] = {1, 2};
    adj[4] = {2};

    dfs(0,adj);

    return 0;
}