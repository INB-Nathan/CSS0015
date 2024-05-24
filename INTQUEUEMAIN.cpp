#include <iostream>
#include "INTQUEUE.H"
using namespace std;
int main(){
    int size, value;
    cout << "How big should the queue be? ";
    cin >> size;
    IntQueue iQueue(size);
    cout << "Enqueuing";
    for(int i = 0; i < size; i++){
        cout << "Enter an integer: ";
        cin >> value;
        iQueue.enqueue(value);
    }
    cout << "Dequeuing 5 items...\n";
    while(!iQueue.isEmpty()){
        iQueue.dequeue();
        cout << value << endl;
    }
    cout << "Attempting to dequeue again...\n";
    iQueue.dequeue();
    return 0;
}