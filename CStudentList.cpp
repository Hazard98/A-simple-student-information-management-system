#include "CStudentList.h"
#include <iostream>
#include <string>
#include <fstream>

CStudentList::CStudentList(int n)
{
	head = new CStudent("head",1,100);
	head->next = NULL;
	for (int i = 0; i < n; i++)
	{
		CStudent* newNode = new CStudent();
		newNode->next = head->next;
		head->next = newNode;
	}
}


CStudentList::CStudentList(CStudent s[], int n)
{
	head = new CStudent("head", 1, 100);
	head->next = NULL;
	for (int i = 0; i < n; i++)
	{
		CStudent* newNode = new CStudent(s[i].getName(),s[i].getSex(),s[i].getScore());
		newNode->next = head->next;
		head->next = newNode;
	}
}
CStudentList::CStudentList()
{
}

void CStudentList::showList()
{
	CStudent* p = head->next;
	cout << "姓名\t性别\t成绩\t" << endl;
	while (p!=NULL)
	{
		p->show(0);
		p = p->next;//工作指针后移
	}
}
int CStudentList::search(string name)
{
	int num = 0;
	CStudent* p = head->next;
	cout << "--------查找结果---------" << endl;
	while (p!=NULL)
	{
		if (p->getName()==name)
		{
			num++;
			p->show(0);
		}
		p = p->next;
	}
	return num;
}

void CStudentList::deleteNode(CStudent* p)
{
	CStudent* p1 = head, *p2 = head->next;
	while (p2!=p)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	p1->next = p->next;
	delete p;

}

int CStudentList::deleteByName(string name)
{
	CStudent* p = head->next;
	while (p != NULL)
	{
		if (p->getName() == name)
		{
			deleteNode(p);
			return 0;
		}
		p = p->next;
	}

	return -1;
}

void CStudentList::save(string fileName)
{
	ofstream fileout(fileName);
	CStudent* p = head->next;
	while (p!=NULL)
	{
		fileout << p->getName() << "\t"
			<< p->getSex() << "\t"
			<< p->getScore() << "\t";
		p = p->next;
	}
}

void CStudentList::open(string filename)
{
	//清空链表
	CStudent* p = head->next;
	while (p != NULL)
	{
		delete head;
		head = p;
		p = p->next;
	}//与析构函数不同，不需要删除头结点
	

	//从文件读取数据

	ifstream filein(filename);
	while (!filein.eof())//文件结尾处
	{
		string name;
		bool sex;
		int score;
		filein >> name >> sex >> score;
		CStudent* newNode = new CStudent(name,sex,score);
		newNode->next = head->next;
		head->next = newNode;
		//利用头插法将数据插入到链表中
	}
}

CStudentList::~CStudentList()
{
	CStudent* p = head->next;
	while (p!=NULL)
	{
		delete head;
		head = p;
		p = p->next;
	}
	delete head;
}
