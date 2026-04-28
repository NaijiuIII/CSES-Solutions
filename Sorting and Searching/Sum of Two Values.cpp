#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    long long s;
    cin>>n>>s;
    vector<pair<long long,int>> a(n);
    for (int i=0;i<n;i++) cin>>a[i].first,a[i].second=i+1;
 
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    while (l<r){
        if (a[l].first+a[r].first==s){
            cout<<a[l].second<<' '<<a[r].second<<'\n';
            return 0;
        }
        else if (a[l].first+a[r].first>s){
            r--;
        }
        else l++;
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}