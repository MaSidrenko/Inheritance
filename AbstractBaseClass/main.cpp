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
	virtual void top_up() = 0;	//Взлёт
	virtual void land() = 0;	//Поскадка
};

class Bike :public GroundVehicle
{
public:
	void move()override
	{
		cout << "Harley Davidson едет на двух колесах" << endl;
	}
};
class Car : public GroundVehicle
{
public:
	void move()override
	{
		cout << "BMW едет на четырех колесах" << endl;
	}
};

class AirPlane : public AirVehicle
{
public:
	void move()override
	{
		top_up();
		cout << "Полет нормальный!" << endl;
		land();
	}
	void top_up()override
	{
		cout << "Нужна взлётная полоса" << endl;
	}
	void land()override
	{
		cout << "Нужна посадочная полоса" << endl;
	}
};
class Helicopter : public AirVehicle
{
public:
	void move()override
	{
		top_up();
		cout << "Полёт в норме!" << endl;
		land();
	}
	void top_up ()override
	{
		cout << "Необходима вертолётная площадка!" << endl;
	}
	void land()override
	{
		cout << "Необходима вертолётная площадка!" << endl;
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