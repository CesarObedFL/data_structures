#ifndef DATE_VALIDATOR_H
#define DATE_VALIDATOR_H

#include <iostream>

#define _MINIMUM_DAY_ 1
#define _MAXIMUM_DAY_ 31
#define _30_DAYS_MONTH_ 30
#define _31_DAYS_MONTH_ 31
#define _FEB_TWYENTY_NINE_ 29
#define ZERO 0

enum months {JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};

class Date {
    private:
        int year;
        int month;
        int day;

    public:
        Date();
        Date(int, int, int);

        // getters and setters
        void set_year(int);
        int get_year();
        void set_month(int);
        int get_month();
        void set_day(int);
        int get_day();

        // methods
        bool date_validator();


        // istream operator overload (>>)
		friend std::istream& operator>>(std::istream& is, Date* date) {
			is >> date->year >> date->month >> date->day;
			return is;
		}

		// ostream operator overload (<<)
		friend std::ostream& operator<<(std::ostream& os, const Date* date) {
            if (date->day < 10) {
                os << "0";
            }
			os << date->day << "/";
            if (date->month < 10) {
                os << "0";
            }
            os << date->month << "/"; 
            os << date->year;
			return os;
		}

};

Date::Date() {
    this->year = 2000;
    this->month = 1;
    this->day = 1;
}

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::set_year (int year) {
	this->year = year;
}

int Date::get_year () {
	return this->year;
}

void Date::set_month (int month) {
	this->month = month;
}

int Date::get_month () {
	return this->month;
}

void Date::set_day (int day) {
	this->day = day;
}

int Date::get_day () {
	return this->day;
}

bool Date::date_validator() {
    if (this->day < _MINIMUM_DAY_ || this->day > _MAXIMUM_DAY_ || this->month < JAN || this->month > DEC)  {
		return false;

	} else {
		bool date_validated = false;
		int month_days; // month's calculating variable
		
		if (this->month == FEB) {
			month_days = FEB;

		} else if (this->month == APR || this->month == JUN || this->month == SEP || this->month == NOV) {
			month_days = _30_DAYS_MONTH_;

		} else {
			month_days = _31_DAYS_MONTH_;
		}

		switch (month_days) {
			case FEB:
					if (this->day == _FEB_TWYENTY_NINE_) {     //calcular el año bisiesto
						if (((this->year%4)==ZERO && (this->year%100)!=ZERO) ||  ((this->year%400) == ZERO)) { 
							date_validated = true;
						} else {
							date_validated = false;
                        }

					} else if (this->day <= 28){
						date_validated = true;

					} else {
						date_validated = false;
                    }
					break;

			case _30_DAYS_MONTH_:
					if (this->day <= _30_DAYS_MONTH_) {
						date_validated = true;

					} else {
						date_validated = false;
                    }
					break;

			case _31_DAYS_MONTH_:
					date_validated = true;
					break;

			default:
				date_validated = false;
				break;
		}

		return date_validated;//*/
	}
}




#endif