#include <iostream>
#include "CStudent.h"
#include "CStudentList.h"
using namespace std;

int main()
{
	CStudent student[3] = {
		CStudent("t",1,100),
		CStudent("tom",1,100),
		CStudent("jack",1,98),
	};
	CStudentList* s = new CStudentList(student,3);
	
	s->showList();
	s->search("tom");
	s->deleteByName("tom");
	s->showList();
	//s->save("data.txt");
	s->open("data.txt");
	s->showList();
	delete s;
	return 0;
}