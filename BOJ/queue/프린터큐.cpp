// 1966
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int main(void)
{
	int c;
	scanf("%d", &c);
	while(c--){
		queue<pair<int, int>> q;
		pair<int, int> intp;
		int n, m, tmp, p[10];
		fill(p, p+10, 0);

		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i){
			scanf("%d", &tmp);
			p[tmp]++;
			intp = make_pair(tmp, i);
			q.push(intp);
		}
		int cnt = 1;
		while(1){
			intp = q.front();
			tmp = intp.first;
			q.pop();
			p[tmp]--;
			int flag = 0;
			for(int i = 9; i > tmp; --i){
				if(p[i]){
					flag++;
					break;
				}
			}
			if(flag){
				q.push(intp);
				p[tmp]++;
			}
			else{
				if(intp.second == m)
					break;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
