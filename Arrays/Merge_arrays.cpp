#include<iostream>
using namespace std;
void Merge(int *a,int *b,int len1,int len2){
    int i,j,k;
    i=j=k=0;
    int c[10];
    while(i<len1 && j<len2){
        if(a[i] < b[j]){
            c[k]=a[i];
            k++;
            i++;
        }
        else{
            c[k] = b[j];
            k++;
            j++;
        }
    }
    for(;i<len1;i++){
        c[k++]=a[i];
    }
    for(;j<len1;j++){
        c[k++]=b[j];
    }
    for(int i=0;i<10;i++){
        cout<<c[i]<<" ";
    }
}
int main(){
    int a[5]={3,4,7,18,20};
    int b[5]={2,6,10,15,25};
    Merge(a,b,5,5);
}