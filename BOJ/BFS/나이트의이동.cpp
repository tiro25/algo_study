// 7562
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
bool visited[300][300];

int main(void){
	int c;
	cin >> c;
	while(c--){
		int n, sx, sy, dx, dy;
		cin >> n;
		cin >> sx >> sy;
		cin >> dx >> dy;
		for(int i = 0; i < n; ++i)
			fill(visited[i], visited[i]+n, false);
		visited[sx][sy] = true;
		queue<pair<int, int>> q;
		q.push(make_pair(0, 1000*sx+sy));
		while(1){
			int move = q.front().first;
			int cur = q.front().second;
			int nx = cur/1000;
			int ny = cur%1000;
			if(nx == dx && ny == dy){
				cout << move << endl;
				break;
			}
			q.pop();
			for(int i = 0; i < 8; ++i){
				int xx = nx + dir[i][0];
				int yy = ny + dir[i][1];
				if(xx < 0 || xx >= n || yy < 0 || yy >= n)
					continue;
				if(!visited[xx][yy]){
					visited[xx][yy] = true;
					q.push(make_pair(move+1, xx*1000+yy));
				}
			}
		}
	}
	return 0;
}
