// 2583
// 2583
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, area;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool arr[100][100];
bool visited[100][100];
vector<int> vc;

void dfs(int x, int y){
    visited[x][y] = true;
    area++;
    for(int dir = 0; dir < 4; ++dir){
        int xx = x+dx[dir];
        int yy = y+dy[dir];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m)
            continue;
        if(arr[xx][yy] || visited[xx][yy])
            continue;
        dfs(xx, yy);
    }
    return;
}

int main(void){
    cin >> n >> m >> k;
    int cnt = 0;
    while(k--){
        int lx, ly, rx, ry;
        cin >> ly >> lx >> ry >> rx;
        for(int x = lx; x < rx; ++x){
            for(int y = ly; y < ry; ++y){
                arr[x][y] = true;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!arr[i][j] && !visited[i][j]){
                cnt++;
                area = 0;
                dfs(i, j);
                vc.push_back(area);
            }
        }
    }

    sort(vc.begin(), vc.end());
    cout << cnt << endl << vc.front();
    for(vector<int>::iterator it = vc.begin()+1; it != vc.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
}
