#include "Showroom.h"

Showroom::Showroom() {
    name = "Unnamed Showroom";
    capacity = 0;
}

Showroom::Showroom(string name, unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}

vector<Vehicle> Showroom::GetVehicleList() {
    return VehicleList;
}

void Showroom::AddVehicle(Vehicle v) {
    if (VehicleList.size() == capacity) {
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    } else {
        VehicleList.push_back(v);
    }
}

void Showroom::ShowInventory() {
    if (VehicleList.empty()) {
        cout << "Unnamed Showroom is empty!" << endl;
    } else {
        cout << "Vehicles in " << name << endl;
        for (int i = 0; i < VehicleList.size(); i++) {
            VehicleList[i].Display();
        }
    }
}

float Showroom::GetInventoryValue() {
    float total = 0;
    for (int i = 0; i < VehicleList.size(); i++) {
        total += VehicleList[i].GetPrice();
    }
    return total;
}
