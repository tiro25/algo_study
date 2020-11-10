//11726
#include <cstdio>
#include <algorithm>
using namespace std;

int memo[1002] = {0, 1, 2, };

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 3; i <= n; ++i)
        memo[i] = (memo[i-1] + memo[i-2])%10007;
    printf("%d\n", memo[n]);
    return 0;
}
