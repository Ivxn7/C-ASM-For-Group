#include "functions.h"
int check_names(string *names, int i);
void enter_name(string *names, int num_of_participants);
// int main()
// {
//     srand(time(0));
//     int pax, choice, numprize;
//     int qtyprize[100];
//     char cont;
//     string name[100], prize[100];

//     do
//     {
//         cout << "Pleasse choose the mode...\n";
//         cout << "1)Single winner mode" << endl;
//         cout << "2)Three winner mode" << endl;
//         cout << "3)Custome mode" << endl;
//         cout << "Enter choice:";
//         cin >> choice;

//         if (choice == 1)
//         {

//             singlewinner(name, prize, pax, numprize, qtyprize);
//         }
//         else if (choice == 2)
//         {

//             triplewinner(name, prize, pax, numprize, qtyprize);
//         }
//         else if (choice == 3)
//         {
//             singlewinner(name, prize, pax, numprize, qtyprize);
//         }
//         else
//         {
//             cout << "Invalid input!!\n\n";
//         }
//         cout << "\nDo you want to continue(y/n):";
//         cin >> cont;
//     } while (cont == 'y' || cont == 'Y');

//     return 0;
// }
// void swap(string &a, string &b)
// {
//     string tmp;
//     tmp = a;
//     a = b;
//     b = tmp;
// }
void swap_int(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swap_ptr(string a, string b)
{
    string tmp;
    tmp = a;
    a = b;
    b = tmp;
}
string randomizer(vector<string> items_to_be_randomize)
{
    srand(time(0));
    string random;
    random = items_to_be_randomize[rand() % items_to_be_randomize.size()];
    return random;
}

void generate_prize(string *prize, int prize_num, int ori_draws, int *win)
{
    vector<string> p_name = {"luxury vacation package for two", "a high-end smartphone with accessories", "a premium smartwatch", "$200 gift card", "gourmet gift basket with chocolates and fine wines", "smart home device bundle", "one-year gym membership with fitness gear", "luxurious spa day", "VIP passes to a concert or sports event", "entertainment vouchers"};
    vector<string> tmp = p_name;
    int draws = ori_draws;
    int num[draws];
    for (int i = 0; i < prize_num; i++)
    {
        string get_prize = randomizer(tmp);
        prize[i] = get_prize;
        tmp.erase(find(tmp.begin(), tmp.end(), get_prize));
    }
    for (int i = 0; i < draws; i++)
    {
        num[i] = i + 1;
    }
    for (int i = draws - 1; i > draws - prize_num - 1; i--)
    { // Fisher Yates Shuffle Algo
        srand(time(NULL));
        int r = rand() % i;
        int tmp = num[i];
        num[i] = num[r];
        win[(draws - 1) - i] = num[r];
        num[r] = tmp;
        // for( int j=0; j<10; j++ ) //check util for algo array
        //     cout << num[j]<< " ";
        // cout <<endl;
    }
    // cout << "The winning draw: ";   //check util for win array
    // for( int j=0; j<3; j++ )
    //     cout << win[j]<< " ";
    // cout <<endl;
}
void start_draw(string *names, int p_num, string *prize, int draws, int *winning_draw, int cds, int *d_num)
{
    srand(time(0));
    int result;
    // string participants[2] = {"ivan", "yo"};
    for (int i = p_num - 1; i > 0; i--)
    {
        int r = rand() % i;
        swap_ptr(names[i], names[r]);   //problem here at the fisher Yates algo
    }
    cout << names[0];
    // cout << *names;
    
    // cout << participants[0];
    // cout <<
//     for (int i = 0; i < p_num; i++)
//     {
//         cout << "Participant: " << participants[i] << "You can draw now!"<<endl;
//         for (int j = draws - cds; j > draws - (draws - 1); j--)
//         {
//             int r_draws = rand() % j;
//             result = d_num[r_draws];
//             swap_int(d_num[j], d_num[r_draws]);
//         }
        
//         cout << "Participant "<<participants[i]<<" You have drawn a "<<result<<"!"<<endl;
//         auto it = find(winning_draw, winning_draw+p_num, result);
//         if (it != winning_draw + p_num)
//         {  
//             int idx = it - winning_draw;
//             cout << "You have won a "<<prize[idx]<<endl;
//         }
//     }
}

int main()
{
    int draws;
    int prize_num;
    int num_of_participants;
    char cont;
    int current_draw_size = 0;
    int draw_num[draws];

    do
    {
        cout << "Initialising Lucky Draw\n\nNumber of participants:";
        while (!(cin >> num_of_participants) || num_of_participants < 2)
        {
            cout << "Invalid input. Please have at least 2 participants ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string *names = new string[num_of_participants];
        cout << "Input the names of participants" << endl;
        enter_name(names, num_of_participants);
        

        cout << "Number of lucky draws:";
        while (!(cin >> draws) || draws < 10 || draws > 100)
        {
            cout << "Invalid input. Please enter a draw number between 10 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Number of prize:";
        while (!(cin >> prize_num) || prize_num > 10 || draws < 0)
        {
            cout << "Invalid input. Please set the number of prize less or equal than 10:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string *prize = new string[prize_num];
        int *winning_draw = new int[prize_num];
        generate_prize(prize, prize_num, draws, winning_draw);
        
        for (int i = 0; i < draws; i++)
            draw_num[i] = i + 1;
        for (int i = 0; i < 10; i++)
        {
            start_draw(names, num_of_participants, prize, draws, winning_draw, current_draw_size, draw_num);
            current_draw_size += 3;
        }

        cout << "\nDo you want to continue(y/n):";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');
}

// for (int i=0; i<num_of_participants;i++){ //debug line
//     cout << names[i] << endl;
// }

int check_names(string *names, int i)
{
    auto it = find(names, names + i, names[i]);
    if (it != names + i)
    {
        cout << "Name has already exists. Please choose another name:";
        cin >> names[i];
        return 0;
    }
    return 1;
}

void enter_name(string *names, int num_of_participants)
{

    for (int i = 0; i < num_of_participants; i++)
    {
        cout << "Enter participant " << i + 1 << "'s name: ";
        cin >> names[i];

        while (true)
        {
            int exist = check_names(names, i);
            if (exist == 1)
            {
                break;
            }
        }
    }
    return;
}
