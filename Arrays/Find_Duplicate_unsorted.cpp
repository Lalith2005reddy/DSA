#include<iostream>
using namespace std;
//Normal
void Duplicate(int a[],int n){
    for(int i=0;i<n-1;i++){
        int count = 1;
        if(a[i]!=-1){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                count++;
                a[j]=-1;       //Marking Finished elements as -1 so that they dont repeat again
            }
        }
        if(count>1){
            cout<<a[i]<<" "<<count<<endl;
        }
    }
    }         //Time = o(n^2)
}
//With HashTable
void Hashtable(int a[],int n){
    int *h; //Hash table array
   h=new int[50];
   for(int i=0;i<n;i++){
    h[i]=0;
   }
   for(int i=0;i<n;i++){
    h[a[i]]++;
   }
   for(int i=0;i<n;i++){
    if(h[i]>1){
        cout<<i<<" Count : "<<h[i];
        cout<<endl;
    }
   }
}     //Time = o(n)
int main(){
    int a[]={8,3,6,4,6,5,6,8,2,7};
    int n= sizeof(a)/sizeof(int);
    //Duplicate(a,n);
    cout<<endl;
    Hashtable(a,n);
    return 0;
}