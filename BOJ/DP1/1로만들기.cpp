// 1463
#include <cstdio>
#include <algorithm>
using namespace std;

int memo[1000002] = {0, 0, 1, 1};

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 4; i <= n; i++){
        memo[i] = memo[i-1]+1;
        if(i%3==0) memo[i] = min(memo[i], memo[i/3]+1);
        if(i%2==0) memo[i] = min(memo[i], memo[i/2]+1);
    }
    printf("%d\n", memo[n]);
    return 0;
}
