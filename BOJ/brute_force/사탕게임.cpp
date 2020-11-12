// 3085
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
char board[50][51];

int func(void){
  int ret = 1;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n-1; ++j){
      int tmp = 1;
      for(int k = j; k < n-1; ++k){
        if(board[i][k] == board[i][k+1])
          tmp++;
        else
          break;
      }
      ret = max(ret, tmp);
    }
  }

  for(int i = 0; i < n-1; ++i){
    for(int j = 0; j < n; ++j){
      int tmp = 1;
      for(int k = i; k < n-1; ++k){
        if(board[k][j] == board[k+1][j])
          tmp++;
        else
          break;
      }
      ret = max(ret, tmp);
    }
  }
  return ret;
}

int main(void){
  int ans = 1;

  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%s", board[i]);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n-1; ++j){
      swap(board[i][j], board[i][j+1]);
      ans = max(ans, func());
      swap(board[i][j], board[i][j+1]);
    }
  }
  for(int i = 0; i < n-1; ++i){
    for(int j = 0; j < n; ++j){
      swap(board[i][j], board[i+1][j]);
      ans = max(ans, func());
      swap(board[i][j], board[i+1][j]);
    }
  }
  printf("%d\n", ans);
}
