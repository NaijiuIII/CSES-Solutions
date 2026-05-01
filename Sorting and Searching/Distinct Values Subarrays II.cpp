#include <bits/stdc++.h>
using namespace std;
 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<long long> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    long long ans=0;
    int l=0;
    int num=0;
    map<long long,int> cnt;
    for (int r=0;r<n;r++){
        if (cnt[a[r]]==0) num++;

        cnt[a[r]]++;

        while (num>k){
            cnt[a[l]]--;
            if (cnt[a[l]]==0) num--;
            l++;
        }

        ans+=r-l+1;
    }

    cout<<ans<<'\n';
    return 0; 
}