#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    while(N--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int &i : v){
            cin>>i;
        }
        int t = v[0] + v[n-1];
        int f = 0;
        for(int i=0;i<n/2;i++){
            if(v[i] + v[n-i-1] != t){
                f = 1;
                break;
            }
        }
        if(f==1){cout<<"NO"<<endl;}
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}