#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <unistd.h>

using namespace std;

class userpoke
{
public:
int HP;
int XP;
int level;
};

void win()
{
        sleep(2);
        cout << "\nYou win the Pokemon fight!\n";
}

void lose()
{
        sleep(2);
        cout << "\nYour Pokemon fainted!\n";
        sleep(1);
        cout << "\nYou lose the Pokemon fight!\n";
        sleep(1);
        cout << "\nYour Pokemon was scurried to the nearest Pokemon center.\n\n";
        sleep(1); cout << "                 ."; sleep(1); cout << "."; sleep(1); cout << ".\n";
        sleep(1);
        cout << "\nYour Pokemon's health was refilled!";
}
//Global Var runtime
int runtime = 0;
int wildbattle(int wildBattleHealth);
int gymbattle(int gymBattleHealth);
int bossbattle(int bossBattleHealth);
int main()
{
        string name;
        string pokemonName;
        int poke1;
        srand(time(0));
        cout << "Enter your name: ";
        cin >> name;
        sleep(2);
        cout << "\nHello, " << name << ". You are a Pokemon master!\n";
        sleep(1);
        cout << "\nWhat would be your first Pokemon?\n";
        sleep(1);
Poke_Choice:
        cout << "\nPress 1 for Charmander, 2 for Bulbasaur and 3 for Squirtle.\n";
        cin >> poke1;
        userpoke firstpoke;
        firstpoke.HP = 20;
        firstpoke.XP = 0;
        firstpoke.level = 1;
        int freshHealth = firstpoke.HP;
        int tempHP;
        int XPcheck1 = 40;
        int XPcheck2 = 120;
        int XPcheck3 = 250;
        int XPcheck4 = 500;
        int maxHPinc = 5;
        switch (poke1)
        {
        case 1:
                pokemonName = "Charmander";
                break;
        case 2:
                pokemonName = "Bulbasaur";
                break;
        case 3:
                pokemonName = "Squirtle";
                break;
        default:
                cout << "Sorry. Press a valid key.";
                goto Poke_Choice;
        }
        cout << "\nYou chose: " << pokemonName << "! Now you can travel along with your pokemon partner.\n";
        int replay = 0;
        int direct;
        int proceed;
        int gym = 0;
        string dir;
        sleep(2);
        cout << "  \n                                    #######\n";
        sleep(1);
        cout << "\nYou want to go to the nearest gym to win your first gym badge.\nBut you lost your way!\n\n";
        sleep(2);
        cout << "You remember obtaining a parchment from someone.\nYou open and view the content of the parchment\n\n";
        sleep(2);
        cout << "The parchment says: FLRFRLF.\nConfused, you look around.\nYou see tall grass everywhere.\n\n";

        while (replay == 0)
        {
                sleep(2);
                if (runtime == 1)
                {
                        cout << "\nThe parchment's contents flash before you: FLRFRLF\n\n";
                }

Movement:
                cout << "Press 1 to move forward.\nPress 2 to move left.\nPress 3 to move right.\n";
                cin >> direct;
                switch (direct)
                {
                case 1:
                        dir = "forward.";
                        if ((gym == 0) || (gym == 3) || (gym == 6))
                        {
                                gym = ++gym;
                        }
                        break;

                case 2:
                        dir = "left.";
                        if ((gym == 1) || (gym == 5))
                        {
                                gym = ++gym;
                        }
                        break;

                case 3:
                        dir = "right.";
                        if ((gym == 2) || (gym == 4))
                        {
                                gym = ++gym;
                        }
                        break;

                default:
                        cout << "\nEnter a valid key.\n";
                        goto Movement;
                }
                cout << "\nYou move " << dir << endl;
                //Gym Reach Test
                if (gym < 7)
                { //Before Gym Sequemce
                        int wild = rand() % 3 + 1;
                        if (wild == 1)
                        {
                                sleep(1);
                                cout << "\nYou see no one around.\n";
                        }
                        else
                        {
                                sleep(1);
                                cout << "\nYou encounter a wild pokemon!\n";
                                tempHP = wildbattle(firstpoke.HP);
                                firstpoke.HP = tempHP;
                                if (firstpoke.HP == 112233)
                                {
                                        sleep(1);
                                        cout << "\nYour pokemon does not recieve any XP.\n";
                                        firstpoke.HP = 1;
                                        goto Exp_skip;
                                }

                                if (firstpoke.HP > 0)
                                {
                                        //EXP Gain
                                        int tempXP;
                                        if (firstpoke.level < 5)
                                        {
                                                tempXP = rand() % 20 + 10;
                                        }
                                        if ((firstpoke.level >= 5) && (firstpoke.level < 10))
                                        {
                                                tempXP = rand() % 30 + 50;
                                        }
                                        int tempLevel;
                                        sleep(1);
                                        cout << "\nYour pokemon gained: " << tempXP << " XP!\n";
                                        firstpoke.XP = firstpoke.XP + tempXP;
                                        switch (firstpoke.level)
                                        {
                                        case 1:
                                                tempLevel = XPcheck1;
                                                break;
                                        case 2:
                                                tempLevel = XPcheck2;
                                                break;
                                        case 3:
                                                tempLevel = XPcheck3;
                                                break;
                                        case 4:
                                                tempLevel = XPcheck4;
                                                break;
                                        }
                                        //Level up check
                                        if (firstpoke.XP >= tempLevel)
                                        { //Level up sequence
                                                sleep(2);
                                                cout << "\nCongratulations! Your pokemon levelled up!\n";
                                                firstpoke.level = firstpoke.level + 1;
                                                cout << pokemonName << " is now level " << firstpoke.level << "! \n";
                                                freshHealth = freshHealth + maxHPinc;
                                                firstpoke.HP = freshHealth;
                                                cout << pokemonName << " now has " << firstpoke.HP << " HP!\n";
                                        }
                                }

Exp_skip:
                                if (firstpoke.HP < 8)
                                {
                                        //Pokemon faint check
                                        if (firstpoke.HP == -112233)
                                        {
                                                firstpoke.HP = freshHealth;
                                        }
                                        else
                                        {
                                                //Low health refill
                                                int pokecenter;
                                                sleep(1);
                                                cout << "\n" << pokemonName << "'s HP is low.\n";
                                                sleep(1);
                                                cout << "\nPress 1 to visit a pokemon center, nearby. Press 0 to Forfeit.\n";
                                                cin >> pokecenter;
                                                if (pokecenter != 1)
                                                {
                                                        sleep(1);
                                                        cout << "\nYou decide not to visit the pokemon center.\n";
                                                }
                                                else
                                                {
                                                        sleep(1);
                                                        cout << "\nYou visit the pokemon center. " << pokemonName << "'s HP was refilled.\n";
                                                        firstpoke.HP =  freshHealth;
                                                }
                                        }
                                }
                        }
                }
                else
                {
                        //Gym Sequence
                        sleep(2);
                        cout << "\n                                   ########\n";
                        sleep(1);
                        cout << "\nYou could spot a pokemon gym in the distance.\n You rush towards the big dome.\n";
                        sleep(1);
                        cout << "\nYou spot your friend Steven near the gym.\n You wave to him as he starts speaking.\n";
                        sleep(1);
                        cout << "\nSTEVEN: Hey, " << name << "! How you doing? Checking the new gym out huh?\n";
                        sleep(1);
                        cout << "\nSTEVEN: Anyways, I heard that the gym leader ROCK, is a tough guy.\n";
                        sleep(1);
                        cout << "\nSTEVEN: Make sure, your pokemon are well trained, before you get inside.\n";
                        sleep(1);

                        int potionchoice;
                        cout <<  "\nSTEVEN: And oh! Seems like your pokemon keeps runnning out of health!\n";
                        sleep(1);
                        cout << "\nSTEVEN: Here's a HP potion to catch up!\n";
                        sleep(1);
                        cout << "\nRecieved HP potion!\n";
                        sleep(1);
                        cout << "\nYou put the potion into your bag. Use it when needed.\n";



Trainer1:
                        //Rock Gym
                        sleep(1);
                        cout << "\nPress 1 to continue.\n";
                        cin >> proceed;
                        sleep(2);
                        cout << "\nTRAINER ONE: Brace yourself! Be prepared for a nasty surprise!\n";
                        sleep(2);
                        tempHP = gymbattle(firstpoke.HP);
                        firstpoke.HP = tempHP;
                        if (firstpoke.HP > 0)
                        {
                                //EXP Gain
                                int tempXP;
                                if (firstpoke.level < 5)
                                {
                                        tempXP = rand() % 20 + 10;
                                }
                                if ((firstpoke.level >= 5) && (firstpoke.level < 10))
                                {
                                        tempXP = rand() % 30 + 50;
                                }
                                int tempLevel;
                                sleep(1);
                                cout << "\nYour pokemon gained: " << tempXP << " XP!\n";
                                firstpoke.XP = firstpoke.XP + tempXP;
                                switch (firstpoke.level)
                                {
                                case 1:
                                        tempLevel = XPcheck1;
                                        break;
                                case 2:
                                        break;
                                        tempLevel = XPcheck2;
                                case 3:
                                        tempLevel = XPcheck3;
                                        break;
                                case 4:
                                        tempLevel = XPcheck4;
                                        break;
                                }
                                //Level up check
                                if (firstpoke.XP >= tempLevel)
                                { //Level up sequence
                                        sleep(2);
                                        cout << "\nCongratulations! Your pokemon levelled up!\n";
                                        firstpoke.level = firstpoke.level + 1;
                                        cout << pokemonName << " is now level " << firstpoke.level << "! \n";
                                        freshHealth = freshHealth + maxHPinc;
                                        firstpoke.HP = freshHealth;
                                        cout << pokemonName << " now has " << firstpoke.HP << " HP!\n";
                                }
                        }

                        int pokecenter = 0;
                        if (firstpoke.HP < 8)
                        {
                                //Pokemon faint check
                                if (firstpoke.HP == -112233)
                                {
                                        firstpoke.HP = freshHealth;
                                        goto Trainer1;
                                }
                                else
                                {
                                        //Low health refill
                                        sleep(1);
                                        cout << "\n " << pokemonName << "'s HP is low.\n";
                                        sleep(1);
                                        cout << "\nPress 1 to visit a pokemon center, nearby. Press 0 to Forfeit.\n";
                                        cin >> pokecenter;
                                        if (pokecenter != 1)
                                        {
                                                sleep(1);
                                                cout << "\nYou decide not to visit the pokemon center.\n";
                                        }
                                        else
                                        {
                                                sleep(1);
                                                cout << "\nYou visit the pokemon center. " << pokemonName << "'s HP was refilled.\n";
                                                firstpoke.HP =  freshHealth;
                                        }
                                }
                        }

                        sleep(1);
pokecc:
                        if (pokecenter == 0)
                        {
                        int pokec;
                        cout << "\nPress 1 to visit the pokemon center. Press 0 to proceed.\n";
                        cin >> pokec;
                        switch (pokec)
                           {
                              default:
                                   sleep(1);
                                   cout << "\nEnter a valid key.\n";
                                   goto pokecc;
                                   break;

                              case 1:
                                   sleep(1);
                                   cout << "\nYou visit the pokemon center. " << pokemonName << "'s HP was refilled.\n";
                                   firstpoke.HP =  freshHealth;
                                   break;

                              case 2:
                                   sleep(1);
                                   cout << "\nYou decide not to visit the pokemon center.\n";
                                   break;

                           }
                        }

Trainer2:
                        cout << "\nPress 1 to continue.\n";
                        cin >> proceed;
                        sleep(2);
                        cout << "\nTRAINER TWO: It's time to get freaked out. Rock gyms are really tough!\n";
                        sleep(2);
                        tempHP = gymbattle(firstpoke.HP);
                        firstpoke.HP = tempHP;
                        if (firstpoke.HP > 0)
                        {
                                //EXP Gain
                                int tempXP;
                                if (firstpoke.level < 5)
                                {
                                        tempXP = rand() % 20 + 10;
                                }
                                if ((firstpoke.level >= 5) && (firstpoke.level < 10))
                                {
                                        tempXP = rand() % 30 + 50;
                                }
                                int tempLevel;
                                sleep(1);
                                cout << "\nYour pokemon gained: " << tempXP << " XP!\n";
                                firstpoke.XP = firstpoke.XP + tempXP;
                                switch (firstpoke.level)
                                {
                                case 1:
                                        tempLevel = XPcheck1;
                                        break;
                                case 2:
                                        break;
                                        tempLevel = XPcheck2;
                                case 3:
                                        tempLevel = XPcheck3;
                                        break;
                                case 4:
                                        tempLevel = XPcheck4;
                                        break;
                                }
                                //Level up check
                                if (firstpoke.XP >= tempLevel)
                                { //Level up sequence
                                        sleep(2);
                                        cout << "\nCongratulations! Your pokemon levelled up!\n";
                                        firstpoke.level = firstpoke.level + 1;
                                        cout << pokemonName << " is now level " << firstpoke.level << "! \n";
                                        freshHealth = freshHealth + maxHPinc;
                                        firstpoke.HP = freshHealth;
                                        cout << pokemonName << " now has " << firstpoke.HP << " HP!\n";
                                }
                        }

                        int pokecenter2 = 0;
                        if (firstpoke.HP < 8)
                        {
                                //Pokemon faint check
                                if (firstpoke.HP == -112233)
                                {
                                        firstpoke.HP = freshHealth;
                                        goto Trainer1;
                                }
                                else
                                {
                                        //Low health refill
                                        sleep(1);
                                        cout << "\n " << pokemonName << "'s HP is low.\n";
                                        sleep(1);
                                        cout << "\nPress 1 to visit a pokemon center, nearby. Press 0 to Forfeit.\n";
                                        cin >> pokecenter2;
                                        if (pokecenter2 != 1)
                                        {
                                                sleep(1);
                                                cout << "\nYou decide not to visit the pokemon center.\n";
                                        }
                                        else
                                        {
                                                sleep(1);
                                                cout << "\nYou visit the pokemon center. " << pokemonName << "'s HP was refilled.\n";
                                                firstpoke.HP =  freshHealth;
                                        }
                                }
                        }

                        sleep(1);
pokecc2:
                        if (pokecenter2 == 0)
                        {
                        int pokec2;
                        cout << "\nPress 1 to visit the pokemon center. Press 0 to proceed.\n";
                        cin >> pokec2;
                        switch (pokec2)
                           {
                              default:
                                   sleep(1);
                                   cout << "\nEnter a valid key.\n";
                                   goto pokecc2;
                                   break;

                              case 1:
                                   sleep(1);
                                   cout << "\nYou visit the pokemon center. " << pokemonName << "'s HP was refilled.\n";
                                   firstpoke.HP =  freshHealth;
                                   break;

                              case 2:
                                   sleep(1);
                                   cout << "\nYou decide not to visit the pokemon center.\n";
                                   break;

                           }
                    }
Trainer3:

                          cout << "\nPress 1 to continue.\n";
                          cin >> proceed;
                          sleep(2);
                          cout << "\nTRAINER THREE: You are really tough. But let's see how you manage through this!\n";
                          sleep(2);
                          tempHP = gymbattle(firstpoke.HP);
                          firstpoke.HP = tempHP;
                          if (firstpoke.HP > 0)
                          {
                                  //EXP Gain
                                  int tempXP;
                                  if (firstpoke.level < 5)
                                  {
                                          tempXP = rand() % 20 + 10;
                                  }
                                  if ((firstpoke.level >= 5) && (firstpoke.level < 10))
                                  {
                                          tempXP = rand() % 30 + 50;
                                  }
                                  int tempLevel;
                                  sleep(1);
                                  cout << "\nYour pokemon gained: " << tempXP << " XP!\n";
                                  firstpoke.XP = firstpoke.XP + tempXP;
                                  switch (firstpoke.level)
                                  {
                                  case 1:
                                          tempLevel = XPcheck1;
                                          break;
                                  case 2:
                                          break;
                                          tempLevel = XPcheck2;
                                  case 3:
                                          tempLevel = XPcheck3;
                                          break;
                                  case 4:
                                          tempLevel = XPcheck4;
                                          break;
                                  }
                                  //Level up check
                                  if (firstpoke.XP >= tempLevel)
                                  { //Level up sequence
                                          sleep(2);
                                          cout << "\nCongratulations! Your pokemon levelled up!\n";
                                          firstpoke.level = firstpoke.level + 1;
                                          cout << pokemonName << " is now level " << firstpoke.level << "! \n";
                                          freshHealth = freshHealth + maxHPinc;
                                          firstpoke.HP = freshHealth;
                                          cout << pokemonName << " now has " << firstpoke.HP << " HP!\n";
                                  }
                          }

                          int pokecenter3 = 0;
                          if (firstpoke.HP < 8)
                          {
                                  //Pokemon faint check
                                  if (firstpoke.HP == -112233)
                                  {
                                          firstpoke.HP = freshHealth;
                                          goto Trainer1;
                                  }
                                  else
                                  {
                                          //Low health refill
                                          sleep(1);
                                          cout << "\n " << pokemonName << "'s HP is low.\n";
                                          sleep(1);
                                          cout << "\nPress 1 to visit a pokemon center, nearby. Press 0 to Forfeit.\n";
                                          cin >> pokecenter2;
                                          if (pokecenter3 != 1)
                                          {
                                                  sleep(1);
                                                  cout << "\nYou decide not to visit the pokemon center.\n";
                                          }
                                          else
                                          {
                                                  sleep(1);
                                                  cout << "\nYou visit the pokemon center. " << pokemonName << "'s HP was refilled.\n";
                                                  firstpoke.HP =  freshHealth;
                                          }
                                  }
                          }

                          sleep(1);
  pokecc3:
                          if (pokecenter3 == 0)
                          {
                          int pokec3;
                          cout << "\nPress 1 to visit the pokemon center. Press 0 to proceed.\n";
                          cin >> pokec3;
                          switch (pokec3)
                             {
                                default:
                                     sleep(1);
                                     cout << "\nEnter a valid key.\n";
                                     goto pokecc3;
                                     break;

                                case 1:
                                     sleep(1);
                                     cout << "\nYou visit the pokemon center. " << pokemonName << "'s HP was refilled.\n";
                                     firstpoke.HP =  freshHealth;
                                     break;

                                case 2:
                                     sleep(1);
                                     cout << "\nYou decide not to visit the pokemon center.\n";
                                     break;

                             }
                          }

BOSS1:
                          sleep(1);
                          cout << "\nPress 1 to continue.\n";
                          cin >> proceed;
                          sleep(2);
                          cout << "\nYour pokemon is fully healed for the boss battle.\n";
                          firstpoke.HP = freshHealth;
                          sleep(2);
                          cout << "\nGYM LEADER: Hello young man! I've heard of you.\n";
                          sleep(2);
                          cout << "\nGYM LEADER: " << name << " isn't it? Very skilfull.\n";
                          sleep(2);
                          cout << "\nGYM LEADER: But be warned. I ain't like the other trainers.\n";
                          sleep(2);
                          cout << "\nGYM LEADER: And I'll finish you in an instant!\n";
                          sleep(2);
                          tempHP = bossbattle(firstpoke.HP);
                          firstpoke.HP = tempHP;
                          if (firstpoke.HP == -112233)
                          {
                            firstpoke.HP = freshHealth;
                            goto BOSS1;
                          }
                          else
                          {
                            sleep(2);
                            cout << "\nGYM LEADER: Wow. That was the most epic duel I've ever seen!\n";
                            sleep(2);
                            cout << "\nGYM LEADER: " << name << ". You truly deserve your first badge.\n";
                            sleep(2);
                            cout << "\nRecieved ROCK BADGE from Gym Leader ROCK!\n";
                            sleep(2);
                            cout << "\nCongratulations! You have won a gym badge! You completed the game!\n";
                            sleep(2);
                            cout << "\nThank you for playing this game!\n";
                            sleep(4);
                            cout << "\n                                ##########CREDITS##########\n";
                            sleep(2);
                            cout << "\nMaking it very short, this game was developed only by me, Sabesh Bharathi (Indie developer)\n";
                            sleep(2);
                            cout << "\nAbout two weeks of hard work and about 1200 lines of code, I managed to complete this game.\n";
                            sleep(2);
                            cout << "\nThank you so much and your support is very well welcomed.\n";
                            sleep(2);
                            cout << "\nAdios... \n";
                            system("Pause");
                            replay = 1;
                          }


                }


        }
        return 0;
}

