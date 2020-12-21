첫번째 원소가 기준에 따라 가장 큰 컨테이너 어댑터

힙과 유사

원소가 빠져나갈 때, top(back)에서부터 pop



### 생성

```c++
#include <iostream>
#include <queue>

using namespace std;

class cmp{
    bool reverse;
public:
    cmp(const bool& rev = false){
        reverse = rev;
    }
    bool operator()(const int& lhs, const int&rhs){
        if(reverse)
            return (lhs > rhs);
        else
            return (lhs < rhs);
    }
};

int main(void){
    int arr[] = {1, 3, 2, 4};

    priority_queue<int> pq1;
    priority_queue<int> pq2(arr, arr+4);
    // 4 3 2 1
    priority_queue<int, vector<int>, greater<int> > pq3(arr, arr+4);
    // 1 2 3 4
    priority_queue<int, vector<int>, cmp > pq4(arr, arr+4);
    // 4 3 2 1
    priority_queue<int, vector<int>, cmp > pq5(arr, arr+4, cmp(true));
    // 1 2 3 4
}
```



### 멤버함수

- empty()
- size()
- top()
- push()
- pop()
- emplace()  \* C++11
- swap() \* C++11

```c++
#include <iostream>
#include <queue>

using namespace std;

int main(void){
    priority_queue<int> pq;
    
    for(int i = 1; i < 10; ++i)
        pq.push(i);
    cout << pq.size() << '\n';
    // 9
    
    while(!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
    // 9 8 7 6 5 4 3 2 1
}
```