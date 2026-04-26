#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    long long mod=1e9+7;
    long long k=1;
    for (int i=0;i<n;i++){
        k<<=1;
        k%=mod;
    }
    cout<<k<<endl;
    return 0;
}