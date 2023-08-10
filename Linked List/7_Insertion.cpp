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
void Display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
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
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    if(index < 0 || index >Count(p)){
        return;
    }
    t=new Node;
    t->data=x;
    if(index ==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}
int main(){
    int a[]={3,5,7};
    create(a,3);
    Insert(first,1,10);
    Insert(first,2,15);
    Insert(first,3,8);

    Display(first);
    Display(first);
    return 0;
}