#include"Graduate.h"

const std::string& Graduate::get_subject()const
{
	return subject;
}
void Graduate::set_subject(const std::string& subject)
{
	this->subject = subject;
}
//		Constructor:
Graduate::Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETRS, GRADUATE_TAKE_PARAMETERS)
	:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETRS)
{
	this->subject = subject;
	cout << "GConstructor:\t" << this << endl;
}
Graduate::Graduate(const Student& student, const std::string& subject) : Student(student)
{
	set_subject(subject);
	cout << "GConstractor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}
//		Methods:
std::ostream& Graduate::print(std::ostream& os)const
{
	return Student::print(os) << " " << subject;
}
std::ofstream& Graduate::print(std::ofstream& ofs)const
{
	Student::print(ofs);
	ofs.width(SUBJECT_WIDHT);
	ofs << subject;
	return ofs;
}
std::ifstream& Graduate::read(std::ifstream& ifs)
{
	Student::read(ifs);
	std::getline(ifs, subject);
	//ifs >> subject;
	return ifs;
}