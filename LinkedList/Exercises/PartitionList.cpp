#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }

        //   +======================================================+
        //   | Description:                                         |
        //   | - Partition list around value x                      |
        //   +======================================================+
        
        void partitionList(int x)
        {
            Node* lessDummy = new Node(0);            // Dummy node for < x list
            Node* greaterEqualDummy = new Node(0);    // Dummy node for >= x list
            Node* lessTail = lessDummy;
            Node* greaterEqualTail = greaterEqualDummy;

            Node* current = head;
            while (current != nullptr)
            {
                if (current->value < x)
                {
                    lessTail->next = current;
                    lessTail = current;
                }
                else
                {
                    greaterEqualTail->next = current;
                    greaterEqualTail = current;
                }
                
                current = current->next;
            }
            
            greaterEqualTail->next = nullptr;
            lessTail->next = greaterEqualDummy->next;

            head = lessDummy->next;

            delete lessDummy;
            delete greaterEqualDummy;
        }

};

// Helper function to check pass/fail
auto checkTestResult = [](bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
};

int main()
{
    cout << "\n------ Test: PartitionMixedNumbers ------\n";
        
    LinkedList list(1);
    list.append(4);
    list.append(3);
    list.append(2);
    list.append(5);
    list.append(2);
    
    cout << "BEFORE:    ";
    list.printList();
    
    cout << "partitionList(3)\n";
    cout << "EXPECTED:  1 -> 2 -> 2 -> 4 -> 3 -> 5\n";
    
    list.partitionList(3);
    
    cout << "ACTUAL:    ";
    list.printList();
    
    // Check if the list is partitioned correctly
    Node* current = list.getHead();
    bool isPartitioned = true;
    bool crossedPartitionValue = false;
    
    while (current && current->next) {
        if (current->value >= 3) {
            crossedPartitionValue = true;
        }
        if (crossedPartitionValue && current->value < 3) {
            isPartitioned = false;
            break;
        }
        current = current->next;
    }

    checkTestResult(isPartitioned);
}


