//! First printing and then calling
/*#include<iostream>
using namespace std;
void fun1(int x){
    if(x>0){
        cout<<x<<" ";
        fun1(x-1);
    }
}
int main(){
    int a=3;
    fun1(a);
    return 0;
}*/

//! First calling and then priting and returning
#include<iostream>
using namespace std;
void fun1(int x){
    if(x>0){
        fun1(x-1);
        cout<<x<<" ";
    }
}
int main(){
    int a;
    cout<<"Enter Num: ";
    cin>>a;
    fun1(a);
    return 0;
}
