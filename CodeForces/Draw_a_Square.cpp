#include<iostream>
using namespace std;

bool isSquare(int l,int r,int d,int u){
    int diag1 = l + r;
    int diag2 = u + d;

    if(diag1 == diag2){
        if(l==r && d==u)
        return true;
        else
        return false;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r,d,u;
        cin>>l>>r>>d>>u;
        bool temp = isSquare(l,r,d,u);
        if(temp==true){
            cout<<"Yes"<<endl;
        }
        else
        cout<<"No"<<endl;
    }
    return 0;
}