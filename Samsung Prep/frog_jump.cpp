#include<bits/stdc++.h>
using namespace std;

int n, sx, sy, tx, ty;

int grid[105][105];
int dist[105][105];

vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

bool isValid(int x,int y){
    return x >=0 && x < n && y >=0 && y<n;
}

void frogJump(){
    deque<pair<int,int>> dq;

    dq.push_front({sx,sy});
    dist[sx][sy] = 0;

    while(!dq.empty()){

        auto p = dq.front();
        dq.pop_front();

        int x = p.first;
        int y = p.second;

        for(auto d : dir){
            int nx = x + d.first;
            int ny = y + d.second;

            if(isValid(nx,ny) && grid[nx][ny] == 1){
                int cost;

                if((d.first == 1 && d.second == 0) || (d.first == -1 && d.second == 0)){
                    cost = 1;
                }
                else cost = 0;

                if(dist[x][y] + cost < dist[nx][ny]){
                    dist[nx][ny] = dist[x][y] + cost;

                    if(cost == 0){
                        dq.push_front({nx,ny});
                    }
                    else{
                        dq.push_back({nx,ny});
                    }
                }
            }
        }
    }
    if(dist[tx][ty] == 1e9)
        cout << -1;
    else
        cout << dist[tx][ty];
}
int main(){
    freopen("input.txt","r",stdin);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            dist[i][j] = 1e9;
        }
    }

    cin >> sx >> sy >> tx >> ty;

    frogJump();

    return 0;
}