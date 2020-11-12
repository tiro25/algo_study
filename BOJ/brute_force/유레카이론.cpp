// 10448
#include <cstdio>
#include <vector>

using namespace std;

vector<int> tri;
int lenTri = 44;

int ans(int k){
  for(int i = 0; i < lenTri; ++i){
    for(int j = 0; j < lenTri; ++j){
      for(int n = 0; n < lenTri; ++n){
        if(tri[i]+tri[j]+tri[n] == k)
          return 1;
      }
    }
  }
  return 0;
}

int main(void)
{
  int c;
  scanf("%d", &c);
  for(int i = 1; i <= lenTri; ++i)
    tri.push_back(i*(i+1)/2);

  while(c--){
    int k;
    scanf("%d", &k);
    printf("%d\n", ans(k));
  }
  return 0;
}
