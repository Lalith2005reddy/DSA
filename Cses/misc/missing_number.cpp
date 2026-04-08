#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long t1 = 0;
    for(int i=1;i<=n;i++){
        t1 ^= i;
    }

    for(int i=0;i<n-1;i++){
        int t;
        cin>>t;
        t1 ^= t;
    }
    cout<<t1;
    return 0;
}