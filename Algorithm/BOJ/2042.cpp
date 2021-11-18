#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e6+1;

ll seg_sum[MAXN*4];
int K;

ll query_sum(int l, int r, int st, int ed, int idx, ll seg[]) {
    if(r<st || ed<l) return 0;
    if(st<=l && r<=ed) {
        return seg[idx];
    }
    int m = (r+l)/2;
    return query_sum(l, m, st, ed, idx*2, seg) 
            + query_sum(m+1, r, st, ed, idx*2+1, seg);
}

void update_sum(int l, int r, int st, int ed, int idx, ll diff, ll seg[]) {
    if(r<st || ed<l) return;
    if(l==r) {
        seg[idx] += diff;
        return;
    }
    
    int m = (r+l)/2;    
    update_sum(l, m, st, ed, idx*2, diff, seg);
    update_sum(m+1, r, st, ed, idx*2+1, diff, seg);
    
    seg[idx] = seg[idx*2] + seg[idx*2+1];
}


int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    K=1;
    while(K<n) K<<=1;

    for(int i=0;i<n;i++) {
        scanf("%lld", &seg_sum[K+i]);
    }
    for(int i=K-1;i>0;i--) {
        seg_sum[i] = seg_sum[2*i] + seg_sum[2*i+1];
    }

    int q = m+k;
    int o;
    while(q--) {
        scanf("%d", &o);
        if(o==1) {  // update
            int i;
            ll x;
            scanf("%d %lld", &i, &x); 
            update_sum(1, K, i, i, 1, x-seg_sum[K+i-1], seg_sum);
        }
        else {
            int l, r;
            scanf("%d %d", &l, &r);
            ll ret = query_sum(1, K, l, r, 1, seg_sum);
            printf("%lld\n", ret);
        }
    }
}