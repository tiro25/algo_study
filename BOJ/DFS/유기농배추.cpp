// 1012

#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int field[50][51];
int visited[50][51];
int m, n;

void dfs(int x, int y){
	visited[y][x] = 1;
	for(int dir = 0; dir < 4; ++dir){
		int xx = x+dx[dir];
		int yy = y+dy[dir];
		if(xx < 0 || xx >= m || yy < 0 || yy >= n)
			continue;
		if(field[yy][xx] && !visited[yy][xx])
			dfs(xx, yy);
	}
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> m >> n >> k;
		int ans = 0;
		for(int i = 0; i < n; ++i){
			fill(field[i], field[i]+m, 0);
			fill(visited[i], visited[i]+m, 0);
		}
		for(int i = 0; i < k; ++i){
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(field[i][j] && !visited[i][j]){
					ans++;
					dfs(j, i);
				}
			}
		}

		cout << ans << endl;
	}
}
