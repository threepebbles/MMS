/* 
Guard Mark
Category:           Bit DP
Time Complexity:    O(n*2^n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 21;
const ll INF = 2e18;

int n, h;
ll H[MAXN], W[MAXN], S[MAXN];  // height, weight, strength
ll dp[1<<20], wsum[1<<20], hsum[1<<20];

int main() {
    
    scanf("%d %d", &n, &h);

    for(int i=0;i<n;i++) {
        scanf("%lld %lld %lld", &H[i], &W[i], &S[i]);
    }

    for(int state=0;state<(1<<n);state++) {
        dp[state] = -INF;
        for(int i=0;(1<<i)<=state;i++) {
            if((1<<i)&state) {
                wsum[state] += W[i];
                hsum[state] += H[i];
            }
        }
    }
    
    ll ans = -1;
    for(int state=0;state<(1<<n);state++) {
        for(int i=0;i<n;i++) {
            if(state&(1<<i)) continue;
            if(dp[state]==-INF) dp[state] = INF;

            int nxt_state = (state | (1<<i));
            dp[nxt_state] = max(
                dp[nxt_state],
                max(
                    min(dp[state]-W[i], S[i]),  // i번째 소가 위에 올라타는 경우
                    min(S[i]-wsum[state], dp[state])    // i번째 소가 맨 아래에 들어가는 경우
                )
            );
            if(hsum[nxt_state]>=h) ans = max(ans, dp[nxt_state]);
        }
    }
    if(ans==-1) puts("Mark is too tall");
    else printf("%lld", ans);
}