#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=1;
    int j;
    while(i<=n){
        j=1;
        while(j<=n-i+1){
            cout<<j;
            j++;
        }
        int star = i-1;
        while(star){
            cout<<"*";
            star--;
        }
        int start = n-i+1;
        while(j<=n-i+1){
            cout<<start;
            start--;
        }
        cout<<endl;
        i++;
    }
}

