#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int n=s.size();

    vector<int> z(n,0);
    int l=0,r=-1;

    for (int i=1;i<n;i++){
        if (i<=r){
            z[i]=min(z[i-l],r-i+1);
        }
        while (i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            z[i]++;
        }

        if (i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }

    for (int k=1;k<n;k++){
        if (z[k]>=n-k){
            cout<<k<<' ';
        }
    }
    cout<<n<<'\n';
    return 0;
}