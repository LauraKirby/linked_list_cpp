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

    // Declare an integer linked list.
    LList<int> linkedList;


    // Add nodes with ints as values to the linked list.
    int intArray[3] = {1,2,3};

    for (int i = 0; i <= 2; i++ ) {
        linkedList.insert(intArray[i]);
        cout << "value added to Linked List: " << (intArray[i]) << endl;
    }

    // Declare some sample lists (book examples)
    LList<Int*> L1;
    LList<Int*> L2(15);
    LList<Int> L3;

    // Call print functions
    linkedList.printList();
    linkedList.printListBackward();

    // Test DoublyLinkedList, accept input from console and add it to Doubly Linked List
    string input;
    LList<string> doublyLinkedList;
    for (int i = 0; i < 3; i++ ) {
        cout << "\n\nenter preferred value into console." << endl;
        cin >> input;
        doublyLinkedList.insert(input);
        cout << "value added to Doubly Linked List: " << input << endl;
    }

    // Print Double Linked List forward and backward
    doublyLinkedList.printList();
    doublyLinkedList.printListBackward();

    return 0;
}

