#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Car {
public:
    vector<Car> cars;
    string brand;
    string model;
    string registrationNumber;
};
    void addCar(vector<Car> &cars) {
        Car newCar;
        cout << "Enter Brand: ";
        cin >> newCar.brand;
        cout << "Enter model: ";
        cin >> newCar.model;
        cout << "Enter registrationNumber: ";
        cin >> newCar.registrationNumber;
    
        cars.push_back(newCar);
        cout << "Car added successfully!" << endl;
    }
    void removeCar(vector<Car>& carList) {
        string registrationNumber;
        cout << "Enter registration number of the car to remove: ";
        cin >> registrationNumber;
        for (auto it = carList.begin(); it != carList.end(); ++it) {
            if (it->registrationNumber == registrationNumber) {
                carList.erase(it);
                cout << "Car removed from rental list." << endl;
                return;
            }
        }
        cout << "Car with registration number " << registrationNumber << " not found in rental list." << endl;
    }
    
    void displayCars(const vector<Car>& cars) {

        cout << "List of Cars:" << endl;
        int i=1;

        for (const auto& car : cars) {
            cout <<i<<" " << "Brand: " << car.brand << ", Model: " << car.model << ", Registration Number: " << car.registrationNumber << endl;
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
        cout<<"\t\t-----------------------------"<<endl;
        cout<<"\t\t Thank You for choosing our sytsem"<<endl;
        cout<<"\t\t-----------------------------"<<endl;
    }
    
    void extendRental(vector<Car> &cars,string brandName,string num)
    {
        int flag;
        int day,x,amount,totalAmount;
        string name,_name;
        do
        {
            for (const auto& car : cars)
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
            }
            if(flag==1)
            {
                cout<<"How many days you want to extend the rental period?"<<endl;
                cin>>day;
                cout<<"You have to pay:"<<endl;
                cout<<"Have you paid the bill?(yes/no)"<<endl;
                cin>>name;
                do
                {
                    if((name=="yes")||(name=="y"))
                    {
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
    

    void returnCar(vector<Car> &cars,string brandName,string regNum)
    {
        int flag;
        string choice,_choice;
        do{
            cout<<"Do you want to return?(yes/no)";
            cin>>choice;
            if(choice=="yes")
            {
                for (const auto& car : cars)
                {
                    if((car.registrationNumber==regNum) &&(car.brand==brandName))
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
                }
                else
                {
                    cout<<"Not a valid registration number to return the car,you wanna try again?(yes/no)"<<endl;
                    cin>>_choice;
                    if(_choice=="no")
                    {
                        cout<<"Thank you for using our system."<<endl;
                    }
                }
                
                
            }
            /*else if(choice=="no")
            {
                extendRental(num);
            }*/
            else
            {
                cout<<"Invalid input,you wanna try again?(yes/no)"<<endl;
                cin>>_choice;
            }
        }while(_choice=="yes");
}


void rentCar(vector<Car> &cars,string subscriberLevel)
    	{
        	int day,choice;
        	string decide,option,ans;
        	        displayCars(cars);
        	        cout<<"Choose your option"<<endl;
        			cin>>choice;
        			cout<<"How many days you want to rent the  car?";
        			cin>>day;
        			cout<<"Are you sure want to rent this car (yes/no/exit)"<<endl;
        			cin>>decide;
        			if(decide=="yes"||decide=="Yes")
        			{
        			    func(cars,choice);
        			}
        			else if(decide=="no"||decide=="No"){
        			    displayCars(cars);
        	    		cout<<"Choose your option"<<endl;
        	    		cin>>choice;
        	    		cout<<"How many days you want to rent the  car?";
            			cin>>day;
            			cout<<"Are you sure want to rent this car (yes/no/exit)"<<endl;
            			cin>>decide;
        			    if(decide=="yes"||decide=="Yes")
        			    {
            				func(cars,choice);
        			    }
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
        			            cout<<"You can rent one more car.Do you want to?(yes/no)"<<endl;
        			            cin>>ans;
        			            if(ans=="yes")
        			            {
        			                rentCar(cars,subscriberLevel);
        			            }
        			            else
        			            {
        			                cout<<"Thank you for renting a car."<<endl;
        			            }
        			        }
        			        else
        			        {
        			            cout<<"You can rent two more cars.Do you want to?"<<endl;
        			            cin>>ans;
        			            if(ans=="yes")
        			            {
        			                rentCar(cars,subscriberLevel);
        			            }
        			            else
        			            {
        			                cout<<"Thank you for renting a car."<<endl;
        			            }
        			        }
        			    }
        			}
        }


        
int main()
{
    vector<Car> cars;
    addCar(cars);
    addCar(cars);
    rentCar(cars,"Silver");
    returnCar(cars,"tata","123");
    extendRental(cars,"tata","123");
    return 0;
}
        





