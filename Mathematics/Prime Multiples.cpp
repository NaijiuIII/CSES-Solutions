#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    int k;
    cin>>n>>k;

    vector<long long> a(k);
    for (int i=0;i<k;i++){
        cin>>a[i];
    }

    long long ans=0;

    for (int mask=1;mask<(1<<k);mask++){
        long long lcm=1;
        int cnt=0;
        bool ok=true;

        for (int i=0;i<k;i++){
            if ((mask>>i)&1){
                cnt++;

                if (lcm>n/a[i]){
                    ok=false;
                    break;
                }

                lcm*=a[i];
            }
        }

        if (!ok) continue;

        if (cnt%2==1){
            ans+=n/lcm;
        }
        else ans-=n/lcm;
    }

    cout<<ans<<'\n';
    return 0;
}