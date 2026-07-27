#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int n=s.size();
    string t=s+s;

    int i=0,j=1;
    int k=0;

    while (i<n&&j<n&&k<n){
        if (t[i+k]==t[j+k]) k++;
        else if (t[i+k]>t[j+k]){
            i=i+k+1;
            if (i==j) i++;

            k=0;
        }
        else{
            j=j+k+1;
            if (i==j) j++;
            k=0;
        }
    }

    int start=min(i,j);

    cout<<t.substr(start,n)<<'\n';

    return 0;
}