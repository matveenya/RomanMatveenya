//12) Определить объект: информация о сотруднике: табельный номер сотрудника (int), его фамилию (*char либо char[20]), год рождения (int), оклад (int). 
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
class Employee {
public:
	Employee() {
	}
	Employee(int pN, string lN, int yOB, int s) {
		setEmployee(pN, lN, yOB, s);
	}
	Employee(const Employee& employee) {//copy
		setEmployee(employee.personnelNumber, employee.lastName, employee.yearOfBirth, employee.salary);
	}

	void setEmployee(int personnelNumber, string lastName, int yearOfBirth, int salary) {
		setPersonnelNumber(personnelNumber);
		setLastName(lastName);
		setYearOfBirth(yearOfBirth);
		setSalary(salary);
	}

	void setPersonnelNumber(int personnelNumber) {
		this->personnelNumber = personnelNumber;
	}

	void setSalary(int salary) {
		this->salary = salary;
	}

	void setYearOfBirth(int yearOfBirth) {
		this->yearOfBirth = yearOfBirth;
	}

	void setLastName(string lastName) {
		this->lastName = lastName;
	}

	int getPersonnelNumber() {
		return personnelNumber;
	}
	int getSalary() {
		return salary;
	}
	int getYearOfBirth() {
		return yearOfBirth;
	}
	string getLastName() {
		return lastName;
	}
	~Employee() {
		cout << "destR" << endl;
	}

private:
	int personnelNumber;
	string lastName;//string ???
	int yearOfBirth;
	int salary;
};

int averageSalary(Employee arr[]) {//averageSalary by all in list Person(employee) !!!(paragraph B!!!)!!!
	int sum = 0;
	for (int i = 0; i <= sizeof(arr); i++) {
		sum += arr[i].getSalary();
	}
	return (sum / (sizeof(arr) + 1));//0..1..2..3..4 = 5 person
}

void maxSalary(Employee array[]) {//maxSalary in list Person(employee) !!!(paragraph C!!!)!!!
	int max = 0;
	string lastName;
	for (int i = 0; i <= sizeof(array); i++) {
		if (array[i].getSalary() > max) {
			max = array[i].getSalary();
			lastName = array[i].getLastName();
		}
	}
	cout << "maxSalary - " << max << ", LastName person: " << lastName << endl;
}

void minSalary(Employee array[]) {//mixSalary in list Person(employee) 
	int min = array[0].getSalary();
	string lastName;
	for (int i = 0; i <= sizeof(array); i++) {
		if (array[i].getSalary() < min) {
			min = array[i].getSalary();
			lastName = array[i].getLastName();
		}
	}
	cout << "minSalary - " << min << ", LastName person: " << lastName << endl;
}

