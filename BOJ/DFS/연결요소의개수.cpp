//11724
#include <iostream>

using namespace std;

int n;
int connect[1000][1000];
int visited[1000];

void dfs(int x){
	visited[x] = 1;
	for(int i = 0; i < n; ++i){
		if(!visited[i] && connect[x][i])
			dfs(i);
	}
}

int main(void){
	int m, ans = 0;
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int n1, n2;
		cin >> n1 >> n2;
		connect[n1-1][n2-1] = 1;
		connect[n2-1][n1-1] = 1;
	}
	for(int i = 0; i < n; ++i){
		if(!visited[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans << endl;
}

