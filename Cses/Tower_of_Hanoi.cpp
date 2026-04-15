#include<bits/stdc++.h>
using namespace std;


void TH(int n,int st,int ed,int m){
    if(n == 1){
        cout<<st<<" "<<ed<<endl;
        return;
    }

    TH(n-1,st,m,ed);
    cout<<st<<" "<<ed<<endl;
    TH(n-1,m,ed,st);
}
int main(){
    int n;
    cin>>n;

    cout<<(1 << n) -1<<endl;

    TH(n,1,3,2);
    return 0;
}