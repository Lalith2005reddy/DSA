#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int x;
    cin>>n>>x;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(begin(a),end(a));

    int i = 0,j=n-1;
    int cnt = 0;

    while(i<=j){
        if(a[i] + a[j] <= x){
            i++;
            j--;
        }
        else{
            j--;
        }
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}