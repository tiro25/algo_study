문자열을 표현하는 객체



# 생성

```c++
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s0("string");	// string
    string s1;	//
    string s2(s0);	// string
    string s3(s0, 2, 3);	// rin
    string s4("abcdefg", 4);	// abcd
    string s5(5, 'A');	// AAAAA
    string s6(s0.begin(), s0.begin()+3);	// str
}
```



---

# 반복자

- begin()
- end()
- rbegin()
- rend()
- cbegin()  \* C++11
- cend() \* C++11
- crbegin() \* C++11
- crend() \* C++11

```c++
#include <iostream>
#include <string>

using namespace std;

int main(void){
    string str("Test string");
    for(string::iterator it = str.begin(); it != str.end(); ++it)
        cout << *it;
    cout << endl;
    // Test string
    for(string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit)
        cout << *rit;
    cout << endl;
    // gnirts tseT
    
    return 0;
}
```



---

# 용량

- size()
- length()
- max_size()
- resize()
- capacity()
- reserve()
- clear()
- empty()
- shrink_to_fix() \* C++11

```c++
#include <iostream>
#include <string>

using namespace std;

int main(void){
    string str("Test string");
    cout << str.size() << endl;
    // 11
    cout << str.length() << endl;
    // 11
    cout << str.max_size() << endl;
    // 1073741823
	
    str.resize(str.size()+2, '!');
    cout << str << endl;
    // Test string!!
    str.resize(4);
    // Test
    
    cout << str.capacity() << endl;
    // 15
}
```



---

# 요소 접근

- []
- at()
- back() \* C++11
- front() \* C++11

```c++
#include <iostream>
#include <string>

using namespace std;

int main(void){
    string str("Test string");
    int len = str.length();
    for(int i = 0; i < len; ++i)
        cout << str[i];
    cout << endl;
    // Test string
    for(int i = 0; i < len; ++i)
        cout << str.at(i);
    cout << endl;
    // Test string
    cout << str.front() << endl;
    // g
    cout << str.back() << endl;
    // T
}
```



---

# 제어

- +=
- append()
- push_back()
- pop_back() \* C++11
- assign()
- insert()
- erase()
- replace()
- swap()

```c++
#include <iostream>
#include <string>

using namespace std;

int main(void){
    string alpha("abcde");
    string number("12345");
    number += "678";
    number += alpha;
    cout << number << endl;
    // 12345678abcde
    
    string str;
    string str2="abcde";
    string str3="12345";
    str.append(str2);	// abcde
    str.append(str3, 2, 2);	// abcde34
    str.append(" ABCDE", 3);	// abcde34 AB
    str.append(10, '.');	// abcde34 AB.....
    
    alpha.push_back('f');
    // abcdef
    number.pop_back();
    // 1234567
    
    str.assign(str2);
    // abcde
    str.assign(str3, 3, 2);
    // 45
    str.assign("ABCDE", 3);
    // ABC
    str.assign(5, '!');
    // !!!!!
    str.assign(number.begin()+1, number.end()-1);
    // 23456
    
    str.insert(3, "abc");
    // 234abc56
    string::iterator it = str.insert(str.begin()+2, ' ');
    // 23 4abc56
    str.insert(it+3, str3.begin(), str3.begin()+2);
    // 23 4aABbc56
    
    str.erase(2, 4);
    // 23Bbc56
    str.erase(str.begin()+3, str.begin()-2);
    // bc
    
    str.assign(str2);
    // abcde
    str.replace(2, 2, str3);
    // ab12345e
    str.replace(str.begin()+1, str.begin()+3, "ABCDE");
    // aABCDE2345e
    str.replace(str.begin(), str.end()-2, "zxcv", 2);
    // zx5e
    str.replace(str.begin()+2, str.end(), 4, '!');
    // zx!!!!
    
    cout << str2 << ' ' << str3 << endl;
    // abcde 12345
    str2.swap(str3);
    cout << str2 << ' ' << str3 << endl;
    // 12345 abcde
    
    return 0;
}
```



---

# 연산

- c_str
- data
- get_allocator
- copy
- find
- rfind
- find_first_of
- find_last_of
- find_first_not_of
- find_last_not_of
- substr
- compare



```c++
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(void){
    string str("qwertyuiop asdfghjkl zxcvbnm");
    char *cstr = new char[str.length()+1];
    strcpy(cstr, str.c_str());
    
    char *p = strtok(cstr, " ");
    while(p != 0){
        cout << p << '\n';
        p = strtok(NULL, " ");
    }
    // qwertyuiop
    // asdfghjkl
    // zxcvbnm
    delete[] cstr;
    
    char buffer[20];
    string str1("Test string");
    int len = str1.copy(buffer, 6, 5);
    buffer[len] = 0;
    cout << buffer << '\n';
    // string
    
    string str2("abcde");
    string str3 = str2.substr(2, 2);
    cout << str3 << '\n';
    // cd
    
    return 0;
}
```


