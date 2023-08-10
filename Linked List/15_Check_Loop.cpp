#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int a[],int n){
    int i;
    Node *t,*last;
    first =new Node;
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
int isLoop(struct Node *f){
    Node *p,*q;
    p=q=f;

    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;   //! Doubt
    }while(p && q && p!=q); 
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    struct Node *t1,*t2;
    int a[]={10,20,30,40,50};
    create(a,5);
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;

    cout<<isLoop(first);
}