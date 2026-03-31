#include<bits/stdc++.h>
using namespace std;


bool check(string s,string x){
    if(x.length() < s.length()) return false;

    for(int i=0;i<x.length();i++){
        if(x.substr(i,s.length()) == s){
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string x,s;
        cin>>x>>s;


        string x0 = x;
        string x1 = x0 + x0;
        string x2 = x1 + x1;
        string x3 = x2 + x2;
        string x4 = x3 + x3;
        string x5 = x4 + x4;

        if(check(s,x0)){
            cout<<0<<"\n";
        }
        else if(check(s,x1)){
            cout<<1<<'\n';
        }
        else if(check(s,x2)){
            cout<<2<<'\n';
        }
        else if(check(s,x3)){
            cout<<3<<'\n';
        }
        else if(check(s,x4)){
            cout<<4<<'\n';
        }
        else if(check(s,x5)){
            cout<<5<<'\n';
        }
        else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}