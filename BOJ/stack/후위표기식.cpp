// 1918
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
	string str;
	vector<char> op;

	cin >> str;
	int len = str.size();
	for(int i = 0; i < len; ++i){
		if('A' <= str[i] && str[i] <= 'Z')
			cout << str[i];
		else{
			if(op.empty()){
				op.push_back(str[i]);
				continue;
			}
			switch(str[i]){
				case '(':
					op.push_back(str[i]);
					break;
				case '*':
				case '/':
					if(op.back() == '*' || op.back() == '/'){
						cout << op.back();
						op.pop_back();
					}
					op.push_back(str[i]);
					break;
				case '+':
				case '-':
					while(op.back() == '*' || op.back() == '/'){
						cout << op.back();
						op.pop_back();
					}
					if(op.back() == '+' || op.back() == '-'){
						cout << op.back();
						op.pop_back();
					}
					op.push_back(str[i]);
					break;
				default:
					while(op.back() != '('){
						cout << op.back();
						op.pop_back();
					}
					op.pop_back();
					break;
			}
		}
	}
	while(!op.empty()){
		cout << op.back();
		op.pop_back();
	}
	return 0;
}

