/*
Summary:
This program simulates a simple airline reservation system where users can view seat information and book tickets. The seat layout is represented by a 2D array.

Steps:
1. Declare function prototypes for seatInfo, bookTicket, and updateSeatInfo.
2. Implement the main function with a menu allowing users to view seat information or book tickets.
3. Implement the seatInfo function to display the current seat booking status.
4. Implement the bookTicket function to facilitate ticket booking, checking seat availability, and updating the seat information.
5. Implement the updateSeatInfo function to mark the selected seat as booked and return the reservation status.
6. Use a while loop to repeatedly prompt the user for input until they choose to exit.

*/

#include<iostream>
#include<string>
using namespace std;

// Declare the function prototypes
void seatInfo(string seatArray[][4], int seatRows, int seatCols);
void bookTicket(string seatArray[][4], int seatRows, int seatCols);
string updateSeatInfo(string seatArray[][4], int seatRows, int seatCols, int updateRow, int updateCol, string input);

int main()
{
    cout << "\"Welcome to R-Airlines\"";
    cout << "\n----------------------";
    const int seatRows = 3, seatCols = 4;
    string seatArray[3][4] =
    {
        {"1A", "1B", "1C", "1D"},
        {"2A", "2B", "2C", "2D"},
        {"3A", "3B", "3C", "3D"}
    };

    while (true)
    {
        char firstEntry;
        cout << "\n*Enter 'R' to Continue | 'Q' to Exit:  ";
        cin >> firstEntry;

        if (firstEntry == 'R' || firstEntry == 'r')
        {
            int choice;
            cout << "\nRoute: CBE->BAN";
            cout << "\n1 Seat info\n2 Book Ticket";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                // Call the seatInfo function
                seatInfo(seatArray, seatRows, seatCols);
                break;

            case 2:
                // Call the function for booking ticket
                bookTicket(seatArray, seatRows, seatCols);
                break;

            default:
                cout << "\nInvalid choice.";
            }
        }
        else if (firstEntry == 'Q' || firstEntry == 'q')
        {
            cout << "\nThank you, Have a nice journey";
            break;
        }
        else
        {
            cout << "\nInvalid Login/Exit Entry";
        }
    }
    return 0;
}

// Implement the seatInfo function
void seatInfo(string seatArray[][4], int seatRows, int seatCols)
{
    cout << "\n\nSeat Booking Status:\n";

    for (int i = 0; i < seatRows; i++)
    {
        for (int j = 0; j < seatCols; j++)
        {
            cout << seatArray[i][j] << " ";
        }
        cout << "\n";
    }
}

// Implement the bookTicket function
void bookTicket(string seatArray[][4], int seatRows, int seatCols)
{
    cout << "\nTicket Booking:";

    string duplicateSeatArray[3][4] =
    {
        {"1A", "1B", "1C", "1D"},
        {"2A", "2B", "2C", "2D"},
        {"3A", "3B", "3C", "3D"}
    };
    string input, decision;

    cout << "\nEnter seat Num: ";
    cin >> input;
    
    int updateRow = input[0] - '0';  // Convert the first character to an integer

    cout << "\nConfirm your ticket no: " << input << " (Y/N): ";
    cin >> decision;

    if (decision == "Y" || decision == "y")
    {
        int updateCol, colFoundFlag = 0;
        for (int j = 0; j < seatCols; j++)
        {
            if (duplicateSeatArray[updateRow - 1][j] == input)
            {
                updateCol = j;
                colFoundFlag = 1;
            }
        }

        if (colFoundFlag == 1)
        {
            string reserveFlag = updateSeatInfo(seatArray, seatRows, seatCols, updateRow, updateCol, input);

            if (reserveFlag == "In")
            {
                cout << "\nYour booking ticket no. " << input << " confirmed.";
                seatInfo(seatArray, seatRows, seatCols);  // Display updated seat information
            }
            else if (reserveFlag == "Out")
            {
                cout << "\nTicket no. " << input << " is already booked";
                seatInfo(seatArray, seatRows, seatCols);  // Display updated seat information
            }
            else
            {
                cout << "\nInvalid seat selection.";
            }
        }
        else
        {
            cout << "\nInvalid seat selection.";
        }
    }
    else if (decision == "N" || decision == "n")
    {
        cout << "\nBooking cancelled.";
    }
    else
    {
        cout << "\nInvalid confirmation";
    }
}

// Implement the updateSeatInfo function
string updateSeatInfo(string seatArray[][4], int seatRows, int seatCols, int updateRow, int updateCol, string input)
{
    if (seatArray[updateRow - 1][updateCol] == input)
    {
        seatArray[updateRow - 1][updateCol] = "-X";  // Mark the seat as booked
        return "In";  // Reservation successful
    }
    else if (seatArray[updateRow - 1][updateCol] == "-X")
    {
        return "Out";  // Seat is already booked
    }
    else
    {
        return "Invalid";  // This case should not be reached if the input is valid
    }

    seatInfo(seatArray, seatRows, seatCols);  // Display updated seat information
}
