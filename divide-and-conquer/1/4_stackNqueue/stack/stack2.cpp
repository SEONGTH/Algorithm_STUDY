#include <iostream>
#include <stdlib.h>
using namespace std;

//Node : stack�� �� ��
struct Node{ //node ����ü
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
    //�ʱ�ȭ

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
            //node ����ü ���� �Ҵ�

            node-> n = input;
            node-> next =NULL;
            //node ����ü �� ����

            if(head==NULL){//���Ḯ��Ʈ�� ����������
                head=node;//head�� ������ node ����
            }
            else{//�ƴԸ���.
                last->next=node;//��������忡next��� ����
            }
            last=node;
            //���Ḯ��Ʈ�� �߰��� node �ּҸ� last�� ����
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
