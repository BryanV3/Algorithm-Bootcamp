#include <stdio.h>

int main(){
	char n[8];
	scanf("%s", n);
	if(n[0] && !n[1])printf("1");
	else if(n[0] && !n[2])printf("2");
	else if(n[0] && !n[3])printf("3");
	else printf("More than 3 digits");
	
//	int n ;
//	scanf("%d", n);
//	if (n < 10)printf("1");
//	else if (n < 100)printf("2");
//	else if (n < 1000)printf("3");
//	else printf("More than 3 digits");
	return 0;
}

