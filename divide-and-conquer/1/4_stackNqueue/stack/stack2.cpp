#include <iostream>
#include <stdlib.h>
using namespace std;

//Node : stack에 들어갈 값
struct Node{ //node 구조체
    struct Node* next; //next
    int n;
};

void menu();
void printNodes(struct Node* p);

int main(){
    int flag = 1;
    int input;

    struct Node *head; //first
    struct Node *last; //last
    struct Node *node; //temp

    head = NULL;
    last = NULL;
    //초기화

    while(flag){
        int n=0;
        int count=0;
        cout<<endl;
        cin >> input;
        count++;
        if(input == -1){
            flag = 0;
        }else{
            node = (struct Node*)malloc(sizeof(struct Node));
            //node 구조체 동적 할당

            node-> n = input;
            node-> next =NULL;
            //node 구조체 값 설정

            if(head==NULL){//연결리스트가 비어있을경우
                head=node;//head에 생성된 node 저장
            }
            else{//아님말고.
                last->next=node;//마지막노드에next노드 저장
            }
            last=node;
            //연결리스트에 추가된 node 주소를 last에 저장
        }
    }
    printNodes(head);
}
void menu(){
    cout<<"enter number : / "<<endl<<"press -1 to exit";
}
	
void printNodes(struct Node* p){
	while(p!=NULL){
		cout<<"|"<<p->n<<"|";
		p=p->next;
	}
}
