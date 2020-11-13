// 2164
#include <cstdio>
#include <queue>
using namespace std;

int main(void)
{
	int n, tmp;
	queue<int> q;
	scanf("%d", &n);
	if(n == 1){
		printf("1\n");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		q.push(i);
	while(q.size() > 2){
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	q.pop();
	printf("%d\n", q.front());
	return 0;
}
