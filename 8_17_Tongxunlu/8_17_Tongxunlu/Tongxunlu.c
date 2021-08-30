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
	//����ͨѶ¼
	Contact con;
	Contact temp;//���ڴ����ʱ����
	//��ʼ��ͨѶ¼
	InitContact(&con);
	InitContact(&temp);

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);//�÷����ݰ���
		switch (input)
		{
		case ADD:
			AddContact(&con);//��ʹ�õ���realco��Ҫ�ͷ��ڴ�
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
			printf("����ɹ�\n");
			break;
		case EXIT:
			printf("�˳�����\n");
			SaveContact(&con);
			DestroyContact(&con);
			break;
		default:
			printf("�������\n");
		}
		
	} while (input);

	return 0;
}
