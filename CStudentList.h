#pragma once
#include "CStudent.h"

using namespace std;
//������ѡ���ͷ���ĵ�������
//����g���캯�����ֶ����룩,���캯��������ڵ�������飩�Լ���������
class CStudentList
{
	CStudent* head;

public:
	CStudentList(int n);//nΪ��Ҫ�����ѧ������
	CStudentList(CStudent s[],int n);
	CStudentList();

	void showList();
	int search(string name);//�����ҵ��ĸ���
	void deleteNode(CStudent* p);
	int deleteByName(string name);//ɾ������ƥ��ĵ�һ����¼
	void save(string fileName);
	void open(string filename);

	~CStudentList();
};

