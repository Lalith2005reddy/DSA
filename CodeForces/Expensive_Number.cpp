//Summary
/*
In this problem if th enumber is 13700 we start a loop from left side and check for any 0's so if we find the zeros we increase the value of ans
as the zeros needed to be removed on trailing part and another loop from right to left until the index of the non zero number and then we find
and non zeroes numbers and increase count and if we find any zeros then ignore them. Remember that we are not considering contigous number the 
numbers may be from any part of the number and also remember we are aiming to get 1 as min value.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int index = n-1;
        int ans=0;

        for(int i=n-1;i>=0;i--){
            int t = s[i] - '0';
            if(t > 0){
                index = i;
                break;
            }
            else{
                ans++;
            }
        }

        for(int i=0;i<index;i++){
            if(s[i] - '0' != 0){
                ans++;
            }
        }
        cout<< ans <<endl;
    }
    return 0;
}