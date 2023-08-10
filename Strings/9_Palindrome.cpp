#include<iostream>
using namespace std;
string reverse(string a){
    int n=a.length();
    for(int i=0;i<n/2;i++){
        char temp;
        temp = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = temp;
    }
    return a;
}
void compare(string a,string b){
    int i,j;
    for(i=0,j=0;a[i]!='\0' && b[j]!='\0';i++,j++){
        if(a[i]!=b[j]){
            break;
        }
    }
    if(a[i]!=b[j]){
        cout<<"Not a Palindrome";
    }
    else{
    cout<<"Palindrome";
    }
}
int main(){
    string a="nitin";
    string b;
    b=reverse(a);
    compare(a,b);
    
}