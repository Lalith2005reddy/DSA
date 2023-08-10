#include<iostream>
using namespace std;
int main(){
    string a="How are you";
    int words=0;
    for(int i=0;a[i]!='\0';i++){
        if(a[i]==' ' && a[i-1]!=' '){
            words++;
        }
    }
    cout<<words+1;           //There are spaces+1 number of words
}