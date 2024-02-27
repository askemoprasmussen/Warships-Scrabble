#include<iostream>
#include<string>
#include <fstream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//initialise array
//Enter playernames
//swap between players
//



bool check_ready_get_correct_word(string player1, int word_length)
{
    string wordtobechecked;
    bool ready = false;
    bool correct_word = false;

    cout << "\n";
    cout << player1 <<" are you ready to compose a "<<word_length<<" letter word? Enter 0 for no - Enter 1 for yes : ";
    cin >> ready;
    cout << "\n";
    cout << "\n";
    if ( ready == true)
    {
        cout << "Enter word : ";
        cin >> wordtobechecked;
        cout << "\n";
        cout << "\n";
        cout <<  " - is this a correct word? 0 for No - 1 for Yes : ";
        cin >> correct_word;
        cout << "\n";
        cout << "\n";
        if (correct_word == true)
        {
            cout << player1 << " wins!!!!!";
        }
        else
        {
            cout << "Non-existent word - Try next round!";


        }


    }
return correct_word;
}

int main()
{
    bool newgame = true;
    while (newgame == true)
    {


        int players;
        int current_player = 0;
        string player1, player2, player3;

        //initialise hidden grid
        const int arraysize = 5;
        int grid1[arraysize];
        char grid2[arraysize][arraysize];

        for (int i = 0; i < arraysize; i++)
        {

            for (int k = 0; k < arraysize; k++)
            {
                grid2[i][k] = '*';
            }

        }

        cout << "Welcome to Wordfeud! Follow the instructions below to start the game.";
        cout << "\n";
        cout << "                      Enjoy!";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "How many players would you like to play? 2 or 3 : ";
        cin >> players;
        cout << "\n";
        cout << "\n";
        cout << "\n";

        cout << "Enter Player1 : ";
        cin >> player1;
        cout << "\n";
        cout << "Enter Player2 : ";
        cin >> player2;

        if (players == 3)
        {
            cout << "\n";
            cout << "Enter Player3 : ";
            cin >> player3;
        }


        //What level of difficulty
        int level;
        cout << "Level 1: Compose a 3 letter word";
        cout << "\n";
        cout << "Level 2: Compose a 5 letter word";
        cout << "\n";
        cout << "What level would you like to play? 1 or 2 : ";
        cin >> level;
        int  dict_size;
        string dict_name;
        int grid_size;
        if(level == 2)
        {
            dict_size = 5757;
            grid_size = 5;
            dict_name = "dictionary.txt";

        }
        else if (level == 1)
        {
            dict_size = 972;
            grid_size = 3;
            dict_name = "3dictionary.txt";
        }

//Load file into array
        string line;
        ifstream myfile (dict_name.c_str());

        string dictionary[dict_size];
        int count = 0;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                dictionary[count] = line;
                count++;
            }
            myfile.close();
        }
        //Generate random number to find word/letters to use for grid
        int random_number ;
        srand (time(NULL));
        random_number = rand() % dict_size;

        //Assign word from array with all words
        string word;
        word = dictionary[random_number];
       // cout << word;                     =====to check for which word that has been scattered on the grid ==TESTING PURPOSES====
        cout << "\n";

        //Assign each letter from word to a char variable
        int random_i, random_j;
        for( int i = 0; i < grid_size; i++)
        {

            srand (time(NULL) + i);
            random_i = rand() % 5;
            //cout << random_i;                                 =====check which coordinates have a letter assigned ==TESTING PURPOSES====
            cout << " ";
            random_j = rand() % 5;
            //cout << random_j;                                 =====check which coordinates have a letter assigned ==TESTING PURPOSES====
            while (grid2[random_i][random_j] == '*' )
            {
                grid2[random_i][random_j] = word[i];

                //cout << grid2[random_i][random_j];            =====check which coordinates have which letter assigned ==TESTING PURPOSES====
                cout << "\n";
            }
        }



        int xcoord, ycoord;

        //Display Grid
        int const displayarraysize = 5;
        int displaygrid1[displayarraysize];
        int displaygrid2[displayarraysize][displayarraysize];

        for (int i = 0; i < displayarraysize; i++)
        {
            cout << "\n";
            for (int k = 0; k < displayarraysize; k++)
            {
                cout << " ( " << k << "," << i << " ) ";


            }
            cout << "\n";
        }
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "\n";
        string player1bank, player2bank, player3bank;
        bool correct_word = false;
        while (correct_word == false)
        {
            string player_name;
            if (current_player== 0)
            {
                player_name = player1;
            }
            else if(current_player ==1)
            {
                player_name = player2;
            }
            else     // must be player 3
            {
                player_name = player3;
            }
            cout << "It is " << player_name << "'s turn";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";

            //Enter coordniate to check for letter
            cout << "if you would like to reveal the position (4,3) you would have to write 4 3";
            cout << "\n";
            cout << "Enter the coordinate of the position you would like to check for a letter : ";
            cin >> xcoord >> ycoord;



            //check to see if coordinate is occupied with a letter or not


            if(grid2[xcoord][ycoord] == '*')
            {
                cout << "\n";
                cout << "\n";
                cout << "Unlucky, no letter found!";
                cout << "\n";
                cout << "\n";
            }
            else
            {
                cout << "The letter : " << grid2[xcoord][ycoord] << " has been found!";
                cout << "\n";
                cout << "\n";
                if(current_player == 0)
                {
                    player1bank = player1bank + grid2[xcoord][ycoord];
                    cout << player1 <<"'s letter bank = " << player1bank;
                }
                else if(current_player == 1)
                {
                    player2bank = player2bank + grid2[xcoord][ycoord];
                    cout << player2 << "'s letter bank = " << player2bank;
                }
                else
                {
                    player3bank = player3bank + grid2[xcoord][ycoord];
                    cout << player3 << "'s leter bank = " << player3bank;
                }
                cout << "\n";
                cout << "\n";
            }
            //Is 'player' ready to compose a word


            int word_length;

            if (level == 1)
            {
                word_length = 3;
            }
            else
            {
                word_length = 5;
            }

            correct_word = check_ready_get_correct_word(player_name, word_length);


        //switches between player1 and player2 and player 3 depending on previous turn

        current_player = (current_player + 1) % players;


        if (correct_word == true)
        {
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "Would you like to start a new game? if YES type 1 - if NO type 0 : ";
            cin >> newgame;
        }
    }
}
}//end of while loop



