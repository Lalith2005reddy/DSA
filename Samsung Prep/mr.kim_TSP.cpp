#include<bits/stdc++.h>
using namespace std;
int n;
int cost[20][20];
int ans;

void dfs(int curr,bool vis[],int count,int value){
    if(count == n){
        ans = min(ans,value + cost[curr][0]);
        return;
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(i,vis,count+1,value + cost[curr][i]);
            vis[i] = false;
        }
    }
}
int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }
    ans = INT_MAX;

    bool vis[20] = {false};

    vis[0]  =true;
    dfs(0, vis,1,0);

    cout<<ans<<endl;

    return 0;
}