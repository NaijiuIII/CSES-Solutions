#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    map<long long,int> cnt;
 
    long long sum=0;
    int l=0;
 
    for (int r=0;r<n;r++){
        cnt[a[r]]++;
 
        while (cnt[a[r]]>1){
            cnt[a[l]]--;
            l++;
        }
 
        sum+=r-l+1;
    }
    cout<<sum<<'\n';
    return 0;
}