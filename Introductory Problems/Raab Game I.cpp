#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin>>t;
    while (t--){
        int n,a,b;
        cin>>n>>a>>b;
        vector<int> va,vb;
 
        if (a+b>n||(a==0&&b>0)||(a>0&&b==0)){
            cout<<"NO"<<endl;
            continue;
        }
        while (a+b!=n){
            va.push_back(n),vb.push_back(n);
            n--;
        }
 
        if (n==1){
            cout<<"NO"<<endl;
            continue;
        }
 
        for (int i=1;i<=n;i++){
            va.push_back((i+b-1)%n+1);
            vb.push_back(i);
        }
        cout<<"YES"<<endl;
 
        for (int i=0;i<va.size();i++){
            if (i!=0) cout<<' ';
            cout<<va[i];
        }
        cout<<endl;
        for (int i=0;i<vb.size();i++){
            if (i!=0) cout<<' ';
            cout<<vb[i];
        }
        cout<<endl;
    }
     
    return 0;
}