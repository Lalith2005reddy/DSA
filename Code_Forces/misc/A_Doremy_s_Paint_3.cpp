#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[a[i]]++;
        }

        if(freq.size() >= 3){
            cout<<"No"<<'\n';
        }

        else{
            int d1 = a[0];
            int d2 = a[0];
            for(int i=1;i<n;i++){
                if(a[i] != d1){
                    d2 = a[i];
                    break;
                }
            }
            int c1 = freq[d1];
            int c2 = freq[d2];
            
            if(c1 == c2){
                cout<<"Yes"<<'\n';
            }
            else if(n % 2 == 1 && abs(c1-c2) == 1){
                cout<<"Yes"<<'\n';
            }
            else{
                cout<<"No"<<'\n';
            }
        }
    }
    return 0;
}