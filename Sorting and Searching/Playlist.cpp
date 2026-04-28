#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
 
    map<int,int> cnt;
 
    int l=0;
    int len=0;
 
    for (int r=0;r<n;r++){
        cnt[a[r]]++;
 
        while (cnt[a[r]]>1){
            cnt[a[l]]--;
            l++;
        }
        len=max(len,r-l+1);
    }
    cout<<len<<'\n';
    return 0;
}