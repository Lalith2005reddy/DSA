// Stack provides static memory allocation, i.e., it is used to store the temporary variables. 
// Heap provides dynamic memory allocation.

// Compile-time is the time at which the source code is converted into an executable code(Machine Code).
// while the run time is the time at which the executable code is started running.

// Declaring an array dynamically 
#include<iostream>
using namespace std;
int main(){
    int *p = new int[5];
    p[0]=1;
    p[1]=2;
    p[2]=3;
    p[3]=4;
    p[4]=5;
    for(int i=0;i<5;i++){
        cout<<p[i];
    }
    delete []p;
}
// The access time in stack is faster.	
// The access time in heap is slower.