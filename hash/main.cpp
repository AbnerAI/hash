/*
author:cuixiangchn@163.com
*/
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define HashMax 100
//声明
int Myhash(int x);
int initialHashTable(int i, int key, string value);
void showHash(int c);
int addHash(int i, int addKey, string addValue);
int deleteHash(int i, int delKey);
void updateHash(int i, int key, string value);
//建立映射表
typedef struct MyMap
{
	int key;
	string value;
}MapTable;

//建立Hash表
typedef struct MyHash
{
	string value;
}HashTable;
//初始化MapTable
MapTable Map[HashMax];
//初始化HashTable
MyHash Hash[HashMax*2+1];

void main()
{
	int select;//查找输入
	int i = 0;//计数器 
	int addKey,delKey,updateKey;
	string addValue,updateValue;
	i = initialHashTable(i, 2, "张三");
	i = initialHashTable(i, 5, "李思");
	i = initialHashTable(i, 7, "小明");
	while (true)
	{
		printf("---简易版Hash---\n");
		printf("1.查看所有映射表和对应的Hash地址\n");
		printf("2.增加一组映射和Hash记录\n");
		printf("3.删除一组映射和Hash记录\n");
		printf("4.通过key修改对应地址的值\n");
		printf("请输入选项:");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			showHash(i);
			break;
		case 2:
			printf("输入key和value:");
			cin >> addKey;
			cin >> addValue;
			i =addHash(i, addKey, addValue);
			break;
		case 3:
			printf("输入要删除的键值对key:");
			cin >> delKey;
			i = deleteHash(i, delKey);
			break;
		case 4:
			printf("请输入key和更新的value:");
			cin >> updateKey;
			cin >> updateValue;
			updateHash(i, updateKey, updateValue);
			break;
		default:
			printf("输入有误");
			break;
		}
	}
}
//Hash函数
int Myhash(int x)
{
	return x * 2 + 1;
}
//初始化Hash表 和 基本映射表
int initialHashTable(int i,int key,string value)
{
	Map[i].value = value;
	Map[i].key = key;
	Hash[Myhash(Map[i].key)].value = Map[i].value;
	return ++i;
}
//查看所有映射表和对应的Hash地址
void showHash(int c)
{
	system("cls");
	int j;
	for (j = 0; j < c; j++)
	{
		//printf("地址：%d 值:%s\n", Hash[j].key,Hash[j].value);
		cout <<"key是："<<Map[j].key <<"地址："<< Myhash(Map[j].key) <<"值为："<< Hash[Myhash(Map[j].key)].value<<endl;
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
	//需要从映射表和Hash表中全部删除
	//首先查询Hash地址
	int position = Myhash(delKey);
	//清除对应Hash表的数据
	Hash[position].value = "已经被销毁";//为了简单起见，就这样简单表示一下
	//清除映射表信息
	int  j = 0;
	for ( j; j < i; j++)
	{
		if (Map[j].key==delKey)
		{
		//	Map[j].key = -1;
			Map[j].value = "已经被销毁";
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
