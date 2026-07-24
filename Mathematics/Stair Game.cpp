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

        long long sum=0;
        for (int i=1;i<=n;i++){
            long long x;
            cin>>x;
            if (i%2==0){
                sum^=x;
            }
        }

        if (sum!=0) cout<<"first\n";
        else cout<<"second\n";
    }
    return 0;
}