#pragma once
#include "CStudent.h"

using namespace std;
//链表类选择带头结点的单项链表
//方法g构造函数（手动输入）,构造函数（传入节点对象数组）以及析构函数
class CStudentList
{
	CStudent* head;

public:
	CStudentList(int n);//n为需要输入的学生个数
	CStudentList(CStudent s[],int n);
	CStudentList();

	void showList();
	int search(string name);//返回找到的个数
	void deleteNode(CStudent* p);
	int deleteByName(string name);//删除表中匹配的第一条记录
	void save(string fileName);
	void open(string filename);

	~CStudentList();
};

