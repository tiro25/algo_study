FIFO 문맥에서 동작하기 위해 설계된 컨테이너 어뎁터



### 생성

```c++
#include <iostream>
#include <deque>
#include <list>
#include <queue>

using namespace std;

int main(void){
    deque<int> d(3, 100);
    list<int> l(2, 50);
    
    queue<int> q1;
    queue<int> q2(d);
    queue<int, list<int>> q3;
    queue<int, list<int>> q4(l);
}
```



### 멤버함수

- empty()
- size()
- front()
- back()
- push()
- pop()
- emplace()  \* C++11
- swap() \* C++11

```c++
#include <iostream>
#include <queue>

using namespace std;

int main(void){
    queue<int> q;
    
    for(int i = 1; i < 10; ++i)
        q.push(i);
    cout << q.back() << '\n';
    // 9
    cout << q.size() << '\n';
    // 9
    
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
    // 1 2 3 4 5 6 7 8 9
}
```