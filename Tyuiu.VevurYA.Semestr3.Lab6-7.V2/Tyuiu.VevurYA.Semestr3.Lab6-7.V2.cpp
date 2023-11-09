#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <Windows.h>
using namespace std;

// всё что дальше - моя шиза.


// Базовый класс "Двигатель"
class Engine
{
protected:
	double* engineVolume;
	double* fuelConsumption;
public:
	Engine()
	{
		engineVolume = new double;
		fuelConsumption = new double;
	}
	
	Engine(double _engineVolume, double _fuelConsumption)
	{
		engineVolume = new double;
		*engineVolume = _engineVolume;
		fuelConsumption = new double;
		*fuelConsumption = _fuelConsumption;
	}

	~Engine()
	{
		delete engineVolume, fuelConsumption;
	}

	virtual void print() = 0;
};

// Базовый класс "Кузов"
class Chasis
{
protected:
	string* name;
	string* type;
	int* year;
	double* fuelCapacity;
public:
	Chasis()
	{
		name = new string;
		type = new string;
		year = new int;
		fuelCapacity = new double;
	}

	Chasis(string _name, string _type, int _year, double _fuelCapacity)
	{
		name = new string;
		*name = _name;
		type = new string;
		*type = _type;
		year = new int;
		*year = _year;
		fuelCapacity = new double;
		*fuelCapacity = _fuelCapacity;
	}

	~Chasis()
	{
		delete name, type, year, fuelCapacity;
	}

	virtual void print() = 0;
};


class Transport : protected Engine, protected Chasis
{
private:
		double* maxSpeed;

public:
	Transport() :Engine(), Chasis() 
	{
		maxSpeed = new double;
	}

	Transport(string _name, string _type, int _year, double _maxSpeed, double _engineVolume, double _fuelConsumption, double _fuelCapacity)
		:Engine(_engineVolume, _fuelConsumption), Chasis(_name, _type, _year, _fuelCapacity) 
	{
		maxSpeed = new double;
		*maxSpeed = _maxSpeed;
	};

	~Transport() 
	{
		delete maxSpeed;
	}

	virtual void print() override
	{
		cout << "Наименование: " << *name << endl;
		cout << "Тип кузова: " << *type << endl;
		cout << "Год:" << *year << endl;
		cout << "Макс. скорость: " << *maxSpeed << " км/ч." << endl;
		cout << "Объем двигателя: " << *engineVolume << " л." << endl;
		cout << "Расход топлива: " << *fuelConsumption << " л/км." << endl;
		cout << "Объем бензобака: " << *fuelCapacity << " л." << endl;
	}

	double Run()
	{
		return *fuelCapacity / (*fuelConsumption / 100.0);
	}

	friend istream& operator>>(istream& in, Transport& transport);
	friend ostream& operator<<(ostream& out, Transport& transport);
	friend ofstream& operator<<(ofstream& fout, Transport& transport);
};

istream& operator>>(istream& in, Transport& transport)
{
	// Ввод информации о транспорте
	cout << "Введите наименование: ";
	in >> *transport.name;
	cout << "Введите тип: ";
	in >> *transport.type;
	cout << "Введите год выпуска: ";
	in >> *transport.year;
	cout << "Введите максимальную скорость: ";
	in >> *transport.maxSpeed;
	cout << "Введите объем двигателя: ";
	in >> *transport.engineVolume;
	cout << "Введите расход топлива: ";
	in >> *transport.fuelConsumption;
	cout << "Введите объем бензобака: ";
	in >> *transport.fuelCapacity;

	return in;
}

ostream& operator<<(ostream& out, Transport& transport)
{
	out << "Наименование: " << * transport.name << endl;
	out << "Тип кузова: " << * transport.type << endl;
	out << "Год:" << * transport.year << endl;
	out << "Макс. скорость: " << *transport.maxSpeed << " км/ч." << endl;
	out << "Объем двигателя: " << * transport.engineVolume << " л." << endl;
	out << "Расход топлива: " << * transport.fuelConsumption << " л/км." << endl;
	out << "Объем бензобака: " << * transport.fuelCapacity << " л." << endl;
	return out;
}

ofstream& operator<<(ofstream& fout, Transport& transport)
{
	fout << "Наименование: \t" << *transport.name << endl;
	fout << "Тип кузова: \t" << *transport.type << endl;
	fout << "Год выпуска: \t" << *transport.year << endl;
	fout << "Макс. скорость: " << *transport.maxSpeed << " км/ч." << endl;
	fout << "Объем двигателя: " << *transport.engineVolume << " л." << endl;
	fout << "Расход топлива: " << *transport.fuelConsumption << " л/км." << endl;
	fout << "Объем бензобака: " << *transport.fuelCapacity << " л." << endl;
	
	return fout;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	try {
		Transport* transport = new Transport;
		cin >> *transport;
		cout << "Информация о введенном транспорте: " << endl;
		cout << *transport;
		//cout << "Print method:\n"; transport->print();
		ofstream fout("output.txt", ios::out);
		if (!fout) {
			throw runtime_error("Ошибка открытия файла.");
		}
		else
		{
			fout << *transport;
		}
		cout << "Макимальное расстояние без дозаправок: " << transport->Run() << endl;
	}
	catch (const exception& e)
	{
		cerr << "ОШИБКА" << e.what() << endl;
	}
}
