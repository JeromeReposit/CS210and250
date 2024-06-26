#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

// initalized functions
void oneSecond(int& hr, int& min, int& sec);
void oneMinute(int& hr, int& min, int& sec);
void oneHour(int& hr, int& min, int& sec);
void displayTime(int hr, int min, int sec);
int menu();
int main()
{
    // initialize hour, minute and seconds
    int hr;
    int min;
    int sec;
    int choice;
    cout << "Input Current Hours:";
    cin >> hr;
    cout << "Input Current Minutes:";
    cin >> min;
    cout << "Input Current Seconds:";
    cin >> sec;

    // do while loop until program exit with number 4
    do
    {
        displayTime(hr, min, sec); // display current time
        choice = menu(); // display input choice for the user menu

        // if else if statements for the menu input
        if (choice == 1) 
            oneHour(hr, min, sec);
        else if (choice == 2) 
            oneMinute(hr, min, sec);
        else if (choice == 3) 
            oneSecond(hr, min, sec);
        // use system("cls") to not repeat the menu program being printed again
    } while (choice != 4);
    


}

// updates seconds incrementing 1
void oneSecond(int& hr, int& min, int& sec) {

    sec++; 
    if (sec == 60) { 
        sec = 0;
        oneMinute(hr, min, sec);
    }
}

// updates minutes incrementing 1
void oneMinute(int& hr, int& min, int& sec)
{
    min++; 
    if (min == 60) 
    {
        min = 0;
        oneHour(hr, min, sec);
    }
}

// updates hour incrementing 1
void oneHour(int& hr, int& min, int& sec)
{
    hr++; 
    if (hr == 24) 
        hr = 0;

}

// display time inputting 3 arguments
void displayTime(int hr, int min, int sec)
{
    // 12 hour format conversion
    int hr12 = hr;
    string am_pm = "AM";

    if (hr == 0)
        hr12 = 12;
    else if (hr == 12)
        am_pm = "PM";
    else if (hr > 12) {
        am_pm = "PM";
        hr12 = hr - 12;
    }

    // time display design for both 12 and 24 hour format clocks
    cout << setw(10) << "" << string(26, '*') << setw(5) << "" << string(26, '*') << endl;
    cout << setw(10) << "" << "*" << setw(6) << "" << "12-Hour Clock" << setw(5) << "" << "*" << setw(5) << "" << "*" << setw(6) << "" << "24-Hour Clock" << setw(5) << "" << "*" << endl;
    cout << setw(10) << "" << "*" << setw(6) << "" << setw(2) << setfill('0') << hr12 << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec
        << "  " << am_pm << setw(6) << setfill(' ') << "" << "*" << setw(5) << "" << "*"
        << setw(6) << "" << setw(2) << setfill('0') << hr << ":" << setw(2) << setfill('0') << min << ":" << setw(2) << setfill('0') << sec
        << setw(10) << setfill(' ') << "" << "*" << endl;
    cout << setw(10) << "" << string(26, '*') << setw(5) << "" << string(26, '*') << endl;
}

// function that displays the menu 
int menu()
{
    // input integer choice for the menu update
    int choice;
    cout << endl << endl;
    cout << setw(25) << "" << string(26, '*') << endl;
    cout << setw(25) << "" << "* 1 - Add One Hour" << setw(7) << "" << "*" << endl;
    cout << setw(25) << "" << "* 2 - Add One Minute" << setw(5) << "" << "*" << endl;
    cout << setw(25) << "" << "* 3 - Add One Second" << setw(5) << "" << "*" << endl;
    cout << setw(25) << "" << "* 4 - Exit Program" << setw(7) << "" << "*" << endl;
    cout << setw(25) << "" << string(26, '*') << endl;

    cout << endl << "Enter a number from the prompted menu: ";
    cin >> choice;

    return choice;
}
