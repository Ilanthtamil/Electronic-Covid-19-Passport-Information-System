#include "Person.h"

Person::Person(){}

void Person::setName(std::string nm)
{
    if (nm != "")
    {
        this->name = nm;
    }
}
void Person::setPassportNumber(int pNum)
{
    if (pNum > 0)
    {
        this->passportNumber = pNum;
    }
}
void Person::setAge(int ag)
{
    if (ag > 0)
    {
        this->age = ag;
    }
}
void Person::setGender(std::string gen)
{
    //     if (tolower(gen) == "male" || tolower(gen) == "female"
    // 	|| thread_localower(gen) == "other")
    //       {
    // 	gender = gen;
    //       }
    //     else
    //       {
    // 	gender = "";
    //       }
    this->gender = gen;

}
std::string Person::getName()
{
    return this->name;
}
int Person::getPassportNumber()
{
    return this->passportNumber;
}
int Person::getAge()
{
    return this->age;
}
std::string Person::getGender()
{
    return this->gender;
}
Vaccination_Information Person::getInfo() {
    return this->info;
}
Vaccination_Status Person::getVaccinationStatus() {
    return this->status;
}

Person::Person(std::string nm, int pNum, int ag, std::string gen,Vaccination_Information &info,Vaccination_Status &status)
{
    this->name = nm;
    this->passportNumber = pNum;
    this->age = ag;
    this->gender = gen;
    this->info = info;
    this->status = status;
}

Person::Person(const Person& temp)
{
    this->name = temp.name;
    this->passportNumber = temp.passportNumber;
    this->age = temp.age;
    this->gender = temp.gender;
    this->info = temp.info;
    this->status = temp.status;
}
void Person::displayPerson()
{
    cout << "\nName : " << this->name << "\n";
    cout << "Passport number : " << this->passportNumber << "\n";;
    cout << "Age : " << this->age << "\n";
    cout << "Gender : " << this->gender << "\n";

}

void Person::setInfo(Vaccination_Information obj) {
    this->info = obj;
}
void Person::setStatus(Vaccination_Status obj) {
    this->status = obj;
}


