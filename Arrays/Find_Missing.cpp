#include<iostream>
using namespace std;
void missing(int a[],int n){
   int *h; //Hash table array
   h=new int[n];
   for(int i=0;i<n;i++){
    h[i]=0;
   }
    for(int i=0;i<n;i++){
        h[a[i]] = 1;
    }
    for(int i=1;i<n;i++){
        if(h[i]==0){
        cout<<i<<" ";
        }
    }
    delete []h;
}
int main(){
    int a[10]={3,7,4,9,12,6,1,11,2,10};
    int n=sizeof(a)/sizeof(int);
    missing(a,n);
}

/*Approach 1 (Using Hashing): The idea behind the following approach is

The numbers will be in the range (1, N), an array of size N can be maintained to keep record of the elements present in the given array

Create a temp array temp[] of size n + 1 with all initial values as 0.
Traverse the input array arr[], and do following for each arr[i] 
if(temp[arr[i]] == 0) temp[arr[i]] = 1 
Traverse temp[] and output the array element having value as 0 (This is the missing element).*/
// C++ program to Find the missing element
