#pragma once
#include"Student.h"

#define GRADUATE_TAKE_PARAMETERS const std::string& subject
#define GRADUATE_GIVE_PARAMETERS subject

class Graduate : public Student
{
	static const int SUBJECT_WIDHT = 25;
	std::string subject;
public:
	const std::string& get_subject()const;
	void set_subject(const std::string& subject);
	//		Constructor:
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETRS, GRADUATE_TAKE_PARAMETERS);
		//:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETRS)
	Graduate(const Student& student, const std::string& subject); //: Student(student)
	~Graduate();
	//		Methods:
	std::ostream& print(std::ostream& os)const override;
	std::ofstream& print(std::ofstream& ofs)const override;
	std::ifstream& read(std::ifstream& ifs)override;
};