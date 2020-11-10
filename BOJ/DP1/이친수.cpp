//2193
#include <cstdio>
#include <algorithm>
using namespace std;

long long memo[92] = {0, 1, 1, };

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 3; i <= n; ++i)
        memo[i] = memo[i-1] + memo[i-2];

    printf("%lld\n", memo[n]);
}
