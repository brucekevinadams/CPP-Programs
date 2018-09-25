#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
using namespace std;

int q, n, f[8200] = {0};
LL dp[1005][8200] = {0}, cnt[1005] = {0};
vector<int> P;

void makePrime(){
    f[0] = f[1] = 1;
    for(int i=2; i*i < 8200; i++){
        if(!f[i]){
            for(int j=i+i; j< 8200; j+=i)
                f[j] = 1;
        }
    }
    for(int i=2; i<8200; i++) if(!f[i]) P.push_back(i);
}

int main() {
    cin >> q;
    makePrime();

    while(q--){
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        memset(dp,0,sizeof(dp));
        
        for(int i=0,x; i<n; i++) cin >> x, cnt[x-3500]++;
        
        dp[0][3500] = (cnt[0] + 1)/2;
        dp[0][0] = (cnt[0] + 2) / 2;
        for(int i=1; i<1005; i++){
            for(int j=0; j<8200; j++){
                dp[i][j] = (dp[i-1][j]*((cnt[i]+2)/2) + dp[i-1][j^(i+3500)]*((cnt[i]+1)/2) ) % M ;
            }
        }
        LL ans = 0;
        for(int p : P){
            (ans += dp[1004][p]) %= M;
        }
        cout << ans%M << endl;
    }
    return 0;
}