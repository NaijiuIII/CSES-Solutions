#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<int> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
    
    vector<int> f;

    for (int i=0;i<n;i++){
        int l=0,r=f.size()-1;

        int pos=-1;
        while (l<=r){
            int mid=r-(r-l)/2;
            if (f[mid]>=a[i]){
                pos=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        if (pos==-1) f.push_back(a[i]);
        else f[pos]=a[i];
    }

    cout<<f.size()<<'\n';
    return 0;
}