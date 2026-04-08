#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> sub;

int dfs(int node){
    int total = 0;

    for(auto child : adj[node]){
        int children = dfs(child);
        total += 1 + children;
    }

    return sub[node] = total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    adj.resize(n+1);
    sub.resize(n+1);

    for(int i=2;i<=n;i++){
        int boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
    dfs(1);

    for(int i=1;i<=n;i++){
        cout<<sub[i]<<" ";
    }
    return 0;
}