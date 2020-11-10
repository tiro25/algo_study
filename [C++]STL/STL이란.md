# 1. STL 이란

Standard Template Library

c++을 위한 라이브러리



## 구성

- 컨테이너
  - 시퀀스 컨테이너: 데이터를 선형으로 저장
    - [https://github.com/tiro25/algo_study/blob/master/%5BC%2B%2B%5DSTL/vector.md][vector]
    - deque
    - list
    - slist
  - 연관 컨테이너: 데이터를 일정 규칙에 따라 조직화하여 저장하고 관리
    - set
    - multiset
    - map
    - multimap
  - 컨테이너 어댑터: 인터페이스를 제한한 시퀀스나 연관 컨테이너의 변형, 반복자 지원 X
    - stack
    - queue
    - priority_queue
- 반복자(Iterator)
- 알고리즘
- 함수자(functor)



## 특징

- 제네릭 프로그래밍
- 추상화
- 폰 노이만 구조
- 벨류 시멘틱스
