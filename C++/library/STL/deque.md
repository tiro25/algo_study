시퀀스 컨테이너

double ended queue

요소가 추가되거나 삭제될 때마다 자동으로 메모리를 재할당하여 크기를 동적으로 변경

element가 흩어져 있다. cf ) deque - 단일 배열



### 생성

```C++
#include <deque>

using namespace std;

int main(){    
    deque<int> first;    // 빈 데크
    deque<int> second(4, 100);    // 4개의 int(값 100)
    deque<int> third(second.begin(), second.end());    // 반복자 사용
    deque<int> fourth(third);    // 벡터 복사

    int myints[] = {1, 2, 3, 4};
    deque<int> fifth(myints, myints + sizeof(myints)/sizeof(int));    // 반복자 사용2(배열)

    return 0;
}
```

---



### 반복자

-   begin() / end()
-   rbegin() / rend()
-   cbegin() / cend() : const \* C++11
-   crbegin() / crend() \* C++11

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    for(int i = 1; i <= 5; ++i)
        dq.push_back(i);

    for(deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
        cout<<*it<<' ';
    cout<<'\n';
    // 1 2 3 4 5
    for(deque<int>::reverse_iterator rit = dq.rbegin(); rit != dq.rend(); ++rit)
        cout<<*rit<<' ';
    cout<<'\n';
    // 5 4 3 2 1

    return 0;
}
```

---



### 용량

-   size()
-   max\_size()
-   resize()
-   empty()
-   shrink\_to\_fit() \* C++11

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    cout << dq.size() << endl;
    cout << dq.max_size() << endl;
    // 0
    // 536870911

    for(int i = 1; i <= 5; ++i)
        dq.push_back(i);
    cout << dq.size() << endl;
    cout << dq.max_size() << endl;
    // 5 {1, 2, 3, 4, 5}
    // 536870911

    dq.insert(dq.end(), 10, 100);
    cout << dq.size() << endl;
    cout << dq.max_size() << endl;
    // 15 {1, 2, 3, 4, 5, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}
    // 536870911

    dq.pop_back();
    cout << dq.size() << endl;
    cout << dq.max_size() << endl;
    // 14 {1, 2, 3, 4, 5, 100, 100, 100, 100, 100, 100, 100, 100, 100}
    // 536870911

    return 0;
}
```

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    for(int i = 1; i < 10; ++i)
        dq.push_back(i);
    // 1 2 3 4 5 6 7 8 9

    dq.resize(5);
    // 1 2 3 4 5
    dq.resize(8, 100);
    // 1 2 3 4 5 100 100 100
    dq.resize(10);
    // 1 2 3 4 5 100 100 100 0 0

    return 0;
}
```

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    int sum = 0;

    for(int i = 1; i <= 10; ++i)
        dq.push_back(i);

    while(!dq.empty()){
        sum += dq.back();
        dq.pop_back();
    }

    cout << sum << endl;
    // 55

    return 0;
}
```

---



### 요소 접근

-   \[\]
-   at()
-   front()
-   back()

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq(10);
    int len = dq.size();
    for(int i = 0; i < len; ++i)
        dq.at(i) = i;

    for(int i = 0; i < len; ++i)
        cout << ' ' << dq.at(i);
    cout << endl;
    // 0 1 2 3 4 5 6 7 8 9

    cout << dq.front() << endl;
    // 0
    cout << dq.back() << endl;
    // 9

    return 0;
}
```

---



### 제어

-   assign()
-   push\_back()
-   pop\_back()
-   push\_front()
-   pop\_front()
-   insert()
-   erase()
-   swap()
-   clear()
-   emplace() \* C++11
-   emplace\_back() \* C++11
-   emplace\_front() \* C++11

[emplace vs insert](https://stackoverflow.com/questions/14788261/c-stddeque-emplace-vs-insert)

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> first;
    deque<int> second;
    deque<int> third;

    first.assign(7, 100);    // 사이즈, 값
    second.assign(first.begin()+1, first.end()-1);    // 반복자, 반복자

    int arr[] = {12, 34, 56};
    third.assign(arr, arr+3);

    cout << first.size() << ' ' << second.size() << ' ' << third.size() << endl;
    // 7 5 3
}
```

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;

    for(int i = 1; i <= 5; ++i)
        dq.push_back(i);
    // 1 2 3 4 5
    for(int i = 6; i < 10; ++i)
        dq.push_front(i);
    // 10 9 8 7 6 1 2 3 4 5
    dq.pop_back();
    // 10 9 8 7 6 1 2 3 4
    dq.pop_front();
    // 9 8 7 6 1 2 3 4
}
```

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq(3, 100);
    dq.insert(dq.begin(), 200);
    dq.insert(dq.begin(), 2, 300);
    // 300 300 200 100 100 100

    deque<int> dq2(2, 400);
    dq.insert(dq.begin() + 2, dq2.begin(), dq2.end());
    // 300 300 400 400 200 100 100 100

    int arr[] = {501, 502, 503};
    dq.insert(dq.begin(), arr, arr+3);
    // 501 502 503 300 300 400 400 200 100 100 100

    dq.erase(dq.begin()+5);
    // 501 502 503 300 300 400 200 100 100 100
    dq.erase(dq.begin()+3, dq.begin()+4);
    // 501 502 503 400 200 100 100 100

    return 0;
}
```

```C++
#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq1(3, 100);
    deque<int> dq2(5, 200);
    dq1.swap(dq2);

    deque<int>::iterator it;
    for(it = dq1.begin(); it != dq1.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    for(it = dq2.begin(); it != dq2.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    // 200 200 200 200 200
    // 100 100 100

    dq1.clear();
    dq1.push_back(1);
    for(it = dq1.begin(); it != dq1.end(); ++it)
        cout << *it << ' ';
    // 1

    return 0;
}
```

---



### 할당

-   get\_allocator()

