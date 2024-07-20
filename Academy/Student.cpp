#include"Student.h"

const std::string& Student::get_speciality()
{
	return speciality;
}
const std::string& Student::get_group()
{
	return group;
}
double Student::get_rating()
{
	return rating;
}
double Student::get_attendance()
{
	return attendance;
}
void Student::set_speciality(const std::string& speciality)
{
	this->speciality = speciality;
}
void Student::set_group(const std::string& group)
{
	this->group = group;
}
void Student::set_rating(double rating)
{
	this->rating = rating;
}
void Student::set_attendance(double attendance)
{
	this->attendance = attendance;
}
//		Constructors:
Student::Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETERS)
{
	set_speciality(speciality);
	set_group(group);
	set_rating(rating);
	set_attendance(attendance);
	cout << "SConstructor:\t" << this << endl;
}
Student::Student(const Human& human, STUDENT_TAKE_PARAMETRS) : Human(human)
{
	set_speciality(speciality);
	set_group(group);
	set_rating(rating);
	set_attendance(attendance);
	cout << "SConstructor:\t" << this << endl;
}
Student::~Student()
{
	cout << "SConstructor:\t" << this << endl;
}
//		Methods:
std::ostream& Student::print(std::ostream& os)const
{
	return Human::print(os) << " " << speciality << " " << group << " " << rating << " " << attendance;
}
std::ofstream& Student::print(std::ofstream& ofs)const 
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
std::ifstream& Student::read(std::ifstream& ifs)
{
	Human::read(ifs);
	ifs >> speciality >> group >> rating >> attendance;
	return ifs;
}