int wildbattle(int wildBattleHealth)
{
        srand(time(0));
        int run;
        int randWildPoke = rand () % 5 + 1;
        string wildPoke;
        int wildPokeSpeed;
        int wildPokeHP;
        int userPokeSpeed;
        //Random Wild Pokemon Generation
        switch (randWildPoke)
        {
        case 1:
                wildPoke = "Pikachu";
                wildPokeSpeed = 5;
                wildPokeHP = 15;
                break;
        case 2:
                wildPoke = "Bulbasaur";
                wildPokeSpeed = 3;
                wildPokeHP = 18;
                break;
        case 3:
                wildPoke = "Abra";
                wildPokeSpeed = 6;
                wildPokeHP = 9;
                break;
        case 4:
                wildPoke = "Pidgey";
                wildPokeSpeed = 7;
                wildPokeHP = 13;
                break;
        case 5:
                wildPoke = "Odish";
                wildPokeSpeed = 4;
                wildPokeHP = 10;
                break;
        }
        sleep(1);
        cout << "\n                             ########\n\n";
        sleep(1);
        cout << "\nWild " << wildPoke << " appears.\n";
        sleep(1);
        cout << "\nWild " << wildPoke << " has " << wildPokeHP << " HP.\n";
        sleep(1);
        cout << "\nPress 1 to attack, 2 to flee\n";
        cin >> run;
        if (run == 2)
        {
                int flee = rand() % 3 + 1;
                if (flee != 2)
                {
                        sleep(1);
                        cout << "\nYou escaped successfully!\n";
                        sleep(1);
                        cout << "\nBut your pokemon trips and loses its HP!\n";
                        sleep(1);
                        cout << "\nYou could decide whether to visit the pokemon center.\n";
                        wildBattleHealth = 112233;
                }
                else
                {
                        int fleeatk = rand() % 3 + 1;
                        sleep(1);
                        cout << "\nCan't escape!\n";
                        sleep(1);
                        cout << "\nWild Pokemon attacks you! Dealing: " << fleeatk << " damage.\n";
                        wildBattleHealth = wildBattleHealth - fleeatk;
                        if (wildBattleHealth > 0)
                        {
                                cout << "\nYour Pokemon has " << wildBattleHealth << " HP left.\n";
                                goto Attack_Sequence;
                        }
                        else
                        {
                                lose();
                                wildPokeHP = 0;
                                wildBattleHealth = -112233;
                        }
                }

        }
        else if (run != 1)
        {
                sleep(1);
                cout << "\nPlease enter a valid key.\n";
        }
        else
        {
                if (runtime == 0)
                {
                        sleep(1);
                        cout << "\nThis is the Attack sequence.\n ";
                        sleep(1);
                        cout << "\nYour pokemon has two different types of attacks.\n";
                        sleep(1);
                        cout << "\nThe Quick Attack promises a quick delivery but a low attack. \n";
                        sleep(1);
                        cout << "\nThe Special Attack on the other hand, gives a slow, strong blow. \n";
                        sleep(1);
                        cout << "\nYou can now, choose your attack.\n";
                        runtime = 1;
                        goto Attack_Sequence;
                }
                else
                {
Attack_Sequence:

                        int atkchoice;
                        string atkType;
                        while (wildPokeHP > 0)
                        {
                                int compatk = rand() % 3 + 1;
                                int randatk = rand() % 4 + 3;
                                int fatk = randatk - 1;
                                int spatk = randatk + 1;
                                int useratk;
                                sleep(1);
                                cout << "\nPress 1 for Quick Attack.\nPress 2 for Special Attack.\n";
                                cin >> atkchoice;
                                switch (atkchoice)
                                {
                                //Attack Choice Simulator
                                case 1:
                                        userPokeSpeed = 7;
                                        useratk = fatk;
                                        atkType = "Quick Attack.";
                                        break;

                                case 2:
                                        userPokeSpeed = 4;
                                        useratk = spatk;
                                        atkType = "Special Attack.";
                                        break;
                                }
                                sleep(1);
                                cout << "\nYou chose: " << atkType << endl;
                                if (wildPokeSpeed > userPokeSpeed)
                                { //Enemy attacks first.
                                        sleep(1);
                                        cout << "\nWild " << wildPoke << " attacks you!\n";
                                        sleep(1);
                                        cout << "\nWild " << wildPoke << " deals: " << compatk << " damage.\n";
                                        wildBattleHealth = wildBattleHealth - compatk;
                                        sleep(1);
                                        //Check if user lost all HP
                                        if (wildBattleHealth > 0)
                                        {
                                                cout << "\nYour pokemon has: " << wildBattleHealth << " HP left.\n";
                                                sleep(2);
                                                cout << "\nYour pokemon attacks, and deals: " << useratk << " damage.\n";
                                                wildPokeHP = wildPokeHP - useratk;
                                                sleep(1);
                                                //Check if enemy lost all HP
                                                if (wildPokeHP > 0)
                                                {
                                                        cout << "\nWild " << wildPoke << " has " << wildPokeHP << " HP left.\n";
                                                }
                                                else
                                                {
                                                        sleep(1);
                                                        cout << "\nWild Pokemon fainted!\n";
                                                        win();
                                                }
                                        }
                                        else
                                        {
                                                lose();
                                                wildPokeHP = 0;
                                                wildBattleHealth = -112233;
                                        }
                                }
                                else if (wildPokeSpeed <= userPokeSpeed)
                                { //User attacks first
                                        sleep(1);
                                        cout << "\nYour pokemon attacks, and deals: " << useratk << " damage.\n";
                                        wildPokeHP = wildPokeHP - useratk;
                                        sleep(1);
                                        //Check if enemy lost all HP
                                        if (wildPokeHP > 0)
                                        {
                                                cout << "\nWild " << wildPoke << " has " << wildPokeHP << " HP left.\n";
                                                sleep(1);
                                                cout << "\nWild " << wildPoke << " attacks you!\n";
                                                sleep(1);
                                                cout << "\nWild " << wildPoke << " deals: " << compatk << " damage.\n";
                                                wildBattleHealth = wildBattleHealth - compatk;
                                                //Check if user lost all HP
                                                if (wildBattleHealth > 0)
                                                {
                                                        cout << "\nYour pokemon has: " << wildBattleHealth << " HP left.\n";
                                                }
                                                else
                                                {
                                                        lose();
                                                        wildPokeHP = 0;
                                                        wildBattleHealth = -112233;
                                                }
                                        }
                                        else
                                        {
                                                sleep(1);
                                                cout << "\nWild Pokemon fainted!\n";
                                                win();
                                        }

                                }
                        }
                }
        }
        return wildBattleHealth;
}

