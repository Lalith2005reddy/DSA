#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        unordered_map<int,int> mp;
        mp[0] = -1;
        int val = 0;
        int maxLen = 0;
        for(int i=0;i<n*2;i++){
            if(s[i] == 'R') val++;
            else if(s[i] == 'B') val--;

            if(mp.find(val) != mp.end()){
                int len = i - mp[val];
                maxLen = max(maxLen, len);
            }
            else{
                mp[val] = i;
            }
        }

        cout<<n*2 - maxLen<<endl;
    }
    return 0;
}