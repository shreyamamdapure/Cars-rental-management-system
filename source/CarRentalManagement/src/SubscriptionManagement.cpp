#include<iostream>
#include<vector>
#include<string>
#include "SubscriptionManagement.h"
#include "Class_CarManagement.h"
#include<algorithm>

using namespace std;

extern vector<Car> cars;
vector<Car> rentedCar;
vector<int> amount;
extern vector<Car> carList;

void bill(vector<int> &amount,int tot)
{
    amount.push_back(tot);
}

    void addBack(vector<Car> &cars,string brandName,string regNum)
    {
        Car object3;
        int index;
    for(int i=0;i<carList.size();i++)
    {
        if(carList[i].brand==brandName)
        {
           index=i;
           break;
        }
    }
    object3.brand=carList[index].brand;
    object3.model=carList[index].model;
    object3.registrationNumber=carList[index].registrationNumber;
    object3.price=carList[index].price;
    cars.push_back(object3);

   }
void removeFrom(vector<Car> &rentedCar,string brandName,string regNum)
{
    for(auto it=rentedCar.begin();it!=rentedCar.end();++it)
    {
        if(it->brand==brandName)
        {
            rentedCar.erase(it);
        }
    }
}
    void rentedCars(vector<Car> &cars,vector<Car> &rentedCar,int choice)
    {
        Car obj;
        obj.brand=cars[choice-1].brand;
        obj.model=cars[choice-1].model;
        obj.registrationNumber=cars[choice-1].registrationNumber;
        rentedCar.push_back(obj);
        for(auto it=cars.begin();it!=cars.end();++it)
        {
            if(it->brand==obj.brand)
            {
                cars.erase(it);
            }
        }
    }

    void displayCars(const vector<Car>& cars) {

        cout << "List of Cars:" << endl;
        int i=1;

        for (const auto& car : cars) {
            cout <<i<<" " << "Brand: " << car.brand << ", Model: " << car.model << ", Registration Number: " << car.registrationNumber;
            cout<<" ,Price: "<<car.price<<endl;
            i++;
        }
    }

    void func(vector<Car> &cars,int choice)
    {
        cout<<"\t\t Car rented Succesfully"<<endl;
        cout<<"\t\t-----------------------------"<<endl;
        cout<<"\t\t Brand:"<<cars[choice-1].brand<<endl;
        cout<<"\t\t Model:"<<cars[choice-1].model<<endl;
        cout<<"\t\t Registration No:"<<cars[choice-1].registrationNumber<<endl;
        cout<<"\t\t Price:"<<cars[choice-1].price<<endl;
        cout<<"\t\t-----------------------------"<<endl;
        cout<<"\t\t Thank You for choosing our sytsem"<<endl;
        cout<<"\t\t-----------------------------"<<endl;
    }

    void extendRental(vector<Car> &rentedCar,vector<int> &amount,string brandName,string num)
    {
        int flag;
        int day;
        int index;
        string name,_name;
        do
        {
            int i=0;
            for (const auto& car : rentedCar)
            {
                if((car.registrationNumber==num) && (car.brand==brandName))
                {
                    flag=1;
                    break;
                }
                else
                {
                    flag=0;
                }
                i++;
            }
            if(flag==1)
            {
                cout<<"How many days you want to extend the rental period?"<<endl;
                cin>>day;
                for(int i=0;i<carList.size();i++)
                {
                    if(carList[i].brand==brandName)
                    {
                        index=i;
                        break;
                    }
                }
                cout<<"You have to pay:"<<day*carList[index].price<<endl;
                cout<<"Have you paid the bill?(yes/no)"<<endl;
                cin>>name;
                do
                {
                    if((name=="yes")||(name=="y"))
                    {
                        bill(amount,day*carList[index].price);
                        cout<<"Thank You.Have a nice day!";
                        break;
                    }
                    else
                    {
                        cout<<"Please pay the bill."<<endl;
                        cout<<"Have you paid the bill?(y/n)"<<endl;
                        cin>>name;
                    }
                }while(name=="y");
            }
            else
            {
                cout<<"Invalid credentials,you want to try again?(yes/no)"<<endl;
                cin>>_name;
            }
        }while(_name=="yes");
    }

    void returnCar(vector<Car> &cars,vector<Car> &rentedCar,vector<int> &amount,string brandName,string regNum)
    {
        int flag;
        string choice,_choice;

            cout<<"Do you want to return?(yes/no)";
            cin>>choice;
            if(choice=="yes")
            {
                for (const auto& car : rentedCar)
                {
                    if((car.registrationNumber==regNum) && (car.brand==brandName))
                    {
                        flag=1;
                        break;
                    }
                    else
                    {
                        flag=0;
                    }
                }
                if(flag==1)
                {
                    cout<<"Thank you for returning the car."<<endl;
                    addBack(cars,brandName,regNum);
                    removeFrom(rentedCar,brandName,regNum);
                }
                else
                {
                    cout<<"The given credentials are not valid to return the car."<<endl;
                }


            }
            else if(choice=="no")
            {
                extendRental(cars,amount,brandName,regNum);
            }
            else
            {
                cout<<"Invalid input."<<endl;

            }

}

        void _extendRental()
        {
            string brand,regNo;
            cout<<"Enter the brand of the car:"<<endl;
            cin>>brand;
            cout<<"Enter the registration number of the car that you have rented:"<<endl;
            cin>>regNo;
            extendRental(rentedCar,amount,brand,regNo);
        }
    	void _returnCar()
        {
            string brand,regNo;
            cout<<"Enter the brand of the car:"<<endl;
            cin>>brand;
            cout<<"Enter the registration number of the car that you have rented:"<<endl;
            cin>>regNo;
            returnCar(cars,rentedCar,amount,brand,regNo);
        }


