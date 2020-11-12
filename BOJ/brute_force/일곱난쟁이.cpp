// 2309
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
    int arr[10] = {0, }, tot = 0;

    for(int i = 0; i < 9; ++i){
        scanf("%d", arr+i);
        tot += arr[i];
    }
    sort(arr, arr+9);

    int flag = 0;
    for(int i = 0; i < 8; ++i){
        for(int j = i+1; j < 9; ++j){
            if (arr[i]+arr[j] == tot-100){
                arr[i] = 0;
                arr[j] = 0;
                flag++;
                break;
            }
        }
        if(flag)
            break;
    }
    for(int i= 0; i < 9; ++i)
        if(arr[i])
            printf("%d\n", arr[i]);

    return 0;
}
