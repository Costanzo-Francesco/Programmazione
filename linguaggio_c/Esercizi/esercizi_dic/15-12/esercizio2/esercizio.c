#include <stdio.h>

int fattoriale (int n);

int main (void) {

	int n, f;
	printf("\nInserisci un numero per ottenerne il fattoriale\n");
	scanf("%d", &n);
	f = fattoriale (n);
	printf("Il fattoriale è %d", f);
	return 0;
}

int fattoriale (int n){
	int f=1;
	for (int i = 1; i <= n; i++)
	{
			f = i*f;
		}

	return f;
}
		

