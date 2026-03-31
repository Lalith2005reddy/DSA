#include<iostream>
using namespace std;

int main(){
    //freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n % 3 == 0){
            cout<<"Second"<<endl;
        }
        else{
            cout<<"First"<<endl;
        }
    }
    return 0;
}