#include "Vaccination_Information.h"

Vaccination_Information::Vaccination_Information() {}
Vaccination_Information::Vaccination_Information( std::string type, MyDate &date) 
{
    this->vaccinationType = type;
    this->dateOfRecievingVaccine = date;
}
Vaccination_Information::Vaccination_Information(Vaccination_Information& temp) {
    this->dateOfRecievingVaccine = temp.dateOfRecievingVaccine;
    this->vaccinationType = temp.vaccinationType;
}




void Vaccination_Information::setVaccinationType(std::string type) {
    this->vaccinationType = type;
}
std::string Vaccination_Information::getVaccinationType() {
    return this->vaccinationType;
}
void Vaccination_Information::setDateOfRecievingVaccine(MyDate t) {
    this->dateOfRecievingVaccine = t;
}
MyDate Vaccination_Information::getDateOfRecievingVaccine() {
    return this->dateOfRecievingVaccine;
}

void Vaccination_Information::displayVacInfo() {
    cout << "Vaccination-Type: " << vaccinationType << " , " << "Date: "; dateOfRecievingVaccine.displayDate();
}