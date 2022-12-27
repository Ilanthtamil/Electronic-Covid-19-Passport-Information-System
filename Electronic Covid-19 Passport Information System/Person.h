#pragma once
#include "Vaccination_Information.h"
#include "Vaccination_Status.h"
class Person
{
    std::string name;
    int passportNumber;
    int age;
    std::string gender;
    Vaccination_Information info;
    Vaccination_Status status;
public:
    friend class eCPIS;
    void setName(std::string);
    void setPassportNumber(int);
    void setAge(int);
    void setGender(std::string);
    void setInfo(Vaccination_Information);
    void setStatus(Vaccination_Status);
    Vaccination_Information getInfo();
    Vaccination_Status getVaccinationStatus();
    std::string getName();
    int getPassportNumber();
    int getAge();
    std::string getGender();
    Person();
    Person(std::string, int, int , std::string,Vaccination_Information&,Vaccination_Status&);
    Person(const Person&);
    void displayPerson();
 
};

