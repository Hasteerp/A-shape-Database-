//
//  Shape.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright �? 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the Shape class below

#include "Shape.h"
#include "string"

Shape::Shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz)
{
    name = n;                   // The name of the shape
    type = t;                   // The type of the shape (see globals.h)
    x_location = x_loc;                // The location of the shape on the x-axis
    y_location = y_loc;                // The location of the shape on the y-axis
    x_size = x_sz;                    // The size of the shape in the x-dimension
    y_size = y_sz;
}

// Accessors
string Shape::getType() {return type;}              // Returns the type
string Shape::getName(){return name;}              // Returns the name of the shape
int Shape::getXlocation(){return x_location;}            // Returns location of the shape on the x-axis
int Shape::getYlocation(){return y_location;}            // Returns location of the shape on the y-axis
int Shape::getXsize(){return x_size;}                // Returns the size of the shape in the x-dimension
int Shape::getYsize(){return y_size;}                // Returns the size of the shape in the y-dimension

// Mutators
void Shape::setType(string t){type = t;}        // Sets the type (see globals.h)
// No error checking done inside the method
// The calling program must ensure the type
// is correct
void Shape::setName(string n){name = n;}        // Sets the name of the shape
void Shape::setXlocation(int x_loc){x_location = x_loc;}  // Sets location of the shape on the x-axis
void Shape::setYlocation(int y_loc){y_location = y_loc;}  // Sets location of the shape on the y-axis
void Shape::setXsize(int x_sz){x_size = x_sz;}       // Sets size of the shape in the x-dimension
void Shape::setYsize(int y_sz){y_size = y_sz;}       // Sets size of the shape in the y-dimension

// Utility methods
void Shape::draw(){cout<<" "<<getName()<<": "<<getType()<<" "<<getXlocation()<<" "<<getYlocation()<<" "<<getXsize()<<" "<<getYsize()<<endl;}


