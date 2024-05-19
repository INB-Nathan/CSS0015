#include <iostream>
#include <list>
#include <string>
#include <stack>
using namespace std;

class Data {
    public:
        char braces;
};

void push(string& input, stack<Data, list<Data>>& xynate) {
    Data M4;
    for(char counter : input){
        M4.braces = counter;
        xynate.push(M4);
    }
}

int countBraces(stack<Data, list<Data>>& xynate) {
    int countopen = 0, countclose = 0;
    Data M4;
    while (!xynate.empty()){
        M4 = xynate.top();
        if (M4.braces == '{'){
            countopen++;
            xynate.pop();
        }
        else if (M4.braces == '}'){
            countclose++;
            xynate.pop();
        }
    }
    return abs(countopen - countclose);
}

int main(){
    stack<Data, list<Data>> xynate;
    string input;
    while(true){
        cout << "Enter a string of curly braces (! to stop): ";
        getline(cin, input);
        if(input == "!"){
            break;
        }
        push(input, xynate);
        int count = countBraces(xynate);
        if (count == 0){
            cout << "The string is balanced." << endl;
        } else {
            cout << "Number of replacements: " << count << endl;
        }
    }    
    return 0;
}
