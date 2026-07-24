#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    
    while (t--){
        int n;
        cin>>n;

        int sum=0;
        for (int i=0;i<n;i++){
            int x;cin>>x;
            sum^=x%4;
        }

        if (sum!=0) cout<<"first\n";
        else cout<<"second\n";
    }
    return 0;
}