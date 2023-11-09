#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <Windows.h>
using namespace std;

// всё что дальше - моя шиза.

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
		cout << *name << endl;
		cout << *type<< endl;
		cout << *year << endl;
		cout << *maxSpeed << endl;
		cout << *engineVolume << endl;
		cout << *fuelConsumption << endl;
		cout << *fuelCapacity << endl;
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
	out << "Макс. скорость: " << *transport.maxSpeed << endl;
	out << "Объем двигателя: " << * transport.engineVolume << endl;
	out << "Расход топлива: " << * transport.fuelConsumption << endl;
	out << "Объем бензобака: " << * transport.fuelCapacity << endl;
	return out;
}

ofstream& operator<<(ofstream& fout, Transport& transport)
{
	fout << "Наименование: \t" << *transport.name << endl;
	fout << "Тип кузова: \t" << *transport.type << endl;
	fout << "Год выпуска: \t" << *transport.year << endl;
	fout << "Макс. скорость: \t" << *transport.maxSpeed << endl;
	fout << "Объем двигателя: \t" << *transport.engineVolume << endl;
	fout << "Расход топлива: \t" << *transport.fuelConsumption << endl;
	fout << "Объем бензобака: \t" << *transport.fuelCapacity << endl;
	
	return fout;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	Transport* transport = new Transport;
	cin >> *transport;
	cout << *transport;
	//transport->print();
	ofstream fout("output.txt", ios::out);
	if (!fout) {
		cout << "ERROR" << endl;
	}
	else
	{
		fout << *transport;
	}
	cout << "Run: " << transport->Run();
}








// это шиза уже из gpt

//class Transport;
//
//istream& operator>>(istream& in, Transport& transport);
//ostream& operator<<(ostream& out, const Transport& transport);
//fstream& operator<<(fstream& file, const Transport& transport);
//
//class Engine {
//protected:
//    double engineVolume;
//    double fuelConsumption;
//
//public:
//    Engine() : engineVolume(0.0), fuelConsumption(0.0) {}
//    Engine(double _engineVolume, double _fuelConsumption)
//        : engineVolume(_engineVolume), fuelConsumption(_fuelConsumption) {}
//
//    virtual ~Engine() {}
//
//    virtual void print() = 0;
//    friend istream& operator>>(istream& in, Engine& engine);
//    friend ostream& operator<<(ostream& out, const Engine& engine);
//};
//
//class Chasis {
//protected:
//    string name;
//    string type;
//    int year;
//    double fuelCapacity;
//
//public:
//    Chasis() : name(""), type(""), year(0), fuelCapacity(0.0) {}
//
//    Chasis(const std::string& _name, const std::string& _type, int _year, double _fuelCapacity)
//        : name(_name), type(_type), year(_year), fuelCapacity(_fuelCapacity) {}
//
//    virtual ~Chasis() {}
//
//    virtual void print() = 0;
//    friend istream& operator>>(istream& in, Chasis& chasis);
//    friend ostream& operator<<(ostream& out, const Chasis& chasis);
//};
//
//class Transport : protected Engine, protected Chasis {
//public:
//    Transport() : Engine(), Chasis() {}
//
//    Transport(const std::string& _name, const std::string& _type, int _year, double _engineVolume, double _fuelConsumption, double _fuelCapacity)
//        : Engine(_engineVolume, _fuelConsumption), Chasis(_name, _type, _year, _fuelCapacity) {}
//
//    virtual void print() override {
//        cout << "Наименование: " << name << endl;
//        cout << "Тип: " << type << endl;
//        cout << "Год выпуска: " << year << std::endl;
//        cout << "Объем двигателя: " << engineVolume << " л" << endl;
//        cout << "Расход топлива: " << fuelConsumption << " л/100 км" << endl;
//        cout << "Объем бензобака: " << fuelCapacity << " л" << endl;
//    }
//
//    double Run() const{
//        return fuelCapacity / (fuelConsumption / 100.0); // Расстояние без подзаправок в км
//    }
//
//    friend istream& operator>>(istream& in, Transport& transport);
//    friend ostream& operator<<(ostream& out, const Transport& transport);
//    friend fstream& operator<<(fstream& file, const Transport& transport);
//};
//
//istream& operator>>(istream& in, Engine& engine) {
//    in >> engine.engineVolume >> engine.fuelConsumption;
//    return in;
//}
//
//ostream& operator<<(ostream& out, const Engine& engine) {
//    out << "Объем двигателя: " << engine.engineVolume << " л" << endl;
//    out << "Расход топлива: " << engine.fuelConsumption << " л/100 км" << endl;
//    return out;
//}
//
//istream& operator>>(istream& in, Chasis& chasis) {
//    in >> chasis.name >> chasis.type >> chasis.year >> chasis.fuelCapacity;
//    return in;
//}
//
//ostream& operator<<(ostream& out, const Chasis& chasis) {
//    out << "Наименование: " << chasis.name << endl;
//    out << "Тип: " << chasis.type << endl;
//    out << "Год выпуска: " << chasis.year << endl;
//    out << "Объем бензобака: " << chasis.fuelCapacity << " л" << endl;
//    return out;
//}
//
//istream& operator>>(istream& in, Transport& transport) {
//    in >> static_cast<Engine&>(transport) >> static_cast<Chasis&>(transport);
//    return in;
//}
//
//ostream& operator<<(ostream& out, const Transport& transport) {
//    static_cast<const Engine&>(transport);
//    static_cast<const Chasis&>(transport);
//    out << "Расстояние без подзаправок: " << transport.Run() << " км" << endl;
//    return out;
//}
//
//fstream& operator<<(fstream& file, const Transport& transport) {
//    static_cast<const Engine&>(transport);
//    static_cast<const Chasis&>(transport);
//    file << "Расстояние без подзаправок: " << transport.Run() << " км" << endl;
//    return file;
//}
//
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    setlocale(0, "");
//    try {
//        Transport* ae86 = new Transport;
//
//        cout << "Введите информацию о транспорте:" << endl;
//        cin >> *ae86;
//
//        ofstream outFile("transport_info.txt");
//        if (!outFile.is_open()) {
//            throw runtime_error("Не удалось открыть файл для записи.");
//        }
//
//        cout << "Информация о транспорте:" << endl;
//        cout << *ae86;
//
//        outFile << "Информация о транспорте:" << endl;
//        outFile << *ae86;
//
//        cout << "Расстояние без подзаправок: " << ae86->Run() << " км" << endl;
//
//        outFile << "Расстояние без подзаправок: " << ae86->Run() << " км" << endl;
//
//        outFile.close();
//        cout << "Информация сохранена в файле 'transport_info.txt'." << endl;
//
//        delete ae86; // Освобождаем выделенную память
//    }
//    catch (const exception& e) {
//        cerr << "Ошибка: " << e.what() << endl;
//    }
//
//    return 0;
//}