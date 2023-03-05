// Figures. Methods.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<string>
#include <iostream>
class Figure
{
protected:
	std::string nameOfFigure = "фигура";
	bool checkFigure = false;
	int quantityOfSides = 0;
	int haveSides = 0;
	int sideLengthA = 0;
	int sideLengthB = 0;
	int sideLengthC = 0;
	int sideLengthD = 0;
	int angleA = 0;
	int angleB = 0;
	int angleC = 0;
	int angleD = 0;
	virtual bool metodCheckFigure()
	{
		if (quantityOfSides == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	};
public:
	std::string getNameOfFigure() { return nameOfFigure; }
	int getSides() { return haveSides; }

	int getSideLengthA() { return sideLengthA; }
	int getSideLengthB() { return sideLengthB; }
	int getSideLengthC() { return sideLengthC; }
	int getSideLengthD() { return sideLengthD; }

	int getAngleA() { return angleA; }
	int getAngleB() { return angleB; }
	int getAngleC() { return angleC; }
	int getAngleD() { return angleD; }

	virtual void printFigure() //Виртуальный метод печати и проверка правильности фигуры
	{
		std::cout << std::endl;
		std::cout << nameOfFigure << ":" << std::endl;
		if (metodCheckFigure())
		{
			std::cout << "Правильная" << std::endl;
		}
		else { std::cout << "Неправильная" << std::endl; }

		std::cout << "Количество сторон: " << quantityOfSides << std::endl;
	}
};
class Triangle : public Figure
{
protected:
	bool metodCheckFigure() override //Переписанный метод проверки на сумма всех углов треуг == 180
	{
		if ((angleA + angleB + angleC) == 180)
		{
			return true;
		}
		else
		{
			return false;
		}
	};


public:
	Triangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
	{
		nameOfFigure = "Треугольник";
		this->sideLengthA = sideLengthA;
		this->sideLengthB = sideLengthB;
		this->sideLengthC = sideLengthC;
		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		quantityOfSides = 3;
		checkFigure = metodCheckFigure();
	}
	void printFigure() override //Переписанный метод печати с вызовом базового метода печати
	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << getSideLengthA() << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << std::endl;
	}

};
class rightTriangle : public Triangle
{
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (angleC == 90))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	rightTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Прямоугольный треугольник";
	};
};
class isoscelesTriangle : public Triangle
{
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (sideLengthA == sideLengthC && angleA== angleC))
		{
			return true;
		}
		else
		{
			return false;
		};
	};

public:
	isoscelesTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC): Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure = "Равнобедренный треугольник";
	};
};

class equilateralTriangle : public Triangle
{
private:
	bool CheckEquilateralTriangle()
	{
		if ((sideLengthA == sideLengthB && sideLengthB == sideLengthC) && ((angleA == 60) && (angleA = 60) && (angleC = 60)))
		{
			return true;
		}
		else
		{
			return false;
		};
	}

public:
	equilateralTriangle(int sideLengthA, int sideLengthB, int sideLengthC, int angleA, int angleB, int angleC)
		: Triangle(sideLengthA, sideLengthB, sideLengthC, angleA, angleB, angleC)
	{
		Triangle::nameOfFigure= "Равносторонний треугольник";
	};
protected:
	bool metodCheckFigure() override
	{
		if (Triangle::metodCheckFigure() && (CheckEquilateralTriangle()))
		{
			return true;
		}
		else
		{
			return false;
		};
	};



};

class Quadrilateral : public Figure
{
protected:
	virtual bool metodCheckFigure()
	{
		if ((angleA + angleB + angleC + angleD) == 360)
		{
			return true;
		}
		else
		{
			return false;
		}
	};


	bool metodCheckSideLengthACiBD()
	{
		if (sideLengthA == sideLengthC && sideLengthB == sideLengthD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	bool metodCheckSideLengthACBD()
	{
		if (sideLengthA == sideLengthB && sideLengthB == sideLengthC && sideLengthC == sideLengthD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	
	bool metodCheckAngleabcd90()
	{
		if (angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	bool metodCheckAngleACiBD()
	{
		if (angleA == angleC&& angleB == angleD)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Quadrilateral(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
	{
		nameOfFigure = "Четырехугольник";

		quantityOfSides = 4;
		this->sideLengthA = sideLengthA;
		this->sideLengthB = sideLengthB;
		this->sideLengthC = sideLengthC;
		this->sideLengthD = sideLengthD;

		this->angleA = angleA;
		this->angleB = angleB;
		this->angleC = angleC;
		this->angleD = angleD;
	}

	void printFigure() override
	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << getSideLengthA() << ", b = " << getSideLengthB() << ", с = " << getSideLengthC();
		std::cout << ", d = " << getSideLengthD() << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getAngleA() << ", В = " << getAngleB() << ", С = " << getAngleC();
		std::cout << ", D = " << getAngleD() << std::endl;
	}

};

class Rectangle : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	};

public:
	Rectangle(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	Square(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Parallelogram(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
protected:
	bool metodCheckFigure() override
	{
		if (Quadrilateral::metodCheckFigure() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleACiBD())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Rhomb(int sideLengthA, int sideLengthB, int sideLengthC, int sideLengthD, int angleA, int angleB, int angleC, int angleD)
		: Quadrilateral(sideLengthA, sideLengthB, sideLengthC, sideLengthD, angleA, angleB, angleC, angleD)
	{
		Quadrilateral::nameOfFigure = "Ромб";
	}
};
int main()
{
	setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
	system("chcp 1251");

	Figure Figure1;
	Figure1.printFigure();

	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	Triangle1.printFigure();

	rightTriangle rightTriangle1(10, 20, 30, 50, 60, 90);
	rightTriangle1.printFigure();

	rightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);
	rightTriangle2.printFigure();

	isoscelesTriangle isoscelesTriangle1(10, 20, 10, 50, 60, 90);
	isoscelesTriangle1.printFigure();

	equilateralTriangle equilateralTriangle1(30, 30, 30, 60, 60, 60);
	equilateralTriangle1.printFigure();

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	Quadrilateral1.printFigure();

	Rectangle Rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
	Rectangle1.printFigure();

	Square Square1(20, 20, 20, 20, 90, 90, 90, 90);
	Square1.printFigure();

	Parallelogram Parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
	Parallelogram1.printFigure();

	Rhomb Rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
	Rhomb1.printFigure();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
