#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <string>

using namespace std;

struct Card
{
    int Number;
    char Color;
    int Card_Number;
};

struct Card* Shuffle_Cards(struct Card *Stack_Of_Cards, int Nr_Cards);

string Make_Small_Letters(string input);

void Play_BlackJack(struct Card *Stack_Of_Cards, int Nr_Cards);

int main()
{
  // Input
  int Nr_Cards_Per_Color = 13;
  int Nr_Colors = 4;
  
  
  int Nr_Cards = Nr_Cards_Per_Color * Nr_Colors;

  //char Colors[4] = {'C', 'H', 'R', 'S'}

  // Oldschool
  char *Colors = (char*)malloc((Nr_Colors+1) * sizeof(char));
  Colors[0] = 'C';
  Colors[1] = 'H';
  Colors[2] = 'R';
  Colors[3] = 'S';

  // Liste over kort vi skal ha i kortstokken
  struct Card *Stack_Of_Cards = (Card*)malloc(Nr_Cards * sizeof(Card));

  // Produserer kortstokken. Ikke shuffled
  int k = 0;
  for (int i = 1; i < (Nr_Cards_Per_Color+1); i++)
    {
      for (int j = 0; j < Nr_Colors; j++)
        {
          struct Card New_Card;
          New_Card.Color = Colors[j];
          New_Card.Card_Number = i;
          
          if (i == 1)
          {
              New_Card.Number = 11;
          }
          
          else if (i > 10)
          {
              New_Card.Number = 10;
          }
          
          else
          {
              New_Card.Number = i;
          }


          Stack_Of_Cards[k] = New_Card;
          k++;
        }
    }
  
  // Stokker kortstokken
  Stack_Of_Cards = Shuffle_Cards(Stack_Of_Cards, Nr_Cards);

  // Spiller blackjack. Kortstokken shuffles underveis i spillet også. Denne funksjonen er altså avhengig av "Shuffle_Cards()". 
  Play_BlackJack(Stack_Of_Cards, Nr_Cards);
  
  // For debugging
  //  for (int i = 0; i < Nr_Cards; i++)
  //{
      //cout << Stack_Of_Cards[i].Color << Stack_Of_Cards[i].Number << " ";
  //}

  // Fri opp minne
  free(Colors);
  //free(Stack_Of_Cards); // This memory is free'ed up in Play_Blackjack function
  // We send the mem-address into the function, so we do not need to free it up again
  
  // Hello world!
  cout << "Hello World" << endl;

  // Exit
  return 0;
}

