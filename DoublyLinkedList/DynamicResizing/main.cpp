//
//  main.cpp
//  DynamicResizing
//
//  Created by Laura Kirby on 10/26/17.
//  Copyright © 2017 LK. All rights reserved.
//

#include "book.h"

// Inlude the version of the link template class that
// uses a freelist
#include "linkFL.h"

// Include the linked list template class
#include "llist.h"

#include <iostream>
#include <cstdlib>
using namespace std;


// Main routine for array-based list driver class
int main(int argc, char** argv) {

    // 1. Declare an integer linked list.
    LList<int> linkedList;


    // 2. Add nodes with ints as values to the linked list.
    int intArray[3] = {1,2,3};

    for (int i = 0; i <= 2; i++ ) {
        linkedList.insert(intArray[i]);
        cout << "value added to Linked List: " << (intArray[i]) << endl;
    }

    // 3. Declare some sample lists (book examples)
    LList<Int*> L1;
    LList<Int*> L2(15);
    LList<Int> L3;

    return 0;
}

