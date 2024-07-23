#include<Windows.h>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
 
#define delimiter "\n|----------------------------------------------------|\n"

namespace Geometry
{
	enum Color
	{
		CONSOLE_RED		= 0xCC, //Страшая 'C' - цвет фона, младшая 'C' - цвет текста.
		CONSOLE_GREEN	= 0xAA,
		CONSOLE_BLUE	= 0x99,
		CONSOLE_DEFAULT = 0x07
	};

	class Shape
	{
	protected:
		Color color;
	public:
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		Shape(Color color) : color(color) {}
		virtual ~Shape() {}
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}
	};

	class Square :public Shape
	{
		double side;
	public:
		Square(double side, Color color) : Shape(color)
		{
			set_side(side);
		}
		~Square() {}
		void set_side(double side)
		{
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна стороны: " << get_side() << endl;
			Shape::info();
		}
	};

	class Rectangle : public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, Color color) : Shape(color)
		{
			set_widht(width);
			set_height(height);
		}
		~Rectangle() {}
		void set_widht(double width)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return 2 * (width + height);
		}
		void draw()const override
		{
			//WinGDI - Windows Graphics Device Interface
			//1. Получаем окно консоли:
			//HWND hwnd = GetConsoleWindow(); // Ф-ция GetConsoleWindow() получает окно консоли
			//2. Для того что бы рисовать, нужен контекст устроиства (Device Context), который есть у каждого окна 
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			// Констекст устройства можно получить при помощи ф-ции GetDC()
			HDC hdc = GetDC(hwnd); //Получаем контекст окна консоли
			//Контекст устройства - это то, на чем мы будем рисовать.

			//3. Теперь нам нужно то, чем мы будем рисовать: 
			HPEN hPen = CreatePen(PS_SOLID, 5, color); //hPen	  - рисует контур фигуры;
													   //PS_SOLID - сплошная линия
													   // 5		  - толщина линии 5 пикселов
			HBRUSH hBrush = CreateSolidBrush(color);   //hBrush	  - рисует заливку фигуры(SolidBrush - это сплощной цвет)

			//4. Выбираем чем, и на чем мы будем рисовать: 
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//5. Рисуем фигуру: 
			::Rectangle(hdc, 100, 100, 500, 300);		//:: - Global Scope (Глобальное пространство имен)

			//6. hdc, hPen и hBrush занимают ресуры, и после того как мы ими воспользовались, ресурсы необходимо освободить
			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника: " << get_width() << endl;
			cout << "Высота прямоугольника: " << get_height() << endl;
			Shape::info();
		}
	};

	class Triangle : public Shape
	{
		//Стороны треугольника:
		double side_a;
		double side_b;
		double side_c;
	public:
		Triangle(double side_a, double side_b, double side_c, Color color) : Shape(color)
		{
			set_side_a(side_a);
			set_side_b(side_b);
			set_side_c(side_c);
		}
		~Triangle() {};
		void set_side_a(double side_a)
		{
			this->side_a = side_a;
		}
		void set_side_b(double side_b)
		{
			this->side_b = side_b;
		}
		void set_side_c(double side_c)
		{
			this->side_c = side_c;
		}
		double get_side_a()const
		{
			return side_a;
		}
		double get_side_b()const
		{
			return side_b;
		}
		double get_side_c()const
		{
			return side_c;
		}
		double get_area()const override
		{
			return sqrt((get_perimeter() / 2) * ((get_perimeter() / 2) - side_a) * ((get_perimeter() / 2) - side_b) * ((get_perimeter() / 2) - side_c));
		}
		double get_perimeter()const override
		{
			return side_a + side_b + side_c;
		}
		void draw()const override
		{
			for (int i = 0; i < get_perimeter(); i++)
			{
				for (int j = i; j < get_perimeter(); j++)
				{
					cout << " ";
				}
				for (int j = 0; j < i; j++)
				{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, color);
					cout << "* ";
				SetConsoleTextAttribute(hConsole, Color::CONSOLE_DEFAULT);
				}
				cout << endl;
			}
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна стороны a: " << get_side_a() << endl;
			cout << "Длинна стороны b: " << get_side_b() << endl;
			cout << "Длинна стороны c: " << get_side_c() << endl;
			Shape::info();
		}
	};
	class Cricle : public Shape
	{
		double radius;
	public:
		Cricle(double radius, Color color) : Shape(color)
		{
			set_radius(radius);
		}
		void set_radius(int radius)
		{
			this->radius = radius;
		}
		double get_radius()
		{
			return radius;
		}
		double get_area()const override
		{
			return 3.14 * (radius * radius);
		}
		double get_perimeter()const override
		{
			return 2 * 3.14 * radius;
		}
		void draw()const override
		{
	
		}
		void info()const override
		{

		}

	};
}



void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square square(5, Geometry::Color::CONSOLE_RED);
	//cout << "Длина стороны: " << square.get_side() << endl;
	//cout << "Площадь квадрата: " << square.get_area() << endl;
	//cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	//square.draw();
	square.info();
	cout << delimiter << endl;
	Geometry::Rectangle rect(100, 50, Geometry::Color::CONSOLE_BLUE);
	rect.info();
	cout << delimiter << endl;
	Geometry::Triangle triangle(5, 5, 10, Geometry::Color::CONSOLE_GREEN);
	triangle.info();
	cout << delimiter << endl;
	Geometry::Cricle circle(5, Geometry::Color::CONSOLE_BLUE);
	circle.draw();

}