#include<iostream>
using namespace std;
int main(){
    int sortarr[10] = {3,6,8,8,10,12,15,15,15,20};
    int lastduplicate=0;
    for(int i=0;i<10;i++){
        if(sortarr[i]==sortarr[i+1] && sortarr[i]!=lastduplicate){
            cout<<sortarr[i]<<" ";
            lastduplicate=sortarr[i];
        }
    }
}