#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
}*first;
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
int Count(struct Node *p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}
void Reverse1(struct Node *p){
    int *a,i=0;
    Node *q=p;
    a=new int[Count(p)];

    while(q){
        a[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q){
        q->data=a[i];
        q=q->next;
        i--;
    }
}
void Reverse2(struct Node *p){
    struct Node *q=NULL,*r=NULL;

    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(){
    int a[]={10,20,30,40,50};
    create(a,5);
    //Reverse1(first);
    Reverse2(first);
    Display(first);
}