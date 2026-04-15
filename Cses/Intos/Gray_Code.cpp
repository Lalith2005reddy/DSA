#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> base = {"0","1"};

    int n;
    cin>>n;

    for(int i=1;i<n;i++){
        vector<string> t = base;
        int s = t.size();
        
        vector<string> rev = t;

        reverse(rev.begin(),rev.end());

        for(string st : rev){
            t.push_back(st);
        }

        for(int i=0;i<s;i++){
            string k = "0";
            k += t[i];
            t[i] = k;
        }

        for(int i=s;i<s+s;i++){
            string k = "1";
            k += t[i];
            t[i] = k;
        }

        base = t;
    }
    for(string y : base){
        cout<<y<<endl;
    }
    return 0;
}