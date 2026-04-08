#include<bits/stdc++.h>
using namespace std;

int MAXN = 2e5+1;
vector<vector<int>> adj(MAXN);
vector<bool> vis(MAXN,false);
int cnt = 0;

void dfs(int node,int parent){
    for(auto c : adj[node]){
        if(c != parent){
            dfs(c,node);
            if(!vis[node] && !vis[c]){
                cnt++;
                vis[c] = true;
                vis[node] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,-1);

    cout<<cnt<<endl;
    return 0;
}