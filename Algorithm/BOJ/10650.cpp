#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+1;
const int INF = 2e9;

int n, q;
ll x[MAXN], y[MAXN];
ll seg_sum[MAXN*4], seg_max[MAXN*4];
int K;

ll calc_dis(int i1, int i2) {
    return abs(x[i2]-x[i1]) + abs(y[i2]-y[i1]);
}

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

ll query_max(int l, int r, int st, int ed, int idx, ll seg[]) {
    if(r<st || ed<l) return 0;
    if(st<=l && r<=ed) {
        return seg[idx];
    }
    int m = (r+l)/2;
    return max(query_max(l, m, st, ed, idx*2, seg),
            query_max(m+1, r, st, ed, idx*2+1, seg));
}

void update_max(int l, int r, int st, int ed, int idx, ll seg[]) {
    if(r<st || ed<l) return;
    if(l==r) {
        seg[idx] = calc_dis(l, l+1) + calc_dis(l+1, l+2) - calc_dis(l, l+2);
        return;
    }
    
    int m = (r+l)/2;    
    update_max(l, m, st, ed, idx*2, seg);
    update_max(m+1, r, st, ed, idx*2+1, seg);
    
    seg[idx] = max(seg[idx*2], seg[idx*2+1]);
}


int main() {
    scanf("%d %d", &n, &q);
    for(int i=1;i<=n;i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    K=1;
    while(K<n) K<<=1;

    for(int i=K;i<2*K;i++) {
        seg_max[i] = -INF;
    }
    for(int i=1;i<n;i++) {
        seg_sum[K+i-1] = calc_dis(i, i+1);
    }
    for(int i=1;i<n-1;i++) {
        seg_max[K+i-1] = calc_dis(i, i+1) + calc_dis(i+1, i+2) - calc_dis(i, i+2);
    }

    for(int i=K-1;i>0;i--) {
        seg_sum[i] = seg_sum[2*i] + seg_sum[2*i+1];
        seg_max[i] = max(seg_max[2*i], seg_max[2*i+1]);
    }

    char o[2];
    while(q--) {
        scanf("%s ", o);
        if(o[0]=='U') { // update
            int idx, nx, ny;
            scanf("%d %d %d", &idx, &nx, &ny);

            if(1<idx && idx<n) {
                ll prev_diff1 = calc_dis(idx-1, idx);
                ll prev_diff2 = calc_dis(idx, idx+1);
                x[idx] = nx, y[idx] = ny;
                ll new_diff1 = calc_dis(idx-1, idx);
                ll new_diff2 = calc_dis(idx, idx+1);
                update_sum(1, K, idx-1, idx-1, 1, new_diff1-prev_diff1, seg_sum);
                update_sum(1, K, idx, idx, 1, new_diff2-prev_diff2, seg_sum);
            }
            else if(idx==1) {
                ll prev_diff2 = calc_dis(idx, idx+1);
                x[idx] = nx, y[idx] = ny;
                ll new_diff2 = calc_dis(idx, idx+1);
                update_sum(1, K, idx, idx, 1, new_diff2-prev_diff2, seg_sum);
            }
            else {  // idx==n
                ll prev_diff1 = calc_dis(idx-1, idx);
                x[idx] = nx, y[idx] = ny;
                ll new_diff1 = calc_dis(idx-1, idx);
                update_sum(1, K, idx-1, idx-1, 1, new_diff1-prev_diff1, seg_sum);
            }

            for(int i=idx;i>=idx-2 && i>=1;i--) {
                if(i<=n-2) {
                    update_max(1, K, i, i, 1, seg_max);
                }
            }
        }
        else {  // query
            int l, r;
            scanf("%d %d", &l, &r);

            if(l==r) {
                puts("0");
                continue;
            }
            else if(l+1==r) {
                printf("%lld\n", calc_dis(l, r));
                continue;
            }
            ll sum = query_sum(1, K, l, r-1, 1, seg_sum);
            ll mx = query_max(1, K, l, r-2, 1, seg_max);
            printf("%lld\n", sum-mx);
        }
    }
}