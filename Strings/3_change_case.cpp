#include<iostream>
using namespace std;
void uppertolower(string a){
    for(int i=0;a[i]!='\0';i++){
        a[i]=a[i]+32;
    }
    cout<<a<<endl;
}
void lowertoupper(string a){
    for(int i=0;a[i]!='\0';i++){
        a[i]=a[i]-32;
    }
    cout<<a<<endl;
}
void Mixed(string s){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]>=65 && s[i]<=90){
            s[i]=s[i]+32;
        }
        /*else if(s[i]>=97 && s[i]<=127){
            s[i]-=32;
        }*/
    }
    cout<<s;
}
int main(){
    string a="WELCOME"; //Uppercase
    string b="welcome"; //Lowercase
    string c="wElCome"; //Mixed
    uppertolower(a);
    lowertoupper(b);
    Mixed(c);
}