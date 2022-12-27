#pragma once
#include "MyDate.h"
class Vaccination_Information:public MyDate
{

	std::string vaccinationType;
	MyDate dateOfRecievingVaccine;
public:
	Vaccination_Information();
	Vaccination_Information( std::string, MyDate&);
	Vaccination_Information(Vaccination_Information&);
	void displayVacInfo();
	void setVaccinationType(std::string);
	 std::string getVaccinationType();
	void setDateOfRecievingVaccine(MyDate);
	 MyDate getDateOfRecievingVaccine();

};

