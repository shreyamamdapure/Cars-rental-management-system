#include <iostream>
#include <vector>
#include <string>
#include "functions_CarManagement.cpp"

using namespace std;
void bill(vector<int> &amount, int tot) {
	amount.push_back(tot);
}

void rentedCars(vector<Car> &cars, vector<Car> &rentedCar, int choice) {
	Car obj;
	obj.brand = cars[choice - 1].brand;
	obj.model = cars[choice - 1].model;
	obj.registrationNumber = cars[choice - 1].registrationNumber;
	rentedCar.push_back(obj);
}

void displayRentedCar(const vector<Car> &rentedCar) {

	cout << "List of Cars:" << endl;
	int i = 1;

	for (const auto &car : rentedCar) {
		cout << i << " " << "Brand: " << car.brand << ", Model: " << car.model
				<< ", Registration Number: " << car.registrationNumber << endl;
		i++;
	}
}
void displayBill(const vector<int> &amount) {

	cout << "List of Cars:" << endl;
	int i = 1;

	for (const auto &car : amount) {
		cout << i << " " << "Bill: " << car << endl;
		i++;
	}
}
void func(vector<Car> &cars, int choice) {
	cout << "\t\t Car rented Succesfully" << endl;
	cout << "\t\t-----------------------------" << endl;
	cout << "\t\t Brand:" << cars[choice - 1].brand << endl;
	cout << "\t\t Model:" << cars[choice - 1].model << endl;
	cout << "\t\t Registration No:" << cars[choice - 1].registrationNumber
			<< endl;
	cout << "\t\t Price:" << cars[choice - 1].price << endl;
	cout << "\t\t-----------------------------" << endl;
	cout << "\t\t Thank You for choosing our system" << endl;
	cout << "\t\t-----------------------------" << endl;
}
void _extendRental(vector<Car> &cars, vector<int> amount) {
	string brand, regNo;
	cout << "Enter the brand of the car:" << endl;
	cin >> brand;
	cout << "Enter the registration number of the car that you have rented:"
			<< endl;
	extendRental(cars, amount, brand, regNo);
}
void _returnCar(vector<Car> &cars, vector<int> amount) {
	string brand, regNo;
	cout << "Enter the brand of the car:" << endl;
	cin >> brand;
	cout << "Enter the registration number of the car that you have rented:"
			<< endl;
	cin >> regNo;
	returnCar(cars, amount, brand, regNo);
}
void _rentCar(vector<Car> &cars, vector<Car> &rentedCar, vector<int> amount) {
	cout << "Enter your subscriber level:" << endl;
	string subscriberLevel;
	cin >> subscriberLevel;
	rentCar(cars, rentedCar, amount, subscriberLevel);
}
