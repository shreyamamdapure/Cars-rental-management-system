#ifndef FUNCTIONS_CARMANAGEMENT_H
#define FUNCTIONS_CARMANAGEMENT_H

#include <vector>

#include "Class_CarManagement.h"
#include "subscribersmanagement.h"

void addCar(std::vector<Car> &cars,std::vector<Car> &carList);
void removeCar(std::vector<Car> &carList);
void manageCar(std::vector<Car> &cars,std::vector<Car> &carList);
void manageSubscriber(CarRentalSystem &carRentalSystem);
void manageSubscription();
void reports(std::vector<Car> &cars,std::vector<Car> &carList, std::vector<Subscriber> &subscribers);

#endif
