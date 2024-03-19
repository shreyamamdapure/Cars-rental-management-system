#include <iostream>
#include <vector>
#include <string>
#include "SubscriptionManagement.h"
#include "subscribersmanagement.h"
#include "functions_CarManagement.h"
using namespace std;
//extern vector<Subscriber> subscribers;
void display_Cars(const vector<Car> &carList) {
	cout << "List of Cars:" << endl;
	for (const auto &car : carList) {
		cout << "Brand: " << car.brand << ", Model: " << car.model
				<< ", Registration Number: " << car.registrationNumber << endl;
	}
}

void displayRentedCars(const vector<Car> &RentedCar) {
	cout << "List of Rented Cars:" << endl;
	for (const auto &car : RentedCar) {
		cout << "Brand: " << car.brand << ", Model: " << car.model
				<< ", Registration Number: " << car.registrationNumber << endl;
	}
}

void displaySubscribers(const vector<Subscriber> &subscribers) {

	cout << "List of Subscribers:" << endl;
	/*for (const auto &Subscriber : subscribers) {
		cout << "Name " << Subscriber.getName() << ", Subscription level    : "
				<< CarRentalSystem::levelToString(Subscriber.getLevel())
				<< endl;
	}*/
	for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
			//if (it->getID() == id) {
				//std::cout << "Subscriber removed successfully:" << std::endl;
				//std::cout<<"tes"<<endl;
				std::cout << "Name: " << it->getName() << std::endl;
				std::cout << "ID: " << it->getID() << std::endl;
				//std::cout << "Subscription Level: " << levelToString(it->getLevel())<< std::endl;
				//subscribers.erase(it);
	return;
			//}

}
}
void displayRevenue(const vector<int> &amount) {
	int sum_total = 0;
	cout << "The total revenue" << endl;
	for (const auto &car : amount) {
		sum_total += car;
	}
	cout << sum_total << endl;
}

