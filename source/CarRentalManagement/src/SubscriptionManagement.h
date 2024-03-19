#include "Class_CarManagement.h"
using namespace std;
//#include "functions_CarManagement.cpp"

void bill(vector<int> &amount, int tot);
void addBack(vector<Car> &cars,string brandName,string regNum);
void removeFrom(vector<Car> &rentedCar,string brandName,string regNum);
void rentedCars(vector<Car> &cars, vector<Car> &rentedCar, int choice);
void displayCars(const vector<Car> &cars);
void func(vector<Car> &cars, int choice);
void extendRental(vector<Car> &cars, vector<int> &amount, string brandName, string num);
void returnCar(vector<Car> &cars, vector<int> &amount, string brandName, string regNum);
void rentCar(vector<Car> &cars, vector<Car> &rentedCar, vector<int> &amount, string subscriberLevel);
void _extendRental();
void _returnCar() ;
void _rentCar();





