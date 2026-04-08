#include<bits/stdc++.h>
using namespace std;

int M = 1e9 + 7;
int n = 0;
vector<vector<int>> dp;
int trav(vector<vector<char>> &grid,int i,int j){

    if (i >= n || j >= n) return 0;
    if (grid[i][j] == '*') return 0;
    if (i == n-1 && j == n-1) return 1;
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int right = 0;
    int down = 0;
    right = trav(grid,i,j+1);
    down = trav(grid,i+1,j);

    return dp[i][j] = (right + down)%M;
}
int main(){
    cin>>n;
    dp.resize(n,vector<int>(n,-1));
    vector<vector<char>> grid(n,vector<char>(n,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }


    int ans = trav(grid,0,0);

    cout<<ans;
    return 0;
}