void rentCar(vector<Car> &cars,vector<Car> &cars1,vector<int> &amount,string subscriberLevel)
    	{
        	int day,choice;
        	string decide,option,ans;
        	        displayCars(cars);
        	        cout<<"Enter your choice:"<<endl;
        		    cin>>choice;
        			cout<<"How many days you want to rent the  car?";
        			cin>>day;
        			cout<<"Are you sure you want to rent this car (yes/no)";
        			cin>>decide;
        			if(decide=="yes"||decide=="Yes")
        			{
        			  func(cars,choice);
        			  cout<<"You have to pay:"<<day*cars[choice-1].price<<endl;
            				cout<<"Have you paid the bill?(yes/no)"<<endl;
            				cin>>ans;
            				if(ans=="yes")
            				{
            				    bill(amount,day*cars[choice-1].price);
            				    cout<<"Thanks for using our system."<<endl;
            				}
            				else
            				{
            				    cout<<"Please pay the bill."<<endl;
            				}
            				rentedCars(cars,rentedCar,choice);
        			}
        			else
        			{
        	    	    cout<<"\t\t Thank you for using our system"<<endl;
        	    		cout<<"\t\t-----------------------------"<<endl;

        			}
        			if((decide=="yes")||(decide=="no"))
        			{
        			cout<<"Do you want to rent another car:(yes/no)";
        			cin>>option;
        			if(option=="yes")
        			{
        			      if(subscriberLevel=="Silver")
        			      {
        			          cout<<"Please upgrade your subscription to gold or platinum to rent another car."<<endl;
        			      }
        			      else if(subscriberLevel=="Gold")
        			      {
        			          cout<<"You can rent one more car.Do you want to?(yes/no)";
        			          cin>>ans;
        			            if(ans=="yes")
        			            {
        			                rentCar(cars,rentedCar,amount,subscriberLevel);
        			            }
        			            else
        			            {
        			                cout<<"Thank you for renting the car."<<endl;
        			            }
        			        }
        			      else
        			      {
        			          cout<<"You can rent two more cars.Do you want to?"<<endl;
        			          cin>>ans;
        			            if(ans=="yes")
        			            {
        			                rentCar(cars,rentedCar,amount,subscriberLevel);
        			            }
        			            else
        			            {
        			                cout<<"Thank you for renting the car."<<endl;
        			            }
        			       }
        			   }
        		}

    	}


        void _rentCar()
        {
            cout<<"Enter your subscriber level:"<<endl;
            string subscriberLevel;
            cin>>subscriberLevel;
            rentCar(cars,rentedCar,amount,subscriberLevel);
        }
