#include<iostream>
using namespace std;
int sum(int a[]){
    int sum =0;
    for(int i=0;i<5;i++){
        sum = sum + a[i];
    }
    return sum;
}
//Time complexity = o(n)
int main(){
    int a[5]={1,8,7,57,4};
    cout<<sum(a);
}
