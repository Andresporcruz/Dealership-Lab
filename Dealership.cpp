#include "Dealership.h"

Dealership::Dealership() {
    name = "Generic Dealership";
    capacity = 0;
}

Dealership::Dealership(string name, unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}

void Dealership::AddShowroom(Showroom s) {
    if (ShowroomList.size() == capacity) {
        cout << "Dealership is full, can't add another showroom!" << endl;
    } else {
        ShowroomList.push_back(s);
    }
}

float Dealership::GetAveragePrice() {
    float totalprice = 0;
    float totalnumber = 0;

    if (ShowroomList.empty()) {
        return 0;
    }

    for (int i = 0; i < ShowroomList.size(); i++) {
        for (int j = 0; j < ShowroomList[i].GetVehicleList().size(); j++) {
            totalprice += ShowroomList[i].GetVehicleList()[j].GetPrice();
            totalnumber++;
        }
    }

    return totalprice / totalnumber;
}

void Dealership::ShowInventory() {
    if (ShowroomList.empty()) {
        cout << name << " is empty!" << endl;
    } else {
        for (int i = 0; i < ShowroomList.size(); i++) {
            ShowroomList[i].ShowInventory();
            cout << endl;
        }
    }

    cout << "Average car price: $" << GetAveragePrice();
}
