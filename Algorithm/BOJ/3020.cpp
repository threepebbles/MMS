/*
Time Complexity : n log(n)
comment : 대부분의 풀이는 H log(n)이었다. 
나중에 강의를 한다면 매우 큰 H로 문제를 변형해서 풀려보는 것도 괜찮아보인다.
*/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e5+3;
int A[MAXN], B[MAXN];

int main() {
	int n, h;
	scanf("%d %d", &n, &h);
	
	int Asz = 1, Bsz = 1;
	for(int i=0, x;i<n;i++) {
		scanf("%d", &x);
		if(i&1) B[Bsz++] = x;
		else A[Asz++] = x;
	}
    A[Asz++] = B[Bsz++] = h;
	sort(A, A + Asz);
	sort(B, B + Bsz);
	
	int min_cnt = INF, sum = 0;
	for(int i = 0, cnt1, cnt2, dh, lbidx;i < Asz - 1;i++) {
		cnt1 = (Asz - 2) - i;
		dh = A[i] + 1;
	
		lbidx = lower_bound(B, B + Bsz, h - dh + 1) - B;
		cnt2 = Bsz - lbidx - 1;
		
		if(cnt1 + cnt2 < min_cnt) {
			min_cnt = cnt1 + cnt2;
			sum = h - B[lbidx-1] - dh + 1;
		}
		else if(cnt1 + cnt2 == min_cnt) {
			sum += h - B[lbidx-1] - dh + 1;
		}
	}
	printf("%d %d", min_cnt, sum);
}
