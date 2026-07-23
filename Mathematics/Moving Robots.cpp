#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin>>k;

    long double emp[8][8];

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            emp[i][j]=1;
        }
    }

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    for (int sx=0;sx<8;sx++){
        for (int sy=0;sy<8;sy++){
            long double dp[8][8]={};
            long double ndp[8][8]={};

            dp[sx][sy]=1;

            for (int step=1;step<=k;step++){
                for (int i=0;i<8;i++){
                    for (int j=0;j<8;j++){
                        ndp[i][j]=0;
                    }
                }

                for (int x=0;x<8;x++){
                    for (int y=0;y<8;y++){
                        int cnt=0;

                        for (int d=0;d<4;d++){
                            int nx=x+dx[d];
                            int ny=y+dy[d];

                            if (nx>=0&&nx<8&&ny>=0&&ny<8) cnt++;
                        }

                        for (int d=0;d<4;d++){
                            int nx=x+dx[d];
                            int ny=y+dy[d];

                            if (nx>=0&&nx<8&&ny>=0&&ny<8){
                                ndp[nx][ny]+=dp[x][y]/cnt;
                            }
                        }
                    }
                }

                for (int i=0;i<8;i++){
                    for (int j=0;j<8;j++){
                        dp[i][j]=ndp[i][j];
                    }
                }
            }

            for (int x=0;x<8;x++){
                for (int y=0;y<8;y++){
                    emp[x][y]*=(1-dp[x][y]);
                }
            }
        }
    }

    long double ans=0;

    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            ans+=emp[i][j];
        }
    }

    cout<<fixed<<setprecision(6)<<ans<<'\n';
    return 0;
}