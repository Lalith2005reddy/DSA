#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long sum = 1LL * n * (n + 1) / 2;

    if(sum % 2 != 0){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    long long target = sum / 2;

    //In this question i figured out the odd, even part of sum, but the 2 sets insertion was not figured out

    //So we can insert into 2 sets by checking if the value i is greater than target -> s1 other wise -> s2

    vector<int> set1, set2;

    for(int i = n; i >= 1; i--){
        if(i <= target){
            set1.push_back(i);
            target -= i;
        }
        else{
            set2.push_back(i);
        }
    }

    cout << set1.size() << endl;
    for(int x : set1) cout << x << " ";
    cout << endl;

    cout << set2.size() << endl;
    for(int x : set2) cout << x << " ";
    cout << endl;

    return 0;
}