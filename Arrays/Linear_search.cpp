//! Linear search with TRANSPOSITION
#include<iostream>
using namespace std;
void swap(int &x,int &y){
    int t;
    t = x;
    x = y;
    y = t;
}
int linearsearch(int *a,int key,int length){
    for(int i=0;i<length;i++){
        if(key==a[i]){
            swap(a[i],a[i-1]);  //for MOVE TO FIRST we just need to change a[i-1] to a[0]
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[5]={2,3,4,5,6};
    int length = 5;
    cout<<"Starting array: "<<endl;
    for(int i:arr){
        cout<<i<<" ";
        }
        cout<<"\n";
    linearsearch(arr,4,length);
    for(int i:arr){
        cout<<i<<" ";
        }
    return 0;
}

