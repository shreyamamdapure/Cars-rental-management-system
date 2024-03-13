
#include<iostream>
#include<vector>
#include<string>
#include "SubscriptionManagementFunctions.cpp"
//#include"subcribersmanagement.cpp"
using namespace std;
		void extendRental(vector<Car> &cars,vector<int> &amount,string brandName,string num)
    {
        int flag;
        int day;
        string name,_name;
        do
        {
            int i=0;
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
                i++;
            }
            if(flag==1)
            {
                cout<<"How many days you want to extend the rental period?"<<endl;
                cin>>day;
                cout<<"You have to pay:"<<day*cars[i].price<<endl;
                cout<<"Have you paid the bill?(yes/no)"<<endl;
                cin>>name;
                do
                {
                    if((name=="yes")||(name=="y"))
                    {
                        bill(amount,day*cars[i].price);
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
    

    void returnCar(vector<Car> &cars,vector<int> &amount,string brandName,string regNum)
    {
        int flag;
        string choice,_choice;
        do{
            cout<<"Do you want to return?(yes/no/exit)";
            cin>>choice;
            if(choice=="yes")
            {
                for (const auto& car : cars)
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
                }
                else
                {
                    cout<<"The given credentials are not valid to return the car,you want to try again?(yes/no)"<<endl;
                    cin>>_choice;
                    if(_choice=="no")
                    {
                        cout<<"Thank you for using our system."<<endl;
                    }
                }
                
                
            }
            else if(choice=="no")
            {
                extendRental(cars,amount,brandName,regNum);
            }
            else
            {
                cout<<"Invalid input,you wanna try again?(yes/no)"<<endl;
                cin>>_choice;
            }
        }while(_choice=="yes");
}


void rentCar(vector<Car> &cars,vector<Car> &rentedCar,vector<int> &amount,string subscriberLevel)
    	{
        	int day,choice;
        	string decide,ans,option;
        	        displayCars(cars);
        	        cout<<"Enter your choice:"<<endl;
        		    cin>>choice;
        			cout<<"How many days you want to rent the  car?";
        			cin>>day;
        			cout<<"Are you sure you want to rent this car (yes/no/exit)"<<endl;
        			cin>>decide;
        			if(decide=="yes"||decide=="Yes")
        			{
        			  func(cars,choice);
        			  rentedCars(cars,rentedCar,choice);
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
        			}
        			else if(decide=="no"||decide=="No")
        			{
        			    displayCars(cars);
        	    		cout<<"Choose your option"<<endl;
        	    		cin>>choice;
        	    		cout<<"How many days you want to rent the  car?";
            			cin>>day;
        			    func(cars,choice);
            			rentedCars(cars,rentedCar,choice);
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
