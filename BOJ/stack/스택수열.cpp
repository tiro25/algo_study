// 1874
#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<char> vc;
    vector<int> vi;
    int vi_input = 1;
    while(n--){
        int seq;
        cin >> seq;
        while(vi_input<=seq){
            vi.push_back(vi_input++);
            vc.push_back('+');
        }
        if(vi.back() == seq){
            vi.pop_back();
            vc.push_back('-');
        }
    }
    if(vi.empty()){
        for(vector<char>::iterator it = vc.begin(); it != vc.end(); ++it)
            cout << *it << '\n';
    }
    else
        cout << "NO" << endl;
    return 0;
}

