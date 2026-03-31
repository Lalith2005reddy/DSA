#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a1,a2,a4,a5;
        cin >> a1 >> a2 >> a4 >> a5;

        vector<int> temp = {a1+a2,a4-a2,a5-a4};
        int maxi = 0;

        for(auto a3 : temp){
            int cnt = 0;

            if(a3 == a1+a2){
                cnt++;
            }
            if(a4 == a2+a3){
                cnt++;
            }
            if(a5 == a4+a3){
                cnt++;
            }
            maxi = max(maxi,cnt);
        }
        cout<<maxi<<endl;
    }
    return 0;
}