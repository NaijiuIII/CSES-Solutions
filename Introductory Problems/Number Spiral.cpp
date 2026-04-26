#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        long long x,y;
        cin>>y>>x;
        long long round=max(x,y);
 
        long long num=(round-1)*(round-1);
        if ((round&1)==0){
            num+=y+(round-x);
        }
        else num+=x+(round-y);
 
        cout<<num<<endl;
 
    }
    return 0;
}