#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ans(n);
        int maxi = 0;
        for(int i=0;i<n;i++){
            cin>>ans[i];
            maxi = max(maxi,ans[i]);
        }
        cout<<maxi*n<<endl;
    }
    return 0;
}