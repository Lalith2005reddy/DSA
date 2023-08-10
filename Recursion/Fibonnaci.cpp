//! Using for loop
/*#include<iostream>
using namespace std;
int main(){
    int t0=0,t1=1,s,n;
    cout<<"Enter N: ";
    cin>>n;
    if(n<=1){
        return n;
    }
    else{
        for(int i=2;i<=n;i++){
            s=t0+t1;
            t0=t1;
            t1=s;
        }
    }
    cout<<s;
}
*/

//! Using Recursion
/*#include<iostream>
using namespace std;
int fib(int n){
    if(n<=1){
        return n;
    }
    else{
        return fib(n-2)+fib(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter N: ";
    cin>>n;
    cout<<fib(n);
}*/


//! Memoization using the arrays to store repeated values and reducing the calls of functions
#include<iostream>
using namespace std;
int F[10];  //Global array
int memfib(int n){
    
    if(n<=1){
        F[n]=n;
        return n;
    }
    else{
        if(F[n-2]==-1){
            F[n-2]=memfib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1]=memfib(n-1);
        }
    }
    return F[n-2]+F[n-1];
}
int main(){
    int n;
    cout<<"Enter N: ";
    cin>>n;
   for(int i=0;i<10;i++){
    F[i]=-1;
   }
   cout<<memfib(n);
}