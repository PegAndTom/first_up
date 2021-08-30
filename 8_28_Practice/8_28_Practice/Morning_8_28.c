#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//int main(){
//	char num;
//	int i, j;
//	scanf("%c", &num);
//	for (i = 0; i<5; i++)
//	{
//		for (j = 4; j - i>0; j--)
//		{
//			printf(" ");
//		}
//		for (j = 0; j<i + 1; j++)
//		{
//			printf("%c ", num);
//		}
//		printf("\n");
//	}
//	return 0;
//}



#include <stdio.h>

//int main(){
//	int i = 0;
//	int a[] = { 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33 };
//	for (i = 0; i < sizeof(a)-1; i++)
//	{
//		printf("%c", a[i]);
//	}
//	return 0;
//}

//int main(){
//
//	printf("%c %c %c %c %c %c %c %c %c %c %c %c", 73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	printf("%02d", i);
//
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int date = 0;
//	scanf("%4d%2d%2d", &year, &month, &date);
//	printf("year=%d\nmonth=%02d\ndate=%02d", year, month, date);
//	return 0;
//}



//#include <stdio.h>
//
//int main(){
//	int a,a1,a2,a3,a4;
//	scanf("%d", &a);
//	/*a4 = a / 1000;
//	a3 = a / 100 - a4 * 10;
//	a2 = a / 10 - a3*10-a4 * 100;
//	a1 = a - a2 * 10 - a3 * 100 - a4 * 1000;*/
//	printf("%d%d%d%d", a%10, a%100/10, a%1000/100, a/1000);
//	return 0;
//}

//#include <stdio.h>
//
//int main(){
//	int a, b, sum;
//	scanf("%d%d", &a, &b);
//	sum = a + b;
//	printf("%d", sum%100);
//	return 0;
//}

#include <stdio.h>
#include <math.h>


//描述
//问题：一年约有3.156×107s，要求输入您的年龄，显示该年龄合多少秒。
//
//输入描述：
//一行，包括一个整数age(0<age <= 200)。
//输出描述：
//一行，包含一个整数，输出年龄对应的秒数。


//int main()
//{
//	int n = 0;
//	while (1)
//	{
//		scanf("%d", &n);
//		long long b = (3.156*pow(10, 7));
//		long long c = n * b;
//		printf("%11d", c);
//	}
//	return 0;
//}//为什么会出现修改一个数据，再修改回来便会出现不可逆的问题？？？

//int main(){
//	int a = 0;
//	scanf("%d", &a);
//	long long s = 3.156*pow(10,7);
//	long long c = a * s;
//	printf("%d", c);
//	return 0;
//}


//int main(){
//	int a;
//	scanf("%d", &a);
//	long long b = (3.156*pow(10, 7));
//	long long c = a * b;
//	printf("%.f", (float)c);
//	return 0;
//}

////正确的形式
int main(){
	int a;
	scanf("%d", &a);
	long long b = (3.156*pow(10, 7));
	long long c = a * b;
	printf("%.f", (double)c);
	return 0;
}



//8_30   
//描述
//实现字母的大小写转换。多组输入输出。
//输入描述：
//多组输入，每一行输入大写字母。
//输出描述：
//针对每组输入输出对应的小写字母。

#include <stdio.h>
#include <math.h>
#define pi 3.1415926

//int main()
//{
//	char ch;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch >= 'A' && ch <= 'Z')
//		{
//			ch += 32;
//		}
//		putchar(ch);
//	}
//	return 0;
//}

//描述
//给定一个球体的半径，计算其体积。其中球体体积公式为 V = 4 / 3 * πr3，其中 π = 3.1415926。
//输入描述：
//一行，用浮点数表示的球体的半径。
//输出描述：
//一行，球体的体积，小数点后保留3位。

#include <stdio.h>
#include <math.h>
#define pi 3.1415926

int main()
{
	float a, v;
	scanf("%f", &a);
	v = 4 * pi*pow(a, 3) / 3 * 10000;
	printf("%.3f", v / 10000);
	return 0;
}