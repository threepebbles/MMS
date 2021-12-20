#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MAXN = 4000;

vector<pii> bales;


int main() {
    int n;
    scanf("%d", &n);
    for(int i=0, S, P; i<n; i++) {
        scanf("%d %d", &S, &P);
        bales.push_back({P, S});
    }
    sort(bales.begin(), bales.end());

    int ans = 0;
    for(int i=0;i<n-1;i++) {
        int width = bales[i+1].first - bales[i].first;
        
        int L = i, R = i + 1;
        while(L>=0 && R<n) {
            bool is_broken = false;    
            int cur_dis = bales[R].first - bales[L].first;
            if(cur_dis>bales[L].second) {
                L--;
                is_broken = true;
            }
            if(cur_dis>bales[R].second) {
                R++;
                is_broken = true;
            }
            if(!is_broken) break;
        }

        if(L>=0 && R<n) {
            ans += width;
        }
    }
    printf("%d", ans);
}