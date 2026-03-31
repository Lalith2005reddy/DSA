#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n + 1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    unordered_map<int,int> path;
    vector<bool> vis(n+1,false);
    path[1] = 0;
    vis[1] = true;
    q.push(1);

    bool found = false;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node == n){
            found = true;
        }

        for(auto &nei : adj[node]){
            if(!vis[nei]){
                q.push(nei);
                vis[nei] = true;
                path[nei] = node;
            }
        }
    }

    int cnt = 0;
    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int> ans;
        int node = n;
        while(node != 0){
            cnt++;
            int par = path[node];
            ans.push_back(node);
            node = par;
        }

        cout<<cnt<<endl;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i != path.size() - 1) cout << " ";
        }
        cout<<endl;
    }
    
    return 0;
}