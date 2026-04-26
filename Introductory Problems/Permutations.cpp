#include <bits/stdc++.h>
using namespace std;

 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin>>n;
    if (n==2||n==3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    else if (n==1){
        cout<<1<<endl;
        return 0;
    }
    else{
        vector<int> odd;
        vector<int> even;
        for (int i=1;i<=n;i++){
            if ((i&1)==0){
                even.push_back(i);
            }
            else odd.push_back(i);
        }
 
        vector<int> num=even;
        for (int i:odd){
            num.push_back(i);
        }
 
        for (int i=0;i<n;i++){
            if (i!=0) cout<<' ';
            cout<<num[i];
        }
        cout<<endl;
 
    }
    return 0;
}