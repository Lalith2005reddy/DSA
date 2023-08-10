#include<iostream>
using namespace std;
int min(int a[]){
    int minimum = a[0];
    for(int i=0;i<5;i++){
        if(a[i]<minimum){
            minimum = a[i];
        }
    }
    return minimum;
}
//Time complexity = o(n)
int main(){
    int a[5]={1,8,7,57,0};
    cout<<min(a);
}
