#include<iostream>
using namespace std;
int Binarysearch(int a[],int key,int length){                      //Binary Search with Iterations
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int RBinSearch(int a[],int l,int h,int key){                      //Binary Search with Recursion
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            return RBinSearch(a,l,mid-1,key);
        }
        else{
            return RBinSearch(a,mid+1,h,key);
        }
    }
    return -1;
}
int main(){
    int a[20];
    int length,key;
    cout<<"Enter no of elements of array: ";
    cin>>length;
    cout<<endl<<"Enter the array elements: ";
    for(int i=0;i<length;i++){
        cin>>a[i];
    }
    cout<<endl<<"Enter Key element to search: ";
    cin>>key;
    cout<<Binarysearch(a,key,length);
    //cout<<RBinSearch(a,0,length,key);
    return 0;
}