#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int but;
        cin>>but;
        vector<int> v(n);
        for(int &i:v){
            cin>>i;
        }
        int i =0;
        bool f = true;
        bool used = false;
        while(i<n){
            if(v[i] == 0){
                i++;
            }
            else if(v[i] == 1){
                if(but == 0 || used ==true){
                    f = false;
                    break;
                }
                if(i + but > n){
                    break;
                }
                i+=but;
                used = true;
            }
        }
        cout << (f ? "YES" : "NO") << '\n';
            
    }
    return 0;
}