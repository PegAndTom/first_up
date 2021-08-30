#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int fun3(int m);
int main(void)
{
	int n;
	for (n = 1; n < 10; n++)
	if (fun3(n) == 1) printf("%d ", n);                   /* %d后有1个空格 */
	return 0;
}
int fun3(int m)
{
	int i;
	if (m == 2 || m == 3) return 1;
	if (m < 2 || m % 2 == 0) return 0;
	for (i = 3; i < m; i = i + 2)
	if (m % i == 0) return 0;
	return 1;
}