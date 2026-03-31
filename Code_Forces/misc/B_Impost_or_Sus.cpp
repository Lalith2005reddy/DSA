#include <bits/stdc++.h>
using namespace std;

static inline int mn(int a,int b){return a<b?a:b;}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        string r; 
        cin>>r;

        int n=r.size();
        
        for(char c:r){
            assert(c=='s'||c=='u');
        }

        int a=(r[0]=='u');
        int b=a+(r[1]=='u');

        for(int i=2;i<n;i++){
            int c=(r[i]=='u')+mn(a,b);
            a=b; 
            b=c;
        }

        cout<<b<<"\n";
    }
    return 0;
}