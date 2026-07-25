#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    int n=s.size();
    vector<int> nxt(n,0);
    for (int i=1,j=0;i<n;i++){
        while(j>0&&s[i]!=s[j]){
            j=nxt[j-1];
        }

        if (s[i]==s[j]) j++;
        nxt[i]=j;
    }

    vector<int> ans;
    int len=nxt[n-1];

    while (len>0){
        ans.push_back(len);
        len=nxt[len-1];
    }

    reverse(ans.begin(),ans.end());

    for (int x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';


    return 0;
}