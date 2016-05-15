// TextAdventure.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "TextAdventure.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_TEXTADVENTURE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEXTADVENTURE));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEXTADVENTURE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_TEXTADVENTURE);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

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
using namespace std;



const int orcHP = 5;
int main()
//Story (introduce problem of cave troll, and that you are part of a human race to prove yourself)
{
	//Have user enter characters name and select a class
	string name = "";
	cout << "Please enter your characters name: " << endl;
	cin >> name;

	//class selection
		string charClass = "";
		string weapon = "";
		int HP = 0;
		int Staff = 5;
		int Sword = 3;
		int Bow = 3;
		int orcAttack = 5;
		int orcHP = 10;


		do
			{
				cout << "Would you like to play as: " << endl;
				cout << "Wizard " << endl;
				cout << "Warrior " << endl;
				cout << "Archer " << endl;
				cin >> charClass;


			if (charClass == "Wizard")
			{
				HP = 5;
				cout << "You have selected a Wizard!" << endl;
				cout << "Your weapon as a Wizard is a Staff. Your attack power is now " << Staff << "." << endl;
				cout << "You start with " << HP << " health points." << endl;
				weapon = Staff;



			}

			else if (charClass == "Warrior")
			{
				HP = 10;
				cout << "You have selected a Warrior!" << endl;
				cout << "Your weapon as a Warrior is a Sword." << endl;
				cout <<	"Your attack power is now " << Sword << "." << endl;
				cout << "You start with " << HP << " health points." << endl;
				weapon = Sword;
			}

			else if (charClass == "Archer")
			{
				HP = 7;
				cout << "You have selected a Archer!" << endl;
				cout << "Your weapon as a Archer is a Bow. Your attack power is now " << Bow << "." << endl;
				cout << "You start with " << HP << " health points." << endl;
				weapon = Bow;
			}

			else if (charClass != "Wizard" && charClass != "Warrior" && charClass !="Archer")
			{
			cout << "You have not selected an appropriate class, please retry, classes are case sensitive." << endl;
			}

		} while(charClass != "Wizard" && charClass != "Warrior" && charClass !="Archer");

	string cinignore = "";
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
	cout << "\n";
	cout << "\n";
	cout << "\n";

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
	cout << "Orcs are much faster than humans, if you see an orc...do not turn your back on it." << endl;
	cout << "";
	cout << "";
	cout << "Sincerely," << endl;
	cout << "         King Fuzzy Kitten" << endl;
	cout << endl;
	cout << endl;
//continue
	string con = "";
	cout << "Continue? Y/N" << endl;
	cin >> con;

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
						/*do
						{
							HP = orcAttack - HP;
							orcHP = weapon - orcHP;
							cout << "Your health points are now at " << HP << ".";
							cout << "The orcs health points are now at " << orcHP << ".";
						}while (orcHP >=0);
						*/





					}

					//if fight orcs and win, back track to other fork and proceed down sound path


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
		cout << "Game Over!!";
		return 0;
	}




//if dead restart game, you lose

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

