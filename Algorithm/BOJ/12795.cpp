#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 2e18;

struct Line {
	ll m, n;
	ll get(ll x) {
		return m * x + n;
	}
};

struct Node {
	int l, r; // child
	ll s, e; // range
	Line line;
};

struct Li_Chao {
	vector<Node> tree;

	void init(ll s, ll e) {
		tree.push_back({ -1, -1, s, e, { 0, -INF } });
	}

	void update(int node, Line v) {
		ll s = tree[node].s, e = tree[node].e;
		ll m = s + e >> 1;

		Line low = tree[node].line, high = v;
		if (low.get(s) > high.get(s)) 
            swap(low, high);

		if (low.get(e) <= high.get(e)) {
			tree[node].line = high;
            return;
		}

		if (low.get(m) < high.get(m)) {
			tree[node].line = high;
			if (tree[node].r == -1) {
				tree[node].r = tree.size();
				tree.push_back({ -1, -1, m + 1, e, { 0, -INF } });
			}
			update(tree[node].r, low);
		}
		else {
			tree[node].line = low;
			if (tree[node].l == -1) {
				tree[node].l = tree.size();
				tree.push_back({ -1, -1, s, m, { 0, -INF } });
			}
			update(tree[node].l, high);
		}
	}

	ll query(int node, ll x) {
		if (node == -1) return -INF;

		ll s = tree[node].s, e = tree[node].e;
		ll m = s + e >> 1;

		if (x <= m) 
            return max(tree[node].line.get(x), 
                        query(tree[node].l, x));
		else
            return max(tree[node].line.get(x), 
                        query(tree[node].r, x));
	}
} seg;

int main(){
	int q;
    scanf("%d", &q);
	seg.init(-2e12, 2e12);

    int o;
    ll m, n;
	while (q--){
        scanf("%d", &o);
		if (o == 1) {
            scanf("%lld %lld", &m, &n);
			seg.update(0, { m, n });
		}
		else {
            scanf("%lld", &m);
            printf("%lld\n", seg.query(0, m));
		}
	}
}