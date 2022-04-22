#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Car {
	string name;
	string color;
	int engine_volume;
	int price;

	static int counter;
};

int Car::counter = 0;

void showCar(Car& car) {
	cout << car.name << "\t" << car.color << "\t" << car.engine_volume << "\t" << car.price << endl;
}

void showCars(Car*& cars) {
	for (int i = 0; i < Car::counter; i++) {
		showCar(cars[i]);
	}
}

void addCar(Car*& cars, Car car){
	Car* buf = new Car[++Car::counter];
	for (int i = 0; i < Car::counter-1; i++) buf[i] = cars[i];
	buf[Car::counter - 1] = car;
	delete[] cars;
	cars = buf;
}

void delCar(Car*& cars) {
	Car* buf = new Car[--Car::counter];
	for (int i = 0; i < Car::counter; i++) buf[i] = cars[i];
	delete[] cars;
	cars = buf;
}

Car* reallocCar(Car*& cars, int size) {
	Car* buf = new Car[size];
	for (int i = 0; i < Car::counter; i++) buf[i] = cars[i];
	Car::counter = size;
	delete[] cars;
	cars = buf;
	return cars;
}

int strToInt(string str) {
	int num = (int)str[0]-48;
	for (int i = 1; i < str.length(); i++) {
		num = (num * 10) + (str[i] - 48);
	}
	return num;
}

Car* readCarFiles(string path) {
	ifstream in{path};
	Car* cars = new Car[0];
	string str = "";
	int counter = 0;
	while (getline(in, str)) {
		string* words = new string[4];
		string temp = "";
		for (int i = 0, k = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				words[k] = temp;
				temp = "";
				k++;
			}
			else {
				temp += to_string(str[i]);
			}
		}
		cars = reallocCar(cars, Car::counter + 1);
		cars[counter] = { words[0], words[1], strToInt(words[2]), strToInt(words[3]) };
	}
}

int main()
{
	string path = "C:\\Users\\Взрослая академия\\Desktop\\boom.negr";
	cout << strToInt("485");
}