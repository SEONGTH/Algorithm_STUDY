#include <iostream>
using namespace std;

#define for(i,n) for(int (i)=0;(i)<(n);(i)++) // 이렇게도 가능.


int main(){
    /*
    1.메인부터 짤것.
    2.입력을 어떻게 받을건지 결정
     ㄴ전역에 넣을지 지역에 넣을지.
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
