#include "functions.h"

string randomizer(vector<string> items_to_be_randomize)  //function to pick a prize randomly for each winning draw.
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
    for (int i = 0; i < prize_num; i++) //based on the number of prize, assign the prizes into the prize array. Chosen prize will be erased.
    {
        string get_prize = randomizer(tmp);
        prize[i] = get_prize;
        tmp.erase(find(tmp.begin(), tmp.end(), get_prize));
    }
    for (int i = 0; i < draws; i++) //generate a temporary array with all the draw numbers up to the total draws.
    {
        num[i] = i + 1;
    }
    for (int i = draws - 1; i > draws - prize_num - 1; i--) //randomly select the winning draws from the temporary array. Selected numbers will be not be picked again.
    {
        srand(time(NULL));
        int r = rand() % i;
        int tmp = num[i];
        num[i] = num[r];
        win[(draws - 1) - i] = num[r];
        num[r] = tmp;
        
    }
    // cout << "The winning draw: "; //to check the winning draw
    // for( int j=0; j<prize_num; j++ )
    //     cout << win[j]<< " ";
    // cout <<endl;
}



int start_draw(string *names, int p_num, string *prize, int draws, int *winning_draw, int cds, int *d_num, int prize_num, int check_draw)
{
    int available;

    srand(time(0));
    cout << "=============================================================================================="<<endl;
    for (int i = p_num - 1; i > 0; i--) //randomise the order of participants each round
    {
        int r = rand() % i;
        swap(names[i], names[r]);
        
    }
    int current_draw = cds;

    for (int i = 0; i < p_num; i++) //loop n amount of times, n = number of participants
    {   
        available = draws - current_draw - 1; //the amount of draws left.
        if(check_draw == prize_num){  //check if the amount of drawn price is equal to the number of prize. If this statement is true, lucky draw ends.
            return check_draw;
        }
        else if (available == 0){  //If there's only 1 draw left, automatically gives the draw number to the corresponding participant.
            cout << "Participant "<<names[i]<<" You have drawn a "<<d_num[0]<<"!"<<endl;
            auto it = find(winning_draw, winning_draw+prize_num, d_num[0]);
            if (it != winning_draw + prize_num) //check if the number is a winning draw
            {  
                int idx = it - winning_draw;
                cout << "You have won a "<<prize[idx]<<endl;
                check_draw += 1;
            }
            cout << "----------------------------------------------------------"<<endl;
        }
        else
        {

            //r_draws is assigned with a randomly selected index in the range of 1 and the number of available draws. Then, the algo will find the number in the d_num array based on the given index. The selected number will then be swapped with the last number in the array. Current_draw will be incremented by 1 and available will be decremented by 1 simultaneously. In this way, the indexes of the numbers that are less than available will not be picked anymore.//
            int r_draws = rand() % available; 
            int result = d_num[r_draws];
            swap(d_num[available], d_num[r_draws]);
            current_draw += 1;
            cout << "Participant "<<names[i]<<" You have drawn a "<<result<<"!"<<endl;
            auto it = find(winning_draw, winning_draw+prize_num, result); //check if the number is a winning draw
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

int check_names(string *names, int i) //check if the user input name has already exist
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

void enter_name(string *names, int num_of_participants) //prompt user to input name
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

void loading_ani(string phrase) //a small loading terminal output for aesthetic purposes.
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