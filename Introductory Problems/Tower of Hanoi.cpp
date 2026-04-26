#include <bits/stdc++.h>
using namespace std;

 
void hanoi(int k,int from,int to,int other){
    if (k==1){
        cout<<from<<' '<<to<<endl;
        return;
    }
    hanoi(k-1,from,other,to);
    cout<<from<<' '<<to<<endl;
    hanoi(k-1,other,to,from);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
   
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    hanoi(n,1,3,2);
    return 0;
}