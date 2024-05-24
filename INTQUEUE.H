#include <iostream>
using namespace std;

class IntQueue{
    private: // member variables lang to
        int* queueArray;
        int queueSize;
        int front;
        int rear;
        int numItems;
    public: // eto na ung mga functions
        IntQueue(int);
        ~IntQueue();
        void enqueue(int);
        int dequeue();
        bool isEmpty() const;
        bool isFull() const;
        void clear();
};

IntQueue::IntQueue(int size){
    // Allocate memory for the queue array
    queueArray = new int[size];
    // Assign the size of the queue
    queueSize = size;
    // Initialize front and rear -1 siya kasi kapag 0 siya ibig sabihin may laman na ung first index ng array
    front = -1;
    rear = -1;
    // Initialize number of items
    numItems = 0;
}

IntQueue::~IntQueue(){
    delete [] queueArray;
}

void IntQueue::enqueue(int num){
    if(isFull()){
        cout << "The queue is full.\n";
    }else{
        // Calculate the new rear position
        rear = (rear + 1) % queueSize; // Alternative: rear++
        // Insert new item
        queueArray[rear] = num;
        // Update item count
        numItems++;
    }
}

int IntQueue::dequeue(){
    int num;
    if(isEmpty()){
        cout << "The queue is empty.\n";
    }else{
        // Move front position forward bali ginagawa lang neto para manesure na kapag it reaches the end na mangyayari is babalik siya sa start
        front = (front + 1) % queueSize; // Alternative: front++
        // Retrieve the front item
        num = queueArray[front];
        // Update item count
        numItems--;
    }
    return num;
}

bool IntQueue::isEmpty() const{
    if(numItems > 0){
        return false;
    }else{
        return true;
    }
}

bool IntQueue::isFull() const{
    if(numItems < queueSize){
        return false;
    }else{
        return true;
    }
}

void IntQueue::clear(){
    front = -1;
    rear = -1;
    numItems = 0;
}

