#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        long long total=1LL*(i*i)*(i*i-1)/2;
 
        total-=1LL*4*(i-1)*(i-2);
        cout<<total<<endl;
    }  
    return 0;
}