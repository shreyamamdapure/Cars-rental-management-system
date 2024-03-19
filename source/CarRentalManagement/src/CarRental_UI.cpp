#include <iostream>
#include <vector>
#include <string>

#include "Class_CarManagement.h"
#include "functions_CarManagement.h"
//#include "subscribersmanagement.cpp"
//#include "subscribersmanagement.h"
//#include "report_display.cpp"
//#include "SubscriptionManagement.cpp"
using namespace std;

vector<Car> cars;
vector<Car> carList;
vector<Subscriber> subscriber;
CarRentalSystem carRentalSystem;
int main() {
	cout << "----------------------" << endl;
	cout << "Company Name : RapidRentals" << endl;
	cout << "----------------------" << endl;

	int choice;

	while (true) {
		cout << "Main Menu:\n";
		cout << "1. Manage Car\n";
		cout << "2. Manage Subscriber\n";
		cout << "3. Manage Subscription\n";
		cout << "4. Reports\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			manageCar(cars,carList);
			break;
		case 2:
			manageSubscriber(carRentalSystem);
			break;
		case 3:
			manageSubscription();
			break;
		case 4:
			reports(cars,carList, subscriber);
			break;
		case 5:
			cout << "Exiting program...\n";
			return 0;
		default:
			cout << "Invalid choice!\n";
		}
	}

	return 0;
}

