#include<bits/stdc++.h>
using namespace std;

int main(){

        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,abs(arr[i]));
        }

        cout<<mini<<endl;
    return 0;
}