#include<iostream>
using namespace std;
int main(){
    string a="Painter";
    string b="Painting";
    int i,j;
    for(i=0,j=0;a[i]!='\0' && b[j]!='\0';i++,j++){
        if(a[i]!=b[j]){
            break;
        }
    }
        if(a[i]==b[j]){
            cout<<"Equal";
        }
        else if(a[i]<b[j]){
            cout<<"Smaller";
        }
        else{
            cout<<"Greater";
        }
}