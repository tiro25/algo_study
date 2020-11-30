// 10773
#include <iostream>
#include <stack>

using namespace std;

int main(void){
    int n;
    stack<int> st;
    cin >> n;
    while(n--){
        int input;
        cin >> input;
        if(input)
            st.push(input);
        else
            st.pop();
    }
    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }
    cout << sum << endl;
    return 0;
}
