#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin>>n;
    long long x;
    cin>>x;
    vector<long long> p(n);
    for (int i=0;i<n;i++) cin>>p[i];
 
    int cnt=0;
    int l=0,r=n-1;
    sort(p.begin(),p.end());
    while (l<=r){
        if (l==r){
            cnt++;
            break;
        }
 
        if (p[l]+p[r]>x){
            cnt++;
            r--;
        }
        else{
            r--;
            l++;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}