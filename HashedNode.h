// Linkded List Node Class
// Created by Frank M. Carrano and Tim Henry.
// Modified by CNguyen

#ifndef _NODE
#define _NODE

using namespace std;

template<class ItemType>
class HashedNode
{
private:
   ItemType star;
   int status;
   int colResCount;

public:
	HashedNode()										{star = 0; status=0; colResCount=0;}
	HashedNode(const ItemType anItem)				{star = anItem; status=1, colResCount=0;}
	void setItem(const ItemType anItem)		{star = anItem; status=1;}
    void setStatus(int newStatus)           {status = newStatus;}
    int getStatus() const                      {return status;}
    void display() const                        {cout<<"\nDisplay\n";}
    ItemType getItem()                      {return star;}
    void deleteStar()                       {star=0; status=-1;}
	int getColResCount() const				{return colResCount;}//added
	void increResCount()					{colResCount++;}//added
};

#endif
