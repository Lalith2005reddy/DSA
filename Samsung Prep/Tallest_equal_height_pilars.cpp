#include<bits/stdc++.h>
using namespace std;

int maxi = 0;
int dp[21][20001];
int solve(vector<int> &rods,int i,int diff){
    if(i == rods.size()){
        if(diff == 0) return 0;
        return -1e9;
    }

    if(dp[i][diff] != -1)
        return dp[i][diff];

    // skip
    int res = solve(rods,i+1,diff);

    // add to p1
    int take1 = solve(rods,i+1,diff + rods[i]);

    // add to p2
    int take2 = solve(rods,i+1,diff - rods[i]);
    if(take2 != -1e9) take2 += rods[i];

    return dp[i][diff] = max({res, take1, take2});
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int> rods(n);
    for(int i=0;i<n;i++){
        cin>>rods[i];
    }

    cout<<solve(rods,0,0);
    return 0;
}