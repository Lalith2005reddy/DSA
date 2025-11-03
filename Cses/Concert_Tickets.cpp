#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> tickets(n);
    vector<int> arr(m);

    for(int i=0;i<n;i++){
        cin>>tickets[i];
    }

    for(int i=0;i<m;i++){
        cin>>arr[i];
    }

    sort(begin(tickets), end(tickets));

    //5 3
    //5 3 7 8 5   -- > 3 5 5 7 8 ->use binary search (Upper bound)
    //4 8 3

    
    return 0;
}