#pragma once
#include "Human.h"

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
	const std::string& get_speciality();
	const std::string& get_group();
	double get_rating();
	double get_attendance();
	void set_speciality(const std::string& speciality);
	void set_group(const std::string& group);
	void set_rating(double rating);
	void set_attendance(double attendance);
	//		Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETRS); //:Human(HUMAN_GIVE_PARAMETERS);
	Student(const Human& human, STUDENT_TAKE_PARAMETRS); //:Human(human);
	~Student();
	//		Methods:
	std::ostream& print(std::ostream& os)const override;
	std::ofstream& print(std::ofstream& ofs)const override;
	std::ifstream& read(std::ifstream& ifs)override;
};
