#include<iostream>
using namespace std;
// TYPE-1
void reverse(int *a,int length){
    int *b;
    int i,j;
    b = new int[length];
    for(i=length-1,j=0;i>=0;i--,j++){
        b[j]=a[i];
    }
    for(i=0;i<length;i++){
        a[i]=b[i];
    }
}

//TYPE -2
void reverse2(int *a,int length){
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--){
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
int main(){
    int len=6;
    int a[6]={1,2,3,4,5,6};
     for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    //reverse(a,len);
    reverse2(a,len);
    for(int i:a){
        cout<<i<<" ";
    }
}