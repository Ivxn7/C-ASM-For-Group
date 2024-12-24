#include <iostream>
#include <ctime>
#include <cstdlib>
#include <bits/stdc++.h>
#include<string>
#include<memory>
#include<vector>
#include <windows.h>
using namespace std;

string randomizer(vector<string> items_to_be_randomize);
int start_draw(string *names, int p_num, string *prize, int draws, int *winning_draw, int cds, int *d_num, int prize_num, int check_draw);
int check_names(string *names, int i);
void generate_prize(string *prize, int prize_num, int ori_draws, int *win);
void enter_name(string *names, int num_of_participants);
void loading_ani(string phrase);