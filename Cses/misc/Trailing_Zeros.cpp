#include<iostream>
using namespace std;



int main(){
        int n;
        cin>>n;
        int cnt = 0;

        while(n > 0){
            n /= 5;
            cnt += n;
        }
        cout<<cnt<<endl;
    return 0;
}