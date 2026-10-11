// Anthony Huey - 10/10/2026 - COMSC 210 - Lab 22: Upgrade DLL Class
// Amend the provided code with - 
// delete_pos() - delete node by position, aswell as cases for head and tail.
// pop_front() - delete head node.
// pop_back() - delete tail node.
// delete() - update to delete_val(), fine to keep head node deleteion.
// exrcise all changes in main.

#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList 
{
private:
    struct Node 
    {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) 
        {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) 
    {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) 
    {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) 
    {
        if (position < 0) 
        {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) 
        {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void print() 
    {
        Node* current = head;
        if (!current) return;
        while (current) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() 
    {
        Node* current = tail;
        if (!current) return;
        while (current) 
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
// delete_pos() - delete node by position, aswell as cases for head and tail.
    void delete_pos(int pos)
    {
        if (!head) return; // Empty list

        Node* temp = head;
        for (int i = 1; i < pos; i++) // get into the right position.
        { 
            temp = temp->next;
            if (!temp) return; // nothing here.
        }
        // crash here if pos is large hmm... fixed :)

        if (temp->prev) 
            temp->prev->next = temp->next;
        else 
            head = temp->next; // Deleting the head
        if (temp->next) 
            temp->next->prev = temp->prev;
        else 
            tail = temp->prev; // Deleting the tail

        delete temp;
    }
// pop_front() - delete head node. i think these crash on just one node gonna...
    void pop_front() 
    {
        if (!head) return; // Empty list -  writing it out to follow logic
        Node* temp = head; // set temp, the node to be deleted, to heda

        head = head->next; // set the new head, 
        // crash here if size = 1 hmm... add a check if we delete last node?
        if (head)                 // check if head has a vaule/is not null
            head->prev = nullptr; // 2+ nodes. set the prev pointer to null
        else                      // there was only one node/list is now empty
            tail = nullptr;       // fix the tail to point to null
        delete temp;        // delete the old head, 
    }
// pop_back() - delete tail node.
    void pop_back() 
    {
        if (!tail) return; // Empty list
        Node* temp = tail; 

        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }
// delete() - update to delete_val(), fine to keep head node deleteion.
    void delete_val(int value) 
    {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) 
            temp->prev->next = temp->next;
        else 
            head = temp->next; // Deleting the head

        if (temp->next) 
            temp->next->prev = temp->prev;
        else 
            tail = temp->prev; // Deleting the tail

        delete temp;
    }


};

// Driver program
int main() 
{
    srand(time(0));
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;
    // save - rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_LS-MIN_LS+1) + MIN_LS);
   
    cout << "\nList forward: ";
    list.print();

    /* dont need this right now
    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();
    */
    int x = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;
    cout << "\ndeleting pos: " << x;
    list.delete_pos(x);
    cout << "\nList forward: ";
    list.print();

    cout << "\nDeleting head...";
    list.pop_front();
    cout << "\nList forward: ";
    list.print();

    cout << "\nDeleting tail...";
    list.pop_back();
    cout << "\nList forward: ";
    list.print();

    int y;
    cout << "\nWhich value would you like to delete: ";
    cin >> y;
    cin.ignore();

    cout << "\nDeleting value: " << y;
    list.delete_val(y);
    cout << "\nList forward: ";
    list.print();

    return 0;
}