int gymbattle(int gymBattleHealth)
{
        int gymPoke = rand() % 5 + 1;
        int gymPokeSpeed;
        int gymPokeHP;
        string gymPokeName;
        int userPokeSpeed;
        switch (gymPoke)
        {
        case 1:
                gymPokeName = "Bulbasaur";
                gymPokeSpeed = 3;
                gymPokeHP = 20;
                break;
        case 2:
                gymPokeName = "Onix";
                gymPokeSpeed = 4;
                gymPokeHP = 18;
                break;
        case 3:
                gymPokeName = "Geodude";
                gymPokeSpeed = 6;
                gymPokeHP = 18;
                break;
        case 4:
                gymPokeName = "Gloom";
                gymPokeSpeed = 2;
                gymPokeHP = 10;
                break;
        case 5:
                gymPokeName = "Eevee";
                gymPokeSpeed = 7;
                gymPokeHP = 20;
                break;
        }

        sleep(1);
        cout << "\n                             ########\n\n";
        sleep(1);
        cout << "\nTrainer challenges you for a pokemon fight!\n";
        sleep(1);
        cout << "\nTrainer choses: " << gymPokeName << "!\n";

        int atkchoice;
        string atkType;
        while (gymPokeHP > 0)
        {
                int compatk = rand() % 3 + 1;
                int randatk = rand() % 5 + 3;
                int fatk = randatk - 1;
                int spatk = randatk + 1;
                int useratk;
                sleep(1);
Atkdec:
                cout << "\nPress 1 for Quick Attack.\nPress 2 for Special Attack.\n";
                cin >> atkchoice;
                switch (atkchoice)
                {
                //Attack Choice Simulator
                case 1:
                        userPokeSpeed = 7;
                        useratk = fatk;
                        atkType = "Quick Attack.";
                        break;

                case 2:
                        userPokeSpeed = 4;
                        useratk = spatk;
                        atkType = "Special Attack.";
                        break;

                default:
                        sleep(1);
                        cout << "\nPlease enter a valid key.\n";
                        goto Atkdec;
                }
                sleep(1);
                cout << "\nYou chose: " << atkType << endl;
                if (gymPokeSpeed > userPokeSpeed)
                { //Enemy attacks first.
                        sleep(1);
                        cout << "\n" << gymPokeName << " attacks you!\n";
                        sleep(1);
                        cout << "\n" << gymPokeName << " deals: " << compatk << " damage.\n";
                        gymBattleHealth = gymBattleHealth - compatk;
                        sleep(1);
                        //Check if user lost all HP
                        if (gymBattleHealth > 0)
                        {
                                cout << "\nYour pokemon has: " << gymBattleHealth << " HP left.\n";
                                sleep(2);
                                cout << "\nYour pokemon attacks, and deals: " << useratk << " damage.\n";
                                gymPokeHP = gymPokeHP - useratk;
                                sleep(1);
                                //Check if enemy lost all HP
                                if (gymPokeHP > 0)
                                {
                                        cout << "\n" << gymPokeName << " has " << gymPokeHP << " HP left.\n";
                                }
                                else
                                {
                                        sleep(1);
                                        cout << "\n" << gymPokeName << " fainted!\n";
                                        win();
                                }
                        }
                        else
                        {
                                lose();
                                gymPokeHP = 0;
                                gymBattleHealth = -112233;
                        }
                }
                else if (gymPokeSpeed <= userPokeSpeed)
                { //User attacks first
                        sleep(1);
                        cout << "\nYour pokemon attacks, and deals: " << useratk << " damage.\n";
                        gymPokeHP = gymPokeHP - useratk;
                        sleep(1);
                        //Check if enemy lost all HP
                        if (gymPokeHP > 0)
                        {
                                cout << "\n" << gymPokeName << " has " << gymPokeHP << " HP left.\n";
                                sleep(1);
                                cout << "\n" << gymPokeName << " attacks you!\n";
                                sleep(1);
                                cout << "\n" << gymPokeName << " deals: " << compatk << " damage.\n";
                                gymBattleHealth = gymBattleHealth - compatk;
                                //Check if user lost all HP
                                if (gymBattleHealth > 0)
                                {
                                        cout << "\nYour pokemon has: " << gymBattleHealth << " HP left.\n";
                                }
                                else
                                {
                                        lose();
                                        gymPokeHP = 0;
                                        gymBattleHealth = -112233;
                                }
                        }
                        else
                        {
                                sleep(1);
                                cout << "\n" << gymPokeName << " fainted!\n";
                                win();
                        }

                }
        }
        return gymBattleHealth;
}

