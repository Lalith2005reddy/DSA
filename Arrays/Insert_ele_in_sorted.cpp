#include<iostream>
using namespace std;
void InsertSort(int *a,int x,int length,int size){
    int i=length-1;
    if(length==size){
        return;
    }
    while(i>=0 && a[i]>x){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=x;
    length++;
}
int main(){
    int a[10]={1,2,3,10,15};
    InsertSort(a,5,5,10);
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }
}