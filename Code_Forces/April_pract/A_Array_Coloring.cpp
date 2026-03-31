#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        long long cnt_odd = 0;
        for(int i=0;i<n;i++){
            if(arr[i] % 2 != 0){
                cnt_odd++;
            }
        }

        if(cnt_odd % 2 != 0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}