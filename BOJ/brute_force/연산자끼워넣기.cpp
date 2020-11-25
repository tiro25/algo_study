// 14888
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> op;
    int mini = 1e9;
    int maxi = -1e9;

    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < 4; ++i){
        int numOp;
        cin >> numOp;
        if(!numOp)
            continue;
        for(int j = 0; j < numOp; ++j)
            op.push_back(i);
    }

    do{
        int tmp = a[0];
        for(int i = 0; i < n-1; ++i){
            switch(op[i]){
                case 0:
                    tmp += a[i+1];
                    break;
                case 1:
                    tmp -= a[i+1];
                    break;
                case 2:
                    tmp *= a[i+1];
                    break;
                case 3:
                    tmp /= a[i+1];
            }
        }
        mini = min(tmp, mini);
        maxi = max(tmp, maxi);
    }
    while(next_permutation(op.begin(), op.end()));

    cout << maxi << endl << mini << endl;
}

