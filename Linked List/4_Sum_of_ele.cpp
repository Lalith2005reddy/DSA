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
int Sum(struct Node *p){
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int RSum(struct Node *p){
    if(p){
        return RSum(p->next)+p->data;
    }
    else{
        return 0;
    }
}
int main(){
    int a[]={3,5,7,10,15,8,12,1};
    create(a,8);
    cout<<"Sum is: "<<RSum(first);
    return 0;
}
