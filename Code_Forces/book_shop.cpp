// #include<bits/stdc++.h>
// using namespace std;

// int n;
// int dp[1001][1000001];

// int solve(vector<int> &pages,vector<int> &price,int i,int x){

//     if(i == n) return 0;

//     if(dp[i][x] != -1) return dp[i][x];

//     int nottake = solve(pages,price,i+1,x);
    
//     int take = 0;

//     if(x-price[i]>=0){
//         take = pages[i] + solve(pages,price,i+1,x-price[i]);
//     }

//     int weight = max(take,nottake);

//     return dp[i][x] = weight;
// }
// int main(){
//     int x;
//     cin>>n>>x;
//     memset(dp,-1,sizeof(dp));
//     vector<int> price(n);
//     for(int i=0;i<n;i++){
//         cin>>price[i];
//     }

//     vector<int> pages(n);

//     for(int i=0;i<n;i++){
//         cin>>pages[i];
//     }

//     int ans = solve(pages,price,0,x);
//     cout<<ans<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            int w = price[i-1];
            int val = pages[i-1];

            int pick = (j >= w ? dp[i-1][j-w] + val: 0);
            int notpick = dp[i-1][j];
            dp[i][j] = max(pick,notpick);
        }
    }

    cout << dp[n][x] << endl;
}
