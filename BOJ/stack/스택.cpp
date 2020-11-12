// 10828
#include <cstdio>
#include <string.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node *next;
} NODE;
NODE stack;
int cnt;

void push(void);
int pop(void);
int size(void);
int empty(void);
int top(void);

int main(void)
{
	int n;
	scanf("%d", &n);

	while (n--) {
		char cmd[6] = { 0 };
		scanf("%s", cmd);

		if (!strcmp(cmd, "push"))
			push();
		if (!strcmp(cmd, "pop"))
			printf("%d\n", pop());
		if (!strcmp(cmd, "size"))
			printf("%d\n", size());
		if (!strcmp(cmd, "empty"))
			printf("%d\n", empty());
		if (!strcmp(cmd, "top"))
			printf("%d\n", top());

	}
}

void push(void)
{
	int num;
	scanf("%d", &num);
	
	NODE *new;
	new = (NODE *)malloc(sizeof(NODE));
	new->data = num;
	new->next = NULL;

	if (stack.next == NULL)
		stack.next = new;
	else {
		new->next = stack.next;
		stack.next = new;
	}
	cnt++;
}

int pop(void)
{
	if (empty())
		return -1;

	int data;
	NODE* cur;
	cur = (NODE*)malloc(sizeof(NODE));
	cur = stack.next;
	data = cur->data;
	stack.next = cur->next;
	cur->next = NULL;
	free(cur);
	cnt--;

	return data;
}

int size(void)
{
	return cnt;
}

int empty(void)
{
	if (cnt)
		return 0;
	else
		return 1;
}

int top(void)
{
	if (empty())
		return -1;
	else {
		NODE* cur;
		cur = (NODE*)malloc(sizeof(NODE));
		cur = stack.next;

		return cur->data;
	}
}
