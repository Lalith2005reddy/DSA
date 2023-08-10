#include<iostream>
using namespace std;
struct Element{
    int i;
    int j;
    int x;
};
struct Sparse{
    int m;
    int n;
    int num;
    struct Element *ele;
};
void Create(struct Sparse *s){
    cout<<"Enter Dimensions :";
    cin>>s->m>>s->n;
    cout<<"Number of non-zero ele: ";
    cin>>s->num;
    s->ele=new Element[s->num];
    for(int i=0;i<s->num;i++){
        cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;
    }
}
void Display(struct Sparse s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(i==s.ele[k].i && j==s.ele[k].j){
                cout<<s.ele[k++].x<<" ";    
            }
            else{
                cout<<"0 ";
            }        
        }
        cout<<"\n";
    }
}
struct Sparse *add(struct Sparse *s1,struct Sparse *s2){
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;
    sum=new Sparse;
    sum->ele=new Element[s1->num+s2->num];
    while(i<s1->num && j<s2->num){
        if(s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++]=s1->ele[i++];
        else if(s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++]=s2->ele[j++];
        else{
              if(s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++]=s1->ele[i++];
            else if(s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++]=s2->ele[j++];
            else{
                sum->ele[k]=s1->ele[i];
                sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x;         
           }
        }
    }
    for(;i<s1->num;i++)sum->ele[k++]=s1->ele[i];
    for(;j<s2->num;i++)sum->ele[k++]=s2->ele[j];
    sum->m=s1->m;
    sum->n=s1->n;
    sum->num=k;
}
int main(){
    struct Sparse s1,s2,*s3;

    Create(&s1);
    Create(&s2);
    s3=add(&s1,&s2);
    Display(*s3);
    return 0;
}