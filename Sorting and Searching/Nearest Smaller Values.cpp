#include <bits/stdc++.h>
using namespace std;
 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    stack<pair<long long,int>> st;

    for (int i=1;i<=n;i++){
        long long x;
        cin>>x;

        while (!st.empty()&&st.top().first>=x) st.pop();

        if (i!=1) cout<<' ';
        if (st.empty()) cout<<0;
        else cout<<st.top().second;

        st.push({x,i});
    }
    
    cout<<'\n';

    return 0; 
}