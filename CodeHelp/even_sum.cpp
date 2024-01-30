#include<iostream>
using namespace std;

int main(){
    int n,i,sum=0;
    cin>>n;
    i=0;
    while(i<=n){
        if(i%2==0){
            sum += i;
        }
        i++;
    }
    cout<<sum;
}