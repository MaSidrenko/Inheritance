//#include<iostream>
#include"Human.h"
#include"Teacher.h"
#include"Student.h"
#include"Graduate.h"

//#define INHERITENCE_1
//#define INHERITENCE_2
#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
	cout << "HelloAcademy" << endl;
	cout << delimiter << endl;

#ifdef INHERITENCE_1

	Human human("Richter", "Jeffery", 40);
	human.print();
	cout << delimiter << endl;

	Student student("Pinkman", "Jessie", 20, "Chemistry", "WW_220", 95, 90);
	student.print();
	cout << delimiter << endl;

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();
	cout << delimiter << endl;

	Graduate graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 50, 70, "How to catch Heisenberg");
	graduate.print();
	cout << delimiter << endl;
#endif // INHERITENCE_1

#ifdef INHERITENCE_2
	Human human("Vercetty", "Tommy", 30);
	human.print();
	cout << delimiter << endl;

	Student student(human, "Theft", "Vice", 95, 98);
	student.print();
	cout << delimiter << endl;

	Graduate graduate(student, "How to make money");
	graduate.print();
	cout << delimiter << endl;
#endif // INHERITENCE_2

#ifdef WRITE_TO_FILE
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 20, "Chemistry", "WW_220", 95, 90),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 50, 70, "How to catch Heisenberg"),
		new Student("Vercetti", "Tommy", 30, "Theft", "Vice", 95, 98),
		new Teacher("Diaz", "Ricardo", 50, "Weapon distribution", 20)
	};

	Write_To_File(group, sizeof(group) / sizeof(group[0]), "Group.txt");
#endif // WRITE_TO_FILE

	
#ifdef READ_FROM_FILE
	int n = 0;
	Human** group = Read_From_File("Group.txt", n);
	Print(group, n);
	Clear(group, n);
#endif // READ_FROM_FILE

}