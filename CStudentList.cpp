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
	cout << "����\t�Ա�\t�ɼ�\t" << endl;
	while (p!=NULL)
	{
		p->show(0);
		p = p->next;//����ָ�����
	}
}
int CStudentList::search(string name)
{
	int num = 0;
	CStudent* p = head->next;
	cout << "--------���ҽ��---------" << endl;
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
	//�������
	CStudent* p = head->next;
	while (p != NULL)
	{
		delete head;
		head = p;
		p = p->next;
	}//������������ͬ������Ҫɾ��ͷ���
	

	//���ļ���ȡ����

	ifstream filein(filename);
	while (!filein.eof())//�ļ���β��
	{
		string name;
		bool sex;
		int score;
		filein >> name >> sex >> score;
		CStudent* newNode = new CStudent(name,sex,score);
		newNode->next = head->next;
		head->next = newNode;
		//����ͷ�巨�����ݲ��뵽������
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
