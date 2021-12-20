#include <bits/stdc++.h>
using namespace std;

int dict[26];
int cnt[7][2];
int nums[7];
int tmp_cnt[6];

int bf(int cidx) {
    if(cidx==7) {
        if((nums[6]*(nums[0]+nums[1])*(nums[2]+nums[3]+nums[4]+nums[5])&1)==0) {
            int ret = 1;
            for(int i=0;i<7;i++)
                ret *= tmp_cnt[i];
            return ret;
        }
        return 0;
    }

    int ret = 0;
    nums[cidx] = 0;
    tmp_cnt[cidx] = cnt[cidx][0];
    ret += bf(cidx+1);

    nums[cidx] = 1;
    tmp_cnt[cidx] = cnt[cidx][1];
    ret += bf(cidx+1);
    
    return ret;
}


int main() {
    int n;
    scanf("%d", &n);
    /*
    (B+I) * (G+O+E+S) * (M) -> even number
    */
    dict['B'] = 0;
    dict['I'] = 1;

    dict['G'] = 2;
    dict['O'] = 3;
    dict['E'] = 4;
    dict['S'] = 5;
    
    dict['M'] = 6;

    char c[2];
    int v;

    for(int i=0;i<n;i++) {
        scanf("%s %d ", c, &v);
        
        cnt[dict[c[0]]][v&1]++;
    }
    printf("%d", bf(0));    
}