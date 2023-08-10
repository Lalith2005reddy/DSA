#include<iostream>
using namespace std;
int pow(int m,int n){
    if(n==0){
        return 1;
    }
    else{
        return pow(m,n-1)*m;
    }
}
int main(){
    cout<<pow(2,2);
}

//!Using pow with <cmath> header file
/*#include<iostream>
#include<cmath>
using namespace std;
int main(){
    cout<<pow(2,2);                //pow(base,exp)
    return 0;
}*/