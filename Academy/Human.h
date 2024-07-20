#pragma once
#include<iostream>
#include<string>	//ќбъ€влен класс std::string
#include<string.h>	//ќбъ€вленны ф-ции дл€ работы с NULL Termenated Line
#include<fstream>

using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n|----------------------------------------------------|\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age
class Human;
void Print(Human* group[], const int n);
void Write_To_File(Human* group[], const int n, std::string file_name);
Human* HumanFarctory(const std::string& type);
bool CheckType(const std::string& buffer);
Human** Read_From_File(const std::string& file_name, int& n);
void Clear(Human* group[], const int n);

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
	const std::string& get_last_name()const;
	const std::string& get_first_name()const;
	int get_age()const;
	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
	void set_age(int age);
	//		Constructors:
	Human(HUMAN_TAKE_PARAMETERS);
	virtual ~Human();
	//		Methods:
	virtual std::ostream& print(std::ostream& os)const;
	virtual std::ofstream& print(std::ofstream& ofs)const;
	virtual std::ifstream& read(std::ifstream& ifs);
};