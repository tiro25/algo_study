// 11055
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1002], memo[1002];

int main(void)
{
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", arr+i);

    for(int i = 0; i < n; ++i){
        memo[i] = arr[i];
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i])
                memo[i] = max(memo[i], memo[j]+arr[i]);
        }
        ans = max(ans, memo[i]);
    }
    printf("%d\n", ans);
    return 0;
}
