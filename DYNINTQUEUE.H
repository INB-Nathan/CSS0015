#include <iostream>
using namespace std;

class DynIntQueue{
    private:
    struct QueueNode{ // struct dahil dynamic which means gagamit tayo ng linked list wooooo!!! bali ung rear and front nanjan paren pero di mo gagalawin ung gitna
        int value;
        QueueNode* next;
    };
    QueueNode *front;
    QueueNode *rear;
    int numItems;
    public: // eto na ung mga functions
        DynIntQueue(void);
        ~DynIntQueue();
        void enqueue(int num);
        int dequeue();
        bool isEmpty();
        void clear();
};

DynIntQueue::DynIntQueue(void){ // constructor na maangaas, bali nag iniitialize lang ng mga values para kapag nacreate na si class eto agad mag rurun
    front = NULL;
    rear = NULL;
    numItems = 0;
}
DynIntQueue::~DynIntQueue(){ // destructor, bali eto ung mag cclear ng memory kapag natapos na si class wieeee
    clear();
}
void DynIntQueue::enqueue(int num){ // same lang ng static ginagawa naman neto is mag aallocate ng memory at mag iinsert ng value sa likod ng linked list
    QueueNode *newNode = new QueueNode; // gumagawa siya dynamic memory allocation para sa new node kc dynamic diba?!?!?!
    // same lang sa linked list ibig sabihin neto is mag iinsert ng value sa likod ng linked list
    newNode->value = num; // eto ung value na ininsert mo sa likod ng linked list
    newNode->next = NULL; // eto ung next na ininsert mo sa likod ng linked list which is wala ibig sabihin nasa likodsiya
    if (isEmpty()){ // kapag walang laman ung linked list ibig sabihin ung front at rear ay the same!!
        front = newNode; 
        rear = newNode;
    }else{ // kapag may laman na ung linked list ibig sabihin ung rear na pinaka huli mag ->next = newnode; siya ibig sabihin ung newNode coconnect sakanya and mangyayari is magiging rear na si newNode pero di pa defined na rear siya
        rear->next = newNode;
        rear = newNode; // dito na siya magiging rear
    }
    numItems++; // eto ung counter ng items sa linked list
}
int DynIntQueue::dequeue(){ // nag dedelete ng mga items sa linked list
    int num; // eto ung value na idelete mo
    QueueNode *temp; // eto ung temporary node na mag hohold ng value na idelete mo
    if (isEmpty()){ // self explanatory go girl
        cout << "The queue is empty.\n";
        return 0;
    }else{
        // eto ung value na idelete mo which is ung pinaka una kc queue, fifo!
        num = front->value;
        // eto ung temporary node na mag hohold ng value na idelete mo which is ung front
        temp = front;
        // ung magiging front naman dito is ung next na node ni front, kc nag front = front->next ka
        front = front->next;
        // then dedelete mo na ung value na want mo idelete which is ung pinakauna
        delete temp;
        // pang update lang ng numitems ng linked list
        numItems--;
        return num;
    }
}
bool DynIntQueue::isEmpty(){
    if (numItems){
        return false;
    }else{
        return true;
    }
}
void DynIntQueue::clear(){
    // queuenode *nodePtr is ung temporary node na mag hohold ng value na idelete mo
    QueueNode *nodePtr;
    while (!isEmpty()){
        // mag loloop lang to until ma empty na ung linked list
        // mangyayari is mag ddelete siya ng value sa front ng linked list hanggat ma empty na siya
        nodePtr = front;
        front = front->next;
        delete nodePtr;
    }
    // then eto ung mga values na ideinitialize mo ulit para maging 0 ulit siya
    front = NULL;
    rear = NULL;
    numItems = 0;

}
