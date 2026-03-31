#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> s(n);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }

        int cnt = 0;
        int t = 0;
        int lcnt = 0;
        for(int i=0;i<n;i++){
            cnt=0;
            if(s[i] == '.'){
                cnt++;
                while(s[i] == s[i+1] && i+1<n){
                    cnt++;
                    i++;
                }
            }
            t += cnt;
            lcnt = max(lcnt,cnt);
        }

        if(lcnt >= 3){
            cout<<"2"<<endl;
        }
        else{
            cout<<t<<endl;
        }

    }
    return 0;
}