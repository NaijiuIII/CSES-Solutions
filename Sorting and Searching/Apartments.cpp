#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n,m;
    cin>>n>>m;
    long long k;
    cin>>k;
    vector<long long> a(n);
    vector<long long> b(m);
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<m;i++) cin>>b[i];
 
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
 
    int i=0,j=0;
    int cnt=0;
    while (i<n&&j<m){
        long long l=a[i]-k;
        long long r=a[i]+k;
        if (b[j]>=l&&b[j]<=r){
            cnt++;
            i++;
            j++;
        }
        else if (b[j]>r) j++;
        else i++;
    }
    cout<<cnt<<endl;
    return 0;
}