// Anthony Huey - 10/3/2026 - COMSC 210 - Lab 17: Linked list
// Rewrite the given code to use functions for the linked list operations.

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node 
{
    float value;
    Node *next; 
};
// Chose a pass by reference to avoid having to deal with what to return
// void functions are simpler for me to understand/write

void addFront(Node*&, int);

void addTail(Node*&, int);

void insertNode(Node*&);

void deleteNode(Node*&);

void deleteAll(Node*&);

void output(Node *);

int main() 
{
    Node *head = nullptr;
    bool exit = false;
    while (exit = false)
    {   
        int entry;
        cout << "\n---What would you like to do?---" 
             << "\n[1] Add a node at front."
             << "\n[2] Add a node at end."
             << "\n[3] Insert a node anywhere."
             << "\n[4] Delete a specific node."
             << "\n[5] Delete the whole list."
             << "\n[6] Display the list.";
        cout << endl;
        cin >> entry;
        cin.ignore();

        if (entry = 1)




    }
    
    // add node at head
    addFront(head, rand() % 100);
    output(head);

    // deleting a node
    deleteNode(head);
    output(head);

    // insert a node
    insertNode(head);
    output(head);

    //add node at tail
    addTail(head, rand() % 100);
    output(head);

    // delete all
    deleteAll(head);
    output(head);

    return 0;
}

void output(Node *hd) 
{
    if (!hd) 
    {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) 
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node*& head, int input)
{
    Node *newVal = new Node;
    if (!head) 
        {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = input;
        }
        else 
        {
            newVal->next = head;
            newVal->value = input;
            head = newVal;
        }
}

void addTail(Node*& head, int input)
{
    Node *newVal = new Node;
    Node *count = head;     // to find the end of the list.
    Node *prev = nullptr;   // keep track of the previous node, to link new node
    newVal->value = input;
    if (head == nullptr)    // check if the list is empty
    {
        head = newVal;
        newVal->next = nullptr;
    } 
    else
    {
        while (count)       // find the end/null, then append the new node
        {
            prev = count;
            count = count->next;
        }
        newVal->next = count;
        prev->next = newVal;
    }
    cout << endl;
       
}

void insertNode(Node*& head)
{
    int count;
    int entry;
    Node *current = head;
    Node *prev = nullptr; 
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    current = head;
    while (current) 
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) 
    {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) 
    {
        // inserting before the head
        head = newnode;
    } else 
    {
        prev->next = newnode;
    }
    cout << endl;
}

void deleteNode(Node*& head)
{
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++)
    {
        prev = current;
        current = current->next;
    }

    // at this point, delete current and reroute pointers
    if (current) 
    {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
}

void deleteAll(Node*& head)
{   
    Node *next = nullptr; 
    if (!head)
    {
        cout << "List is empty!";
        return;
    }

    while(head != nullptr)
    {
        next = head->next;
        delete head;
        head = next;
    }
    cout << endl;
   
}