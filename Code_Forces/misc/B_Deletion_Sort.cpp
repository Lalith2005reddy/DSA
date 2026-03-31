#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        bool sorted = true;

        for(int i=1;i<n;i++){
            if(arr[i] < arr[i-1]){
                sorted = false;
                break;
            }
        }

        if(sorted){
            cout<<n<<endl;
        }
        else{
            cout<<"1"<<endl;
        }
    }
    return 0;
}