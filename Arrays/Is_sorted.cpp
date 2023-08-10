#include<iostream>
using namespace std;
int IsSorted(int *a,int len){
    for(int i=0;i<len-1;i++){
        if(a[i]>a[i+1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    int a[10]={1,2,3,4,5};
    int length = 5;
    cout<<IsSorted(a,length);
}