#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;

    unordered_map<char,int> freq;

    for(char c : str){
        freq[c]++;
    }

    int cnt = 0;
    string ans = "";
    for(auto it : freq){
        int val = it.second;
        if(val % 2 != 0){
            cnt++;
        }
        if(cnt >= 2){
            cout<<"NO SOLUTION"<<endl;
            return 0;
        }
    }

    char oddChar;
    for(auto it : freq){
        int c = it.first;
        int val = it.second;

        if(val % 2 == 0){
            for(int i=0;i<val/2;i++){
                ans += c;
            }
        }
        else{
            oddChar = c;
            for(int i=0;i<val/2;i++){
                ans+=c;
            }
        }
    }

    string temp = "";
    temp.reserve(ans.length());

    // add full middle ONLY if exists
    if(cnt == 1){
            temp += oddChar;
    }

    for(int i=ans.length()-1;i>=0;i--){
        temp += ans[i];
    }
    ans += temp;
    cout<<ans<<endl;
    return 0;
}