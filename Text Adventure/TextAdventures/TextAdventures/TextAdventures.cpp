// TextAdventures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*
 * Nick Knabe
 * 10/11/15
 This will be a text adventure game, no graphics.
 You can choose between a wizard, warrior, or archer.
 The goal is to find the cave troll and defeat it.
 */

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
//#include "FightMath.h"
//#include "FightMath.cpp"
using namespace std;


const int orcAttack = 20;
const int orcHP = 5;

int main()
//Story (introduce problem of cave troll, and that you are part of a human race to prove yourself)
{
	//Have user enter characters name and select a class
	string name = "";
	cout << "Please enter your characters name: " << endl;
	cin >> name;
	cout << "" << endl;


	//class selection
		string charClass = "";
		int HP = 0;
		string weapon = "";
		int orcAttack = 20;
		int atkPow = 0;

		do
			{
				cout << "Would you like to play as: " << endl;
				cout << "Wizard " << endl;
				cout << "Warrior " << endl;
				cout << "Archer " << endl;
				cin >> charClass;
				cout << "" << endl;


			if (charClass == "Wizard")
			{
				weapon = "Staff";
				atkPow = 7;
				HP = 5;
				cout << "You have selected a Wizard!" << endl;
				cout << "Your weapon as a Wizard is a Staff." << endl;
				cout << "Your attack power is now " << atkPow << "." << endl;
				cout << "You start with " << HP << " health points." << endl;
				
				
			}

			else if (charClass == "Warrior")
			{
				weapon = "Sword";
				HP = 10;
				atkPow = 5;
				cout << "You have selected a Warrior!" << endl;
				cout << "Your weapon as a Warrior is a Sword." << endl;
				cout <<	"Your attack power is now " << atkPow << "." << endl;
				cout << "You start with " << HP << " health points." << endl;
				
			}

			else if (charClass == "Archer")
			{
				weapon = "Bow";
				HP = 7;
				atkPow = 7;
				cout << "You have selected a Archer!" << endl;
				cout << "Your weapon as a Archer is a Bow. Your attack power is now " << atkPow << "." << endl;
				cout << "You start with " << HP << " health points." << endl;
				
			}

			else if (charClass != "Wizard" && charClass != "Warrior" && charClass !="Archer")
			{
			cout << "You have not selected an appropriate class, please retry, classes are case sensitive." << endl;
			}

		} while(charClass != "Wizard" && charClass != "Warrior" && charClass !="Archer");


	string start = "";
	cout << "Are you ready to start the your adventure? Y/N" << endl;
	cin >> start;
	if(start != "Y" && start != "N")
		{
			cout << "Enter either Y or N. Please restart game." << endl;
			return 0;
		}

	if(start == "Y")
	{
			cout << "" << endl;
			cout << "" << endl;


			//start game here
			cout << "You reach into your pocket and retrieve a note.\n";
			cout << "\n";
			cout << "You read the note one last time before reaching your final destination.\n";
			cout << "\n";
			cout << "Dear " << name << ", \n";
			cout <<  endl;
			cout << "As you know, we have had a cave troll terrorizing our animals during the middle of the night.\n" <<
					"We are willing to give any reward in order to be rid of this terrible creature. \n";
			cout <<  endl;
			cout <<  endl;
		//Introduce cave troll w/back story (slow and dumb)
		//warning that this area has been known to be crawling with orcs as well (move faster than humans)
			cout << "As you know, cave trolls and slow and dumb, easily frightened by bright lights, since they never see daylight.\n";
			cout << "I feel that I should warn all adventurers too about the orcs as well.\n";
			cout <<	"There as been reports of orcs running around these parts lately.\n";
			cout << "Orcs are weaker than humans, but much faster. If you see an orc...I would not turn your back on it." << endl;
			cout << "";
			cout << "";
			cout << "Sincerely," << endl;
			cout << "         King Fuzzy Kitten" << endl;
			cout << endl;

		//continue
			string con = "";
			cout << "Continue? Y/N" << endl;
			cin >> con;
			cout << endl;
		//user prompted to enter or not enter cave (if statement)
			string cave = "";
			cout << "You have arrived at your final destination, the cave entrance." << endl;
			cout << "Do you wish to enter the cave? Y/N " << endl;
			cin >> cave;

		//enter cave with lighted torch and weapon in hand (define weapon based on char type)
		
		if(cave == "Y")
		{
			cout << "You pause before entering the cave, you draw your " << weapon << " and pull out a torch and light it. "  << endl;

			//tell character small story while entering cave (you are going down a dark narrow path)
			cout << "You enter the cave. It is dark and narrow but you begin your journey. " << endl;
			cout << "Far in the distance you can hear what sounds like screams." << endl;
			cout << "With a towns live stock in trouble you push on walking carefully down into the depths, through the dark, slimy, wet cave." << endl;
			cout << "" << endl;

			//Char comes to a fork in the path, you hear sounds (moans of distress) down one path and see light flickering down the other
		
			string fork = "";
			cout << "You come to a fork in your path. You can not clearly see down either path." << endl;
			cout << "To the left you see what looks like it might be a flicker of light at the end of the path." << endl;
			cout << "To the right you see nothing except pitch black, but you find where the screams have been coming from." << endl;
			cout << "Do you wish to proceed left, down the light path, or right, down the dark path filled with screams? Left/Right?" << endl;
			cin >> fork;
				//light path

			do
			{
				if(fork =="Left")
				{
					//torch at the end of the path, you find a "char weapon", your power has doubled, also ambushed by orcs
					cout << "Your choose to proceed down the path towards a flicker of light." << endl;
					cout << "" << endl;
					cout << "As you grow closer you can hear muffled grunts and what sounds like arguing" << endl;
					cout << "";
					cout << "You reach the light source, what turns out to be dead end." << endl;
					cout << "Look out! You found Orcs!";
					cout << "The light you saw flickering was that of an orc torch!" << endl;
					cout << "" << endl;
					cout << "You see three sets of piercing red and black eyes staring you down as one of the orcs slowly blows out their torch. " << endl;
					cout << "You hear them scream with excitement as one screams GUT HIM LIKE A STUCK PIG!!" << endl;

					//fight or run
					string fightOrc = "";
					cout << "You must make a choice, do you run back and try to find the cave troll, or do you stay and fight? Run/Fight" << endl;
					cin >> fightOrc;
					cout << "" << endl;



					do
					{
						//if run, orcs hunt you down and kill you
						if (fightOrc == "Run")
						{
							cout << "You turn and run to fight another day." << endl;
							cout << "Hearing screams behind you, you remember what the Kings letter said, Orcs are faster than humans." << endl;
							cout << "As you sprint up the cave path this thought begins to feaster, at that point, you feet a sharp pain in your side." << endl;
							cout << "You hold the torch down to see a crude arrow in your side. " << endl;
							cout << "You also feel a pinch as a blade pierces through your back coming out the middle of your stomach." << endl;
							cout << "The light fades as you pass into an abyss of darkness." << endl;
							cout << "Your health points are now at " << HP-orcAttack << "." << endl;
							cout << "You are now dead, you should have listened to the king, the orcs ran you down." << endl;
							cout << "Game over. " << endl;
						
							/*do
							{
								HP = orcAttack - HP;
								orcHP = wepower - orcHP;
								cout << "Your health points are now at " << HP << "." << endl;
								cout << "The orcs health points are now at " << orcHP << "." << endl;
								cout << "You are now dead, you should have listened to the king, orcs run faster than you can." << endl;
								cout << "Game over. " << endl;
								return 0;
							}while (orcHP >=0);
							*/
						





					
						}
						//if fight orcs and win, back track to other fork and proceed down sound path
							//kill orcs
						else if (fightOrc == "Fight")
						{
							cout << "As three sets of piercing red eyes stair at you, one blows out their torch." << endl;
							cout << "Screams and wails ensue as the excitement of the orcs future meal is standing right in front of them!" << endl;
							cout << "Orcs health points start at " << orcHP << " ." << endl;
							cout << "You grit you teeth, draw back your weapon and move forward to attack. " << endl;
							cout << "As you swing your " << weapon << " you knock the head of an orc clean off. " << endl;
							cout << "The orcs health points are now " << orcHP - atkPow <<  "." << endl;
							cout << "The rest of the orc pack scatters are your sheer power and skill. " << endl;
						
							string search = "";
							cout << "Do you wish to search the room? Y/N" << endl;
							cin >> search;
							if (search == "Y")
							{
								cout << "You search the chamber where you found the orcs." << endl;
								cout << "You found a new and powerful " << weapon << ", this is not made of any craft men or orcs possess." << endl;
								cout << "Your power has now doubled!" << endl;
								cout << "Your attack power is now " << atkPow*2 << "." << endl;
								
								
								

							}
							else if(search == "N")
							{
							
							}

						}
						
						//choice of search cave or back track immediately

							//search cave = find weapon, double weapon power

							//don't search cave = go back and fight


					}while(fightOrc != "Run" && fightOrc != "Fight");
				}
				//sound path
				if (fork == "Right")
				{
					cout << "Your chose right!";
					//troll is munching on an orc, he was hungry and you've interrupted his dinner!

					//fight troll

						//use weapon or torch

						//if torch, scares orc then use weapon for one swift kill

						//if use weapon first inflict damage, but orc fights back
				}

				else if (fork != "Left" && fork != "Right")
				{
					cout << "Please type Left or Right for your choice" << endl;
				}
			}while (fork != "Left" && fork != "Right");
	}
	
	else if (cave == "N")
	{
		cout << "You have chosen not to enter the cave. Return to your home land and come back when you are no longer a coward." << endl;
		cout << "";
		cout << "Game Over!! ";
		return 0;
	}

	


//if all enemies dead proceed out back to castle to for reward
	}

	else
	{
	cout << "The game has ended, please restart when you are ready to play." << endl;
	}
	return 0;
}




/*ideas for game
 -use a function for the math portion.
 -create a seperate header file for referencing to clean up main file.
 */


