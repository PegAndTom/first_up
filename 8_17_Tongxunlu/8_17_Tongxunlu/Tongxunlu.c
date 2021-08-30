#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void menu()
{
	printf("*****************************************\n");
	printf("***** 1. add            2. del      *****\n");
	printf("***** 3. modify         4. search   *****\n");
	printf("***** 5. show           6. sort     *****\n");
	printf("***** 7. save           0. exit     *****\n");
	printf("*****************************************\n");
}


int main()
{
	int input = 0;
	//创建通讯录
	Contact con;
	Contact temp;//用于存放临时变量
	//初始化通讯录
	InitContact(&con);
	InitContact(&temp);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);//得放数据啊！
		switch (input)
		{
		case ADD:
			AddContact(&con);//若使用到了realco需要释放内存
			break;
		case DEL:
			DelContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con, &temp);
			break;
		case SAVE:
			SaveContact(&con);
			printf("保存成功\n");
			break;
		case EXIT:
			printf("退出程序\n");
			SaveContact(&con);
			DestroyContact(&con);
			break;
		default:
			printf("输入错误\n");
		}
		
	} while (input);

	return 0;
}
