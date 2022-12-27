#include "eCPIS.h"
#include "Person.h"



eCPIS::eCPIS() {
	this->size = 5;
	this->count = 0;
	this->data = new Person[this->size];
}
eCPIS::eCPIS(const eCPIS& obj) {
	this->data = obj.data;
	this->size = obj.size;
	this->count = obj.count;
}
// This is the function that takes required input from the user and inserts it to the object
void eCPIS::insertPerson() {
	std::string name="", gender, type;
	int age, passport,g=0,status=-1,t=-1,month=1,day=1,year=1900;
	cout << "\n***** Add Record *****\n";

	cin.ignore();
	cout << "********** Personal Information:\nEnter Your Name: ";
	std::getline(std::cin, name);
	cout << "Enter Age: ";
	cin >> age;
	while (!(g >0 && g< 3)) {
	cout << "Enter Gender: \n1--> Male\n2--> Female\n: ";
	cin >> g;
	}
	if (g == 1) {
		gender = "Male";
	}
	else if(g==2) {
		gender = "Female";
	}

	cout << "Enter Passport-Number (length max 10 integers): ";
	cin >> passport;

	while (!(status>0&&status<=3)) {
	cout << "**********\nEnter your Vaccination Status Accordingly:\n1--> Not taken Vaccination\n2--> Partially Vaccinated\n3--> Vaccinated Completly\n:";
	cin >> status;
	}
	
	
	if (status-1 != 0) {
		while (!(t > 0 && t <= 3)) {
			cout << "***********\nEnter Vaccination Type Name:\n1-->Pfizer\n2-->Sinovac\n3-->AstraZeneca\n: ";
			cin >> t;
		}
		if (t-1 == 0) {
			type = "Pfizer";

		}
		else if (t-1 == 1) {
			type = "Sinovac";

		}
		else if(t-1==2){
			type = "AstraZeneca";

		}
	
		do
		{
			// If an invalid date is enterd then it will ask the user to enter the valid again and again...
			cout << "\nEnter Date of Vaccination \nEnter Day (in range 1 - 31): ";
			cin >> day;
			cout << "Enter Month (in range 1 - 12): ";cin >> month;
			cout << "Enter Year: ";cin >> year;
			if((day<1||day>31)||(month<1||month>12))
			{
				cout<<"\nWrong day or month enterd\n";
			}	
		}while((day<1||day>31)||(month<1||month>12));

	

	}

	

	MyDate date(day,month,year);
	Vaccination_Information info_temp(type,date);
	Vaccination_Status status_temp(status-1);
	Person temp_person(name, passport, age, gender, info_temp, status_temp);
	// to add the person object which consist of other objects (necessary) as well 
	addVaccinationInfo(temp_person);
	

}
void eCPIS::updatePerson(int passport) {
	std::string name = "", gender, type;
	int age, pass, g = 0, status = -1, t = -1, month = 1, day = 1, year = 1900,i=0;
	bool flag = false;
	int index=-1;
	cout << "\n***** Update Record *****\n";

	for (;i < count && flag==false;i++) {
		if (passport == this->data[i].getPassportNumber()) {
			flag = true;
			index=i;
		}
	}
	if (flag) {
		cin.ignore();
		cout << "********** Personal Information:\nEnter Your Name: ";
		std::getline(std::cin, name);
		cout << "Enter Age: ";
		cin >> age;
		while (!(g > 0 && g < 3)) {
			cout << "Enter Gender: \n1--> Male\n2--> Female\n: ";
			cin >> g;
		}
		if (g == 1) {
			gender = "Male";
		}
		else if (g == 2) {
			gender = "Female";
		}

		cout << "Enter Passport-Number (length max 10 integers): ";
		cin >> pass;

		while (!(status > 0 && status <= 3)) {
			cout << "**********\nEnter your Vaccination Status Accordingly:\n1--> Not taken Vaccination\n2--> Partially Vaccinated\n3--> Vaccinated Completly\n:";
			cin >> status;
		}


		if (status != 0) {
			while (!(t > 0 && t <= 3)) {
				cout << "***********\nEnter Vaccination Type Name:\n1-->Pfizer\n2-->Sinovac\n3-->Astrazeneca\n: ";
				cin >> t;
			}
			if (t-1 == 0) {
				type = "Pfizer";

			}
			else if (t-1 == 1) {
				type = "Sinovac";

			}
			else if(t-1 == 2){
				type = "Astrazeneca";

			}
			cout << "\nEnter Date of Vaccination \nEnter Day: ";
			cin >> day;
			cout << "Enter Month: ";cin >> month;
			cout << "Enter Year: ";cin >> year;
		}
	

	MyDate date(day, month, year);
	Vaccination_Information info_temp(type, date);
	Vaccination_Status status_temp(status);
	data[index].setName(name);
	data[index].setAge(age);
	data[index].setGender(gender);
	data[index].setPassportNumber(passport);
	data[index].setInfo(info_temp);
	data[index].setStatus(status_temp);
	cout << endl << "***** Record Updated *****\n" << endl;

	}
	else {
		cout << endl<<"***** No such Record Exsist *****\n"<<endl;
	}


}

