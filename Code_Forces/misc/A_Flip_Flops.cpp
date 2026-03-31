#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long n,c,k;
        cin>>n>>c>>k;

        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        sort(arr.begin(),arr.end());

        for(int i=0;i<n;i++){
            if(arr[i] <= c){
                int can_add = min(k,c-arr[i]);

                c += (can_add + arr[i]);

                k-=can_add;
            }
            else{
                break;
            }
        }

        cout<<c<<endl;
    }
    return 0;
}