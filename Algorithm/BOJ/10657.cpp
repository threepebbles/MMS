#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+1;

typedef pair<int, int> pii;
pii cow[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0,ip,sp;i<n;i++) {
        scanf("%d %d", &ip, &sp);
        cow[i] = {ip, sp};
    }

    sort(cow, cow+n);

    int ans=1;
    int cur_sp = cow[n-1].second;
    for(int i=n-2;i>=0;i--) {
        if(cow[i].second<=cur_sp) {
            ans++;
            cur_sp = cow[i].second;
        }
    }
    printf("%d", ans);
}