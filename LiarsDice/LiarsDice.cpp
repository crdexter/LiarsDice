#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include <string>
#include <istream>
using namespace std;

				// gets, stores and outputs player info for the game
class Player
{
	public:

		string playName;
		int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0;

		void getName() // prompts and logs player name
		{
			
			cout << "Input Name: " ;
			cin >> playName;

			return;
		}

		void roll() // rolls 5 dice for player and logs 
		{

			d1 = rand() % 6 + 1;
			d2 = rand() % 6 + 1;
			d3 = rand() % 6 + 1;
			d4 = rand() % 6 + 1;
			d5 = rand() % 6 + 1;

			return;
		}

		int playDice() // prints the players dice used for player turn
		{
			
			cout << d1 << ' ' << d2 << ' ' << d3 << ' ' << d4 << ' ' << d5 << " " << endl;
			
			return 0;
		}



};


// Controls the files and output of the rules
class Rules
{
	public:

		void fullRules() // prints from the main rules text doc
		{
			string line;
			ifstream file("LiarsDiceRules.txt");

			if (file.is_open())
			{
				while (getline(file, line))
				{
					cout << line << '\n';

				}

				file.close();
			}

			else
			{
				cout << "File is not open." << endl;
			}

		}
		
		void shortRules() // prints the shorter rules txt doc for use during player turn
		{
			string line;
			ifstream file("ShortRules.txt");

			if (file.is_open())
			{
				while (getline(file, line))
				{
					cout << line << '\n';

				}

				file.close();
			}

			else
			{
				cout << "File is not open." << endl;
			}

		}



};

