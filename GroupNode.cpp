#include "GroupNode.h"




GroupNode::GroupNode(string n)
{
    name = n;
    myShapeList = new ShapeList();
    next = nullptr;
}                   // sets group name to n and makes myShapeList
// point to a new ShapeList; sets next to nullptr
GroupNode::~GroupNode()
{
    delete myShapeList;
}                          // deletes the myShapeList list
string GroupNode::getName() const{return name;}                // returns group name
ShapeList* GroupNode::getShapeList() const{return myShapeList;}       // returns myShapeList
void GroupNode::setShapeList(ShapeList* ptr){myShapeList = ptr;}     // sets myShapeList to ptr
GroupNode* GroupNode::getNext() const{return next;}            // returns next
void GroupNode::setNext(GroupNode* ptr)
{next = ptr;}          // sets next to ptr
void GroupNode::print() const
{
    cout<<name<<":"<<endl;
    myShapeList->print();
}



