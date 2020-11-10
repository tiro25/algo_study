// 10844
#include <cstdio>
#include <algorithm>
using namespace std;

int memo[102][10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, };

int main(void)
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        memo[i][0] = memo[i-1][1];
        for(int j = 1; j < 9; ++j)
            memo[i][j] = (memo[i-1][j-1]+memo[i-1][j+1]) % 1000000000;
        memo[i][9] = memo[i-1][8];
    }
    for(int i = 0; i < 10; ++i)
        ans = (ans + memo[n-1][i]) % 1000000000;
    printf("%d\n", ans);
    return 0;
}
