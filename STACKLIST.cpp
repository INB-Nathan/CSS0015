#include <iostream>
#include <list>
#include <stack>
using namespace std;

struct Data{
    int id;
    string name;
};

int main(){
    // declare a stack object
    // the stack will be implemented using a linked-list
    // the stack will accept the structure named Data as its element
    stack<Data, list<Data>> records; //list stack, si Data ung tatanggapin na struct ng stack, list<data> ung list na gagamitin
    // eto ung variables for the input
    int id;
    string name;
    // dedeclare mo ung structure variable
    Data data;
    while (true){
        cout << "Enter ID Number (-1 to stop): ";
        cin >> id;
        cin.ignore();
        if (id < 0) break; // mag iistop si loop pag -1 na
        cout << "Enter Name: ";
        getline(cin, name);
        // dito mag seset the values of the record
        data.id = id;
        data.name = name;
        // dito ka na mag pupush ng droga which is an element
        records.push(data);
    }
    cout << "Getting all records: " << endl;
    while (!records.empty()){
        // dito ung mag reretrieve the values at the top of the stack tsaka iloloop nya hanggang wala ng laman
        data = records.top();
        cout << "ID Number: " << data.id << endl;
        cout << "Name: " << data.name << endl;
        records.pop();
    }
}
