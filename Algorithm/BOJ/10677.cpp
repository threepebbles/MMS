#include <bits/stdc++.h>
using namespace std;

vector<int> us_x, us_y;


int main() {
    int T;
    scanf("%d", &T);
    
    int N_X, N_Y;
    int n1, n2;
    while(T--) {
        scanf("%d %d ", &N_X, &N_Y);  // <= 2,025,135,009
        int ans_x = -1, ans_y = -1;
        for(int base = 10; base<=15000; base++) {
            int tmp_n_x = N_X, tmp_n_y = N_Y;
            int tmp_base = 1;
            n1 = n2 = 0;
            while(tmp_n_x) {
                n1 += tmp_n_x%10*tmp_base;
                tmp_n_x/=10;
                tmp_base*=base;
            }
            tmp_base = 1;
            while(tmp_n_y) {
                n2 += tmp_n_y%10*tmp_base;
                tmp_n_y/=10;
                tmp_base*=base;
            }
            us_x.push_back(n1);
            us_y.push_back(n2);
        }
        sort(us_x.begin(), us_x.end());
        sort(us_y.begin(), us_y.end());

        for(int i=0; i<us_x.size();i++) {            
            int lbidx = lower_bound(us_y.begin(), us_y.end(), us_x[i])-us_y.begin();
            if(lbidx==us_y.size()) continue;
            if(us_y[lbidx]==us_x[i]) {
                ans_x = 10 + i;
                ans_y = 10 + lbidx;
            }
        }
        printf("%d %d\n", ans_x, ans_y);
        us_x.clear();
        us_y.clear();
    }
}