void Play_BlackJack(struct Card *Stack_Of_Cards, int Nr_Cards)
{
    // Input
    int dealer_limit = 17;
    int Money_In_Bank = 10000;
    string Replay_Input = "yes";
    
    cout << "Lets play blackjack!" << endl;
    int max_nr_cards = 15;
    string Play_Again = "yes";
    
    struct Card *Dealers_Cards = (Card*)malloc(max_nr_cards * sizeof(Card));
    struct Card *Your_Cards = (Card*)malloc(max_nr_cards * sizeof(Card));
    
    
    
    
    while (Play_Again == Replay_Input)
    {
        Stack_Of_Cards = Shuffle_Cards(Stack_Of_Cards, Nr_Cards);

        int Current_Card = 0;

        cout << "You have " << Money_In_Bank << " moneys. Please enter your bet" << endl;
        int Bet;

        cin >> Bet;

        while (Bet > Money_In_Bank)
        {
            cout << "To high bet, you do not have enough money. Try again, you have " << Money_In_Bank << " to bet." << endl;
            cin >> Bet;
        }

        cout << endl;
        cout << "You bet " << Bet << " on this hand." << endl;

        int Current_Dealer_Card = 0;
        int Current_Your_Card = 0;
        int Dealer_Sum = 0;

        for (int J = 0; J < 2; J++)
        {
            if (J == 0)
                cout << "Dealer gets " << Stack_Of_Cards[Current_Card].Color << Stack_Of_Cards[Current_Card].Card_Number << endl;

            else
                cout << "Dealer gets one hidden card." << endl;
            Dealers_Cards[Current_Dealer_Card] = Stack_Of_Cards[Current_Card];
            Dealer_Sum += Dealers_Cards[Current_Dealer_Card].Number;
            Current_Card++;
            Current_Dealer_Card++;
        }

        cout << "Two cards for you" << endl;

        for (int J = 0; J < 2; J++)
        {
            cout << "You get " << Stack_Of_Cards[Current_Card].Color << Stack_Of_Cards[Current_Card].Card_Number << endl;
            Your_Cards[Current_Your_Card] = Stack_Of_Cards[Current_Card];
            Current_Card++;
            Current_Your_Card++;
        }

        bool continue_playing = true;
        bool Break_On_21;

        string Input;
        int Total_Sum;

        while (continue_playing)
        {
            Break_On_21 = false;
            Total_Sum = 0;
            for (int JJ = 0; JJ < Current_Your_Card; JJ++)
            {
                Total_Sum += Your_Cards[JJ].Number;
            }

            if (Total_Sum == 21)
            {
                cout << "You won!" << endl;
                Break_On_21 = true;

            }

            if (Total_Sum > 21)
            {
                bool Holds_Ace = false;

                for (int JJ = 0; JJ < Current_Your_Card; JJ++)
                {
                    if (Your_Cards[JJ].Number == 11)
                    {
                        // Put one ace to be value of 1 instead of 11
                        Your_Cards[JJ].Number = 1;
                        JJ = Current_Your_Card;
                        Holds_Ace = true;
                    }
                }

                if (Holds_Ace == false)
                {
                    // Over 21, you loose
                    cout << "You lost dude! " << endl;
                    continue_playing = false;
                    break;
                }

                else
                {
                    // If we had an ace we continue with lower total sum
                    Total_Sum = 0;
                    for (int JJ = 0; JJ < Current_Your_Card; JJ++)
                    {
                        Total_Sum += Your_Cards[JJ].Number;
                    }
                }
            }

            if (Break_On_21 == false)
            {

                cout << "You have " << Total_Sum << endl;
                cout << "Please enter hit or stand. Lets go!" << endl;

                cin >> Input;

                if (Input != "hit")
                {
                    continue_playing = false;
                    break;
                }
                
                else
                {
                    cout << "You get " << Stack_Of_Cards[Current_Card].Color << Stack_Of_Cards[Current_Card].Card_Number << endl;
                    Your_Cards[Current_Your_Card] = Stack_Of_Cards[Current_Card];
                    Current_Card++;
                    Current_Your_Card++;
                }
            }

            else
            {
                continue_playing = false;
                break;
            }


        }


        // If we are under 21 and we do not have exactly 21 then dealer plays
        if ((Total_Sum <= 21) && (Break_On_21 == false))
        {
            cout << "You got: " << Total_Sum << endl;
            cout << "Now dealer goes" << endl;
            cout << "Dealer shows " << Dealers_Cards[Current_Dealer_Card-1].Color <<
                    Dealers_Cards[Current_Dealer_Card-1].Card_Number << endl;
            cout << "Dealer has: " << Dealer_Sum << endl;

            // Dealer ends playing at dealer_limit
            while (Dealer_Sum <= dealer_limit)
            {
                cout << "Dealer is set to stop playing when hitting " << dealer_limit << endl;
                cout << "Dealer gets new card: " << Stack_Of_Cards[Current_Card].Color << Stack_Of_Cards[Current_Card].Card_Number << endl;
                Dealers_Cards[Current_Dealer_Card] = Stack_Of_Cards[Current_Card];
                Dealer_Sum += Dealers_Cards[Current_Dealer_Card].Number;
                Current_Card++;
                Current_Dealer_Card++;
                cout << "Dealer has: " << Dealer_Sum << endl;
            }

            if (Total_Sum > Dealer_Sum)
            {
                cout << "You win!" << endl;
                Money_In_Bank += Bet;
            }

            if (Total_Sum < Dealer_Sum)
            {
                cout << "You loose!" << endl;
                Money_In_Bank -= Bet;
            }

            if (Total_Sum == Dealer_Sum)
            {
                cout << "Draw..." << endl;
            }
        }

        else if (Break_On_21 == true)
        {
            Money_In_Bank += Bet;
        }

        else
        {
            Money_In_Bank -= Bet;
        }

        if (Money_In_Bank <= 0)
        {
            cout << "Your broke" << endl;
            break;
        }
        cout << "Play again?" << endl;
        cin >> Play_Again;
	Play_Again = Make_Small_Letters(Play_Again); // Sørg for at "YES", "Yes" og "yes" godtas som ja, brukeren vil spille igjen
    }

    free(Dealers_Cards);
    free(Your_Cards);
    free(Stack_Of_Cards);
}

struct Card* Shuffle_Cards(struct Card *Stack_Of_Cards, int Nr_Cards)
{
    cout << "Shuffling cards." << endl;
    
    // Funksjonen krever definisjon av struct Card i tillegg til
    // inkludering av cstdlib
    // Function to randomly shuffle cards
    
    int random_nr;
    bool *Used_Cards = (bool*)malloc(Nr_Cards * sizeof(bool));
    
    for (int i = 0; i < Nr_Cards; i++)
      Used_Cards[i] = false; // Keep track that no card is inserted twice in the shuffled stack of cards
    
    struct Card *Shuffled_Stack_Of_Cards = (Card*)malloc(Nr_Cards * sizeof(Card));
    
    for (int i = 0; i < Nr_Cards; i++)
    {
        random_nr = rand() % Nr_Cards; // pick a random card
        
        while (Used_Cards[random_nr] == true)
        {
            random_nr = rand() % Nr_Cards; // pick a new card if card is already used
        }
        
        Used_Cards[random_nr] = true;
        
        Shuffled_Stack_Of_Cards[i] = Stack_Of_Cards[random_nr]; // Put this card in shuffled deck
    }
    
    // Replace stack of cards and return new stacked one
    free(Used_Cards);
    free(Stack_Of_Cards);
    return Shuffled_Stack_Of_Cards;
}

string Make_Small_Letters(string input)
{
  string value = "no";

  // Brute force måte å sørge for at alt av "yes" skal godtas når vi spørr om bruker vil spille igjen.
  if ((input == "Yes") || (input == "yEs") || (input == "yES") || (input == "YES") || (input == "yeS") || (input == "YEs") || (input == "yes"))
    {
      value = "yes";
    }

  return value;
}  
