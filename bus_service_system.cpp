
#include <iostream>
#include <fstream>
using namespace std;
int available = 10;
int booked_seats = 0;
bool seats[10] = {false};
void show()
{
    cout << "            ARYA BUS SERVICE              " << endl;
    for (int i = 0; i < 10; i += 2)
    {
        cout << i + 1 << " ";
        if (seats[i])
            cout << "BOOKED";
        else
            cout << "VACANT";
        cout << "        " << i + 2 << " ";
        if (seats[i + 1])
            cout << "BOOKED";
        else
            cout << "VACANT";
        cout << endl;
    }
    cout << "\n       BOOKED = Reserved    VACANT = Available" << endl;
    cout << "       Total Seats     : 10" << endl;
    cout << "       Booked Seats    : " << booked_seats << endl;
    cout << "       Available Seats : " << available << endl;
}
void booktickets()
{
    string name, pickup_city, drop_city;
    int no_of_seats;
    cout << "\nEnter your name: ";
    cin >> name;
    cout << "Enter number of seats you want to book: ";
    cin >> no_of_seats;
    if (no_of_seats <= 0)
    {
        cout << "Invalid number of seats!" << endl;
        return;
    }
    if (no_of_seats > available)
    {
        cout << "Not enough seats are available!" << endl;
        return;
    }
    cout << "Enter pickup city: ";
    cin >> pickup_city;
    cout << "Enter drop city: ";
    cin >> drop_city;
    ofstream bus("seat and traveller detaiil", ios::app);
    if (!bus)
    {
        cout << "File could not be opened!" << endl;
        return;
    }
    bus << "Traveller Name: " << name << endl;
    bus << "Number of Seats: " << no_of_seats << endl;
    bus << "Pickup City: " << pickup_city << endl;
    bus << "Drop City: " << drop_city << endl;
    bus.close();
    int count = 0;
    for (int i = 0; i < 10 && count < no_of_seats; i++)
    {
        if (seats[i] == false)
        {
            seats[i] = true;
            count++;
        }
    }
    available = available - no_of_seats;
    booked_seats = booked_seats + no_of_seats;
    cout << "\nSeats booked successfully!" << endl;
    show();
}
int main()
{
    int choice;
    while (true)
    {
        cout << "\n====================================" << endl;
        cout << "          ARYA BUS SERVICE           " << endl;
        cout << "====================================" << endl;
        cout << "1. Book Seats" << endl;
        cout << "2. View Bus Details" << endl;
        cout << "3. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                booktickets();
                break;
            case 2:
                show();
                break;
            case 3:
                cout << "\nThank you for using Arya Bus Service!" << endl;
                return 0;
            default:
                cout << "\nInvalid choice!" << endl;
        }
    }
    return 0;
}
