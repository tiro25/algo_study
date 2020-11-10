// 2231
#include <cstdio>
#include <string>

using namespace std;

int sum(int n){
  string tmp = to_string(n);
  for(int i = 0; i < tmp.size(); ++i)
    n += (tmp[i]-'0');

  return n;
}

int main(void){
  int n;
  scanf("%d", &n);

  for(int i = 1; i < n; ++i){
    if(sum(i) == n){
      printf("%d\n", i);
      return 0;
    }
  }
  printf("0\n");
  return 0;
}
