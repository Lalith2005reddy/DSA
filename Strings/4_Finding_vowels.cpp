#include<iostream>
using namespace std;
int main(){
    string s="How are you";
    int vcount=0,ccount=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            vcount++;
        }
        else if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=127)){
            ccount++;
        }
    }
    cout<<"Vowels: "<<vcount<<endl;
    cout<<"Consonants : "<<ccount;
}