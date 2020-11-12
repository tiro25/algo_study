// 2304
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	int idx, value, max_idx, max_val = 0;
	int h = 0;
	int ans = 0;
	vector<pair<int, int>> vc;

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> idx >> value;
		vc.push_back(make_pair(idx, value));
		if(value > max_val){
			max_val = value;
			max_idx = idx;
		}
	}
	sort(vc.begin(), vc.end());
	for(vector<pair<int, int>>::iterator it = vc.begin(); it->first != max_idx; ++it){
		h = max(h, it->second);
		ans += ((it+1)->first-it->first)*h;
	}
	h = 0;
	ans += max_val;
	for(vector<pair<int, int>>::iterator it = vc.end()-1; it->first != max_idx; --it){
		h = max(h, it->second);
		ans += (it->first-(it-1)->first)*h;
	}
	cout << ans << endl;
}
