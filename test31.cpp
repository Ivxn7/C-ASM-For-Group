#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

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

int main()
{
    srand(time(0));
    int pax, choice, numprize;
    int qtyprize[100];
    char cont;
    string name[100], prize[100];

    do
    {
        cout << "Pleasse choose the mode...\n";
        cout << "1)Single winner mode" << endl;
        cout << "2)Three winner mode" << endl;
        cout << "3)Custome mode" << endl;
        cout << "Enter choice:";
        cin >> choice;

        if (choice == 1)
        {

            singlewinner(name, prize, pax, numprize, qtyprize);
        }
        else if (choice == 2)
        {

            triplewinner(name, prize, pax, numprize, qtyprize);
        }
        else if (choice == 3)
        {
            singlewinner(name, prize, pax, numprize, qtyprize);
        }
        else
        {
            cout << "Invalid input!!\n\n";
        }
        cout << "\nDo you want to continue(y/n):";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
