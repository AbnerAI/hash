/*
author:abner_albert@163.com
*/
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define HashMax 100
//����
int Myhash(int x);
int initialHashTable(int i, int key, string value);
void showHash(int c);
int addHash(int i, int addKey, string addValue);
int deleteHash(int i, int delKey);
void updateHash(int i, int key, string value);
//����ӳ���
typedef struct MyMap
{
	int key;
	string value;
}MapTable;

//����Hash��
typedef struct MyHash
{
	string value;
}HashTable;
//��ʼ��MapTable
MapTable Map[HashMax];
//��ʼ��HashTable
MyHash Hash[HashMax*2+1];

void main()
{
	int select;//��������
	int i = 0;//������ 
	int addKey,delKey,updateKey;
	string addValue,updateValue;
	i = initialHashTable(i, 2, "����");
	i = initialHashTable(i, 5, "��˼");
	i = initialHashTable(i, 7, "С��");
	while (true)
	{
		printf("---���װ�Hash---\n");
		printf("1.�鿴����ӳ���Ͷ�Ӧ��Hash��ַ\n");
		printf("2.����һ��ӳ���Hash��¼\n");
		printf("3.ɾ��һ��ӳ���Hash��¼\n");
		printf("4.ͨ��key�޸Ķ�Ӧ��ַ��ֵ\n");
		printf("������ѡ��:");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			showHash(i);
			break;
		case 2:
			printf("����key��value:");
			cin >> addKey;
			cin >> addValue;
			i =addHash(i, addKey, addValue);
			break;
		case 3:
			printf("����Ҫɾ���ļ�ֵ��key:");
			cin >> delKey;
			i = deleteHash(i, delKey);
			break;
		case 4:
			printf("������key�͸��µ�value:");
			cin >> updateKey;
			cin >> updateValue;
			updateHash(i, updateKey, updateValue);
			break;
		default:
			printf("��������");
			break;
		}
	}
}
//Hash����
int Myhash(int x)
{
	return x * 2 + 1;
}
//��ʼ��Hash�� �� ����ӳ���
int initialHashTable(int i,int key,string value)
{
	Map[i].value = value;
	Map[i].key = key;
	Hash[Myhash(Map[i].key)].value = Map[i].value;
	return ++i;
}
//�鿴����ӳ���Ͷ�Ӧ��Hash��ַ
void showHash(int c)
{
	system("cls");
	int j;
	for (j = 0; j < c; j++)
	{
		//printf("��ַ��%d ֵ:%s\n", Hash[j].key,Hash[j].value);
		cout <<"key�ǣ�"<<Map[j].key <<"��ַ��"<< Myhash(Map[j].key) <<"ֵΪ��"<< Hash[Myhash(Map[j].key)].value<<endl;
	}
}
int addHash(int i,int addKey,string addValue) {
	i = initialHashTable(i, addKey, addValue);
	printf("\n");
	showHash(i);
	return i;
}
int deleteHash(int i,int delKey)
{
	//��Ҫ��ӳ����Hash����ȫ��ɾ��
	//���Ȳ�ѯHash��ַ
	int position = Myhash(delKey);
	//�����ӦHash�������
	Hash[position].value = "�Ѿ�������";//Ϊ�˼�������������򵥱�ʾһ��
	//���ӳ�����Ϣ
	int  j = 0;
	for ( j; j < i; j++)
	{
		if (Map[j].key==delKey)
		{
		//	Map[j].key = -1;
			Map[j].value = "�Ѿ�������";
			break;
		}
	}
	showHash(i);
	return i;
}
void updateHash(int i,int key,string value)
{
	Hash[Myhash(key)].value = value;
	showHash(i);
}
