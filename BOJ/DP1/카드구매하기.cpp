// 11052
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, card[1001], memo[1001] = {0, };
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", card+i);
        memo[i] = card[i];
    }
    for(int i = 2; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            memo[i] = max(memo[i], memo[i-j]+card[j]);
    printf("%d\n", memo[n]);
    return 0;
}
