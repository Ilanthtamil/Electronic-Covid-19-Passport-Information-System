#pragma once
#include<iostream>
using namespace std;
class Person;
class eCPIS
{
	Person* data;
	int size;
	int count;

public:
	eCPIS();
	eCPIS(const eCPIS&);
	void resize();
	void updatePerson(int);
	void startApplication();
	void addVaccinationInfo(Person);
	void searchByPassport(int);
	void unvaccinatedPerson();
	void searchByType(std::string);
	void statisticalInfo();
	void insertPerson();

	~eCPIS();
};

