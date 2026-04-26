#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
 
    if (n%4==1||n%4==2){
        cout<<"NO"<<endl;
        return 0;
    }
    else cout<<"YES"<<endl;
 
    vector<int> a,b;
    long long suma=0,sumb=0;
    for (int i=n;i>=1;i--){
        if (suma<=sumb){
            a.push_back(i);
            suma+=i;
        }
        else{
            b.push_back(i);
            sumb+=i;
        }
    }
 
    cout<<a.size()<<endl;
    for (int i=0;i<a.size();i++){
        if (i!=0) cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
 
    cout<<b.size()<<endl;
    for (int i=0;i<b.size();i++){
        if (i!=0) cout<<' ';
        cout<<b[i];
    }
    cout<<endl;
    return 0;
}