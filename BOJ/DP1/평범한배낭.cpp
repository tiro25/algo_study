// 12865
#include <cstdio>
#include <algorithm>
using namespace std;

int memo[102][100002];

int main(void)
{
    int n, k, w[102], v[102];

    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", w+i, v+i);

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            memo[i][j] = memo[i-1][j];
            if(j >= w[i])
                memo[i][j] = max(memo[i][j], memo[i-1][j-w[i]]+v[i]);
        }
    }
    printf("%d\n", memo[n][k]);

    return 0;
}
