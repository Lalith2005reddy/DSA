#include<iostream>
using namespace std;
int main(){
    int *p = new int[5];
    //int *p = (int *)malloc(5*sizeof(int));
    p[0]=3;     //Initializing array
    p[1]=5;
    p[2]=7;
    p[3]=9;
    p[4]=11;
    
    int *q = new int[10];
    for(int i=0;i<5;i++){
        q[i]=p[i];
    }
    delete []p;       //removing previous p array
    p=q;              //p in now pointing to q array
    q=NULL;           //q is pointing noting  (NULL pointer)
    for(int i=0;i<5;i++){
        cout<<p[i]<<endl;
    }
}