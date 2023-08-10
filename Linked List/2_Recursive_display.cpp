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
    if(p!=NULL){
        cout<<p->data<<" ";
        Display(p->next);
    }
}
void reverse_Display(struct Node *p){
    if(p!=NULL){
        reverse_Display(p->next);
        cout<<p->data<<" ";
    }
}
int main(){
    int a[]={3,5,7,10,15};
    create(a,5);
    Display(first);
    cout<<endl;
    reverse_Display(first);
    return 0;
}