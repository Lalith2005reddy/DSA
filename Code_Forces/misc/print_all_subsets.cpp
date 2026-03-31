#include<bits/stdc++.h>
using namespace std;

void printsubset(vector<int> arr,int i,vector<int> &sub){

    if( i>= arr.size()){
        for(int i=0;i<sub.size();i++){
            cout<<sub[i];
        }
        cout<<endl;
        return;
    }

    //take
    sub.push_back(arr[i]);
    printsubset(arr,i+1,sub);
    //Not take
    sub.pop_back();
    printsubset(arr,i+1,sub);
    

}
int main(){
    vector<int> arr = {1,2,2,4};
    vector<int> sub;
    printsubset(arr,0,sub);
    return 0;
}