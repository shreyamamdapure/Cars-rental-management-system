//============================================================================
// Name        : main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;


enum class SubscriptionLevel {
    Silver,
    Gold,
    Platinum
};

class Subscriber {
private:
    string name;
    string id;
    SubscriptionLevel level;
    int maxCars;
    double discount;

public:

    Subscriber(string n, string i, SubscriptionLevel l, int max, double disc) : name(n), id(i), level(l), maxCars(max), discount(disc) {}

    string getName() const { return name; }
    string getID() const { return id; }
    SubscriptionLevel getLevel() const { return level; }
    int getMaxCars() const { return maxCars; }
    double getDiscount() const { return discount; }


    void setLevel(SubscriptionLevel newLevel) { level = newLevel; }
};

class CarRentalSystem {
private:
    vector<Subscriber> subscribers;

public:
    void addSubscriber(string name, string id, SubscriptionLevel level) {
        int maxCars;
        double discount;

        switch(level) {
            case SubscriptionLevel::Silver:
                maxCars = 1;
                discount = 0.0;
                break;
            case SubscriptionLevel::Gold:
                maxCars = 2;
                discount = 0.10;
                break;
            case SubscriptionLevel::Platinum:
                maxCars = 3;
                discount = 0.20;
                break;
        }

        subscribers.push_back(Subscriber(name, id, level, maxCars, discount));
        cout << "Subscriber added successfully:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Subscription Level: ";
        switch(level) {
            case SubscriptionLevel::Silver:
                cout << "Silver" << endl;
                break;
            case SubscriptionLevel::Gold:
                cout << "Gold" << endl;
                break;
            case SubscriptionLevel::Platinum:
                cout << "Platinum" << endl;
                break;
        }
    }

    void removeSubscriberByID(string id) {
        for(auto it = subscribers.begin(); it != subscribers.end(); ++it) {
            if(it->getID() == id) {
                cout << "Subscriber removed successfully:" << endl;
                cout << "Name: " << it->getName() << endl;
                cout << "ID: " << it->getID() << endl;
                cout << "Subscription Level: ";
                switch(it->getLevel()) {
                    case SubscriptionLevel::Silver:
                        cout << "Silver" << endl;
                        break;
                    case SubscriptionLevel::Gold:
                        cout << "Gold" << endl;
                        break;
                    case SubscriptionLevel::Platinum:
                        cout << "Platinum" << endl;
                        break;
                }
                subscribers.erase(it);
                return;
            }
        }
        cout << "Subscriber with ID " << id << " not found." << endl;
    }

    void promoteSubscriber(string id, int newLevel) {
        for(auto& subscriber : subscribers) {
            if(subscriber.getID() == id) {
                SubscriptionLevel currentLevel = subscriber.getLevel();
                SubscriptionLevel level;
                switch(newLevel) {
                    case 0:
                        level = SubscriptionLevel::Silver;
                        break;
                    case 1:
                        level = SubscriptionLevel::Gold;
                        break;
                    case 2:
                        level = SubscriptionLevel::Platinum;
                        break;
                    default:
                        cout << "Invalid subscription level." << endl;
                        return;
                }
                if (currentLevel == level) {
                    cout << "Subscriber with ID " << id << " is already at " << levelToString(level) << " level." << endl;
                    return;
                }
                subscriber.setLevel(level);
                cout << "Subscriber with ID " << id << " promoted to " << levelToString(level) << " level." << endl;
                return;
            }
        }
        cout << "Subscriber with ID " << id << " not found." << endl;
    }


    string levelToString(SubscriptionLevel level) {
        switch(level) {
            case SubscriptionLevel::Silver:
                return "Silver";
            case SubscriptionLevel::Gold:
                return "Gold";
            case SubscriptionLevel::Platinum:
                return "Platinum";
        }
    }
};

int main() {
    CarRentalSystem rentalSystem;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a subscriber" << endl;
        cout << "2. Remove a subscriber by ID" << endl;
        cout << "3. Promote subscription level" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            string name, id;
            int level;
            cout << "Enter subscriber name: ";
            cin >> name;
            cout << "Enter subscriber ID: ";
            cin >> id;
            cout << "Enter subscription level (0 for Silver, 1 for Gold, 2 for Platinum): ";
            cin >> level;
            rentalSystem.addSubscriber(name, id, static_cast<SubscriptionLevel>(level));
        } else if (choice == 2) {
            string id;
            cout << "Enter subscriber ID to remove: ";
            cin >> id;
            rentalSystem.removeSubscriberByID(id);
        } else if (choice == 3) {
            string id;
            int level;
            cout << "Enter subscriber ID to promote: ";
            cin >> id;
            cout << "Enter new subscription level (0 for Silver, 1 for Gold, 2 for Platinum): ";
            cin >> level;
            rentalSystem.promoteSubscriber(id, level);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

