#include<bits/stdc++.h>
using namespace std;

bool is_valid(int n,int m,int i,int j){
    return i>=0 && i<n && j >= 0 && j<m;
}

int main(){

    int n,m;
    cin>>n>>m;
    vector<string> grid(n);

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }


    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            set<char> not_allowed;

            not_allowed.insert(grid[i][j]); //Current
            if(is_valid(n,m,i,j-1)){
                not_allowed.insert(grid[i][j-1]); //Left
            }
            else if(is_valid(n,m,i-1,j)){
                not_allowed.insert(grid[i-1][j]);//Top
            }
            for(int k=0; k < 4 ;k++){
                char t = 'A'+k;

                if(not_allowed.find(t) == not_allowed.end()){
                    grid[i][j] = t;
                }
            }
        } 
    }

    for(int i=0;i<n;i++){
        cout<<grid[i]<<endl;
    }
}