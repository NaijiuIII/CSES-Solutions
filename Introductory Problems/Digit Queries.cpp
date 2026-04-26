#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int q;
    cin>>q;
    while (q--){
        long long k;
        cin>>k;
 
        long long d=1;
        long long cnt=9;
        long long s=1;
 
        while (k>cnt*d){
            k-=cnt*d;
            d++;
            cnt*=10;
            s*=10;
        }
 
        long long num=s+(k-1)/d;
        int pos=(k-1)%d;
        cout<<to_string(num)[pos]<<'\n';
    }
    return 0;
}