#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    multiset<int> tickets;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        tickets.insert(p);
    }

    for(int i=0;i<m;i++){
        int t;
        cin>>t;

        auto it = tickets.upper_bound(t);

        if(it == tickets.begin()){
            cout<<"-1"<<endl;
        }
        else{
            --it;
            cout<<*it<<endl;
            tickets.erase(it);
        }
    }
    return 0;
}