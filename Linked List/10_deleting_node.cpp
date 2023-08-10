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
int Delete(struct Node *p,int index){
    struct Node *q;
    int x=-1;
    if(index <1 || index > Count(p)){
        return -1;
    }
    else if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        delete q;
        return x;
    }
    else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}
int main(){
    int a[]={10,20,30,40,50};
    create(a,5);
    cout<<"Deleted Element: "<<Delete(first,5)<<endl;
    Display(first);
}