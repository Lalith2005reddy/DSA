#include<iostream>
using namespace std;
int max(int a[]){
    int maxmimum = a[0];
    for(int i=0;i<5;i++){
        if(a[i]>maxmimum){
            maxmimum = a[i];
        }
    }
    return maxmimum;
}
//Time complexity = o(n)
int main(){
    int a[5]={1,8,7,57,4};
    cout<<max(a);
}
