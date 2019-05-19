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
	cout << "请输入学生姓名：" << endl;
	cin >> name;

	cout << "请输入学生性别(1为男性，0为女性)：" << endl;
	int isex;
	cin >> isex;
	sex = isex ? true : false;

	cout << "请输入学生成绩：" << endl;
	cin >> score;
}

void CStudent::show(int method)
{
	switch (method)
	{
	case 0:
		cout << name << "\t"
			<< (sex ? "男" : "女") << "\t"
			<< score << "\t"
			<< endl;
		break;
	case 1:
		cout << "姓名：" << name << endl
			<< "性别：" << (sex ? "男" : "女") << endl
			<< "成绩：" << score << endl;
		break;
	}
	
}

