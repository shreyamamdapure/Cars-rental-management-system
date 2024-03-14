#ifndef FUNCTIONS_CARMANAGEMENT_H
#define FUNCTIONS_CARMANAGEMENT_H

#include <vector>

#include "Class_CarManagement.h"
#include "subscribersmanagement.h"

void addCar(std::vector<Car> &cars);
void removeCar(std::vector<Car> &carList);
void manageCar(std::vector<Car> &cars);
void manageSubscriber(CarRentalSystem &carRentalSystem);
void manageSubscription();
void reports(std::vector<Car> &cars, std::vector<Subscriber> &subscribers);

#endif
