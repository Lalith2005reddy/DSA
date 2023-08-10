//!Using For loop
/*#include<iostream>
using namespace std;
void fact(int n){
    int sum=1;
    for(int i=1;i<=n;i++){
        sum=sum*i;
    }
    cout<<sum;
}
int main(){
    int n=0;
    fact(n);
    return 0;
}*/

//!Using recursion
#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){
    return 1;
    }
    else{
    return fact(n-1)*n;
    }
}
int main(){
    int n;
    cout<<"Enter Value of n: ";
    cin>>n;                                                    //! If the input number is negative then stack overflow will occur
    if(n<0){
        cout<<"Factorial is not Possible";
    }
    else{
    cout<<fact(n);
    }
    return 0;
}