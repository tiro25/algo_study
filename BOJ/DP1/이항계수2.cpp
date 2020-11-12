// 11051
#include <cstdio>
#include <algorithm>
using namespace std;

int memo[1002][1002];

int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j <= i && j <= k; ++j){
            if(j == 0 || j == i)
                memo[i][j] = 1;
            else
                memo[i][j] = (memo[i-1][j-1]+memo[i-1][j]) % 10007;
        }
    printf("%d\n", memo[n][k]);
    return 0;
}
