LIFO 문맥에서 동작하기 위해 설계된 컨테이너 어댑터

stack의 top으로 알려진 container의 back에서 push와 pop



### 생성

```c++
#include <iostream>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

int main(){
    deque<int> deq(3, 100);
    vector<int> vc(2, 200);
    
    stack<int> first;	// 빈 스택
    stack<int> second(deq);	 // deque를 복사하여 초기화
    stack<int, vector<int>> third;
    stack<int, vector<int>> fourth(vc);
}
```



---

### 용량

- empty()
- size()



---

### 제어

- top()
- push()
- pop()
- emplace() \* C++11
- swap() \* C++11

```c++
#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> st;
    int sum = 0;
    
    for(int i = 1; i <= 10; ++i)
        st.push(i);
    cout << st.size() << endl;
    // 10
    
    while(!st.empty()){
        sum+= st.top();
        st.pop();
    }
    
    cout << sum << endl;
    // 55
}
```
