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


//����
//���⣺һ��Լ��3.156��107s��Ҫ�������������䣬��ʾ������϶����롣
//
//����������
//һ�У�����һ������age(0<age <= 200)��
//���������
//һ�У�����һ����������������Ӧ��������


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
//}//Ϊʲô������޸�һ�����ݣ����޸Ļ��������ֲ���������⣿����

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

////��ȷ����ʽ
int main(){
	int a;
	scanf("%d", &a);
	long long b = (3.156*pow(10, 7));
	long long c = a * b;
	printf("%.f", (double)c);
	return 0;
}



//8_30   
//����
//ʵ����ĸ�Ĵ�Сдת�����������������
//����������
//�������룬ÿһ�������д��ĸ��
//���������
//���ÿ�����������Ӧ��Сд��ĸ��

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

//����
//����һ������İ뾶��������������������������ʽΪ V = 4 / 3 * ��r3������ �� = 3.1415926��
//����������
//һ�У��ø�������ʾ������İ뾶��
//���������
//һ�У�����������С�������3λ��

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