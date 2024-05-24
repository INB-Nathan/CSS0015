#include <iostream>
#include "DYNINTQUEUE.H"
using namespace std;
int main(){
    DynIntQueue iQueue;
    int value;
    cout << "Enqueuing (-1 to stop...\n";
    while(value != -1){
        cout << "Enter an integer: ";
        cin >> value;
        if(value != -1){
            iQueue.enqueue(value);
        }
    }
    cout << "Dequeuing...\n";
    while(!iQueue.isEmpty()){
        cout << iQueue.dequeue() << endl;
    }
    cout << "Attempting to dequeue again...\n";
    iQueue.dequeue();
    return 0;
}