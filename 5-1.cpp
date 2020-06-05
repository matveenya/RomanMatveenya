//()Класс дата. Операция - вывести какой день недели сейчас хранится в объекте
#include <iostream>
#include <string>

using namespace std;
class Date {
public:

	Date(int d = 2, int m = 6, int y = 2020) { 
		setDate(d, m, y);
	}

	Date(const Date& date) {
		setDate(date.day, date.month, date.year); // copy Date
	}

	void print() const {
		cout << day << '.'
			<< month << '.'
			<< year << endl;
	}

	bool isValidDate(int day, int month, int year) {
		if (month > 0 && month <= 12) {//cheak month January - December (1-12)
			if (month == 2) {//Cheak February
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
					if (day > 0 && day <= 29) return true;
					else return false;

				}
				else {
					if (day > 0 && day <= 28) return true;
					else return false;
				}
			}
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{//cheak Month where amount day =31
				if (day > 0 && day <= 31) return true;
				else return false;
			}
			else {
				if (day > 0 && day <= 30) return true;// else 30 day
				else return false;
			}
		}
		else {
			cout << "\n" << "Mouth <0 or >12";
			return false;
		}
		return true;
	}

	void setDay(int day) {
		this->day = day;
	}

	void setMonth(int month) {
		this->month = month;
	}

	void setYear(int year) {
		this->year = year;
	}

	void setDate(int day, int month, int year) {
		if (isValidDate(day, month, year)) {
			setDay(day);
			setMonth(month);
			setYear(year);
		}

		else {
			cout << "\n" << "Date is not Valid!";
			exit(1); //EXIT!!!!!!!!!!!!!!!! CAN DELETE 
		}

	}
	int getDay() const
	{
		return day;
	}
	int getMonth() const
	{
		return month;
	}

	int getYear() const
	{
		return year;
	}
	string getDayOfTheWeek(int day) {

	}

	string getDateOfTheWeek(int day, int month, int year) { 
		int a, y, m, R;
		a = (14 - month) / 12;
		y = year - a;
		m = month + 12 * a - 2;
		R = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
		R = R % 7;

		switch (R) {
		case 1:
			return "Monday";
			break;
		case 2:
			return "Tuesday";
			break;
		case 3:
			return "Wednesday";
			break;
		case 4:
			return "Thursday";
			break;
		case 5:
			return "Friday";
			break;
		case 6:
			return "Saturday";
			break;
		case 0:
			return "Sunday";
			break;
		default:
			return "Error dayOfTheWeek";
			break;
		}
	}

	~Date() { 
		// cout<<"\n";
	}

private:
	int day;
	int month;
	int year;


};


const int operator + (Date d1, Date d2) { //can changes + day
	return(d1.getDay() + d2.getDay());

}

const int operator - (Date d1, Date d2) { //can changes - day
	return(d1.getDay() - d2.getDay());

}

const int operator * (Date d1, Date d2) {//can changes * day
	return(d1.getDay() * d2.getDay());

}

const bool operator > (Date d1, Date d2) { //2020 > 2019...2010 and ....
	return(d1.getYear() > d2.getYear());
}
const bool operator < (Date d1, Date d2) {
	return(d1.getYear() < d2.getYear());
}

const bool operator == (Date d1, Date d2) {
	return(d1.getYear() == d2.getYear() && d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth());   //data 1 == data 2 if day and month and year == 
}

const bool operator != (Date d1, Date d2) {
	return(d1.getYear() != d2.getYear() || d1.getDay() != d2.getDay() || d1.getMonth() != d2.getMonth());
}

int main() {
	Date d0(15, 11, 2010);
	d0.print();
	d1.print();

	Date d2 = d1;
	d2.setDay(11);
	d2.print();

	Date* d3 = new Date;
	d3->print();

	Date* d4 = d3;
	d4->print();



	Date arr[5];
	arr[0] = d0;
	arr[1] = d1;
	arr[2] = d2;
	arr[3] = *d3;
	arr[4] = *d4;


	for (int i = 0; i < 5; i++) {
		cout << arr[i].getDay() << " - " << arr[i].getDateOfTheWeek(arr[i].getDay(), arr[i].getMonth(), arr[i].getYear()) << "\n"; 
	};

	cout << "\n" << "d1+d2 = " << d1 + d0; //GetDay
	cout << "\n" << "d1-d2 = " << d1 - d0;
	cout << "\n" << "d1*d2 = " << d1 * d0;

	bool is1 = d1 > d0; //0-False  1-True!!!!!
	bool is2 = d1 < d0;
	bool is3 = d1 == d0;
	bool is4 = d1 == d2;
	bool is5 = d1 != d0;
	bool is6 = d1 != d2;
	cout << "\n" << "d1>d0 = " << is1; //GetYear
	cout << "\n" << "d1<d0 = " << is2;
	cout << "\n" << "d1==d0 = " << is3;
	cout << "\n" << "d1==d2 = " << is4;

	cout << "\n" << "d1!=d0 = " << is5; //Get All date
	cout << "\n" << "d1!=d2 = " << is6;
}

