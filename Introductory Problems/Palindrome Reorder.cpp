#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    string s;
    cin>>s;
    vector<int> a(26,0);
    for (int i=0;i<s.size();i++){
        a[s[i]-'A']++;
    }
    int odd=0;
    string mid="";
    for (int i=0;i<26;i++){
        if (a[i]%2==1){
            odd++;
            mid.push_back('A'+i);
        }
    }
 
    if (odd>1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
 
    string left="";
    for (int i=0;i<26;i++){
        left+=string(a[i]/2,'A'+i);
    }
    string right=left;
    reverse(right.begin(),right.end());
    cout<<left+mid+right<<endl;
    return 0;
}