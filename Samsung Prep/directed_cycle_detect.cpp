#include<iostream>
#include<vector>
using namespace std;


class Solution{
    public:
        bool dfs(int node,vector<int> &state,vector<vector<int>> &adj){
            state[node] = 1;

            for(auto nei : adj[node]){
                if(state[nei] == 0){
                    if(dfs(nei,state,adj)){
                        return true;
                    }
                }
                else if(state[nei] == 1){
                    return true;
                }
            }

            state[node] = 2;
            return false;
        }
        bool detectCycle(int n,vector<vector<int>> edges){
            vector<vector<int>> adj;

            for(auto ele : edges){
                adj[ele[0]].push_back(ele[1]);
            }

            vector<int> state(n,0);

            if(dfs(0,state,adj)){
                return true;
            }
            return false;
        }
};
int main(){

    int n, m;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges;

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;

    bool result = obj.detectCycle(n, edges);

    if(result)
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}