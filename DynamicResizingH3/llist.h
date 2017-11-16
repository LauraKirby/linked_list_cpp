//
//  llist.h
//  DynamicResizing
//
//  Created by Laura Kirby on 11/15/17.
//  Copyright © 2017 LK. All rights reserved.
//

#ifndef llist_h
#define llist_h

// This is the file to include in your code if you want access to the
// complete SList template class

// First, get the declaration for the base list class
#include "list.h"

// This is the declaration for LList. It is broken up because the
// methods that appear in the book are in a separate file.
// Linked list implementation
template <typename E> class LList: public List<E> {
private:
    Link<E>* head;      // Pointer to list header
    Link<E>* tail;      // Pointer to list tail
    Link<E>* curr;      // Pointer current element
    int cnt;            // Size of list

    void init() {        // Initialization helper method
        curr = tail = head = new Link<E>;
        cnt = 0;
    }

    void removeall() {      // Return link nodes to free store
        while(head != NULL) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList(int size=defaultSize) { init(); }     // Constructor
    ~LList() { removeall(); }                   // Destructor

    // Include those  methods that are different from singly linked list
    // Insert "it" at current position
    void insert(const E& it) {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next;    // New tail
        cnt++;
    }

    // Append "it" to the end of the list.
    void append(const E& it) {
        tail->prev = tail->prev->next =
        new Link<E>(it, tail->prev, tail);
        cnt++;
    }

    // Remove and return current element
    E remove() {
        Assert(curr->next != NULL, "No element");
        E it = curr->next->element;             // Remember value
        Link<E>* ltemp = curr->next;            // Remember link node
        if (tail == curr->next) tail = curr;    // Reset tail
        curr->next = curr->next->next;          // Remove from list
        delete ltemp;                           // Reclaim space
        cnt--;                                  // Decrement the count
        return it;
    }

    \
    void moveToStart()      // Place curr at list start
    { curr = head; }

    void moveToEnd()        // Place curr at list end
    { curr = tail; }

    // Move fence one step left; no change if left is empty
    void prev() {
        if (curr == head) return;       // No previous element
        Link<E>* temp = head;
        // March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
    }

    void clear() { removeall(); init(); }       // Clear list

    // Move fence one step right; no change if right is empty
    void next()
    { if (curr != tail->prev) curr = curr->next; }

    int length() const  { return cnt; }  // Return length

    // Return the position of the current element
    int currPos() const {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
            temp = temp->next;
        return i;
    }

    // Move down list to position
    void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
    }

    // Return current element
    const E& getValue() const {
        Assert(curr->next != NULL, "No value");
        return curr->next->element;
    }
};

#endif /* llist_h */
