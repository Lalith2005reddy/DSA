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
int main(){
    struct Sparse s;

    Create(&s);
    Display(s);
    return 0;
}