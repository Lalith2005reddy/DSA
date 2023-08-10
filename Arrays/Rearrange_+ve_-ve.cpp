#include<iostream>
using namespace std;
void Rearrange(int *a,int length){
    int i,j;
    i=0;
    j=length-1;
    while(i<j){
        while(a[i]<0){i++;}
        while(a[j]>=0){j--;}
        if(i<j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
}
int main(){
    int a[10] ={1,-7,8,-4,-2,3,4,-1};
    int length = 8;
    Rearrange(a,length);
    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
}