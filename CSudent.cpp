#include <iostream>
#include <string>
#include "CStudent.h"

using namespace std;
CStudent::CStudent(string p_name, bool p_sex, int p_score)
{
	this->name = p_name;
	this->sex = p_sex;
	this->score = p_score;

}

CStudent::CStudent()
{
	input();
}

void CStudent::input()
{
	cout << "������ѧ��������" << endl;
	cin >> name;

	cout << "������ѧ���Ա�(1Ϊ���ԣ�0ΪŮ��)��" << endl;
	int isex;
	cin >> isex;
	sex = isex ? true : false;

	cout << "������ѧ���ɼ���" << endl;
	cin >> score;
}

void CStudent::show(int method)
{
	switch (method)
	{
	case 0:
		cout << name << "\t"
			<< (sex ? "��" : "Ů") << "\t"
			<< score << "\t"
			<< endl;
		break;
	case 1:
		cout << "������" << name << endl
			<< "�Ա�" << (sex ? "��" : "Ů") << endl
			<< "�ɼ���" << score << endl;
		break;
	}
	
}

