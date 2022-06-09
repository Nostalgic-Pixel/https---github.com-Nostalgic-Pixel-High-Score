///////////////////////////////////////////////////////////////////////////////////////////
// AUTHOR: Joseph Wilson
//
// PROGRAM: HIGH SCORE
//
// PURPOSE: The purpose of this program is to be able to store player high score info so 
//          that the user can visually see all of the player's information all at once and
//          see who has the better high score.
///////////////////////////////////////////////////////////////////////////////////////////
// Testing
#include <iostream>
#include <cstdlib>
using namespace std;

// This will be the structure for the program.
struct score{             

  // Member variable declarations.
  int player_id;
  string player_name;
  float player_score;

  // This will point to the next part of the linked list.
  // Remember, a "pointer" is a variable that stores the memory address
  // as its value.
  struct score* next;

} myStructure; // Structure variable


// Function Declarations.
void add_player(struct score* score_point);
int display_all();
void find_player(struct score* score_point);
void edit_player(struct score* score_point);


// The add_player function will prompt the user for the player's ID, name, and score for 
// the program.
void add_player(struct score* score_point) {


  // Prompt the user for the player's ID number.
  cout << "Please enter the player's ID number: ";
  cin >> "%d", &score_point->player_id; // Should it be...cin >> &score_point->player_id;


  // Prompt the user for the player's name.
  cout << "Please enter the Player's name: ";
  cin >> "%s", &score_point->player_name;


  // Prompt the user for their high score.
  cout << "Please enter the player's high score: ";
  cin >> "%d", &score_point->player_score;


} // END OF ADD_PLAYER FUNCTION.


// The display_score function will display all of the results of the input(s) that the 
// player(s) has entered in.
int display_all(struct score* score_point)
{
  // Create variable(s).
  struct score *scores = score_point;

  while (scores != NULL)
  {
    cout << "Player ID: %d \n",  scores->player_id;
    cout << "Player Name: %s \n", scores->player_name;
    cout << "Player High Score: %d \n", scores->player_score;

    scores = scores->next;
  }

  return 0;

} // END OF DISPLAY_SCORE FUNCTION.


// The find_player function will prompt the user for the player's ID in order to look up
// the specific player.
void find_player(struct score* score_point)
{
  // Declare variable(s).
  struct score *search = score_point;
  int f;

  cout << "Please enter the Player ID you are looking for: ";

  cin >> "%d", &f;

  while (search != NULL)
  {
    if (search->player_id)
    {
      //pass
    }

    else
    {
      cout << "Player Found\n";
      cout << "Player ID: %d \n",  search->player_id;
      cout << "Player Name: %s \n", search->player_name;
      cout << "Player High Score: %d \n", search->player_score;
    }

    search = search->next;

  }

} // END OF FIND_PLAYER FUNCTION.


// The edit_player function will do the same thing as the find_player function, but will 
// then ask the user for an updated info for the searched player.
void edit_player(struct score* score_point)
{
  // Declare variable(s).
  struct score *search = score_point;
  int f;

  cout << "Please enter the Player ID you are looking for: ";

  cin >> "%d", &f;

  while (search != NULL)
  {
    if (search->player_id)
    {
      //pass
    }

    else
    {
      cout << "Player Found\n";
      cout << "Player ID: %d \n",  search->player_id;
      cout << "Player Name: %s \n", search->player_name;
      cout << "Player High Score: %d \n", search->player_score;

      cout << "Please enter the new player's information. \n";

      add_player(search);
    }

    search = search->next;

  }

} // END OF THE EDIT_PLAYER FUNCTION.


int main() {
  
  // Declared variable(s)
  struct score *head = NULL;
  int i = 1;


  // While the user's has not picked option 0, the program will keep running 
  // over and over until option 0 is picked.
  while (i != 0) 
  {
    cout << "------------------------------------------------------------\n";
    cout << "|                     (Main Menue)                         |\n";
    cout << "|                                                          |\n";
    cout << "|1: ADD A NEW PLAYER                                       |\n";
    cout << "|2: DISPLAY ALL PLAYER(S)                                  |\n";
    cout << "|3: FIND A PLAYER                                          |\n";
    cout << "|4: EDIT A PLAYER                                          |\n";
    cout << "|0: QUIT PROGRAM                                           |\n";
    cout << "|                                                          |\n";
    cout << "------------------------------------------------------------\n";

    // This will prompt the user for a choice. 
    cout << "YOUR CHOICE: ";
    cin >> i; // I might need to make it as "cin >> &i;"
    cout << "\n";


    // If the user chooses option 1, it will call the add_player function.
    if (i == 1)
    {
      // This will create space for the new player.
      struct score *new_player = (struct score*) malloc(sizeof(struct score));


      // This will set the new_player to NULL.
      new_player->next = NULL;


      // This will call the add_player function and
      add_player(new_player);


      // If the head is NULL, then it will make sure that they head is the new_player.
      if (head==NULL)
      {
        head = new_player;
      }


      // Otherwise, it will go all the way down to the tail and add the memory there.
      else
      {
        struct score *tail = head;
        
        while (tail->next != NULL)
        {
          tail = tail->next;
        }

        // Once the program finds the end of the list, it will add the new player to it.
        tail->next = new_player;

      }

    }
 

    // If the user chooses option 2, it will call the display_all function.
    else if (i == 2)
    {
      // This is a test.
      cout << "Choice 2 works!\n";
      display_all(head);
    }


    // If the user chooses option 3, it will call the find_player function.
    else if (i == 3)
    {
      // This is a test.
      cout << "Choice 3 works!\n";
      find_player(head);
    }


    // If the user chooses option 4, it will call the edit_player function.
    else if (i == 4)
    {
      // This is a test.
      cout << "Choice 4 works!\n";
      edit_player(head);
    }


    // If the user chooces option 5, it will end the entire program.
    else if (i == 0)
    {
      NULL;
    }


  } // END OF WHILE LOOP.


  free(head);


  return 0;
} // END OF MAIN FUNCTION.

////////////////////////////////////////////////////////////////////////////////////////
// Notes:
//
// To run the main file, in the terminal, type in .\main.exe in order to run this file.
// It would be easier if the High Score file is the only folder that is open in VS Code.
////////////////////////////////////////////////////////////////////////////////////////
