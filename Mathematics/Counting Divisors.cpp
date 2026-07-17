#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> cnt(1e6+1,0);
    for (int i=1;i<=1e6;i++){
        for (int j=i;j<=1e6;j+=i){
            cnt[j]++;
        }
    }

    while (n--){
        int x;
        cin>>x;

        cout<<cnt[x]<<'\n';
    
    }
    return 0;
}