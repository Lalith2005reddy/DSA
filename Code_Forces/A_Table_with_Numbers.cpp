#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,h,l;
        cin>>n>>h>>l;

        vector<int> arr(n);

        for(int i=0;i<n;i++) cin>>arr[i];


        int Row_e = 0;
        int Col_e = 0;

        for(int i=0;i<n;i++){
            if(arr[i] <= l) Col_e++;
            if(arr[i] <= h) Row_e++;
        }

        cout<<min({n/2,Row_e,Col_e})<<endl;
    }
    return 0;
}