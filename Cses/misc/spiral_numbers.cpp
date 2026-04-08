#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll y,x;
        cin >> y >>x;

        ll layer = max(y,x);
        ll maxiOfLayer = layer*layer;
        ll ans;
        
        if(layer % 2 == 0){ // For even
            if(y==layer){
                ans = maxiOfLayer - (x -1);
            }
            else{
                ans = (layer-1) * (layer -1) + y;
            }
        }
        else if(layer %2 ==1){//For Odd
            if(x == layer){
                ans = maxiOfLayer - (y-1);
            }
            else{
                ans = (layer-1) * (layer-1) + x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}