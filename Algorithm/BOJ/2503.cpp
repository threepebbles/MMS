#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

typedef struct BB{
    int s, b;
};

int n;
int x[MAXN], s[MAXN], b[MAXN];

bool is_valid(int num) {
    bool chk[10]={};
    while(num) {
        if(num%10==0 || chk[num%10]) return false;
        chk[num%10] = true;
        num/=10;
    }
    return true;
}

BB get_sbcnt(int num1, int num2) {
    char tmp_num1[4], tmp_num2[4];
    sprintf(tmp_num1, "%d", num1);
    sprintf(tmp_num2, "%d", num2);
    
    int scnt=0, bcnt=0;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(tmp_num1[i]==tmp_num2[j]) {
                if(i==j) scnt++;
                else bcnt++;
            }
        }
    }
    return {scnt, bcnt};
}

bool is_possible(int num) {
    for(int i=0;i<n;i++) {  // x[i] and num
        BB cur_sbcnt = get_sbcnt(x[i], num);
        if(s[i]!=cur_sbcnt.s || b[i]!=cur_sbcnt.b) return false;
    }
    return true;
}


int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d %d %d", &x[i], &s[i], &b[i]);
    }

    int cnt=0;
    for(int i=123;i<=987;i++) {
        if(!is_valid(i)) continue;
        cnt += is_possible(i);
    }
    printf("%d", cnt);
}