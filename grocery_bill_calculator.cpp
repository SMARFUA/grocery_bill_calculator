#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int max_members = 100;
int max_items = 100;
string item_list[100][100];
float price_list[100][100] = {0};
float sum_price[100];

void add_record(int row, int col, string item_list[][100], float price_list[][100], float sum_price[]){
    cout << "Enter Item name:" << flush;
    string item;
    cin >> item;

    for (int i = 0; i < col; ++i){
        item_list[row][i] = item;
    }

    cout << endl << "Total members item shared between:"<< flush;
    int member;
    cin >> member;

    cout << endl << "Names of members item shared between: " << endl;
    int names[member];
    int name;
    for(int i = 0; i< member; ++i){
        cin >> name;
        names[i] = name;
    }

    
    cout << endl << "Enter item price:" << flush;
    float shared_price;
    cin >> shared_price;
    for (int i = 0; i< member; ++i){
        price_list[row][names[i]] = shared_price/member;
        sum_price[names[i]] += price_list[row][names[i]];

    }


    cout << endl << " Next item ..."<< endl;
}
    

int main(){
    cout << "Total members:" << flush;
    int members;
    cin >> members;

    cout << "Total items:" << flush;
    int items;
    cin >> items;

    cout << endl << "Add Names of Members:" << endl;
    string name;
    for (int i = 0; i< members; ++i){
        cin >> name;
        item_list[0][i] = name;

    }

    cout << endl << "Start adding items..." << endl;
    for (int i = 1; i < items + 1; ++i){
       add_record(i, members, item_list, price_list, sum_price);
    }

    cout << endl;

    cout << "Final Result " << endl;

    for (int i = 0; i< members; ++i){
        cout<< "          "<< item_list[0][i] << "          " << flush;
    }
    cout << endl;

    for (int i = 1; i< items + 1; ++i){
        for (int j =0; j < members; ++j){
            cout << "          "<< i << "." << item_list[i][j] << ":" << price_list[i][j]<<"          " << flush;
        }
        cout << endl;

    }
    
    cout << "Total :" << flush;
    for (int i = 0; i< members; ++i){
            cout << "          " << sum_price[i] <<"         " <<  flush;
        }
        cout << endl;

    }

    