#include<iostream>
using namespace std;
class Elements{
    public:
    int i,j,x;
};
class Sparse{
    public:
    int m,n,num;
    Elements *ele;
    public:
    void Create(){
       
        cout<<"Enter Dimensions :";
        cin>>m>>n;
        cout<<"Number of non-zero ele: ";
        cin>>num;
        ele=new Elements[num];
        for(int i=0;i<num;i++){
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
    }
}
void Display(){
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==ele[k].i && j==ele[k].j){
                cout<<ele[k++].x<<" ";    
            }
            else{
                cout<<"0 ";
            }        
        }
        cout<<"\n";
    }
}
};
int main(){
    Sparse s;
    s.Create();
    s.Display();
}