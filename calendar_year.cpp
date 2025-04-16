#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

// Function to calculate the day of the week for the 1st of a given month and year
int getStartDay(int year, int month) {
    int day = 1;
    int y = year - (14 - month) / 12;
    int m = month + 12 * ((14 - month) / 12) - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

// Function to display the calendar for a given year
void displayCalendar(int year) {
    string months[] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};
    int daysInMonth, startDay = getStartDay(year, 1);

    for (int month = 1; month <= 12; ++month) {
        daysInMonth = getDaysInMonth(month, year);

        // Print the month header
        cout << "\n  " << months[month - 1] << " " << year << endl;
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        // Print leading spaces for the first week
        for (int i = 0; i < startDay; ++i) {
            cout << "     ";
        }

        // Print the days of the month
        for (int day = 1; day <= daysInMonth; ++day) {
            cout << setw(5) << day;
            if ((day + startDay) % 7 == 0 || day == daysInMonth) {
                cout << endl;
            }
        }

        // Update the start day for the next month
        startDay = (startDay + daysInMonth) % 7;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <year>" << endl;
        return 1;
    }

    int year = stoi(argv[1]);
    if (year < 1) {
        cerr << "Invalid year. Please enter a positive integer." << endl;
        return 1;
    }

    displayCalendar(year);
    return 0;
}