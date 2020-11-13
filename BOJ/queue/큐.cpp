// 10845
#include <cstdio>
#include <string.h>
using namespace std;

int fr = -1, re = -1;
int queue[100002];

void push(){
	int n;

	scanf("%d", &n);
	queue[++re] = n;
}

void pop(){
	if(fr == re)
		printf("-1\n");
	else
		printf("%d\n", queue[++fr]);
}

void size(){
	printf("%d\n", re-fr);
}

void empty(){
	if(fr == re)
		printf("1\n");
	else
		printf("0\n");
}

void front(){
	if(fr == re)
		printf("-1\n");
	else
		printf("%d\n", queue[fr+1]);
}

void back(){
	if(fr == re)
		printf("-1\n");
	else
		printf("%d\n", queue[re]);
}

int main(void)
{
	int n;
	char str[10] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", str);
		if(!strcmp(str, "push"))
			push();
		else if(!strcmp(str, "pop"))
			pop();
		else if(!strcmp(str, "size"))
			size();
		else if(!strcmp(str, "empty"))
			empty();
		else if(!strcmp(str, "front"))
			front();
		else
			back();
	}
	return 0;
}
