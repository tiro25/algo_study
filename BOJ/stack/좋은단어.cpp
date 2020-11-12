// 3986
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
	int n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string str;
		cin >> str;

		int len = str.size();
		vector<char> vc;
		vc.push_back(str[0]);
		for(int i = 1; i < len; ++i){
			if(vc.back() == str[i])
				vc.pop_back();
			else
				vc.push_back(str[i]);
		}

		if(vc.empty())
			ans++;
	}
	cout << ans << endl;
}
