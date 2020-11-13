// 1436
#include <iostream>

using namespace std;

int pow(int x, int n){
	int ret = 1;
	for(int i = 0; i < n; ++i)
		ret *= x;
	return ret;
}

bool func(int n){
	int len = 1;
	int tmp = n;
	while(tmp/=10)
		len++;
	for(int i = 0; i < len-2; ++i){
		tmp = n;
		tmp %= pow(10, i+3);
		tmp /= pow(10, i);
		if(tmp == 666)
			return true;
	}
	return false;
}

int main(void){
	int n, nth = 0, ans = 666;
	cin >> n;
	while(1){
		if(func(ans))
			nth++;
		if(n==nth)
			break;
		ans++;
	}
	cout << ans << endl;

	return 0;
}

