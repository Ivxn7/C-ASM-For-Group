#include "functions.h"

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
    {
        srand(time(NULL));
        int r = rand() % i;
        int tmp = num[i];
        num[i] = num[r];
        win[(draws - 1) - i] = num[r];
        num[r] = tmp;
        
    }
    cout << "The winning draw: "; //needs to be deleted
    for( int j=0; j<prize_num; j++ )
        cout << win[j]<< " ";
    cout <<endl;
}



int start_draw(string *names, int p_num, string *prize, int draws, int *winning_draw, int cds, int *d_num, int prize_num, int check_draw)
{
    int available;

    srand(time(0));
    cout << "=============================================================================================="<<endl;
    for (int i = p_num - 1; i > 0; i--)
    {
        int r = rand() % i;
        swap(names[i], names[r]);
        
    }
    int current_draw = cds;

    for (int i = 0; i < p_num; i++)
    {   
        available = draws - current_draw - 1;
        if(check_draw == prize_num){
            return check_draw;
        }
        else if (available == 0){
            cout << "Participant "<<names[i]<<" You have drawn a "<<d_num[0]<<"!"<<endl;
            auto it = find(winning_draw, winning_draw+prize_num, d_num[0]);
            if (it != winning_draw + prize_num)
            {  
                int idx = it - winning_draw;
                cout << "You have won a "<<prize[idx]<<endl;
                check_draw += 1;
            }
            cout << "----------------------------------------------------------"<<endl;
        }
        else
        {
            int r_draws = rand() % available;
            int result = d_num[r_draws];
            swap(d_num[available], d_num[r_draws]);
            current_draw += 1;
            cout << "Participant "<<names[i]<<" You have drawn a "<<result<<"!"<<endl;
            auto it = find(winning_draw, winning_draw+prize_num, result);
            if (it != winning_draw + prize_num)
            {  
                int idx = it - winning_draw;
                cout << "You have won a "<<prize[idx]<<endl;
                check_draw += 1;
            }
            cout << "----------------------------------------------------------"<<endl;
        }
    }
    return check_draw;
}

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

void loading_ani(string phrase)
{
    cout << phrase;
    
    for (int i=0; i<5; i++)
    {
        Sleep(250);
        cout << "." << flush;
        Sleep(250);
        cout << "." << flush;
        Sleep(250);
        cout << "." << flush;
        Sleep(250);
        cout << "\b\b\b   \b\b\b" << flush;
    }
    cout <<endl;
}