#include "menuPropmt.h"

void display(DataRecord & anItem)
{
	cout << anItem << endl;
}

Menu::Menu()
{
	// contains propmt for user to use the menu.
}

void Menu::Add(BinarySearchTree<DataRecord>& a)
{
	DataRecord NewRecord;
	//Asks user for data to insert. Similar to lab 4.
	NewRecord.setKey(123); 
	//Now checking to see if data already exists
	DataRecord Temp;//Data Temp needed to access getEntry function of BST. Should be similar to hash fucntion
	if (a.getEntry(NewRecord, Temp))
	{
		//data already exists
		cout << "already exists\n";
		return;
	}
	//prompt for rest of data.
	NewRecord.setRadius(3.14);
	a.insert(NewRecord);
}

void Menu::Delete(BinarySearchTree<DataRecord>& b)
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

void Menu::Display(const BinarySearchTree<DataRecord>& c)
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
void Menu::List(const BinarySearchTree<DataRecord>& d)
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
void Menu::PrintTree(const BinarySearchTree<DataRecord>& e)
{
	//print indented tree
	//e.printIndentedTree(Display);
	cout << "print indented tree";
}
void Menu::HashStatistic(const BinarySearchTree<DataRecord>& f)
{
	//print hash statistic
	cout << "hash statisitics";
}
void Menu::Undo(BinarySearchTree<DataRecord>& g)
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
void Menu::Save(const BinarySearchTree<DataRecord>& h)
{
	DataStack.clear();
	//save to file output
}
