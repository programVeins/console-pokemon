#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

class userpoke
{
public:
int HP;
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

        int freshHealth = firstpoke.HP;
        int tempHP;

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
        int gym = 0;
        string dir;
        sleep(2);
        cout << "  \n                                    #######\n";
        sleep(1);
        cout << "\nWelcome to Pokemon Sandbox!.\nHere, you play a sandboxed version of the original game!\n\n";
        sleep(2);
        cout << "This means, your pokemon won't level up or gain XP.\nYou could roam around and battle wild pokemon.\n\n";
        sleep(2);
        cout << "Just sit back and play Pokemon sandbox!\nYou see tall grass everywhere around you.\n\n";

        while (replay == 0)
        {
                sleep(2);
                if (runtime == 1)
                {
                        int quote = rand() % 10 + 1;
                        sleep(1);
                        switch (quote)
                        {
                        case 1:
                                cout << "\nPokemon sandbox: Your choices don't matter!\n\n";
                                break;
                        case 2:
                                cout << "\nPokemon sandbox: Have a Poke-Morning!\n\n";
                                break;
                        case 3:
                                cout << "\nPokemon sandbox: Move in any direction. I don't care!\n\n";
                                break;
                        case 4:
                                cout << "\nPokemon sandbox: Gods. This thing never gets old!\n\n";
                                break;
                        case 5:
                                cout << "\nPokemon sandbox: Currently thinking about a good indie brand name!\n\n";
                                break;
                        case 6:
                                cout << "\nPokemon sandbox: Cause life is empty without pokemons!\n\n";
                                break;
                        case 7:
                                cout << "\nPokemon sandbox: Your pokemon is weaker than mine!\n\n";
                                break;
                        case 8:
                                cout << "\nPokemon sandbox: I Know, you're probably tired of this game!\n\n";
                                break;
                        case 9:
                                cout << "\nPokemon sandbox: It goes on and on and on and on and on and on and on...!\n\n";
                                break;
                        case 10:
                                cout << "\nPokemon sandbox: No matter how hard you try, you can't break the iteration!\n\n";
                                break;




                        }
                }

Movement:
                sleep(1);
                cout << "Press 1 to move forward.\nPress 2 to move left.\nPress 3 to move right.\n";
                cout << "Press 4 to visit the pokemon center.\n";
                cout << "\nAlso press 0 to quit now.\n";

                cin >> direct;
                switch (direct)
                {
                case 0:
                        replay = 1;
                        sleep(2);
                        cout << "\n\nThank you for playing pokemon Sandbox.\n";
                        cout << "\nThis game was created by Sabesh Bharathi aka PoisonVeins.\n";
                        cout << "\nMay the force be with thee.\n";
                        system("pause");
                        goto Endgame;
                        break;

                case 1:
                        dir = "forward.";
                        break;

                case 2:
                        dir = "left.";
                        break;

                case 3:
                        dir = "right.";
                        break;

                case 4:
                        sleep(1);
                        cout << "\nYou visit the pokemon center. " << pokemonName << "'s HP was refilled.\n\n";
                        sleep(1);
                        firstpoke.HP =  freshHealth;
                        goto Movement;
                        break;

                default:
                        sleep(1);
                        cout << "\nPress a valid key.\n";
                        goto Movement;
                }

                cout << "\nYou move " << dir << endl;

                //Sandbox Sequemce
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
Endgame:
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
                                int compatk = rand() % 5 + 2;
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
