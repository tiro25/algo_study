// 1018
#include <cstdio>
#include <algorithm>

using namespace std;

char board[50][50];

int check(int x, int y, char color){
  int ret = 0;
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      if((i+j)%2){
        if(board[x+i][y+j] == color)
          ret++;
      }
      else{
        if(board[x+i][y+j] != color)
          ret++;
      }
    }
  }
  return ret;
}

int main(void){
  int n, m, ans = 1e2;
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i)
    scanf("%s", board[i]);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j)
      printf("%c", board[i][j]);
    printf("\n");
  }

  for(int i = 0; i < n-7; ++i){
    for(int j = 0; j < m-7; ++j){
      ans = min(ans, check(i, j, 'W'));
      ans = min(ans, check(i, j, 'B'));
    }
  }
  printf("%d\n", ans);
}

