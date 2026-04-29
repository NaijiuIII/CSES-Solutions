#include <bits/stdc++.h>
using namespace std;
 
struct Node{
    int l,r,id;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<Node> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }

    sort(a.begin(),a.end(),[](Node &x,Node &y){
        return x.l<y.l;
    });

    vector<int> ans(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

    int cnt=0;

    for (auto cur:a){
        if (!q.empty()&&q.top().first<cur.l){
            auto [end,room]=q.top();
            q.pop();

            ans[cur.id]=room;
            q.push({cur.r,room});
        }
        else{
            cnt++;
            q.push({cur.r,cnt});
            ans[cur.id]=cnt;
        }
    }

    cout<<cnt<<'\n';
    for (int i=0;i<n;i++){
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}