#define _USE_MATH_DEFINES
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
		RED = 0x000000FF,
		GREEN = 0x0000FF00,
		BLUE = 0x00FF0000,
		YELLOW = 0x000055FF,
		CONSOLE_RED = 0xCC, //Страшая 'C' - цвет фона, младшая 'C' - цвет текста.
		CONSOLE_GREEN = 0xAA,
		CONSOLE_BLUE = 0x99,
		CONSOLE_DEFAULT = 0x07
	};
#define SHAPE_TAKE_PARAMETERS unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color
	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		Color color;
		static const int MIN_START_X = 100;
		static const int MAX_START_X = 1000;
		static const int MIN_START_Y = 50;
		static const int MAX_START_Y = 500;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 32;
		static const int MIN_SIZE = 50;
		static const int MAX_SIZE = 200;
		static int count;
	public:
		//Чисто-виртуальные ф-ции
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		///////////////////////////////////////////////////////////
		Shape(SHAPE_TAKE_PARAMETERS) : color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
			count++;
		}
		virtual ~Shape()
		{
			count--;
		}

		//				Encapsulation:
		int get_count()const
		{
			return count;
		}
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			//if (start_x < 100)start_x = 100;
			//if (start_x > 1000)start_x = 1000;
			this->start_x = start_x < MIN_START_X ? MIN_START_X : start_x > MAX_START_X ? MAX_START_X : start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			//if (start_y < 50)start_y = 50;
			//if (start_y > 500)start_y = 500;
			this->start_y = start_y < MIN_START_Y ? MIN_START_Y : start_y > MAX_START_Y ? MAX_START_Y : start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			this->line_width =
				line_width < MIN_LINE_WIDTH ? MIN_LINE_WIDTH :
				line_width > MAX_LINE_WIDTH ? MAX_LINE_WIDTH :
				line_width;
		}
		int filter_size(int size)const
		{
			return
				size < MIN_SIZE ? MIN_SIZE :
				size > MAX_SIZE ? MAX_SIZE :
				size;
		}
		virtual void info()const
		{
			cout << "Площадь фигуры: " << get_area() << endl;
			cout << "Периметр фигуры: " << get_perimeter() << endl;
			draw();
		}


	};

	int Shape::count = 0;

	/*class Square :public Shape
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
	};*/

	class Rectangle : public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_widht(width);
			set_height(height);
		}
		~Rectangle() {}
		void set_widht(double width)
		{
			this->width = filter_size(width);
		}
		void set_height(double height)
		{
			this->height = filter_size(height);
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
			HPEN hPen = CreatePen(PS_SOLID, line_width, color); //hPen	  - рисует контур фигуры;
			//PS_SOLID - сплошная линия
			// 5		  - толщина линии 5 пикселов
			HBRUSH hBrush = CreateSolidBrush(color);   //hBrush	  - рисует заливку фигуры(SolidBrush - это сплощной цвет)

			//4. Выбираем чем, и на чем мы будем рисовать: 
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//5. Рисуем фигуру: 
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);		//:: - Global Scope (Глобальное пространство имен)

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

	class Square : public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) : Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
	class Triangle : public Shape
	{
	public:
		Triangle(SHAPE_TAKE_PARAMETERS): Shape(SHAPE_GIVE_PARAMETERS) {}
		~Triangle() {}
		virtual double get_heigth_triangle()const = 0;
		void info()const override
		{
			cout << "Высота треугольника: " << get_heigth_triangle() << endl;
			Shape::info();
		}
	};
	class EquilateralTriangle : public Triangle
	{
		double side_a;
	public:
		EquilateralTriangle(double side_a, SHAPE_TAKE_PARAMETERS) : Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side_a(side_a);
		}
		~EquilateralTriangle() {}
		void set_side_a(double side_a)
		{
			this->side_a = side_a;
		}
		double get_side_a()
		{
			return side_a;
		}
		double get_heigth_triangle()const override
		{
			return (side_a * sqrt(3)) / 2;
		}
		double get_area()const override
		{
			return 0.5 * side_a * get_heigth_triangle();
		}
		double get_perimeter()const override
		{
			return 3 * side_a;
		}
		void draw()const override 
		{}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна сторон равностороннего треугольника: " << side_a << endl;
			Triangle::info();
		}
	};
	class IsoscalesTriangle : public Triangle
	{
		double side_a;
		double side_b;
	public:
		IsoscalesTriangle(double side_a, double side_b, SHAPE_TAKE_PARAMETERS) : Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side_a(side_a);
			set_side_b(side_b);
		}
		~IsoscalesTriangle() {}
		void set_side_a(double side_a)
		{
			this->side_a = side_a;
		}
		void set_side_b(double side_b)
		{
			this->side_b = side_b;
		}
		double get_side_a()
		{
			return side_a;
		}
		double get_side_b()
		{
			return side_b;
		}
		double get_heigth_triangle()const override
		{
			return sqrt((side_a * side_a) - (side_b * side_b) / 4);
		}
		double get_area()const override
		{
			return 0.5 * side_b * get_heigth_triangle();
		}
		double get_perimeter()const override
		{
			return 2 * side_a + side_b;
		}
		void draw()const override
		{

		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длинна равных сторон равнобедреннго треугольника: " << side_a << endl;
			cout << "Длинна основания равнобедренного теругольника: " << side_b << endl;
			Triangle::info();
		}
	};
	class RightTriangle : public Triangle
	{
		double side_a;
		double side_b;
		double side_c;
	public:
		RightTriangle(double side_a, double side_b, double side_c, SHAPE_TAKE_PARAMETERS) : Triangle(SHAPE_GIVE_PARAMETERS)
		{
			set_side_a(side_a);
			set_side_b(side_b);
			set_side_c(side_c);
		}
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
		double get_side_a()
		{
			return side_a;
		}
		double get_side_b()
		{
			return side_b;
		}
		double get_side_c()
		{
			return side_c;
		}
	};
	class Cricle : public Shape
	{
		double radius;
	public:
		Cricle(double radius, SHAPE_TAKE_PARAMETERS) : Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		~Cricle() {}
		void set_radius(int radius)
		{
			this->radius = filter_size(radius);
		}
		double get_radius()const
		{
			return radius;
		}
		double get_diameter()const
		{
			return 2 * radius;
		}
		double get_area()const override
		{
			return  M_PI * (radius * radius);
		}
		double get_perimeter()const override
		{
			return M_PI * get_diameter();
		}
		void draw()const override
		{
			HWND hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			//Очищаем ресурсы: 
			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);

		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Радиус круга: " << get_radius() << endl;;
			cout << "Диаметр круга: " << get_diameter() << endl;
			Shape::info();
		}

	};
}



void main()
{
	setlocale(LC_ALL, "");
	Geometry::Square square(5000, 100, 100, 5, Geometry::Color::RED);
	//cout << "Длина стороны: " << square.get_side() << endl;
	//cout << "Площадь квадрата: " << square.get_area() << endl;
	//cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	//square.draw();
	square.info();
	cout << delimiter << endl;
	Geometry::Rectangle rect(10000, 5000, 5000, 100, 100, Geometry::Color::BLUE);
	rect.info();
	cout << delimiter << endl;
	//Geometry::Triangle triangle(5, 5, 5, Geometry::Color::GREEN);
	//triangle.info();
	cout << delimiter << endl;
	Geometry::Cricle disk(3600, 500, 100, 5, Geometry::Color::YELLOW);
	disk.info();
	cout << delimiter << endl;
	Geometry::EquilateralTriangle equilateral_triangle(5, 200, 300, 10, Geometry::Color::GREEN);
	equilateral_triangle.info();
	cout << delimiter << endl;

	Geometry::IsoscalesTriangle isoscales_triangle(10, 5, 100, 50, 15, Geometry::Color::BLUE);
	isoscales_triangle.info();
	cout << delimiter << endl;
	
	cout << "Количество фигур: " << disk.get_count() << endl;
}