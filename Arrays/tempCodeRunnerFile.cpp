#include<iostream>
using namespace std;
void missing(int a[],int n){
    int *h; //Hash table array
    h=new int[20];
    for(int i=0;i<n;i++){
        h[a[i]]++;
    }
    for(int i=0;i<n;i++){
        if(h[i]==1){
        cout<<i<<" ";
        }
    }
}
int main(){
    int a[10]={3,7,4,9,12,6,1,11,2,10};
    int n=sizeof(a)/sizeof(int);
    missing(a,n);
}
