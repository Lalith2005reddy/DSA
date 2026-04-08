#include<iostream>
using namespace std;


void reverse(string &s){
    int i = 0;
    int j = s.length()-1;

    while(i<j){
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }

}

void print(string s){
    for(char c:s){
        cout<<c;
    }
}
int main(){
    string s;
    cin>>s;
    reverse(s);
    print(s);
    return 0;
}