// 1699
#include <cstdio>
#include <algorithm>
using namespace std;

int memo[100002] = {0, };

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i){
        memo[i] = memo[i-1]+1;
        for(int j = 2; j*j <= i; ++j)
            memo[i] = min(memo[i], memo[i-j*j]+1);
    }
    printf("%d\n", memo[n]);
    return 0;
}
