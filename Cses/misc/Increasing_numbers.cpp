#include<iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    long long moves = 0;

    for(long long i=1;i<n;i++){// 3 2 5 1 7
        if(arr[i] >= arr[i-1]) continue;
        else if(arr[i] < arr[i-1]){
            long long diff = arr[i-1] - arr[i];
            arr[i] += diff;
            moves += diff;
        }
    }

    cout<<moves<<endl;
    return 0;
}