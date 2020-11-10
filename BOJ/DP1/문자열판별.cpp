// 16500
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int memo[102];

int main(void)
{
    char s[102] = {0}, a[101][102] = {0, };
    int n, slen, alen[101] = {0, };

    scanf("%s%d", s, &n);
    for(int i = 1; i <= n; ++i){
        scanf("%s", a[i]);
        alen[i] = strlen(a[i]);
    }

    slen = strlen(s);
    for(int i = 1; i <= slen; ++i){
        for(int j = 1; j <= n; ++j){
            char tmp[102] = {0};
            if(i < alen[j])
                continue;
            else if(i == alen[j]){
                strncpy(tmp, s, i);
                if(!strcmp(tmp, a[j])){
                    memo[i] = 1;
                    break;
                }
            }
            else{
                if(!memo[i-alen[j]])
                    continue;
                strncpy(tmp, s+(i-alen[j]), alen[j]);
                if(!strcmp(tmp, a[j])){
                    memo[i] = 1;
                    break;
                }
            }
        }
    }
    printf("%d\n", memo[slen]);
    return 0;
}
