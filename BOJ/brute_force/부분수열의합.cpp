// 1182
#include <cstdio>
#include <algorithm>

using namespace std;

int n, s, ans;
int arr[20];

void func(int idx, int sum){
  if(idx == n)
    return;
  if(sum+arr[idx] == s)
    ans++;

  func(idx+1, sum);
  func(idx+1, sum+arr[idx]);
}

int main(void){
  scanf("%d%d", &n, &s);

  for(int i = 0; i < n; ++i)
    scanf("%d", arr+i);
  sort(arr, arr+n);

  func(0, 0);
  printf("%d\n", ans);
}
