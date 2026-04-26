#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    long long n;
    cin>>n;
    long long num=0;
    while (n>0){
        n/=5;
        num+=n;
    }
    cout<<num<<endl;
    return 0;
}