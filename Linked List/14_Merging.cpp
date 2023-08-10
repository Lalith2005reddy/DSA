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
void create2(int a[],int n){
    int i;
    Node *t,*last;
    second =new Node;
    second->data=a[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++){
        t=new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
void Concat(struct Node *p,struct Node *q){
    third=p;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}
void Merge(struct Node *p,struct Node*q){
    struct Node *last;
    if(p->data < q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}
int main(){
    int a[]={10,20,30,40,50};
    int b[]={5,15,25,35,45};
    create(a,5);
    create2(b,5);
    
    //Concat(first,second);
    Merge(first,second);
    Display(third);

}