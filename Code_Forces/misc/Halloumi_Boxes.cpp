#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        vector<int> cpy(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cpy = arr;
        sort(begin(cpy),end(cpy));
        if(k == 1){
            if(cpy == arr){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}