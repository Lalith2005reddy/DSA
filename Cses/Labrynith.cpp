#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<pair<int,int>>> parent;

vector<pair<int,int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};  // L, R, U, D
vector<char> dirChar = {'L','R','U','D'};

bool isvalid(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m && !visited[i][j] && grid[i][j] != '#');
}

void bfs(pair<int,int> start){
    queue<pair<int,int>> q;
    visited[start.first][start.second] = true;
    q.push(start);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(auto d : dir){
            int ni = x+d.first;
            int nj = y+d.second;

            if(isvalid(ni,nj)){
                visited[ni][nj] = true;
                parent[ni][nj] = {x,y};
                q.push({ni,nj});
            }
        }
    }
}
string reconstructPath(pair<int,int> start,pair<int,int> end){
    string path;
    pair<int,int> curr = end;

    while(curr != start){
        int px = parent[curr.first][curr.second].first;
        int py = parent[curr.first][curr.second].second;

        for (int d = 0; d < 4; ++d) {
            if (px + dir[d].first == curr.first && py + dir[d].second == curr.second) {
                path += dirChar[d];
                break;
            }
        }
        curr = {px,py};
    }
    reverse(path.begin(),path.end());
    return path;
}
int main(){
    cin>>n>>m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int,int>>(m, {-1, -1}));

    pair<int,int> start,end;

    for(int i=0;i<n;i++){
        cin>>grid[i];
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A') start = {i,j};
            if(grid[i][j] == 'B') end = {i,j};
        }
    }

    bfs(start);

    if(!visited[end.first][end.second]){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        string path = reconstructPath(start, end);
        cout<<path.size()<<endl;
        cout<<path;
    }
    return 0;
}