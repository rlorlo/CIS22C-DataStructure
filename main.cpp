//Main.cpp
//Created By Richard Orlowski

#include "UserInterface.h"

int main()
{
<<<<<<< HEAD

	UserInterface myUI;

=======
	UserInterface myUI;
>>>>>>> FETCH_HEAD
	myUI.Choice[0] = 'y';
	while (strcmp(myUI.Choice,"q") != 0)
	{
        myUI.PrintMenu();
        cin >> myUI.Choice;
		myUI.ChoiceFunc();
        cout << endl;
    }
}
