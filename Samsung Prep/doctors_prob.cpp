#include<bits/stdc++.h>
using namespace std;


void docProb(vector<vector<double>> &arr,int n,int t,int curr,double p,vector<double> &ans){
    if(t <= 0){
        ans[curr] += p;
        return;
    }

    for(int i=1;i<=n;i++){
        if(arr[curr][i] != 0){
            p *= arr[curr][i];
            docProb(arr,n,t-10,i,p,ans);
            p /= arr[curr][i];
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;

    while(t--){
        int nodes,edges,Time;
        cin >> nodes >> edges >> Time;

        // double **arr = new double*[nodes];
        // for(int i=1;i<=nodes;i++){
        //     arr[i] = new double[nodes];
        //     for(int j=1;j<=nodes;j++){
        //         arr[i][j] = 0;
        //     }
        // }

        vector<vector<double>> arr(nodes+1,vector<double>(nodes+1,0.0));

        int from,to;
        double prob;
        for(int i=0;i<edges;i++){
            cin>>from>>to>>prob;
            arr[from][to] = prob;
        }

        vector<double> ans(nodes,0.0);

        docProb(arr,nodes,Time,1,1.0,ans);

        double finalProb = 0.0;
        int div = 0;

        for(int i=0;i<nodes;i++){
            if(ans[i+1] > finalProb){
                finalProb = ans[i+1];
                div = i+1;
            }
        }

        cout<<finalProb<<" "<<div<<"\n";
    }
    return 0;
}