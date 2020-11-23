// 4796
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int l, p, v;
    int c = 0;
    while(1){
        c++;
        int ans = 0;
        cin >> l >> p >> v;
        if(l == 0 || p == 0 || v == 0){
            return 0;
        }
        while(v > p){
            ans += l;
            v -= p;
        }
        ans += min(l, v);
        cout << "Case " << c << ": " << ans << endl;
    }
}
