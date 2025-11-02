#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    ifstream fin("input.txt");
    int t;
    fin>>t;

    while(t--){
        int n,k;
        fin>>n>>k;

        int arr[n];

        for(int i=0;i<n;i++){
            fin>>arr[i];
        }

        if(k>=2) cout<<"YES"<<endl;
        else{ //if k ==1

            bool sort = true;
            for(int i=1;i<n;i++){
                if(arr[i-1] > arr[i]) {sort = false; break;}
            }
            if(sort) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            
        }
    }
    
    
    return 0;
}