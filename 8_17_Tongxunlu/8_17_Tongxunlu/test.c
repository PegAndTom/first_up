#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"


////��ʼ��
//void InitContact(Contact* ps)
//{
//	memset(ps->data, 0, sizeof(ps->data));//���ռ䲢��ֵΪ0
//	ps->size = 0;//��ʼ�洢����Ϊ0
//}

//��ʼ���Ż�
void InitContact(Contact* ps)
{
	ps->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
	//���ع�ȥ�洢��Ϣ
	LoadContact(ps);
}


void LoadContact(Contact* ps)
{
	PeoInfo temp = {0};//��ʱ����
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact.data::%s\n", strerror(errno));
		return;
	}
	//��ȡ����
	//fread(&temp, sizeof(PeoInfo), 1, pfRead);//�ô˺����ķ���ֵȷ���Ƿ����
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
			printf("��ӳɹ�\n");
		}
		else
		{
			printf("���ʧ��\n");
		}
	}
}

//1.�����û���Ϣ
void AddContact(Contact* ps)
{
	//����2
	CheckCapacity(ps);
	printf("����������:>");
	scanf("%s", ps->data[ps->size].name);
	printf("����������:>");
	scanf("%d", &ps->data[ps->size].age);//��������׳�����int�͡���Ҫ&����
	printf("�������Ա�:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("������绰:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("������סַ:>");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("��ӳɹ���\n");


	//if (ps->size == MAX)
	//{
	//	printf("�������ٷţ�\n");
	//}
	//else
	//{
	//	printf("����������:>");
	//	scanf("%s", ps->data[ps->size].name);
	//	printf("����������:>");
	//	scanf("%d", &ps->data[ps->size].age);//��������׳�����int�͡���Ҫ&����
	//	printf("�������Ա�:>");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("������绰:>");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("������סַ:>");
	//	scanf("%s", ps->data[ps->size].addr);
	//	ps->size++;
	//	printf("��ӳɹ���\n");
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

//2.ɾ��ָ���û���Ϣ
void DelContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ��������:>");
	scanf("%s", name);
	//�ҵ���Ӧ�û�����λ��pos
	//�Ҳ�������-1
	int pos = FindByName(ps, name);

	//�Ը�λ�ý�����Ӧ�滻
	if (pos == -1)
	{
		printf("��ɾ�����󲻴���\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}


//3.�޸��û���Ϣ
void ModifyContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ�޸ĵ��û�����");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("���޸ĵ��û�������\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[pos].name);
		printf("����������:>");
		scanf("%d", &ps->data[pos].age);//��������׳�����int�͡���Ҫ&����
		printf("�������Ա�:>");
		scanf("%s", ps->data[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->data[pos].tele);
		printf("������סַ:>");
		scanf("%s", ps->data[pos].addr);
		printf("�޸ĳɹ���\n");
	}
}

//4.�����û���Ϣ
void SearchContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ��ѯ���û�����");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("����ѯ���û�������\n");
	}
	else
	{
		printf("%-15s\t %-4s\t %-5s\t %-12s\t %-30s\n",
			"����", "����", "�Ա�", "�绰", "סַ");
		printf("%-15s\t %-4d\t %-5s\t %-12s\t %-30s\n",
				ps->data[pos].name,
				ps->data[pos].age,
				ps->data[pos].sex,
				ps->data[pos].tele,
				ps->data[pos].addr);//�ڶ�������ϸ΢���ע�⣡
	}
}


//5.��ӡ�û���Ϣ
void ShowContact(Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	else
	{
		int i = 0;
		printf("%-15s\t %-4s\t %-5s\t %-12s\t %-30s\n",
			"����", "����", "�Ա�", "�绰", "סַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-15s\t %-4d\t %-5s\t %-12s\t %-30s\n",
				ps->data[i].name,
				ps->data[i].age, 
				ps->data[i].sex, 
				ps->data[i].tele,
				ps->data[i].addr);//�ڶ�������ϸ΢���ע�⣡
		}
	}
}

//6.����
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

//7.����
void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contact.dat", "wb");//��fopen����Ҫ��fclose
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//д����
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}


//�ͷ��ڴ�
void DestroyContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}