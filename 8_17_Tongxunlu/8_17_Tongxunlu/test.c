#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


////初始化
//void InitContact(Contact* ps)
//{
//	memset(ps->data, 0, sizeof(ps->data));//给空间并赋值为0
//	ps->size = 0;//初始存储个数为0
//}

//初始化优化
void InitContact(Contact* ps)
{
	ps->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//加载过去存储信息
	LoadContact(ps);
}


void LoadContact(Contact* ps)
{
	PeoInfo temp = {0};//临时变量
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact.data::%s\n", strerror(errno));
		return;
	}
	//读取数据
	//fread(&temp, sizeof(PeoInfo), 1, pfRead);//用此函数的返回值确定是否读完
	while (fread(&temp, sizeof(PeoInfo), 1, pfRead))
	{
		//printf("%d", fread(&temp, sizeof(PeoInfo), 1, pfRead));
		CheckCapacity(ps);
		ps->data[ps->size] = temp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

void CheckCapacity(Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2)*sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("添加成功\n");
		}
		else
		{
			printf("添加失败\n");
		}
	}
}

//1.增加用户信息
void AddContact(Contact* ps)
{
	//满加2
	CheckCapacity(ps);
	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &ps->data[ps->size].age);//这里会容易出错，是int型。需要&操作
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入住址:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("添加成功！\n");


	//if (ps->size == MAX)
	//{
	//	printf("已满勿再放！\n");
	//}
	//else
	//{
	//	printf("请输入名字:>");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("请输入年龄:>");
	//	scanf("%d", &ps->data[ps->size].age);//这里会容易出错，是int型。需要&操作
	//	printf("请输入性别:>");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("请输入电话:>");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("请输入住址:>");
	//	scanf("%s", ps->data[ps->size].addr);
	//	ps->size++;
	//	printf("添加成功！\n");
	//}
}

int FindByName(Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
			return i;
	}
	return -1;
}

//2.删除指定用户信息
void DelContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的名字:>");
	scanf("%s", name);
	//找到对应用户所在位置pos
	//找不到返回-1
	int pos = FindByName(ps, name);

	//对该位置进行相应替换
	if (pos == -1)
	{
		printf("所删除对象不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}


//3.修改用户信息
void ModifyContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入所要修改的用户姓名");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("所修改的用户不存在\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &ps->data[pos].age);//这里会容易出错，是int型。需要&操作
		printf("请输入性别:>");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->data[pos].tele);
		printf("请输入住址:>");
		scanf("%s", ps->data[pos].addr);
		printf("修改成功！\n");
	}
}

//4.查找用户信息
void SearchContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入所要查询的用户姓名");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("所查询的用户不存在\n");
	}
	else
	{
		printf("%-15s\t %-4s\t %-5s\t %-12s\t %-30s\n",
			"名字", "年龄", "性别", "电话", "住址");
		printf("%-15s\t %-4d\t %-5s\t %-12s\t %-30s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);//第二个数据细微差别，注意！
	}
}


//5.打印用户信息
void ShowContact(Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空！\n");
	}
	else
	{
		int i = 0;
		printf("%-15s\t %-4s\t %-5s\t %-12s\t %-30s\n",
			"名字", "年龄", "性别", "电话", "住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-15s\t %-4d\t %-5s\t %-12s\t %-30s\n",
				ps->data[i].name,
				ps->data[i].age, 
				ps->data[i].sex, 
				ps->data[i].tele,
				ps->data[i].addr);//第二个数据细微差别，注意！
		}
	}
}

//6.排序
void SortContact(Contact* ps,Contact* temp)
{
	int i = 0;
	for (i = 0; i < ps->size-1; i++)
	{
		int j = 0;
		for (j = 0; j < ps->size - i - 1; j++)
		{
			if (strcmp(ps->data[j].name, ps->data[j + 1].name)<0)
			{	
				temp->data[0] = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = temp->data[0];
			}
		}
	}
}

//7.保存
void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");//有fopen，就要有fclose
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//写数据
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}


//释放内存
void DestroyContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}