#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first;

void create(int a[],int n){
    int i;
    struct Node *t,*last;
    first = new Node;
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int max(Node *p){
    int m=INT32_MIN;  //Minimum Integer
    while(p){
        if(p->data>m){
            m=p->data;
        }
        p=p->next;
    }
    return m;
}
int Rmax(Node *p){
    int x=0;
    if(p==0)
        return INT32_MIN;
    x=Rmax(p->next);
    if(x>p->data){
        return x;
        }
    else{
        return p->data;
        }
}
int main(){
    int a[]={3,5,87,5,4};
    create(a,5);
    cout<<max(first);
    return 0;
}