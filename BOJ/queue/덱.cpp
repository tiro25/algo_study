// 10866
#include <cstdio>
#include <string.h>
using namespace std;

#define MAX 10000

int q[MAX];
int fr = -1, re = -1;

void push_front()
{
	int n;
	scanf("%d", &n);
	fr = (fr + MAX) % MAX;
	q[fr] = n;
	fr = (fr - 1 + MAX) % MAX;
}

void push_back()
{
	int n;
	scanf("%d", &n);
	re = (re + 1) % MAX;
	q[re] = n;
}

void pop_front()
{
	fr = (fr + MAX) % MAX;
	re = (re + MAX) % MAX;
	if(fr == re)
		printf("-1\n");
	else{
		fr = (fr + 1) % MAX;
		printf("%d\n", q[fr]);
	}
}

void pop_back()
{
	fr = (fr + MAX) % MAX;
	re = (re + MAX) % MAX;
	if(fr == re)
		printf("-1\n");
	else{
		printf("%d\n", q[re]);
		re = (re - 1 + MAX) % MAX;
	}
}

void size()
{
	printf("%d\n", (re - fr + MAX) % MAX);
}

void empty()
{
	printf("%d\n", (fr == re));
}

void front()
{
	fr = (fr + MAX) % MAX;
	re = (re + MAX) % MAX;
	if(fr == re)
		printf("-1\n");
	else
		printf("%d\n", q[(fr+1)%MAX]);
}

void back()
{
	fr = (fr + MAX) % MAX;
	re = (re + MAX) % MAX;
	if(fr == re)
		printf("-1\n");
	else
		printf("%d\n", q[re]);
}

int main(void)
{
	int n;
	char com[12] = "";
	scanf("%d", &n);
	while(n--){
		scanf("%s", com);
		if(!strcmp(com, "push_front"))
			push_front();
		else if(!strcmp(com, "push_back"))
			push_back();
		else if(!strcmp(com, "pop_front"))
			pop_front();
		else if(!strcmp(com, "pop_back"))
			pop_back();
		else if(!strcmp(com, "size"))
			size();
		else if(!strcmp(com, "empty"))
			empty();
		else if(!strcmp(com, "front"))
			front();
		else
			back();
	}
}
