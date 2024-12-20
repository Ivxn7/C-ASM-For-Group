#include "functions.h"
// #include <bits/stdc++.h>

// string randomizer(vector<string> items_to_be_randomize){
//     srand(time(0));
//     string random;
//     random = items_to_be_randomize[rand() % items_to_be_randomize.size()];
//     return random;
// }

// int main(){
    
//     vector<string> p_name = {"luxury vacation package for two", "a high-end smartphone with accessories", "a premium smartwatch", "$200 gift card", "gourmet gift basket with chocolates and fine wines", "smart home device bundle", "one-year gym membership with fitness gear", "luxurious spa day", "VIP passes to a concert or sports event", "entertainment vouchers"};
//     string *prize = new string[3];
//     int prize_num = 3;
//     vector<string> tmp= p_name;
//     for (int i=0; i<prize_num; i++){
//         srand(time(0));
//         string get_prize = randomizer(tmp);
//         prize[i] = get_prize;
//         tmp.erase(find(tmp.begin(), tmp.end(), get_prize));
//     }
//     for (auto i : tmp)
//         cout << i << " "<< endl;
//     for (int i=0; i<prize_num; i++){
//         cout <<"\n\n\n\n\n";
//         cout << prize[i]<<endl;
//     }
// }

#include <iostream>
#include <stdlib.h>
#include <time.h>
#define N1 5
#define N2 10
using namespace std;

// main(){
//     int len = 10-5+1 , i , r , temp;
//     int num[len];

//     for( temp=0,i=5; temp<len; i++,temp++ ){
//         num[temp] = i;
//         // cout << num[temp]<<"\n\n";

//     }


//     srand( time(NULL) );  //seed rand()

//     //Fisher–Yates shuffle algorithm
//     for( i=len-1; i>0; i-- ){
//         r = rand()%i;
        
//         temp = num[i];
        
//         num[i] = num[r];
        
//         num[r] = temp;
//         for( int j=0; j<6; j++ )
//             cout << num[j]<< " ";
//         cout <<endl;
//     }

//     // for( i=0; i<len; i++ )
//     //     cout << num[i] << endl;
// }
void swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
int main(){
    srand(time(NULL));
    int prize_num = 3;
    int draws = 11;
    int num[draws];
    int win[3];
    for (int i=0; i<draws;i++){
        num[i] = i+1;
    }
    for (int i=draws-1;i>draws-prize_num-1;i--){ //Fisher Yates Shuffle Algo
        int r = rand()%i;
        // int tmp = num[i];
        // num[i] = num[r];
        // win[(draws-1)-i] = num[r];
        // num[r] = tmp;
        swap(num[i],num[r]);
        for( int j=0; j<11; j++ ) //check util
            cout << num[j]<< " ";
        cout <<endl;        
    }
    // for( int j=0; j<3; j++ ) //check util
    //     cout << win[j]<< " ";
    // cout <<endl;   
    // cout << draws-(draws-prize_num);
}