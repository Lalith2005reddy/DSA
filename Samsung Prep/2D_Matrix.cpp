#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
    public:
        pair<int,int> f(int i,int j,vector<vector<pair<int,int>>> &dp,vector<vector<char>> &grid){
            if(i<0 || j<0 || grid[i][j] == 'x') return {-1,0};
            if(i==0 && j==0) return {grid[i][j]-'0',1};

            if(dp[i][j].first != -1) return dp[i][j];

            pair<int,int> left = f(i,j-1,dp,grid);
            pair<int,int> up= f(i-1,j,dp,grid);
            pair<int,int> diag = f(i-1,j-1,dp,grid);

            int maxSum = max(left.first, max(up.first, diag.first));
            int pathCount = 0;
            if(left.first == maxSum) pathCount += left.second;
            if(up.first == maxSum) pathCount += up.second;
            if(diag.first == maxSum) pathCount += diag.second;

            return {maxSum + (grid[i][j] - '0'),pathCount};
        }

        pair<int, int> maxSumPaths(int n, vector<vector<char>> &grid) {
            vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));

        auto res = f(n - 1, n - 1, dp, grid);
        if (res.first < 0) return {0, 0};  // No path exists
        return res;
        }
};

int main() {
        int n;
        cout << "Enter grid size (n): ";
        cin >> n;
    
        vector<vector<char>> grid(n, vector<char>(n));
        cout << "Enter grid values (0-9 for numbers, x for obstacles):\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
    
        Solution sol;
        pair<int, int> result = sol.maxSumPaths(n, grid);
        cout << "Maximum Sum: " << result.first << "\n";
        cout << "Number of Paths: " << result.second << "\n";
    
        return 0;
    }