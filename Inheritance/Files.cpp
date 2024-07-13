#include<iostream>
#include<fstream>

using std::cout;
using std::cin;
using std::endl;

//#define WRITE_TO_FILE
#define READ_FROW_FILE

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello Files" << endl;

#ifdef WRITE_TO_FILE
	std::ofstream fout;							//1. Создаем поток
	fout.open("File.txt", std::ios_base::app);	//2. Открываем поток (При откритии потока, 
	//	 мы казываем в какой именно файл мы будем будем писать)
	//	 std::ios_base::app (append) - дописывать в конец файла
	fout << "Hello Files" << endl;				//3. Пишем в поток
	fout << "Привет!" << endl;
	fout.close();								//4. Закрываем поток (Потоки обязательно нужно закрывать,
	//	 если не закрывать потоки, это может привести к
	//	 непредвиденным последствиям)
	//	 (Behaviour is undefier)
	system("notepad File.txt");
#endif // WRITE_TO_FILE

	std::ifstream fin("File.txt");					//1. Создание и открытие потока можно совместить
	if (fin.is_open())								//2. При чтении обязательно нужно прверять, открылся поток или нет
	{
		while (!fin.eof())//eof(End of file)		//3. Чтение из файла
		{
			const int SIZE = 402884;
			char buffer[SIZE]{};
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close();								//4. Поток есть смысл закрывать только в том случае, если он был открыт
	}
	else
	{
		std::cerr << "Error File not found" << endl;
	}
}