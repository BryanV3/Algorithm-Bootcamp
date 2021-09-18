#include <stdio.h>

int main(){
	char c;
	scanf("%c", &c);
	if(c == 'A'|| c == 'I' || c == 'U' || c == 'E' || c == 'O')printf("Vowel");
	else printf("Consonant");
	return 0;
}

