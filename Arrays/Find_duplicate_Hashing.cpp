#include<iostream>
using namespace std;
void Duplicate(int sort[],int n){
    int *h;
    int x=sort[n-1];  //Last element is max so make array with max num size
    h=new int[x];
    for(int i=0;i<x;i++){
        h[i]=0;
    }
    for(int i=0;i<n;i++){
        h[sort[i]]++;
    }
    for(int i=0;i<x;i++){
        if(h[i]>1){
            cout<<i<<" ";
            cout<<"Count : "<<h[i]<<endl;
        }
    }
}
int main(){
    int sort[10]={3,6,8,8,10,12,15,15,15,20};
    int n =sizeof(sort)/sizeof(int);
    Duplicate(sort,n);
}