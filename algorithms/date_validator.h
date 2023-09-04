#ifndef DATE_VALIDATOR_H
#define DATE_VALIDATOR_H

#include <iostream>

#define _MINIMUM_DAY_ 1
#define _MAXIMUM_DAY_ 31
#define _30_DAYS_MONTH_ 30
#define _31_DAYS_MONTH_ 31
#define _FEB_TWYENTY_NINE_ 29
#define ZERO 0

#define NUMBER_FORMAT 1
#define STRING_FORMAT 2

enum MONTHS {JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};



class Date {
    private:
        int year;
        int month;
        int day;

		int print_format; // 1 = numbers, 2 = letter months

    public:
        Date();
		Date(int, int, int);
        Date(int, int, int, int);

        // getters and setters
        void set_year(int);
        int get_year();
        void set_month(int);
        int get_month();
        void set_day(int);
        int get_day();
		void set_print_format(int);
		int get_print_format();
		string get_string_month_format() const;

        // methods
        bool date_validator();


        // istream operator overload (>>)
		friend std::istream& operator>>(std::istream& is, Date* date) {
			cout << "year: "; is >> date->year;
			cout << "month: "; is >> date->month;
			cout << "day: "; is >> date->day;
			return is;
		}

		// ostream operator overload (<<)
		friend std::ostream& operator<<(std::ostream& os, const Date* date) {
            if (date->day < 10) {
                os << "0";
            }
			os << date->day << "/";
            
			if ( date->print_format == 1 ) {
				if (date->month < 10) {
                	os << "0";
            	}
            	os << date->month << "/"; 
			} else {
				os << date->get_string_month_format() << "/";
			}

			if ( date->year < 10 ) {
				os << "000" << date->year;
			} else if ( date->year < 100 ) {
				os << "00" << date->year;
			} else if ( date->year < 1000 ) {
				os << "0" << date->year;
			} else {
				os << date->year;
			}

			return os;
		}

};

Date::Date() {
    this->year = 2000;
    this->month = 1;
    this->day = 1;
	this->print_format = NUMBER_FORMAT;
}

Date::Date(int year, int month, int day) {
    this->year = year;
    this->month = month;
    this->day = day;
	this->print_format = NUMBER_FORMAT;
}

Date::Date(int year, int month, int day, int print_format) {
    this->year = year;
    this->month = month;
    this->day = day;

	if ( print_format == NUMBER_FORMAT || print_format == STRING_FORMAT ) {
		this->print_format = print_format;
	} else {
		this->print_format = NUMBER_FORMAT;
	}
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

void Date::set_print_format(int print_format) {
	if ( print_format < NUMBER_FORMAT || print_format > STRING_FORMAT ) {
		this->print_format = print_format;
	} else {
		this->print_format = NUMBER_FORMAT;
	}
}

int Date::get_print_format() {
	return this->print_format;
}

string Date::get_string_month_format() const {
	string MONTHS[12];
	MONTHS[0] = "JAN";
	MONTHS[1] = "FEB";
	MONTHS[2] = "MAR";
	MONTHS[3] = "APR";
	MONTHS[4] = "MAY";
	MONTHS[5] = "JUN";
	MONTHS[6] = "JUL";
	MONTHS[7] = "AUG";
	MONTHS[8] = "SEP";
	MONTHS[9] = "OCT";
	MONTHS[10] = "NOV";
	MONTHS[11] = "DEC";

	if ( month >= 1 && month <= 12 ) {
		return MONTHS[month - 1];
	} else {
		return "MONTH INVALID";
	}
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