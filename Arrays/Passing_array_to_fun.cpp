#include<iostream>
using namespace std;
void test(int *a){
    a[1]=10;
    //! IMP
    //array size cannot be obtained in passed function with below process
    int n = sizeof(a)/sizeof(int);
    cout<<n<<endl;
}
int main(){
    int a[5]={1,2,3,4,5};
    test(a);

    for(int i:a){
        cout<<i<<" ";
    }
}