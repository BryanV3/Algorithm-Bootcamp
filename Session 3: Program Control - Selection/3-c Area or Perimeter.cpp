#include <stdio.h>

int main(){
	int p, l; // panjang lebar
	scanf("%d%d", &p, &l);
	int area = p*l;
	int peri = (2*(p+l));
	if(area == peri) printf("Eq\n%d", area);
	else if (area > peri)printf("Area\n%d", area);
	else printf("Peri\n%d", peri);
	return 0;
}

