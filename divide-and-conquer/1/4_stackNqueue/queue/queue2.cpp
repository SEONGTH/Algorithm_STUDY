#include <iostream>
using namespace std;

int n; // size of circle
int count;
int front;
int back;
int num;

void insertMode();
void printMode();
int deleteMode();

bool isFull();
bool isEmpty();

int main(){
    while(1){ 
        cout << "press 1 to print  mode\n";
        cout << "press 2 to delete mode\n";
        cout << "press 3 to insert mode\n";
        int mode=0;
        if(mode == 1){
            printMode();
        }
        else if(mode == 2){
            deleteMode();
        }
        else if(mode == 3){
            insertMode();
        }
    }
}
void insertMode(){
    cout << "enter number"<<endl;
    cin >> num;
    if(isFull()){
        cout << "queue is full"<<endl;
        break; // is it work?
    }
    else{
        back = (back++)%n;
        arr[back] = num;
    }
}

void deleteQueue(){
    if(isEmpty()){
        cout << "queue is empty"<<endl;
        break;
    }
    else{
        front = (front++)%n;
        return arr[front];
    }
}

bool isEmpty(){
    if(front==back){
        return true;
    }
    else{
        return false;
    }
}
