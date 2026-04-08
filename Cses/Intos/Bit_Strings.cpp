#include<bits/stdc++.h>
#include<cmath>
using namespace std;
const int MOD = 1e9+7;


long long power(long long a,long long b){
    long long result = 1;

    while(b > 0){
        if(b & 1){
            result = (result * a) % MOD;
        }

        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

long long power2(long long a,long long b){
    if(b == 0) return 1;

    long long val = power2(a,(b/2));
    val *= val;
    if(b % 2 == 1){
        val = val * a;
    }
    return val;
}
int main(){
    int n;
    cin>>n;
    long long val = pow(2,n);
    val = val % MOD;

    cout<<val<<endl;

    return 0;
}