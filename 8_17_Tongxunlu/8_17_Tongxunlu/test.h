#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX 100
#define DEFAULT_SZ 3

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

//ʹ��ö�ٶ�������ж���
enum Option
{
	EXIT,	//0
	ADD,	//1
	DEL,
	MODIFY,
	SEARCH,
	SHOW,
	SORT,
	SAVE
};


//��Ա��Ϣ
typedef struct  PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


////ͨѶ¼����
//typedef struct Contact{
//	PeoInfo data[MAX];//�ṹ������
//	int size;//��¼��ǰ�洢���û�����
//}Contact;

//ͨѶ¼�����Ż������Ĭ��ֵ
typedef struct Contact{
	PeoInfo* data;//�ṹ������ָ��
	int size;//��¼��ǰ�洢���û�����
	int capacity;
}Contact;

////��ʼ��
//void InitContact(Contact* ps);
//
////1.�����û���Ϣ
//void AddContact(Contact* ps);

//��ʼ���Ż�
//Ĭ���ڴ�Ϊ3�����˼�2
void InitContact(Contact* ps);


//����ڴ��Ƿ���
void CheckCapacity(Contact* ps);

//1.�����û���Ϣ
void AddContact(Contact* ps);

//2.ɾ��ָ���û���Ϣ
void DelContact(Contact* ps);

//3.�޸��û���Ϣ
void ModifyContact(Contact* ps);

//4.�����û���Ϣ
void SearchContact(Contact* ps);

//5.��ӡ�û���Ϣ
void ShowContact(Contact* ps);

//6.����
void SortContact(Contact* ps,Contact* temp);

//7.����
void SaveContact(Contact* ps);

//�����ļ����ص���ʼͨѶ¼��
void LoadContact(Contact* ps);

//�ͷ��ڴ�
void DestroyContact(Contact* ps);

