#include<iostream>
using namespace std;
int main(){
    int a[10]={1,2,3,4,5};
    int size = sizeof(a)/sizeof(int);
    int length = 5;
    //Display opertation
    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


    //Add(x) or append(x) an element
    //! Here we are just replacing some unused element value, we are not increasing size of array

    a[length] = 9;
    length++;
    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    //Insert(index,x)
    int index=3;
    for(int i=length;i>index;i--){
    a[i]=a[i-1];
    }
    a[index]=8;
    length++;

     for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;


    //Delete(index)
    int x = a[index];
    for(int i=index;i<length-1;i++){
        a[i]=a[i+1];
    }
    length--;
    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
}