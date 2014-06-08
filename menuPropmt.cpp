#include "menuPropmt.h"
/*
void display(DataRecord & anItem)
{
	cout << anItem << endl;
}*/

Menu::Menu()
{
	// contains propmt for user to use the menu.
}

void Menu::Add(DataBase& a)
{
	DataRecord NewRecord;
	//Asks user for data to insert. Similar to lab 4.
	NewRecord.set_name("Star"); 
	//Now checking to see if data already exists
	DataRecord Temp;//Data Temp needed to access getEntry function of BST. Should be similar to hash fucntion
	if (a.accessTree()->getEntry())
	{
		//data already exists
		cout << "already exists\n";
		return;
	}
	//prompt for rest of data.
	NewRecord.setRadius(3.14);
	a.insert(NewRecord);
}

void Menu::Delete(DataBase& b)
{
	//Asks user for which record to delete.

	//pass that key to the hash function to see if data exists.
	DataRecord LookingFor(5, 14.8);
	DataRecord Temp;
	if (b.getEntry(LookingFor, Temp))
	{
		DataStack.push(Temp);
		b.remove(Temp);
		return;
	}
	//can't be found
	cout << "cant be found\n";
	return;

}

void Menu::Display(const DataBase& c)
{	
	//Asks user for which Record they are looking for
	DataRecord LookingFor;
	LookingFor.setKey(123);
	DataRecord Found;
	if (c.getEntry(LookingFor, Found))
	{
		//print what is found.
		cout << Found;
		return;
	}
	else
	{
		//print cant be found.
		cout << "cant be found";
		return;
	}
}
void Menu::List(const DataBase& d)
{
	//prompt user to decide which data to list
	cout << "h. for hash sequence\ns. for sorted sequence\n";
	string input;
	cin >> input;
	if (input == "h")
		//print hash
		cout << "print hash";
	else
		//print sorted
		d.inOrder(display);
		cout << "inorder";
}
void Menu::PrintTree(const DataBase& e)
{
	//print indented tree
	//e.printIndentedTree(Display);
	cout << "print indented tree";
}
void Menu::HashStatistic(const DataBase& f)
{
	//print hash statistic
	cout << "hash statisitics";
}
void Menu::Undo(DataBase& g)
{
	if (DataStack.isEmpty())
		//Nothing to undo
		cout << "nothing to undo";
	else
	{
		//add to Hash Table and BST
		DataRecord Temp;
		DataRecord topStack;
		DataStack.peek(topStack);
		DataStack.pop();
		if (g.getEntry(topStack, Temp))
		{
			//data already exists
			cout << "already exists";
			return;
		}
		else
		{
			g.insert(topStack);
			//successful
			cout << "undo was successful";
			return;
		}
	}
}
void Menu::Save(const DataBase& h)
{
	DataStack.clear();
	//save to file output
}
