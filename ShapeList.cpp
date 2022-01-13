//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright �? 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below




#include "Shape.h"
#include "ShapeList.h"
#include "string"

 ShapeList::ShapeList(){head=nullptr;}
ShapeList::~ShapeList()
{
    ShapeNode* ptr = head;
    while(ptr != NULL)
    {
        ShapeNode* temp = ptr;
        ptr=ptr->getNext();
        delete temp;
    }                       // deletes all list nodes starting
}                                        // with head plus associated Shapes

ShapeNode* ShapeList::getHead() const{return head;}         // returns the head pointer
void ShapeList::setHead(ShapeNode* ptr){head = ptr;}       // sets the head pointer to ptr

ShapeNode* ShapeList::find(string name) const
{
    ShapeNode* tptr = head;
    while(tptr != NULL)
    {
        if((tptr->getShape()->getName()) == name)break;
        tptr = tptr->getNext();
    }
    return tptr;
} // finds a shape node with the specified shape name
// returns a pointer to the node if found, otherwise
// returns nullptr if the node is not found
void ShapeList::insert(ShapeNode* s) {
    if (s != NULL) {
        if (head == NULL) {
            head = s;
            s->setNext(NULL);
        } else {
            ShapeNode *tptr = head;
            while (tptr->getNext() != NULL)
                tptr = tptr->getNext();
            tptr->setNext(s);
            s->setNext(NULL);
        }
    }
}

    ShapeNode *ShapeList::remove(string name)
    {
        if(head == NULL) return nullptr;
        ShapeNode* tptr = head;
        ShapeNode* pptr = NULL;
        while(tptr != NULL)
        {
            if((tptr->getShape()->getName()) == name)break;
            pptr = tptr;
            tptr = tptr->getNext();
        }
        if(tptr == NULL) return nullptr;
        if(tptr == head)
        {
            head =  head->getNext();

            return tptr;
        }
        pptr->setNext(tptr->getNext());
        return tptr;
    }     // removes the node with the shape called name
    // returns a pointer to the removed node or
    // nullptr is a node with name does not exist
    void ShapeList::print() const
    {
        ShapeNode* tptr =head;
        while(tptr!=NULL)
        {
            tptr->print();
            tptr = tptr->getNext();
        }

    }
