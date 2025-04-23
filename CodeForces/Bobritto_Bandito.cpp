#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,l,r;
        cin>> n >> m >> l >>r;
        int x =0;
        int l1 = l+x;
        int r1 = r - (n-m-x);
        cout<< l1 << " " <<r1<<endl;
    }
    return 0;
}