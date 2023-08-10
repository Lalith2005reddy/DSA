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
int isSorted(struct Node *p){
    int x=INT32_MIN;
    while(p){
        if(p->data < x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}
int main(){
    int a[]={10,20,30,40,50};
    create(a,5);
    if(isSorted(first)){
        cout<<"Sorted ";
    }
    else{
        cout<<"Not Sorted";
    }

}