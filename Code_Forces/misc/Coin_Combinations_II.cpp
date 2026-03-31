#include<bits/stdc++.h>
using namespace std;

int n;
int MOD = 1e9 + 7;

int solve(vector<int> &arr,int sum,set<vector<int>> &st,vector<int> &cont){
    if(sum == 0){
        vector<int> t = cont;
        sort(t.begin(),t.end());
        st.insert(t);
    }
    if(sum < 0){
        return 0;
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        cont.push_back(arr[i]);
        ans = (ans + solve(arr,sum-arr[i],st,cont));
        cont.pop_back();
    }
    return ans;

}
int main(){
    int x;
    cin>>n>>x;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin>>arr[i];
    set<vector<int>> st;
    vector<int> cont;
    int s = solve(arr,x,st,cont);
    cout<<st.size()<<endl;
    return 0;
}