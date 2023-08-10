#include<iostream>
using namespace std;
int sum(int n){
    if(n==0){
        return 0;
    }
    else{
        return sum(n-1)+n;
    }
}
int main(){
    int n,x;
    cout<<"Enter Value of n : ";
    cin>>n;
    x=sum(n);
    cout<<x;
    return 0;
}