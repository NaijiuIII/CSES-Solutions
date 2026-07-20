#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> isprime(2e6+1,true);
    vector<long long> prime;

    isprime[0]=false;
    isprime[1]=false;

    for (int i=2;i<=2e6;i++){
        if (!isprime[i]) continue;

        prime.push_back(i);
        for (long long j=1LL*i*i;j<=2e6;j+=i){
            isprime[j]=false;
        }
    }

    auto check=[&](long long x)->bool{
        for (long long p:prime){
            if (p*p>x) break;

            if (x%p==0) return false;
        }
        return true;
    };
    
    int t;
    cin>>t;
    while (t--){
        long long n;
        cin>>n;

        long long x=n+1;
        if (x<=2){
            cout<<2<<'\n';
            continue;
        }

        if (x%2==0) x++;

        while (!check(x)){
            x+=2;
        }

        cout<<x<<'\n';
    }
    return 0;
}