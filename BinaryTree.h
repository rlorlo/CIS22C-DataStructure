#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "BinaryNode.h"

template<class ItemType>
class BinaryTree
{
protected:
	BinaryNode<ItemType>* rootPtr;		// ptr to root node
	int count;							// number of nodes in tree

public:
    //default ctor
 	BinaryTree() {rootPtr = 0; count = 0;}

    //copy ctor
	BinaryTree(const BinaryTree<ItemType> & tree)
	{rootPtr = copyTree(tree.rootPtr); count=tree.getCount();}

    //dtor
	virtual ~BinaryTree() {destroyTree(this->rootPtr);} //Do we need the this pointer?

    // overloaded assignment operator
	BinaryTree & operator=(const BinaryTree & sourceTree);

    // accessor
    /* ************************************************************************
    The getCount function is the same as the size function below.
    ****************************************************************************/
	int getCount () const {return count;}
    BinaryNode<ItemType>* getRootPtr () const {return rootPtr;}


	// common functions for all binary trees
 	bool isEmpty() const				{return count == 0;}
	int size() const					{return count;}
	void clear()						{destroyTree(rootPtr); rootPtr = 0; count = 0;}
	void preOrder(void visit(ItemType &)) const		{_preorder(visit, rootPtr);}
	void inOrder(void visit(ItemType &)) const		{_inorder(visit, rootPtr);}
	void inRevOrder(void visit(ItemType &)) const	{_inRevOrder(visit, rootPtr);}
	void postOrder(void visit(ItemType &)) const	{_postorder(visit, rootPtr);}

	// abstract functions to be implemented by derived class
	virtual bool insert(const ItemType & newData) = 0;
	virtual bool remove(const ItemType & data) = 0;
	virtual bool getEntry(const ItemType & anEntry, ItemType & returnedItem) const = 0;

private:
    // mutator
    /* ************************************************************************
    do we really need the setCount function? Unless you are going to use it to set count the
    same as head pointer, count should just increase or decrease when adding or
    to the removing from the tree.
    *************************************************************************/
    void setCount (int c) {count=c;} //No one outside the class should be able to set count

    void setRootPtr (BinaryNode<ItemType>* ptr) {rootPtr=ptr;}

	// delete all nodes from the tree
	void destroyTree(BinaryNode<ItemType>* nodePtr);

	// copy from the tree rooted at nodePtr and returns a pointer to the root of the copied tree
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* nodePtr);

	// internal traverse
	void _preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _inRevOrder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
	void _postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;

};

template<class ItemType>
BinaryNode<ItemType>* BinaryTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr)
{
    BinaryNode<ItemType>* newNodePtr = 0;
    if (nodePtr !=0)
    {
        /* ************************************************************************
        It is not necessary to add the 0, 0 for the default constructor for the
        BinaryNode will take care of it.
       *************************************************************************/
        newNodePtr = new BinaryNode<ItemType>(nodePtr->getItem(),0,0);
        newNodePtr->setLeftPtr(copyTree(nodePtr->getLeftPtr()));
        newNodePtr->setRightPtr(copyTree(nodePtr->getRightPtr()));
    }
    return newNodePtr;
}

template<class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
    if(nodePtr!=0)
    {
        //postOrder traversal to delete children before parents in a recursion
        destroyTree(nodePtr->getLeftPtr());
        destroyTree(nodePtr->getRightPtr());
        delete nodePtr;
    }
}

template<class ItemType>
void BinaryTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
	if (nodePtr != 0)
	{
		ItemType item = nodePtr->getItem();
		visit(item); //preOrder
		_preorder(visit, nodePtr->getLeftPtr());
		_preorder(visit, nodePtr->getRightPtr());
	}
}

template<class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
	{
	    ItemType item = nodePtr->getItem();
        _inorder(visit, nodePtr->getLeftPtr());
        visit(item); //inOrder
		_inorder(visit, nodePtr->getRightPtr());
	}
}

template<class ItemType>
void BinaryTree<ItemType>::_inRevOrder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
	{
	    ItemType item = nodePtr->getItem();
	    _inRevOrder(visit, nodePtr->getRightPtr());
        visit(item); //inOrder
		_inRevOrder(visit, nodePtr->getLeftPtr());
	}
}

template<class ItemType>
void BinaryTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
	{
        ItemType item = nodePtr->getItem();
        _postorder(visit, nodePtr->getLeftPtr());
        _postorder(visit, nodePtr->getRightPtr());
        visit(item); //postOrder
	}
}

template<class ItemType>
BinaryTree<ItemType> & BinaryTree<ItemType>::operator=(const BinaryTree<ItemType> & sourceTree)
{
this->clear();
this.rootPtr = copyTree(sourceTree.rootPtr);
this.count = sourceTree.count;
return *this;
}

#endif

