#include <bits/stdc++.h>
using namespace std;
 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    long long s;
    cin>>s;

    vector<pair<long long,int>> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }

    sort(a.begin(),a.end());
    bool found=false;

    vector<int> ans;

    for (int i=0;i<n;i++){
        int l=i+1,r=n-1;
        if (found) break;
        while (l<r){

            if (found) break;

            long long k=a[i].first+a[l].first+a[r].first;
            if (k==s){
                found=true;
                ans.push_back(a[i].second);
                ans.push_back(a[l].second);
                ans.push_back(a[r].second);
            }
            else if (k<s) l++;
            else r--;
        }
    }

    if (found){
        for (int i=0;i<3;i++){
            if (i) cout<<' ';
            cout<<ans[i];
        }
    }
    else cout<<"IMPOSSIBLE";
    cout<<'\n';
    return 0; 
}