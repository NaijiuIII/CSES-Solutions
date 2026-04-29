#include <bits/stdc++.h>
using namespace std;
 
struct range{
    int l,r;
    int id;
};

vector<int> bit;
int siz;

int lowbit(int x){
    return x&-x;
}

void add(int pos,int x){
    while (pos<=siz){
        bit[pos]+=x;
        pos+=lowbit(pos);
    }
}

int sum(int pos){
    int res=0;
    while (pos>0){
        res+=bit[pos];
        pos-=lowbit(pos);
    }
    return res;
}

int getid(const vector<int> &k,int x){
    int l=0,r=k.size()-1;

    int ans=0;
    while (l<=r){
        int mid=(l+r)/2;
        if (k[mid]>=x){
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }

    return ans+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<range> a(n);
    set<int> temp;
    for (int i=0;i<n;i++){
        cin>>a[i].l>>a[i].r;
        a[i].id=i;
        temp.insert(a[i].r);
    }

    vector<int> vals;
    for (int x:temp) vals.push_back(x);
    siz=vals.size();
    sort(vals.begin(),vals.end());
    bit.assign(siz+2,0);

    sort(a.begin(),a.end(),[](const auto&x,const auto &y){
        if (x.l!=y.l) return x.l<y.l;
        return x.r>y.r;
    });

    vector<int> contain(n,0);
    vector<int> contained(n,0);

    for (int i=n-1;i>=0;i--){
        int id=getid(vals,a[i].r);
        contain[a[i].id]=sum(id);
        add(id,1);
    }

    bit.assign(siz+2,0);

    for (int i=0;i<n;i++){
        int id=getid(vals,a[i].r);
        contained[a[i].id]=i-sum(id-1);
        add(id,1);
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