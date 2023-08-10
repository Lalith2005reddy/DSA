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
struct Node * LSearch(struct Node *p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}
struct Node * Transposition(struct Node *p,int key){
    struct Node *q; //Tail Pointer for p
    q=p;
    while(p){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        p=p->next;
    }
    return NULL;
}
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(){
    Node *temp;
    int a[]={3,4,1,5,2};
    create(a,5);

    temp=Transposition(first,4);
    if(temp){
        cout<<"Key Is Found: "<<temp->data<<endl;
    }
    else
        cout<<"Key Is Not Found";
    Display(first);
}