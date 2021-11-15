#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 1e5+1;
const ll INF = 2e18;

ll A[MAXN], LIS[MAXN];
int LIS_len;

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    for(int i=0, ip, sp;i<n;i++) {
        scanf("%d %d", &ip, &sp);   // initial position, speed
        A[i] = (ip + (ll)sp*t);
    }

    reverse(A, A+n);
    for(int i=0;i<n;i++) {
        LIS[i] = INF;
        int ubidx = upper_bound(LIS, LIS+i, A[i])-LIS;
        LIS[ubidx] = A[i];
    }
    LIS_len = lower_bound(LIS, LIS+n, INF)-LIS;
    printf("%d", LIS_len);
}