// This function presents the menu of the application and whole application runs from here.
void eCPIS::startApplication()
{	

	int choice = 0;
	do {
		cout << "\n***** Welcome to ECPIS *****\n";
		cout << "Enter 1 to enter information \n";
		cout << "Enter 2 to display all information \n";
		cout << "Enter 3 to Search Person by Passport Number\n";

		cout << "Enter 4 to list UnVaccinated People\n";
		cout << "Enter 5 to Search Person by Vaccination Type\n";
		cout << "Enter 6 to Update Information\n";
		cout << "Enter 7 to View Statistical Report\n";


		cout << "Enter 8 to exit app \n-->";
		cin >> choice;
		if (choice == 1)
		{
			this->insertPerson();
			system("pause");
			//To cleat the screen after insert operation
			system("cls");
		}
		else if (choice == 2)
		{
			// To display all the records of the registered members
			cout << "****** RECORDS ******\n" << endl;
			for (int i = 0;i < this->count;i++)
			{
				cout << "***** Record No. " << i + 1 << endl;
				this->data[i].displayPerson();
				this->data[i].info.displayVacInfo();
				this->data[i].status.vaccinationStatus();
				cout << "\n************\n";
			}
			cout << endl<<endl;
			system("pause");
			system("cls");
		}
		else if (choice == 3)
		{
			int temp;
			cout << "Enter Passport Number: ";
			cin >> temp;
			//  this function will call the search method which will then take passport number as input then search it in the list
			this->searchByPassport(temp);
			system("pause");
			system("cls");
		}
		else if (choice == 4)
		{
			// TO see the unvaccinated persons the list
				this->unvaccinatedPerson();
				system("pause");
				system("cls");
		}
		else if (choice == 5)
		{
			// Search the memebers based on Vaccination type
			int t = -1;
			std::string type;
			while (!(t >= 0 && t < 3)) {
				cout << "***********\nEnter Vaccination Type Name:\n1-->Pfizer\n2-->Sinovac\n3-->Astrazeneca\n: ";
				cin >> t;
			}
			if (t-1 == 0) {
				type = "Pfizer";

			}
			else if (t-1 == 1) {
				type = "Sinovac";

			}
			else {
				type = "Astrazeneca";

			}
			this->searchByType(type);
			system("pause");
			system("cls");
		}
		else if (choice == 6)
		{
			// To Update the user using the passport number
			int temp;
			cout<<"Enter Passport-Number (length max 10 integers): ";
			cin >> temp;
			this->updatePerson(temp);
			system("pause");
			system("cls");
		}
		else if (choice == 7)
		{
			// Diplay the statistial information based on gnder ,vaccination status and vaccination information as well
			this->statisticalInfo();
			system("pause");
			system("cls");
		}

		else {
			if (choice != 8)
			{
				//  this is if the enterd choice is out of the range
				cout << "Please enter a choice in range 1 -8 \n";
			}
		}

	} while (choice != 8);

	cout << "Thank you for using the application. \n";
}

