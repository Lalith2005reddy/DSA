//Optimized with Xor operation
#include<iostream>
using namespace std;

int main(){
    int n = 9,ans=0;
    int a[n] = {3,4,3,4,5,7,7,5,9};
    for(int i=0;i<n;i++){
        ans = ans ^ a[i];
    }
    cout<<ans;

}