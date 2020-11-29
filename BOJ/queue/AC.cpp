// 5430
#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void){
    int t;
    cin >> t;
    while(t--){
        string func, s;
        int n;
        cin >> func;
        cin >> n;
        cin >> s;

        deque<int> dq;
        int len = s.length();
        int tmp = 0;
        for(int i = 1; i < len; ++i){
            if(s[1] == ']')
                break;
            if(s[i] == ',' || s[i] == ']'){
                dq.push_back(tmp);
                tmp = 0;
            }
            else
                tmp = tmp*10+s[i]-'0';
        }

        bool dir = true;
        int func_len = func.length();
        bool flag = 0;
        for(int i = 0; i < func_len; ++i){
            if(func[i] == 'R')
                dir = !dir;
            else{
                n--;
                if(dq.empty()){
                    cout << "error" << endl;
                    flag = true;
                    break;
                }
                if(dir)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if(flag)
            continue;

        if(n == 0){
            cout << "[]" << endl;
            continue;
        }
        if(dir){
            for(int i = 0; i < n; ++i){
                if(i == 0)
                    cout << '[';
                cout << dq.front();
                dq.pop_front();
                if(i == n-1)
                    cout << ']' << endl;
                else
                    cout << ',';
            }
        }
        else{
            for(int i = 0; i < n; ++i){
                if(i == 0)
                    cout << '[';
                cout << dq.back();
                dq.pop_back();
                if(i == n-1)
                    cout << ']' << endl;
                else
                    cout << ',';
            }
        }
    }
}