void eCPIS::searchByPassport(int number) {
	bool flag = false;
	cout << "\n***** Search Results *****\n";
	for (int i = 0;i < count;i++) {
		if (number == this->data[i].getPassportNumber()) {
			cout << "***** Record No. " << i + 1 << endl;
			this->data[i].displayPerson();
			this->data[i].info.displayVacInfo();
			cout << "\n************\n";

			flag = true;
		}	
	}
	if (!flag) {
		cout <<endl<< "***** No Record Found *****" << endl<<endl;
	}
}
void eCPIS::unvaccinatedPerson() {
	cout << "\n***** UnVaccinated Records *****\n";
	for (int i = 0;i < count;i++) {
		if (this->data[i].getVaccinationStatus().getStatus() == "Not taken Vaccination") {
			cout << "***** Record No. " << i + 1 << endl;
			 this->data[i].displayPerson();
			 cout << "\n************\n";
			 cout<<endl;

		}
	}
}
void eCPIS::searchByType(std::string type) {
	bool flag=false;
	cout << "\n***** Search Results *****\n";

	for (int i = 0;i < count;i++) {
		if (type == this->data[i].getInfo().getVaccinationType()) {
			cout << "***** RECORD# " << i + 1 << endl;
			this->data[i].displayPerson();
			cout << "\n************\n";
			flag = true;
		}
	}
	if (!flag) {
		cout << endl<<"***** No Record Exsist *****" << endl<<endl;
	}
}
void eCPIS::statisticalInfo() {
	int pc=0, sc=0, ac = 0,fv=0,pv=0,uv=0;
	cout << "\n***** Statistical Information *****\n";

	cout << endl;
	for (int i = 0;i < count;i++) {
		if ("Pfizer" == this->data[i].getInfo().getVaccinationType()) {
			pc++;
		}else if("Sinovac" == this->data[i].getInfo().getVaccinationType()) {
			sc++;
		}
		else if("AstraZeneca" == this->data[i].getInfo().getVaccinationType()){
			ac++;
		}
	}
	cout << "***** Person Count by Vaccination Type: \n";
	cout << "1- Pfizer: " << pc << endl;
	cout << "2- Sinovac: " << sc << endl;
	cout << "3- AstraZeneca: " << ac << endl;
	cout << endl;

	for (int i = 0;i < count;i++) {
		if ("Not taken Vaccination" == this->data[i].getVaccinationStatus().getStatus()) {
			uv++;
		}
		else if ("Partially Vaccinated" == this->data[i].getVaccinationStatus().getStatus()) {
			pv++;
		}
		else {
			fv++;
		}
	}
	cout << "***** Person Count by Vaccination Status: \n";
	cout << "1- Fully Vaccinated: " << fv << endl;
	cout << "2- Partially Vaccinated: " << pv << endl;
	cout << "3- Not Vaccinated: " << uv << endl;
	cout << endl;

	int mc=0, fc=0;
	for (int i = 0;i < count;i++) {
		if ("Male" == this->data[i].getGender()) {
			mc++;
		}
		else {
			fc++;
		}
	}
	cout << "****** Count By Gender\n-->Male Count: " << mc << "\n-->Female Count: " << fc << endl;
	cout << endl;

}


void eCPIS::addVaccinationInfo(Person vcs)
{
	if (this->count == this->size)
	{
		resize();
	}
	this->data[this->count] = vcs;
	this->count++;
	cout << "\n********** Person has been Added to Record **********" << endl<<endl;
}

void eCPIS::resize()
{
	Person* temp = new Person[this->size + 5];
	this->size = this->size + 5;
	for (int i = 0; i < this->count; i++)
	{
		temp[i] = this->data[i];
	}
	delete[]this->data;
	this->data = temp;
}




eCPIS::~eCPIS() {
	if (data != NULL) {
	delete[]this->data;
	}
	this->data = nullptr;
	count = 0;
	size = 0;
}
