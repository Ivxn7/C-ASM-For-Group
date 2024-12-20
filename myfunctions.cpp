#include "functions.h"

void singlewinner(string name[], string prize[], int &pax, int &numprize, int qtyprize[])
{
    cout << "\n\nPlease enter the number of participants:";
    cin >> pax;

    cout << "\n\nPlease enter the names" << endl;
    for (int i = 0; i < pax; i++)
    {
        cout << "Name " << i + 1 << ":";
        cin >> name[i];
    }
    cout << "\n\nPlease enter the prize name" << endl;
    for (int i = 0; i < 1; i++)
    {
        cout << "Prize " << i + 1 << " :";
        cin >> prize[i];
        int winner = rand() % pax;
        cout << "\nThe lucky winner is:" << name[winner] << "!" << endl;
    }
}

void triplewinner(string name[], string prize[], int &pax, int &numprize, int qtyprize[])
{
    cout << "\n\nPlease enter the number of participants (no less than 3):";
    cin >> pax;

    cout << "\n\nPlease enter the names" << endl;
    for (int i = 0; i < pax; i++)
    {
        cout << "Name " << i + 1 << ":";
        cin >> name[i];
    }
    cout << "\n\nPlease enter the prize name" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Prize " << i + 1 << " :";
        cin >> prize[i];
    }
    for (int i = 0; i < 3; i++)
    {
        int winner = rand() % pax;
        cout << "\nThe " << prize[i] << " lucky winner is:" << name[winner] << "!" << endl;
    }
}