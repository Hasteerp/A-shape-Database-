#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

bool nameexists =false;
bool groupexists =false;
bool shapeexists =false;
bool grexists = false;
bool argexists = false;
bool arggexists = false;

int main() {
    // Create the groups list
    gList = new GroupList();
    
    // Create the poo group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup);
    
    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        if(command == keyWordsList[0] || command == keyWordsList[1] || command == keyWordsList[2] || command == keyWordsList[3] || command == keyWordsList[4] || command == keyWordsList[5])
        {
            if(command == keyWordsList[0])
            {
                string sname;
                lineStream >> sname;
                for(int i=0; i<6;i++)
                {
                    if(sname ==  keyWordsList[i])
                    {
                        cout<<"error: invalid name"<<endl;
                    }
                }
                for(int i=0; i<3;i++)
                {
                    if(sname ==  shapeTypesList[i])
                    {
                        cout<<"error: invalid name"<<endl;

                    }
                }
                // namechecker
                GroupNode* tptr = gList->getHead();
                while(tptr!= nullptr)
                {

                    if(tptr->getShapeList()->find(sname) != nullptr || tptr->getName() == sname)
                    {
                        nameexists = true;
                        cout<<"error: name "<<sname<<" exists"<<endl;
                        break;
                    }
                    else
                    {
                        nameexists = false;
                        tptr = tptr->getNext();
                    }

                }
                if(nameexists == false)
                {
                    string groupname;
                    lineStream >> groupname;
                    if(groupname == shapeTypesList[0] || groupname == shapeTypesList[1] || groupname == shapeTypesList[2])
                    {
                        int xloca;
                        int yloca;
                        int xsize;
                        int ysize;
                        lineStream >> xloca;
                        lineStream >> yloca;
                        lineStream >> xsize;
                        lineStream >> ysize;

                        Shape* shapeNew = new Shape(sname, groupname, xloca, yloca, xsize, ysize);
                        ShapeNode* shapeNodenew = new ShapeNode();
                        shapeNodenew->setShape(shapeNew);
                        poolGroup->getShapeList()->insert(shapeNodenew);
                        shapeNew->draw();
                    }

                }

            }
            if(command == keyWordsList[1])
            {
                int s=1;
                string gname;
                lineStream >> gname;
                for(int i=0; i<6;i++)
                {
                    if(gname ==  keyWordsList[i])
                    {
                        s=0;
                        cout<<"error: invalid name"<<endl;
                    }
                }
                for(int i=0; i<3;i++)
                {
                    if(gname ==  shapeTypesList[i])
                    {
                        s=0;
                        cout<<"error: invalid name"<<endl;

                    }
                }
                if(s == 1)
                {
                    GroupNode* gptr = gList->getHead();
                    while(gptr != NULL) 
                    {
                        if (gptr->getName() == gname || gptr->getShapeList()->find(gname) != nullptr) 
                        {
                            groupexists = true;
                            cout << "error: name "<<gname<<" exists"<< endl;
                            break;
                        } 
                        else 
                        {
                            groupexists = false;
                            gptr = gptr->getNext();
                        }
                    }
                    if(groupexists == false)
                    {
                        GroupNode* tempGroup = new GroupNode(gname);
                        gList->insert(tempGroup);
                        cout<<gname<<": "<<"group"<<endl;
                    }
                }
                
            }
            else if(command == keyWordsList[2])
            {
                int s=1;
                int g=1;
                string mname;
                string sname;
                lineStream >> mname;
                for(int i=0; i<6;i++)
                {
                    if(mname ==  keyWordsList[i])
                    {
                        s=0;
                        cout<<"error: invalid name"<<endl;
                    }
                }
                for(int i=0; i<3;i++)
                {
                    if(mname ==  shapeTypesList[i])
                    {
                        s=0;
                        cout<<"error: invalid name"<<endl;
                    }
                }
                if(s == 1)
                {

                    lineStream >> sname;

                    for(int i=0; i<6;i++)
                    {
                        if(sname ==  keyWordsList[i])
                        {
                            g=0;
                            cout<<"error: invalid name"<<endl;
                        }
                    }
                    for(int i=0; i<3;i++)
                    {
                        if(sname ==  shapeTypesList[i])
                        {
                            g=0;
                            cout<<"error: invalid name"<<endl;
                        }
                    }
                    if(g == 1)
                    {
                        GroupNode* tptr = gList->getHead();
                        GroupNode* sptr = gList->getHead();
                        GroupNode* cptr = nullptr;
                        GroupNode* ptr;
                        ShapeNode* ptr1;
                        while(tptr!= nullptr)
                        {
                            if(tptr->getShapeList()->find(mname) != nullptr)
                            {
                                shapeexists = true;
                                ptr = tptr;
                                //ptr = tptr->getShapeList()->find(mname);
                                tptr = NULL;
                            }
                            else
                            {
                                shapeexists = false;
                                tptr = tptr->getNext();
                            }
                        }
                        if(shapeexists == true)
                        {
                            while(sptr!= nullptr)
                            {
                                if(sptr->getName() == sname)
                                {
                                    grexists = true;
                                    cptr = sptr;
                                    sptr = NULL;
                                }
                                else
                                {
                                    grexists = false;
                                    sptr = sptr->getNext();
                                }
                            }
                            if(grexists == true)
                            {
                                ptr1 = ptr->getShapeList()->remove(mname);
                                cptr->getShapeList()->insert(ptr1);
                                cout<<"moved "<<mname<<" to "<<sname<<endl;
                            }
                            else{cout<<"error: group "<<sname<<" not found"<<endl;}
                        }
                        else
                        {
                            cout<<"error: shape "<<mname<<" not found"<<endl;
                        }
                    }

                }

            }
            else if(command == keyWordsList[3])
            {
               int s=0;
                string argname;
               lineStream >> argname;
               for(int i=0; i<6;i++)
               {
                   if(argname ==  keyWordsList[i])
                   {
                       s=1;
                       cout<<"error: invalid name"<<endl;
                       break;
                   }
               }
               for(int i=0; i<3;i++)
               {
                   if(argname ==  shapeTypesList[i])
                   {
                       s=1;
                       cout<<"error: invalid name"<<endl;
                   }
               }
               if(s == 0)
               {
                   GroupNode* ptr= gList->getHead();
                   GroupNode* temp= nullptr;
                   while(ptr!=NULL)
                   {
                       if(ptr->getName() == argname)
                       {
                           argexists = true;
                           temp = ptr;
                           ptr = NULL;
                       }
                       else
                       {
                           argexists = false;
                           ptr = ptr->getNext();
                       }
                   }
                   if (argexists == true)
                   {
                        ShapeList* start = temp->getShapeList();
                        ShapeNode* tptr = start->getHead();
                        while (tptr != nullptr){
                            string ny = tptr->getShape()->getName();
                            tptr = tptr->getNext();
                            ShapeNode* theshapeNode = start->remove(ny);
                            poolGroup->getShapeList()->insert(theshapeNode);
                        }
                        cout<<argname<<": deleted"<<endl;
                        GroupNode* find =gList->remove(argname);
                        delete find;
                        
                        //ShapeNode* n = temp->getShapeList()->getHead();
                        //while (n!= nullptr)
                       //{
                           
                            //ShapeNode* temp2 = new ShapeNode();
                           //Shape* setting = new Shape(n->getShape()->getName(), n->getShape()->getType(), n->getShape()->getXlocation(), n->getShape()->getYlocation(), n->getShape()->getXsize(), n->getShape()->getYsize());
                           //temp2->setShape(setting);
                           //poolGroup->getShapeList()->insert(temp2);
                           //delete temp2;
                           //temp2->print();
                           //delete setting;
                           //n= n->getNext();
                       //}
                       //gList->remove(argname);
                       //cout<<argname<<": deleted"<<endl;

                   }
                   else
                   {
                       GroupNode* ptr1= gList->getHead();
                       GroupNode* shap= nullptr;
                       while(ptr1!=NULL)
                       {
                           if(ptr1->getShapeList()->find(argname) != nullptr)
                           {
                               arggexists = true;
                               shap = ptr1;
                               ptr1 = NULL;
                           }
                           else
                           {
                               arggexists = false;
                               ptr1 = ptr1->getNext();
                           }
                       }
                       if(arggexists == true)
                       {
                           ShapeNode* tempshape = shap->getShapeList()->remove(argname);
                           delete tempshape;
                           cout<<argname<<": deleted"<<endl;
                       }
                       else
                       {
                           cout<<"error: shape "<<argname<<" not found"<<endl;
                       }

                   }
               }


            }
            else if(command == keyWordsList[4])
            {
                cout<<"drawing: "<<endl;
                gList->print();
            }
        }
        command ="";
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }
    // End input loop until EOF.
    
    return 0;
}

