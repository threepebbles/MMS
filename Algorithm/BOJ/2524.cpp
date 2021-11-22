#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mh_dis(ll A[], ll B[]) {
    return abs(A[0]-B[0]) + abs(A[1]-B[1]);
}

double calc_dis(double A[], double B[]) {
    return sqrt((A[0]-B[0])*(A[0]-B[0]) + (A[1]-B[1])*(A[1]-B[1]));
}

int main() {
    ll A[2], B[2];
    double A2[2], B2[2];

    double p,q,r;
    scanf("%lld %lld %lld %lld", &A[0], &A[1], &B[0], &B[1]);
    scanf("%lf %lf %lf", &p, &q, &r);

    A2[0] = A[0], A2[1] = A[1];
    B2[0] = B[0], B2[1] = B[1];

    // 1) Manhattan distance
    double ans = (double)mh_dis(A, B);

    // 2) manhattan distance + Broadway
    // 2-1) intersection with x = A[0], y = A[1]
    // p*A[0] + q*y = r -> y = (r-p*A[0])/q
    // p*x + q*A[1] = r -> x = (r-q*A[1])/p
    double C[2][2] = {{A[0], (r-p*A[0])/q}, {(r-q*A[1])/p, A[1]}};
    // 2-2) intersection with x = B[0], y = B[1]
    double D[2][2] = {{B[0], (r-p*B[0])/q}, {(r-q*B[1])/p, B[1]}};

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            double cur_dis = calc_dis(A2, C[i]) + calc_dis(C[i], D[j]) + calc_dis(D[j], B2);
            ans = min(ans, cur_dis);
        }
    }
    printf("%.9lf", ans);
}