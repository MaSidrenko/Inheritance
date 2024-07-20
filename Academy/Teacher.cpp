#include"Teacher.h"

const std::string& Teacher::get_speciality()
{
	return speciality;
}
int Teacher::get_experience()
{
	return experience;
}
void Teacher::set_speciality(const std::string& speciality)
{
	this->speciality = speciality;
}
void Teacher::set_experience(int experience)
{
	this->experience = experience;
}
//		Constractos:
Teacher::Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERES) :Human(HUMAN_GIVE_PARAMETERS)
{
	set_speciality(speciality);
	set_experience(experience);
	cout << "TConstructor:\t" << this << endl;
}
Teacher::~Teacher()
{
	cout << "TDestructor:\t" << this << endl;
}
//		Methods:
std::ostream& Teacher::print(std::ostream& os)const 
{
	return  Human::print(os) << " " << speciality << " " << experience;
}
std::ofstream& Teacher::print(std::ofstream& ofs)const 
{
	Human::print(ofs);
	ofs.width(SPECIALITY_WIDHT);
	ofs << speciality;
	ofs.width(EXPERIENCE_WIDHT);
	ofs << experience;
	return ofs;
}
std::ifstream& Teacher::read(std::ifstream& ifs)
{
	Human::read(ifs);
	char sz_speciality[SPECIALITY_WIDHT + 1]{};
	ifs.read(sz_speciality, SPECIALITY_WIDHT);
	for (int i = SPECIALITY_WIDHT - 2; sz_speciality[i] == ' '; i--)sz_speciality[i] = 0;
	while (sz_speciality[0] == ' ')
		for (int i = 0; sz_speciality[i]; i++)sz_speciality[i] = sz_speciality[i + 1];
	speciality = sz_speciality;
	ifs >> experience;
	return ifs;
}