int main()
{
	int i = 0;
	int callSide = 0;
	int callGuess = 0;
	int finalSides = 0;
	int currentPlay = 0;
	int totalPlay = 0;
	int liarCall = 1;
	int previousGuess = 0;
	int previousSide = 0;
	string callerName;
	string prevName;
	Rules rules;

	srand(time(NULL)); // used to insure that each player's dice roll is diffrent

	Player p1;   // Initializes each player for the game
	Player p2;;
	Player p3;
	Player p4;
	Player p5;


	rules.fullRules();

	cout << "Please Enter Between 2 and 5 players" << endl;
	cout << "Input Number of Players: ";
	cin >> totalPlay;

	system("cls");
	
	while (totalPlay <= 1 || totalPlay >=6) //while loop to catch player limit 
	{
		cout << "Please Enter Between 2 and 5 players" << endl;
		cout << "Input Number of Players: ";
		cin >> totalPlay;
		system("cls");
	}


	/*
		Switch for setting total number of players and logging
		player names later in
	
	*/
	switch (totalPlay-1) //switch for building player classes for number of players selected
	{			/*
					Because there cannot be a single player total number of players is 
					subtracted by one and applied to the switch. This keeps the orginal
					value of total players while still using the same int to control the switch.
				*/

		case 1:
			p1.getName();
			p1.roll();
			p2.getName();
			p2.roll();

			break;

		case 2:
			p1.getName();
			p1.roll();
			p2.getName();
			p2.roll();
			p3.getName();
			p3.roll();
			break;

		case 3:
			p1.getName();
			p1.roll();
			p2.getName();
			p2.roll();
			p3.getName();
			p3.roll();
			p4.getName();
			p4.roll();
			break;

		case 4:
			p1.getName();
			p1.roll();
			p2.getName();
			p2.roll();
			p3.getName();
			p3.roll();
			p4.getName();
			p4.roll();
			p5.getName();
			p5.roll();
			break;

		default:
			cout << "Error" << endl;



	}

	

	system("cls");


	cout << p1.playName << " have a seat." << endl;
	cout << "Look away if it is not your turn." << endl << "No cheating now..." << endl;
	system("pause");
	system("cls");

	
	while (liarCall == 1) // while loop allows the guessing to cycle through players multiple times 
	{   


		if (currentPlay <= totalPlay) // if statment to insure you cannot exceed total of players selected
		{
			rules.shortRules(); //A shorter set of rules for general player use
			"/n";

			switch (currentPlay) // used to control the main flow of the game and player turn
			{
			case 1: // player one  (ALL COMMENTS CAN BE USED FOR OTHER PLAYERS)
				cout << p1.playName << endl;
				p1.playDice();
				'/n';
				cout << "Previous Guess: " << previousGuess << ' ' << previousSide << "s" << endl; 
				cout << "1. Make Your Guess" << endl;
				cout << "2. Call out the Liar!" << endl;
				cin >> i; 
				switch (i) // used to let player choose between guessing or calling
				{
				case 1:  // if player selects guess
					cout << "Input Your Guess" << endl; // takes in input for players guess dice total and dice side
					cout << "Total Number of Dice: ";
					cin >> callGuess;
					cout << "Dice Side: ";
					cin >> callSide;

					if (callGuess <= previousGuess) // if statement checks player guess against the previous guess to insure it is higher
					{

						cout << "Guess too Low." << endl;

					}
					else
					{
						previousGuess = callGuess; // transfers the players info from current to previous to display to next player
						previousSide = callSide;
						currentPlay++;				// used to move player turn order in the switch
						prevName = p1.playName;		// logs to use during next players turn
						system("cls");			// clears the player screen to hide player dice
					}
					break;

				case 2: // if player calls the liar

					callerName = p1.playName; // logs the calling player for use if they win
					liarCall = 0;				// breaks while loop
					break;

				default:
					cout << "Thats Not an Option..." << endl;
				};

			break;

			case 2: //player 2
				cout << p2.playName << endl;
				p2.playDice();
				cout << "Previous Guess: " << previousGuess << ' ' << previousSide << "s" << endl;
				cout << "1. Make Your Guess" << endl;
				cout << "2. Call out the Liar!" << endl;
				cin >> i;
				switch (i)
				{
				case 1:
					cout << "Input Your Guess" << endl;
					cout << "Total Number of Dice: ";
					cin >> callGuess;
					cout << "Dice Side: ";
					cin >> callSide;

					if(callGuess<=previousGuess)
					{
						
						cout << "Guess too Low." << endl;

					}
					else
					{
						previousGuess = callGuess;
						previousSide = callSide;
						currentPlay++;
						prevName = p2.playName;
						system("cls");
					}
					break;

				case 2:

					callerName = p2.playName;
					liarCall = 0;
					break;

				default:
					cout << "Thats Not an Option..." << endl;
				};

				break;

			case 3: // player 3
				cout << p3.playName << endl;
				p3.playDice();
				'/n';
				cout << "Previous Guess: " << previousGuess << ' ' << previousSide << "s" << endl;
				cout << "1. Make Your Guess" << endl;
				cout << "2. Call out the Liar!" << endl;
				cin >> i;
				switch (i)
				{
				case 1:
					cout << "Input Your Guess" << endl;
					cout << "Total Number of Dice: ";
					cin >> callGuess;
					cout << "Dice Side: ";
					cin >> callSide;

					if (callGuess <= previousGuess)
					{

						cout << "Guess too Low." << endl;

					}
					else
					{
						previousGuess = callGuess;
						previousSide = callSide;
						currentPlay++;
						prevName = p3.playName;
						system("cls");
					}
					break;

				case 2:

					callerName = p3.playName;
					liarCall = 0;
					break;

				default:
					cout << "Thats Not an Option..." << endl;

				};
			break;

			case 4: // player 4
				cout << p4.playName << endl;
				p4.playDice();
				'/n';
				cout << "Previous Guess: " << previousGuess << ' ' << previousSide << "s" << endl;
				cout << "1. Make Your Guess" << endl;
				cout << "2. Call out the Liar!" << endl;
				cin >> i;
				switch (i)
				{
				case 1:
					cout << "Input Your Guess" << endl;
					cout << "Total Number of Dice: ";
					cin >> callGuess;
					cout << "Dice Side: ";
					cin >> callSide;

					if (callGuess <= previousGuess)
					{

						cout << "Guess too Low." << endl;

					}
					else
					{
						previousGuess = callGuess;
						previousSide = callSide;
						currentPlay++;
						prevName = p4.playName;
						system("cls");
					}
					break;

				case 2:

					callerName = p4.playName;
					liarCall = 0;
					break;

				default:
					cout << "Thats Not an Option..." << endl;
				};

			break;

			case 5: //player five 
				cout << p5.playName << endl;
				p5.playDice();
				'/n';
				cout << "Previous Guess: " << previousGuess << ' ' << previousSide << "s" << endl;
				cout << "1. Make Your Guess" << endl;
				cout << "2. Call out the Liar!" << endl;
				cin >> i;
				switch(i)
				{ 
					case 1:
						cout << "Input Your Guess" << endl;
						cout << "Total Number of Dice: ";
						cin >> callGuess;
						cout << "Dice Side: ";
						cin >> callSide;

						if (callGuess <= previousGuess)
						{

							cout << "Guess too Low." << endl;

						}
						else
						{
							previousGuess = callGuess;
							previousSide = callSide;
							currentPlay++;
							prevName = p5.playName;
							system("cls");
						}
						break;

					case 2:

						p5.playName = callerName;
						liarCall = 0;
						break;
					
					default:
						cout << "Thats Not an Option..." << endl;
				};
				break;

			default: // will always start here for player one 
					// DOES NOT contain previous guess or option to call
				cout << p1.playName << endl;
				p1.playDice();
				'/n';
				cout << "Input Your Guess" << endl;
				cout << "Total Number of Dice: ";
				cin >> callGuess;
				cout << "Dice Side: ";
				cin >> callSide;

				if (callGuess,callSide == 0)
				{
					cout << "Zero is not an option" << endl;


				}
				else
				{ 
					previousGuess = callGuess;
					previousSide = callSide;
					prevName = p1.playName;
					currentPlay++; //sets currentPlay to player 2 
					currentPlay++;
					system("cls");
				 }
			}

		}
		
		else
		{
			currentPlay = 1;  // resets current player to one
		}


					// Stops the game to allow players to change seats keeping player dice secret
		cout << "Next Player have a seat." << endl << "Look away if it is not your turn." << endl << "No cheating now..." << endl;
		system("pause");
		system("cls");


	}


	
	system("cls");
	

				 /*array stores all dice for each player 
				   NOTE. if players are not active their dice will be 0 
				   this will not cause problems with the final count as
				   it is not possible to enter 0 for dice */

	int totaldice[] = { p1.d1,p1.d2,p1.d3,p1.d4,p1.d5,p2.d1,p2.d2,p2.d3,p2.d4,p2.d5,p1.d5,p3.d1,p3.d2,p3.d3,p3.d4,p3.d5,p1.d5,p4.d1,p4.d2,p4.d3,p4.d4,p4.d5,p4.d5,p5.d1,p5.d2,p5.d3,p5.d4,p5.d5 };

	for (int i = 0; i < 25; i++) // cycles through player dice
	{


		if (totaldice[i] == callSide) // each time a dice in the array matches the called side it will count towards the final side
		{				
			finalSides++;

		}

	}  

	cout << "There were " << finalSides << " " << previousSide << "'s Among All Players" << endl;

	if (previousGuess <= finalSides) // Called player Wins
	{
		cout << prevName << " WINS!!!" << endl;

		cout << "Looks Like They Were Tellin The Truth This Time" << endl;



	}

	else // calling player wins
	{
		cout << callerName << " WINS!! Great Job catching that liar." << endl;
		cout << prevName << " You're A Dirty Liar! ... I'm very disappointed in you." << endl;
	}

	

	system("pause");


	cout << "Thanks For Playing!" << endl;




}