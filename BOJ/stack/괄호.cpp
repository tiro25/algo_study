// 9012
#include <cstdio>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int t;
	int i, j;
	char str[50];
	int vps;
	int cnt;

	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%s", str);

		cnt = 0;
		vps = 1;

		for(j = 0; j < strlen(str); j++){
			if(str[j] == '(')
				cnt++;
			else
				cnt--;
			if(cnt < 0){
				vps = 0;
				break;
			}
		}
		if(cnt)
			vps = 0;

		if(vps == 1)
			printf("YES\n");
		if(vps == 0)
			printf("NO\n");
	}
	exit(0);
}
