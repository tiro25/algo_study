// 2503
#include <cstdio>
#include <string>

using namespace std;

int main(void)
{
  int n, answer = 0;
  scanf("%d", &n);

  int ans[1000] = {0, };
  for(int i = 123; i < 1000; ++i){
    string tmp = to_string(i);
    if(tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
      continue;
    if(tmp[1] == '0' || tmp[2] == '0')
      continue;
    ans[i] = 1;
  }

  while(n--){
    int num, s, b;
    scanf("%d%d%d", &num, &s, &b);
    string cmp = to_string(num);

    for(int i = 123; i < 1000; ++i){
      int cnt_s = 0, cnt_b = 0;

      if(!ans[i])
        continue;
      string tmp = to_string(i);
      for(int x = 0; x < 3; ++x){
        for(int y = 0; y < 3; ++y){
          if(cmp[x] == tmp[y]){
            if(x == y)
              cnt_s++;
            else
              cnt_b++;
          }
        }
      }
      
      if(s != cnt_s || b != cnt_b)
        ans[i] = 0;
    }
  }

  for(int i = 123; i < 1000; ++i)
    if(ans[i] == 1)
      answer++;

  printf("%d\n", answer);
  return 0;
}
