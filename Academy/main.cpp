#include<iostream>
#include<string>	//Объявлен класс std::string
#include<string.h>	//Объявленны ф-ции для работы с NULL Termenated Line
#include<fstream>

using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n|----------------------------------------------------|\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	static const int TYPE_WIDTH = 12;
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 15;
	static const int AGE_WIDTH = 5;
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	//		Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}
	//		Methods:
	virtual std::ostream& print(std::ostream& os)const
	{
		//os << strchr(typeid(*this).name(), ' ') + 1 << ":\t";
		return os << last_name << " " << first_name << " " << age;
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(TYPE_WIDTH);	//Метод width() задает ширину вывода
						//При первом вызове метод width() включает выравнивание по правому краю.
		ofs << std::left;	//Возвращаем выравнивание по левому краю
						//Один вызво width() влияет только на одно выводимое значение
		ofs << std::string(strchr(typeid(*this).name(), ' ') + 1) + ":";
		
		ofs.width(LAST_NAME_WIDTH);
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << first_name;
		ofs.width(AGE_WIDTH);
		ofs << age;
		return ofs;
	}
};
std::ostream& operator<<(std::ostream& os, const Human& obj) 
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);
}


void Print(Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		//cout << delimiter << endl;
		cout << *group[i] << endl;
		cout << delimiter << endl;

	}
}
void Write_To_File(Human* group[], const int n, std::string file_name)
{
	std::ofstream fout;
	fout.open(file_name);
	for (int i = 0; i < n; i++)
	{
		fout << group[i] << endl;
	}
	fout.close();
	//std::string('')+

}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance


class Student : public Human
{
	const static int SPECIALITY_WIDHT = 25;
	const static int GROUP_WIDHT = 8;
	const static int RATING_WIDHT = 8;
	const static int ATTENDANCE_WIDHT = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()
	{
		return speciality;
	}
	const std::string& get_group()
	{
		return group;
	}
	double get_rating()
	{
		return rating;
	}
	double get_attendance()
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//		Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	Student(const Human& human, STUDENT_TAKE_PARAMETRS) : Human(human)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SConstructor:\t" << this << endl;
	}
	//		Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return Human::print(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
	}	
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDHT);
		ofs << speciality;
		ofs.width(GROUP_WIDHT);
		ofs << group; 
		ofs.width(RATING_WIDHT);
		ofs << rating;
		ofs.width(ATTENDANCE_WIDHT);
		ofs << attendance;
		return ofs;
	}
};

#define TEACHER_TAKE_PARAMETERES const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERES speciality, experience

class Teacher : public Human
{
	const static int SPECIALITY_WIDHT = 25;
	const static int EXPERIENCE_WIDHT = 5;
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()
	{
		return speciality;
	}
	int get_experience()
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	//		Constractos:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERES) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//		Methods:
	std::ostream& print(std::ostream& os)const override
	{
		return  Human::print(os) << " " << speciality << " " << experience;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDHT);
		ofs << speciality; 
		ofs.width(EXPERIENCE_WIDHT);
		ofs << experience;
		return ofs;
	}
};

#define GRADUATE_TAKE_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject

class Graduate : public Student
{
	static const int SUBJECT_WIDHT = 30;
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//		Constructor:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETRS, GRADUATE_TAKE_PARAMETERS)
		:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETRS)
	{
		this->subject = subject;
		cout << "GConstructor:\t" << this << endl;
	}
	Graduate(const Student& student, const std::string& subject) : Student(student)
	{
		set_subject(subject);
		cout << "GConstractor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//		Methods:
	std::ostream& print(std::ostream& os)const override
	{
	return Student::print(os) << " " << subject;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Student::print(ofs);
		ofs.width(SUBJECT_WIDHT);
		ofs << subject;
		return ofs;
	}

};


//#define INHERITENCE_1
//#define INHERITENCE_2

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

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 20, "Chemistry", "WW_220", 95, 90),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 50, 70, "How to catch Heisenberg"),
		new Student("Vercetti", "Tommy", 30, "Theft", "Vice", 95, 98),
		new Teacher("Diaz", "Ricardo", 50, "Weapon distribution", 20)
	};

	//Print(group, sizeof(group) / sizeof(group[0]));
	std::ofstream fout;
	fout.open("Group.txt");//std::ios_base::app);
	//fout << "Hello Group!" << endl;
	//fout << delimiter;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		fout << *group[i] << endl;;
		//fout << delimiter;
	}
	fout.close();
	system("notepad Group.txt");
	Clear(group, sizeof(group) / sizeof(group[0]));
}