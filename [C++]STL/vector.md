시퀀스 컨테이너

동적 배열

요소가 추가되거나 삭제될 때마다 자동으로 메모리를 재할당하여 크기를 동적으로 변경



### 생성

```c++
#include <vector>

using namespace std;

int main(){    
	vector<int> first;	// 빈 벡터
	vector<int> second(4, 100);	// 4개의 int(값 100)
	vector<int> third(second.begin(), second.end());	// 반복자 사용
	vector<int> fourth(third);	// 벡터 복사

	int myints[] = {1, 2, 3, 4};
	vector<int> fifth(myints, myints + sizeof(myints)/sizeof(int));	// 반복자 사용2(배열)

	return 0;
}
```





---

### 반복자

- begin() / end()
- rbegin() / rend()
- cbegin() / cend() : const  \* C++11
- crbegin() / crend() \* C++11

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc;
	for(int i = 1; i <= 5; ++i)
		vc.push_back(i);

	for(vector<int>::iterator it = vc.begin(); it != vc.end(); ++it)
		cout<<*it<<' ';
	cout<<'\n';
	// 1 2 3 4 5
	for(vector<int>::reverse_iterator rit = vc.rbegin(); it != vc.rend(); ++rit)
		cout<<*rit<<' ';
	cout<<'\n';
	// 5 4 3 2 1

	return 0;
}
```



---

### 용량

- size()
- max_size()
- capacity()
- resize()
- empty()
- reserve() : capacity 변경
- shrink_to_fit() \* C++11

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc;
	cout << vc.size() << endl;
	cout << vc.capacity() << endl;
	cout << vc.max_size() << endl;
	// 0
	// 0
	// 536870911

	for(int i = 1; i <= 5; ++i)
		vc.push_back(i);
	cout << vc.size() << endl;
	cout << vc.capacity() << endl;
	cout << vc.max_size() << endl;
	// 5 {1, 2, 3, 4, 5}
	// 8
	// 536870911

	vc.insert(vc.end(), 10, 100);
	cout << vc.size() << endl;
	cout << vc.capacity() << endl;
	cout << vc.max_size() << endl;
	// 15 {1, 2, 3, 4, 5, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}
	// 15
	// 536870911

	vc.pop_back();
	cout << vc.size() << endl;
	cout << vc.capacity() << endl;
	cout << vc.max_size() << endl;
	// 14 {1, 2, 3, 4, 5, 100, 100, 100, 100, 100, 100, 100, 100, 100}
	// 15
	// 536870911

	return 0;
}

```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc;
	for(int i = 1; i < 10; ++i)
		vc.push_back(i);
	// 1 2 3 4 5 6 7 8 9

	vc.resize(5);
	// 1 2 3 4 5
	vc.resize(8, 100);
	// 1 2 3 4 5 100 100 100
	vc.resize(10);
	// 1 2 3 4 5 100 100 100 0 0

	return 0;
}
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc;
	int sum = 0;

	for(int i = 1; i <= 10; ++i)
		vc.push_back(i);

	while(!vc.empty()){
		sum += vc.back();
		vc.pop_back();
	}

	cout << sum << endl;
	// 55

	return 0;
}
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc(100);
	cout << vc.capacity() << endl;
	// 100
	vc.resize(10);
	cout << vc.capacity() << endl;
	// 100
	vc.shrink_to_fit();
	cout << vc.capacity() << endl;
	// 10

	return 0;
}
```



---

### 요소 접근

- []
- at()
- front()
- back()
- data() \* C++11

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc(10);
	int len = vc.size();
	for(int i = 0; i < len; ++i)
		vc.at(i) = i;

	for(int i = 0; i < len; ++i)
		cout << ' ' << vc.at(i);
	cout << endl;
	// 0 1 2 3 4 5 6 7 8 9

	cout << vc.front() << endl;
	// 0
	cout << vc.back() << endl;
	// 9

	return 0;
}
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc(5);
	int *p = vc.data();

	*p = 10;
	++p;
	*p = 20;
	p[2] = 100;
	// 10 20 0 100 0

	return 0;
}
```



---

### 제어

- assign()
- push_back()
- pop_back()
- insert()
- erase()
- swap()
- clear()
- emplace() \* C++11
- emplace_back() \* C++11

[https://stackoverflow.com/questions/14788261/c-stdvector-emplace-vs-insert][emplace vs insert]

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> first;
	vector<int> second;
	vector<int> third;

	first.assign(7, 100);	// 사이즈, 값
	second.assign(first.begin()+1, first.end()-1);	// 반복자, 반복자

	int arr[] = {12, 34, 56};
	third.assign(arr, arr+3);

	cout << first.size() << ' ' << second.size() << ' ' << third.size() << endl;
	// 7 5 3
}
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc;

	for(int i = 1; i <= 5; ++i)
		vc.push_back(i);
	// 1 2 3 4 5
	vc.pop_back();
	// 1 2 3 4
}
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc(3, 100);
	vc.insert(vc.begin(), 200);
	vc.insert(vc.begin(), 2, 300);
	// 300 300 200 100 100 100

	vector<int> vc2(2, 400);
	vc.insert(vc.begin() + 2, vc2.begin(), vc2.end());
	// 300 300 400 400 200 100 100 100

	int arr[] = {501, 502, 503};
	vc.insert(vc.begin(), arr, arr+3);
	// 501 502 503 300 300 400 400 200 100 100 100

	vc.erase(vc.begin()+5);
	// 501 502 503 300 300 400 200 100 100 100
	vc.erase(vc.begin()+3, vc.begin()+4);
	// 501 502 503 400 200 100 100 100

	return 0;
}
```

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> vc1(3, 100);
	vector<int> vc2(5, 200);
	vc1.swap(vc2);

	vector<int>::iterator it;
	for(it = vc1.begin(); it != vc1.end(); ++it)
		cout << *it << ' ';
	cout << endl;
	for(it = vc2.begin(); it != vc2.end(); ++it)
		cout << *it << ' ';
	cout << endl;
	// 200 200 200 200 200
	// 100 100 100

	vc1.clear();
	vc1.push_back(1);
	for(it = vc1.begin(); it != vc1.end(); ++it)
		cout << *it << ' ';
	// 1

	return 0;
}
```



---

### 할당

- get_allocator()
