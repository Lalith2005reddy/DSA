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
int main(){
    int a[]={3,5,7,10,15};
    create(a,5);
    Display(first);
    return 0;
}
//!  With Class
/*#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
class Linked_List : public Node{
    public:
    Node *first;
    public:
    void create(int a[],int n){
        int i;
        Node *temp,*last;
        first=new Node;
        first->data=a[0];
        first->next=NULL;
        last=first;

        for(i=1;i<n;i++){
            temp=new Node;
            temp->data=a[i];
            temp->next=NULL;
            last->next=temp;
            last=temp;
    }
}
    void display(){
        while(first!=NULL){
            cout<<first->data<<" ";
            first=first->next;
    }
}
};
int main(){
    int a[]={3,2,4,7,8};
    Linked_List l1;
    l1.create(a,5);
    l1.display();
    return 0;
}*/