#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    vector<int> h(n+1);
    for (int i=1;i<=n;i++){
        cin>>h[i];
    }

    vector<int> nxt(n+2,n+1);
    stack<int> st;

    for (int i=n;i>=1;i--){
        while (!st.empty()&&h[st.top()]<=h[i]){
            st.pop();
        }

        if (!st.empty()) nxt[i]=st.top();
        st.push(i);
    }

    vector<vector<int>> up(20,vector<int>(n+2,n+1));

    for (int i=1;i<=n;i++){
        up[0][i]=nxt[i];
    }

    for (int j=1;j<20;j++){
        for (int i=1;i<=n;i++){
            up[j][i]=up[j-1][up[j-1][i]];
        }
    }

    while (q--){
        int a,b;
        cin>>a>>b;

        int cur=a;
        int ans=1;
        for (int j=19;j>=0;j--){
            if (up[j][cur]<=b){
                ans+=1<<j;
                cur=up[j][cur];
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}