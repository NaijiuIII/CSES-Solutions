#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    for (long long i=0;i<(1<<n);i++){
        int g=i^(i>>1);
        for (int j=n-1;j>=0;j--){
            cout<<((g>>j)&1);
        }
        cout<<endl;
    }
    return 0;
}