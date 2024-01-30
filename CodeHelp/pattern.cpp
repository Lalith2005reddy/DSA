#include<iostream>
using namespace std;

int main(){
    // int n=3,i=1,j;
    // while(i<=n){
    //     j=1;
    //     while(j<=n){
    //         cout<<n-j+1;
    //         j++;
    //     }
    //     cout<<endl;
    //     i++;
    // }

    int n=4;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}