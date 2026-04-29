#include <bits/stdc++.h>
using namespace std;
 
struct range{
    int l,r;
    int id;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<range> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
    }

    sort(a.begin(),a.end(),[](const auto&x,const auto &y){
        if (x.l!=y.l) return x.l<y.l;
        return x.r>y.r;
    });

    vector<int> contain(n,0);
    vector<int> contained(n,0);

    int minr=1e9+2;
    for (int i=n-1;i>=0;i--){
        if (minr<=a[i].r){
            contain[a[i].id]=1;
        }

        if (a[i].r<minr) minr=a[i].r;
    }

    int maxr=0;
    for (int i=0;i<n;i++){
        if (maxr>=a[i].r){
            contained[a[i].id]=1;
        }

        if (a[i].r>maxr) maxr=a[i].r;
    }

    for (int i=0;i<n;i++){
        if (i) cout<<' ';
        cout<<contain[i];
    }
    cout<<'\n';
    
    for (int i=0;i<n;i++){
        if (i) cout<<' ';
        cout<<contained[i];
    }
    cout<<'\n';
    return 0;
}