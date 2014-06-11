//Main.cpp
//Created By Richard Orlowski

#include "UserInterface.h"

int main()
{
	UserInterface myUI;
	myUI.Choice[0] = 'y';
	while (strcmp(myUI.Choice,"q") != 0)
	{
        myUI.PrintMenu();
        cin >> myUI.Choice;
		myUI.ChoiceFunc();
        cout << endl;
    }
}
