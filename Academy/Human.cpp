#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

const std::string& Human::get_last_name()const
{
	return last_name;
}
const std::string& Human::get_first_name()const
{
	return first_name;
}
int Human::get_age()const
{
	return age;
}
void Human::set_last_name(const std::string& last_name)
{
	this->last_name = last_name;
}
void Human::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(int age)
{
	this->age = age;
}
//		Constructors:
Human::Human(HUMAN_TAKE_PARAMETERS)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	cout << "HConstructor:\t" << this << endl;
}
Human::~Human()
{
	cout << "HDestructor:\t" << this << endl;
}
//		Methods:
std::ostream& Human::print(std::ostream& os)const
{
	//os << strchr(typeid(*this).name(), ' ') + 1 << ":\t";
	return os << last_name << " " << first_name << " " << age;
}
std::ofstream& Human::print(std::ofstream& ofs)const
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
std::ifstream& Human::read(std::ifstream& ifs)
{
	ifs >> last_name >> first_name >> age;
	return ifs;
}
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);
}
std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.read(ifs);
}


void Print(Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		//cout << delimiter << endl;
		if (group[i])
		{
			cout << *group[i] << endl;
			cout << delimiter << endl;
		}
	}
	cout << "Количество человек в группе: " << n << endl;
}
void Write_To_File(Human* group[], const int n, std::string file_name)
{
	std::ofstream fout;
	fout.open(file_name);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad " + file_name;
	system(cmd.c_str());
}
Human* HumanFarctory(const std::string& type)
{
	Human* human = nullptr;
	if (type == "Human:")human = new Human("", "", 0);
	if (type == "Teacher:")human = new Teacher("", "", 0, "", 0);
	if (type == "Student:")human = new Student("", "", 0, "", "", 0, 0);
	if (type == "Graduate:")human = new Graduate("", "", 0, "", "", 0, 0, "");
	return human;
}
bool CheckType(const std::string& buffer)
{
	return 	buffer.find("Human") == std::string::npos &&
		buffer.find("Student") == std::string::npos &&
		buffer.find("Teacher") == std::string::npos &&
		buffer.find("Graduate") == std::string::npos;
}
Human** Read_From_File(const std::string& file_name, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(file_name);
	if (fin.is_open())
	{
		//1. Вычислим размер файла (Количество записей в файле):
		n = 0;
		while (!fin.eof())
		{
			std::string buffer;
			std::getline(fin, buffer);	//Читает всю строку
			if (CheckType(buffer))continue;
			n++;
		}
		cout << "Количество записей в файле:" << n << endl;
		//2. Выделяем память для группы:
		group = new Human * [n] {};

		//3. Возвращаемся в начло файла, для того чтобы прочитать содержимое этого файла
		cout << "Позиция курсора на чтение: " << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "Позиция курсора на чтение: " << fin.tellg() << endl;

		//4. Читаем файл:
		for (int i = 0; i < n; i++)
		{
			std::string type;
			fin >> type;
			if (CheckType(type))continue;
			group[i] = HumanFarctory(type);
			if (group[i])fin >> *group[i];
		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	return group;
}

void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
}