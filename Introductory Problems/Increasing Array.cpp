#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    vector<long long> a(n);
    for (int i=0;i<n;i++) cin>>a[i];
 
    long long step=0;
    for (int i=1;i<n;i++){
        if (a[i]>=a[i-1]) continue;
        step+=a[i-1]-a[i];
        a[i]=a[i-1];
    }
    cout<<step<<endl;
    return 0;
}