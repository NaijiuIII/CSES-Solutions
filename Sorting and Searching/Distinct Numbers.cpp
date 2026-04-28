#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
    set<long long> s;
    long long x;
    for (int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    return 0;
}