int averageSalaryPerson(Employee arr[], string lastName) {//averageSalary by one person(employee)
	int sum = 0; //!!!(paragraph B!!!)!!! ????
	int amount = 0;
	for (int i = 0; i <= sizeof(arr); i++) {
		if (lastName == arr[i].getLastName()) { //if lastName cannot be unique
			sum += arr[i].getSalary();
			amount++;
		}
	}
	if (amount == 0)return 0;
	return (sum / amount);
}
void sortByAge(Employee arr[]) {//sort by Age !!!(paragraph D!!!)!!!
	Employee tmp;
	for (int i = 0; i < sizeof(arr); i++) {
		for (int j = i + 1; j <= sizeof(arr); j++) {
			if (arr[i].getYearOfBirth() > arr[j].getYearOfBirth()) { 
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	cout << "SORT BY AGE: " << endl;
	for (int i = 0; i <= sizeof(arr); i++) {
		cout << "LastName: " << arr[i].getLastName();
		cout << ", " << arr[i].getYearOfBirth() << endl;
	}

}



int main()
{
	int average = 0;
	//Array Employee From Work, find MaxSalary, MinSalary,Average and Sortby Age
	Employee person1(1, "German", 2000, 1500);
	Employee person2(2, "Petrov", 1997, 1100);
	Employee person3(3, "Ivanov", 1999, 1200);
	Employee person4(4, "Deniski", 2002, 1400);
	Employee person5(5, "German", 2000, 2600);//if lastName cannot be unique


	Employee arr[5];//Create Array
	arr[0] = person1;
	arr[1] = person2;
	arr[2] = person3;
	arr[3] = person4;
	arr[4] = person5;

	cout << "Average by employeeS - " << averageSalary(arr) << endl;
	maxSalary(arr);//call Max and Min Salary
	minSalary(arr);
	string lastName;
	cout << "Input LastName(for averageSalary?):  ";//???? if this need
	cin >> lastName;
	average = averageSalaryPerson(arr, lastName);
	if (average != 0) {
		cout << "Average by employee - " << average << endl; //if lastName cannot be unique
	}
	else {
		cout << "Average by employee - Error" << endl;
	}
	sortByAge(arr);

	//WORK WITH FILE!!!!
	cout << "WORK WITH FILE!!!" << endl;
	setlocale(LC_ALL, "eng");
	char lines[255];
	ifstream file;
	file.open("C:\\file.txt"); //!!!!!LOCATION!!!!!!!!LOCATION!!!!!!!!LOCATION!!!!!!!!!!!
	if (file.is_open())cout << "open File" << endl;
	else {
		cout << "Read Error Fle" << endl;
	}
	vector<string> date;//all Date from file store in vector Date
	while (!file.eof()) {
		file >> lines;
		date.push_back(lines); //add line from file in vector
	}
	int amount = 0;
	int help = 0;
	if (date.size() != 0)amount = date.size() / 4; //1-Number, 2-lastName, 3-yearOfBirth, 4-Salary. 4 params from 1 Employee, 8 params = 2 employee, 12 params = 3 employee ...
	Employee** array = new Employee * [amount]; //New Array with date from file.txt
	for (int i = 0; i < amount; i++) {
		array[i] = new Employee();
		for (int params = 0; params < 4; params++) {//install all params START
			if (params == 0)array[i]->setPersonnelNumber(atoi(date[params + help].c_str()));
			if (params == 1)array[i]->setLastName(date[params + help]);
			if (params == 2)array[i]->setYearOfBirth(atoi(date[params + help].c_str()));
			if (params == 3)array[i]->setSalary(atoi(date[params + help].c_str()));//install all params END
		}
		help += 4;//0..3 params = 1 employee, if hasNext()-> 0+4(4)..3+4(7) params next Employee = 2,if hasNext()-> 4+4(8)..7+4(11) params next Employee = 3 and Td. .. 
	}
	file.close();
	for (int i = 0; i < amount; i++) {
		cout << "Date from File, lastName: " << array[i]->getLastName() << endl;
	}
	array[0]->setLastName("Kasperski"); //Change in New File (1)!!!
	//array[1]->setLastName("Ivanov2");

	for (int i = 0; i < amount; i++) {//ChangeS IN FILE, set Salary+=100 (2)!!!
		array[i]->setSalary(array[i]->getSalary() + 100);
	}

	ofstream fileOut;
	fileOut.open("C:\\file.txt"); //Rewritting Old File With New Date //!!!!!LOCATION!!!!!!!!LOCATION!!!!!!!!LOCATION!!!!!!!!!!!
	for (int i = 0; i < amount; i++) {
		fileOut << array[i]->getPersonnelNumber() << endl;
		fileOut << array[i]->getLastName() << endl;
		fileOut << array[i]->getYearOfBirth() << endl;
		fileOut << array[i]->getSalary() << endl;
	}

	fileOut.close();
	//END WORK WITH FILE

//for (int i = 0; i < amount; i++) {
//	delete[] array[i];
//}
	delete[] array;
	cout << "Array Deleted" << endl;


	//Paragraph A (ADD,CHANGES,DELETE)
	//SETTED - FROM CHANGES EMPLOYEE
	/*Employee person2 (person1); //PRIMER COPY
	cout << person1.getLastName();
	Employee *person3 = new Employee(); //PRIMER CREATE NEW EMPLOYEE
	person3->setPersonnelNumber(2); //PRIMER CHANGES
	person3->setSalary(200);
	person3->setYearOfBirth(2000);
	cout << person3->getLastName();
	delete person3;//PRIMER DELETED ????
	cout << person3->getLastName();*/





	system("pause");








}