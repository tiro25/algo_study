// 2294
#include <cstdio>
#include <algorithm>
using namespace std;

int memo[100002];

int main()
{
    int n, k, coin[101] = {0, };
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++i){
        scanf("%d", coin+i);
        memo[coin[i]-1] = 1;
    }

    for(int i = 0; i < k; ++i){
        if(!memo[i])
            memo[i] = 1e9;
        for(int j = 0; j < n; ++j){
            if(i>=coin[j]){
                memo[i] = min(memo[i], memo[i-coin[j]]+1);
            }
        }
    }
    if(memo[k-1] == 1e9)
        printf("-1\n");
    else
        printf("%d\n", memo[k-1]);
    return 0;
}
