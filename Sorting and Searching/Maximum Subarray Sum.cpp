#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin>>n;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
 
    long long Themax=a[0],cur=a[0];
    for (int i=1;i<n;i++){
        cur=max(a[i],cur+a[i]);
        Themax=max(cur,Themax);
    }
    cout<<Themax<<endl;
    return 0;
}