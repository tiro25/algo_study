// 1935
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
	int n;
	string expr;
	vector<int> va;

	cin >> n;
	cin >> expr;
	for(int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		va.push_back(tmp);
	}

	vector<double> st;
	int len = expr.size();
	for(int i = 0; i < len; ++i){
		if('A' <= expr[i] && expr[i] <= 'Z')
			st.push_back((double)va[expr[i]-'A']);
		else{
			double res;
			double y = st.back();
			st.pop_back();
			double x = st.back();
			st.pop_back();
			switch(expr[i]){
				case '+':
					res = x+y;
					break;
				case '-':
					res = x-y;
					break;
				case '*':
					res = x*y;
					break;
				case '/':
					res = x/y;
					break;
			}
			st.push_back(res);
		}
	}
	cout.precision(2);
	cout << fixed << st.back() << endl;
}
