// 2075
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	stack<int> st[n];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int tmp;
			cin >> tmp;
			st[j].push(tmp);
		}
	}
	for(int i = 0; i < n-1; ++i){
		int max_idx = 0;
		for(int j = 1; j < n; ++j){
			if(st[max_idx].top() < st[j].top()){
				max_idx = j;
			}
		}
		st[max_idx].pop();
	}

	int ans = st[0].top();
	for(int i = 1; i < n; ++i)
		ans = max(ans, st[i].top());
	cout << ans << endl;
	return 0;
}
