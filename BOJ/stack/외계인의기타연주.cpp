// 2841
#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n, p, ans = 0;
	vector<int> vc[7];
	cin >> n >> p;
	for(int i = 0; i < n; ++i){
		int line, fret;
		cin >> line >> fret;
		if(vc[line].empty()){
			vc[line].push_back(fret);
			ans++;
		}
		else{
			while(vc[line].back() > fret){
				vc[line].pop_back();
				ans++;
			}
			if(vc[line].back() < fret){
				vc[line].push_back(fret);
				ans++;
			}
		}
	}
	cout << ans << endl;
}

