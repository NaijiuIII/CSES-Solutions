#include <bits/stdc++.h>
using namespace std;

 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    int n;
    cin>>n;
    vector<long long> p(n);
    long long total=0;
    for (int i=0;i<n;i++){
        cin>>p[i];
        total+=p[i];
    }
 
    long long minsum=total;
    for (int i=0;i<(1<<n);i++){
        long long suma=0;
        for (int j=0;j<n;j++){
            if ((i&(1<<j))!=0) suma+=p[j];
             
        }
        long long sumb=total-suma;
 
        minsum=min(minsum,max(suma,sumb)-min(suma,sumb));
         
    }
    cout<<minsum<<endl;
    return 0;
}