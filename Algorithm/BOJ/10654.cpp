#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 1e5+1;

pll cow[MAXN];

int main() {
    int n,t;
    scanf("%d %d", &n, &t);

    for(int i=0, ip, sp;i<n;i++) {
        scanf("%d %d", &ip, &sp);   // initial position, speed
        cow[i] = {(ll)ip, (ll)sp};
    }
    sort(cow, cow+n);

    int ans=1;
    ll cur_p = cow[n-1].first + cow[n-1].second*t;
    for(int i=n-2;i>=0;i--) {
        ll nxt_p = cow[i].first + cow[i].second*t;
        if(nxt_p<cur_p) {
            ans++;
            cur_p = nxt_p;
        }
    }
    printf("%d", ans);
}