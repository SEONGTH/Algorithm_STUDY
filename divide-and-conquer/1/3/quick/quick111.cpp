#include <iostream>
using namespace std;

#define for(i,n) for(int (i)=0;(i)<(n);(i)++) // �̷��Ե� ����.


int main(){
    /*
    1.���κ��� ©��.
    2.�Է��� ��� �������� ����
     �������� ������ ������ ������.
    3.
    */
   int n, m;
   int *card, *question;

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n;
   card = new int[n];
   for(i, n){
       cin >> card[i];
   }
   for(i, n){
       cout<< card[i];
   }
   delete card;
   return 0;
}
