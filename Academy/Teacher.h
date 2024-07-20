#pragma once
#include"Human.h"

#define TEACHER_TAKE_PARAMETERES const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERES speciality, experience

class Teacher : public Human
{
	const static int SPECIALITY_WIDHT = 25;
	const static int EXPERIENCE_WIDHT = 5;
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality();
	int get_experience();
	void set_speciality(const std::string& speciality);
	void set_experience(int experience);
	//		Constractos:
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERES); //:Human(HUMAN_GIVE_PARAMETERS)
	~Teacher();
	//		Methods:
	std::ostream& print(std::ostream& os)const override;
	std::ofstream& print(std::ofstream& ofs)const override;
	std::ifstream& read(std::ifstream& ifs)override;
};