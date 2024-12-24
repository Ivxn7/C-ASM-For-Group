#include "functions.h"

int main()
{
    int draws;
    int prize_num;
    int num_of_participants;
    char cont;
    int current_draw_size;
    int check_draw;

    do
    {   
        current_draw_size = 0;
        check_draw = 0;
        cout << "======================="<<endl;
        loading_ani("Initialising Lucky Draw");
        cout << "======================="<<endl;
        cout << "Calibration starts: ";
        cout << "Please enter:"<<endl;
        cout << "Number of participants: ";
        while (!(cin >> num_of_participants) || num_of_participants < 2)
        {
            cout << "Invalid input. Please have at least 2 participants: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        string *names = new string[num_of_participants];
        cout << "\nInput the names of participants" << endl;
        enter_name(names, num_of_participants);
        

        cout << "=======================\nNumber of lucky draws:";
        while (!(cin >> draws) || draws < 10 || draws > 100)
        {
            cout << "Invalid input. Please enter a draw number between 10 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "=======================\nNumber of prize:";
        while (!(cin >> prize_num) || prize_num > 10 || draws < 0)
        {
            cout << "Invalid input. Please set the number of prize less or equal than 10:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int *d_num = new int[draws];
        for (int j = 0; j < draws; j++) 
            d_num[j] = j + 1;
        string *prize = new string[prize_num];
        int *winning_draw = new int[prize_num];
        generate_prize(prize, prize_num, draws, winning_draw);
        
        for (int i = 0; i < 10; i++)
        {   if (check_draw == prize_num){
                cout << "The lucky draw has ended";
                break;
            }
            else if (current_draw_size != 0 && draws % current_draw_size == draws){
                cout <<"The lucky draw has ended";
                break;
            }
            else{
                cout << "========================================Round "<<i + 1<<" Starts========================================"<<endl;
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