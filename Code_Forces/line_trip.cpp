#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        //Take Inputs
        int n,x;
        cin>>n>>x;

        //Write logic for finding maxi

        

        vector<int> ans(n); //Impletation with array to be done and python also
        
        for(int i=0;i<n;i++){
            cin>>ans[i];
        }
        int maxi = ans[0];
        int last_maxi = 2 * (x - ans[n-1]);

        for(int i=1;i<n;i++){
            maxi = max(ans[i] - ans[i-1],maxi);
        }

        //Print maxi
        cout<<max(maxi,last_maxi)<<endl;
        
    }
    return 0;
}