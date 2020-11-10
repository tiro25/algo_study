// 11057
#include <cstdio>
#include <algorithm>
using namespace std;

int memo[1002][10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int main(void)
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        memo[i][0] = memo[i-1][0];
        for(int j = 1; j < 10; ++j)
            memo[i][j] = (memo[i-1][j] + memo[i][j-1]) % 10007;
    }
    for(int i = 0; i < 10; ++i)
        ans += memo[n-1][i];
    printf("%d\n", ans % 10007);
    return 0;
}
