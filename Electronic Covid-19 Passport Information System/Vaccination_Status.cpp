#include "Vaccination_Status.h"
Vaccination_Status::Vaccination_Status() {}
Vaccination_Status::Vaccination_Status(int status) {
    this->status = status;
}

string Vaccination_Status::getStatus() {
    if (this->status == 0)
    {
        return "Not taken Vaccination";
    }
    else if (this->status == 1)
    {
        return "Partially Vaccinated";
    }
    else {
        return "Vaccinated Completly";
    }
}

void Vaccination_Status::setStatus(int i) {
    this->status = i;
}
void Vaccination_Status::vaccinationStatus() {
    cout << "Vaccination Status: ";
    if (this->status == 0)
    {
        cout<< "Not taken Vaccination";
    }
    else if (this->status == 1)
    {
        cout<< "Partially Vaccinated";
    }
    else {
        cout<< "Vaccinated Completly";
    }
}
