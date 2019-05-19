#pragma once
#include <iostream>
#include <string>

using namespace std;

class CStudent
{
	string name;
	bool sex;
	int score;
	
public:
	CStudent * next;

	CStudent(string p_name, bool p_sex, int p_score);
	CStudent();
	~CStudent(){}

	void input();
	void show(int method);
	string getName() { return name; }
	bool getSex() { return sex; }
	int getScore() { return score; }
};