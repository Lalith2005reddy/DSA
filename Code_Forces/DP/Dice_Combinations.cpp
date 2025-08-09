#include<iostream>
#include<vector>
using namespace std;

int mod = 1e9+7;
vector<int> dp(1000001, -1);
//You're passing the already updated ways again — this pollutes recursion.
int fun(int sum, int until){
    if(until == sum) return 1;
    if(until > sum) return 0;
    if(dp[until] != -1) return dp[until];
    int ways = 0;
    for (int i = 1; i <= 6; i++) {
        ways = (ways + fun(sum,until+i)) % mod;
    }
    return dp[until] = ways;
}
int main(){
    int n;
    cin>>n;
    int ways = 0;
    ways = fun(n,0);
    cout << ways;
}