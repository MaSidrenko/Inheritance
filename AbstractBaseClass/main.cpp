#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class Vehicle
{
	int speed;
public:
	//		Methods: 
	virtual void move() = 0;
};

class GroundVehicle :public Vehicle {};
class AirVehicle: public Vehicle 
{
public:
	virtual void top_up() = 0;	//����
	virtual void land() = 0;	//��������
};

class Bike :public GroundVehicle
{
public:
	void move()override
	{
		cout << "Harley Davidson ���� �� ���� �������" << endl;
	}
};
class Car : public GroundVehicle
{
public:
	void move()override
	{
		cout << "BMW ���� �� ������� �������" << endl;
	}
};

class AirPlane : public AirVehicle
{
public:
	void move()override
	{
		top_up();
		cout << "����� ����������!" << endl;
		land();
	}
	void top_up()override
	{
		cout << "����� ������� ������" << endl;
	}
	void land()override
	{
		cout << "����� ���������� ������" << endl;
	}
};
class Helicopter : public AirVehicle
{
public:
	void move()override
	{
		top_up();
		cout << "���� � �����!" << endl;
		land();
	}
	void top_up ()override
	{
		cout << "���������� ���������� ��������!" << endl;
	}
	void land()override
	{
		cout << "���������� ���������� ��������!" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle vehicle;
	//GroundVehicle gv;
	Bike harley_davidson;
	harley_davidson.move();

	Car bmw;
	bmw.move();

	AirPlane Boeing;
	Boeing.move();

	Helicopter backHawk;
	backHawk.move();
}