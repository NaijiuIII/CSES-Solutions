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
        bool ok=false;

        for (int i=0;i<n;i++){
            long long x;
            cin>>x;

            if (x%2==1) ok=true;
        }

        if (ok) cout<<"first\n";
        else cout<<"second\n";
    }
    return 0;
}