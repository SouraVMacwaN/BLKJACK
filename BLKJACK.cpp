#include <bits/stdc++.h>
#include <ctime>
using namespace std;
#define ll long long
void blackjack(int total_comp , int total_user)         // initial hand

{
  if(total_comp == 21)
    {
      cout << "dealer's blackjack u lost";
    }
    else if(total_user == 21)
    {
      cout << "U WON !!! ";
    }
    else if(total_user == 21 && total_comp == 21)
    {
      cout << "Draw";
    }
    else{

    }
}
void main_game(int total_comp , int total_user ,int cards[])
{
  abc:
  char c;
  int gen_num;
  cout << " HIT (h)   STAND (s)    EXIT(e)\n";
  cin >> c;
  if(c == 'h')
  {
   
      gen_num = (rand() % (13));
      total_user += cards[gen_num];
      cout << "       YOUR CARDS\n         "<< total_user << " \n\n";
      if(total_user > 21)
      {
        cout << "   Dealer's total = "<< total_comp; 
         cout << "\n\n**********YOU LOSE**************\n";
      }
      else if(total_user = 21)
      {
        cout << "\n\n**********YOU WON**************\n";
      }
      else{
      goto abc;
      }
  
  }

  if(c == 's')
  {

    abcd :
    if((total_user > total_comp) && (total_comp >= 16))
    {
      cout << "   Dealer's total = "<< total_comp; 
      cout << "\n**********U WON**************";
    }
     else if(total_user == total_comp)
    {
      cout << "   Dealer's total = "<< total_comp; 
  cout << "\n*********DRAW*************";
    }
    else if((total_user > total_comp) && (total_comp < 16))
    {
      while(total_comp < 16)
      {
        int generated_num = (rand() % (13));
        total_comp += cards[generated_num];
        goto abcd;
      }
    }
    else if((total_user < total_comp) && (total_comp > 21))
    {
      cout << "   Dealer's total = "<< total_comp; 
      cout << "\n**********U WON**************";
    }
    else
    {
      cout << "   Dealer's total = "<< total_comp; 
      cout << "\n\n***********U LOSE *************";
    }
  }
}


int main()
{
    int cards[13] = {11,2,3,4,5,6,7,8,9,10,10,10,10} , total_comp = 0, total_user = 0, generated_num , sample_space[3];
    srand(time(0));                   // Initialize random number generator.
    for(int i = 0 ; i < 4; i++)
    {
      generated_num = (rand() % (13));
      sample_space[i] = cards[generated_num];
    }
  total_comp = sample_space[0] + sample_space[1];
  total_user = sample_space[2] + sample_space[3];

                                     

  cout << "     DEALER's NUMBER\n           " << sample_space[0] << "  |*|" << "\n\n"; 
  cout << "       YOUR CARDS\n         "<< sample_space[2] << "    " << sample_space[3] << "\n\n";
  cout << " TOTAL =  " << total_user << "\n\n";

  if((total_user == 21) || (total_comp == 21))
    blackjack(total_comp, total_user);
  
  else
    main_game(total_comp, total_user , cards);
   
}
