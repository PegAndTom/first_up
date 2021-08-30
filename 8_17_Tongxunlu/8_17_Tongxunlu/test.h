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

//使用枚举对情况进行定义
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


//成员信息
typedef struct  PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


////通讯录类型
//typedef struct Contact{
//	PeoInfo data[MAX];//结构体数组
//	int size;//记录当前存储的用户个数
//}Contact;

//通讯录类型优化，添加默认值
typedef struct Contact{
	PeoInfo* data;//结构体数组指针
	int size;//记录当前存储的用户个数
	int capacity;
}Contact;

////初始化
//void InitContact(Contact* ps);
//
////1.增加用户信息
//void AddContact(Contact* ps);

//初始化优化
//默认内存为3，满了加2
void InitContact(Contact* ps);


//检查内存是否够用
void CheckCapacity(Contact* ps);

//1.增加用户信息
void AddContact(Contact* ps);

//2.删除指定用户信息
void DelContact(Contact* ps);

//3.修改用户信息
void ModifyContact(Contact* ps);

//4.查找用户信息
void SearchContact(Contact* ps);

//5.打印用户信息
void ShowContact(Contact* ps);

//6.排序
void SortContact(Contact* ps,Contact* temp);

//7.保存
void SaveContact(Contact* ps);

//保存文件加载到初始通讯录中
void LoadContact(Contact* ps);

//释放内存
void DestroyContact(Contact* ps);

