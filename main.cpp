#include "functions.h"

int main()
{
    int draws;                      //number of draws
    int prize_num;                  //number of prize
    int num_of_participants;        //number of participants
    char cont;                      //do while
    int current_draw_size;
    int check_draw;

    do
    {   
        current_draw_size = 0;
        check_draw = 0;
        cout << "======================="<<endl;    //initialise lucky draw (from line 16 to line 48.)
        loading_ani("Initialising Lucky Draw");
        cout << "======================="<<endl;
        cout << "Calibration starts: ";
        cout << "Please enter:"<<endl;
        cout << "Number of participants: ";
        while (!(cin >> num_of_participants) || num_of_participants < 2) //participants cannot be less than 2.
        {
            cout << "Invalid input. Please have at least 2 participants: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        string *names = new string[num_of_participants];
        cout << "\nInput the names of participants" << endl;
        enter_name(names, num_of_participants); //check if there are duplicate names
        

        cout << "=======================\nNumber of lucky draws:";
        while (!(cin >> draws) || draws < 10 || draws > 100) // number of draws cannot be less than 10 and more than 100
        {
            cout << "Invalid input. Please enter a draw number between 10 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "=======================\nNumber of prize:";
        while (!(cin >> prize_num) || prize_num > 10 || prize_num < 1) //prize cannot be more than 10 and less than 1.
        {
            cout << "Invalid input. Please set the number of prize less or equal than 10:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int *d_num = new int[draws];   
        for (int j = 0; j < draws; j++)  //this for loop initialise an array to store a number of elements equivalent to the draws.
            d_num[j] = j + 1;
        string *prize = new string[prize_num];
        int *winning_draw = new int[prize_num];
        generate_prize(prize, prize_num, draws, winning_draw); //generate winning draws and the prize for each winning draws.
        
        for (int i = 0; i < 10; i++)
        {   if (check_draw == prize_num){           //check_draw will be incremented if the prize is drawn. If check_draw is equal to prize_num, which is the total number of prize, the lucky draw will end.
                cout << "The lucky draw has ended";
                break;
            }
            else if (current_draw_size != 0 && draws % current_draw_size == draws){ //check if the amount of drawn numbers is equal to draws.
                cout <<"The lucky draw has ended";
                break;
            }
            else{
                cout << "========================================Round "<<i + 1<<"  Starts========================================"<<endl; //starts each round for the lucky draw.
                loading_ani("The participants are drawing");
                check_draw = start_draw(names, num_of_participants, prize, draws, winning_draw, current_draw_size, d_num, prize_num, check_draw);
                current_draw_size += num_of_participants;
            }
        }

        cout << "\nDo you want to continue(y/n):";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
    return 0;
}