int bossbattle(int bossBattleHealth)
{
  int allpokeover = 0;
  int pokecount = 1;
  int bossPokeSpeed;
  int bossPokeHP;
  string bossPokeName;
  int userPokeSpeed;
  int potionCount = 1;
  int fullhealth = bossBattleHealth;

  sleep(1);
  cout << "\n                             ########\n\n";
  sleep(1);
  cout << "\nGym Leader ROCK challenges you for a pokemon fight!\n";
  sleep(1);

  while (allpokeover == 0)
  {

    switch (pokecount)
    {
       case 1:
       bossPokeName = "Golem";
       bossPokeSpeed = 12;
       bossPokeHP = 24;
       break;

       case 2:
       bossPokeName = "Steelix";
       bossPokeSpeed = 10;
       bossPokeHP = 30;
       break;

       case 3:
       bossPokeName =  "Rhydon";
       bossPokeSpeed = 20;
       bossPokeHP = 18;
       break;

    }
  cout << "\nROCK choses: " << bossPokeName << "!\n";

  int atkchoice;
  string atkType;
  while (bossPokeHP > 0)
  {
          int compatk = rand() % 4 + 2;
          int randatk = rand() % 6 + 4;
          int fatk = randatk - 1;
          int spatk = randatk + 2;
          int useratk;
          sleep(1);
Atkdec:
          cout << "\nPress 1 for Quick Attack.\nPress 2 for Special Attack.\nPress 3 to use a HP potion.\n";
          cin >> atkchoice;
          switch (atkchoice)
          {
          //Attack Choice Simulator
          case 1:
                  userPokeSpeed = 13;
                  useratk = fatk;
                  atkType = "Quick Attack.";
                  break;

          case 2:
                  userPokeSpeed = 6;
                  useratk = spatk;
                  atkType = "Special Attack.";
                  break;

          case 3:
                 if (potionCount == 1)
                 {
                    sleep(1);
                    cout << "\nYou use a HP potion on your pokemon.\n";
                    cout << "\nYour pokemon's HP is restored!\n";
                    bossBattleHealth = fullhealth;
                    potionCount = 0;
                    goto Atkdec;
                 }
                 else
                 {
                   sleep(1);
                   cout << "You don't have any potions left.\n";
                   goto Atkdec;
                 }
                break;

          default:
                  sleep(1);
                  cout << "\nPlease enter a valid key.\n";
                  goto Atkdec;
          }
          sleep(1);
          cout << "\nYou chose: " << atkType << endl;
          if (bossPokeSpeed > userPokeSpeed)
          { //Enemy attacks first.
                  sleep(1);
                  cout << "\n" << bossPokeName << " attacks you!\n";
                  sleep(1);
                  cout << "\n" << bossPokeName << " deals: " << compatk << " damage.\n";
                  bossBattleHealth = bossBattleHealth - compatk;
                  sleep(1);
                  //Check if user lost all HP
                  if (bossBattleHealth > 0)
                  {
                          cout << "\nYour pokemon has: " << bossBattleHealth << " HP left.\n";
                          sleep(2);
                          cout << "\nYour pokemon attacks, and deals: " << useratk << " damage.\n";
                          bossPokeHP = bossPokeHP - useratk;
                          sleep(1);
                          //Check if enemy lost all HP
                          if (bossPokeHP > 0)
                          {
                                  cout << "\n" << bossPokeName << " has " << bossPokeHP << " HP left.\n";
                          }
                          else
                          {
                                  sleep(1);
                                  cout << "\n" << bossPokeName << " fainted!\n";
                                  win();
                                  pokecount = ++pokecount;
                                  if (pokecount == 4)
                                  {
                                    allpokeover = 1;
                                  }
                          }
                  }
                  else
                  {
                          lose();
                          bossPokeHP = 0;
                          bossBattleHealth = -112233;
                          allpokeover = 1;
                  }
          }
          else if (bossPokeSpeed <= userPokeSpeed)
          { //User attacks first
                  sleep(1);
                  cout << "\nYour pokemon attacks, and deals: " << useratk << " damage.\n";
                  bossPokeHP = bossPokeHP - useratk;
                  sleep(1);
                  //Check if enemy lost all HP
                  if (bossPokeHP > 0)
                  {
                          cout << "\n" << bossPokeName << " has " << bossPokeHP << " HP left.\n";
                          sleep(1);
                          cout << "\n" << bossPokeName << " attacks you!\n";
                          sleep(1);
                          cout << "\n" << bossPokeName << " deals: " << compatk << " damage.\n";
                          bossBattleHealth = bossBattleHealth - compatk;
                          //Check if user lost all HP
                          if (bossBattleHealth > 0)
                          {
                                  cout << "\nYour pokemon has: " << bossBattleHealth << " HP left.\n";
                          }
                          else
                          {
                                  lose();
                                  bossPokeHP = 0;
                                  bossBattleHealth = -112233;
                                  allpokeover = 1;
                          }
                  }
                  else
                  {
                          sleep(1);
                          cout << "\n" << bossPokeName << " fainted!\n";
                          win();
                          pokecount = ++pokecount;
                          if (pokecount == 4)
                          {
                            allpokeover = 1;
                          }
                  }

          }
  }
}
  return bossBattleHealth;
}
