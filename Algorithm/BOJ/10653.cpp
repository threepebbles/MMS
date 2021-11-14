#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;
const int INF = 1e9;

int x[MAXN], y[MAXN];
int dp[MAXN][MAXN];

int calc_dis(int i1, int i2) {
    return abs(x[i1]-x[i2]) + abs(y[i1]-y[i2]);
}

int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    for(int i=1;i<=n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    dp[2][0] = calc_dis(1, 2);

    for(int i=3;i<=n;i++) {
        dp[i][0] = dp[i-1][0] + calc_dis(i-1, i);
        for(int j=1;j<=k;j++) {
            for(int l=0;l<=k && i-l-1>0 && j-l>=0;l++) { // skip 횟수
                dp[i][j] = min({
                    dp[i][j],
                    dp[i-l-1][j-l] + calc_dis(i-l-1, i)
                });
            }
        }
    }

    int ans = INF;
    for(int i=0;i<=k;i++) {
        ans = min(ans, dp[n][i]);
    }
    printf("%d", ans);
}