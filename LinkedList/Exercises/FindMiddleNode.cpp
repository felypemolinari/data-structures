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
        Node* tail;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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

        Node* getTail() {
            return tail; 
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        //   +======================================================+
        //   | Description:                                         |
        //   | - Find the middle node of the linked list            |
        //   +======================================================+

        Node* findMiddleNode()
        {
            Node* slow = head;
            Node* fast = head;

            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            return slow;
        }
};

// Function to convert nullptr to "0 (nullptr)"
auto ptrToNum = [](Node* ptr) -> string {
    return (ptr == nullptr) ? "0 (nullptr)" : to_string(ptr->value);
};

// Helper function to check test result
auto checkTestResult = [](bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
};

int main() 
{
    cout << "\n------ LinkedList Test: Middle Node ------\n";
    
    LinkedList list(1);
    list.append(2);
    list.append(3);
    
    list.printList();
    
    Node* middle = list.findMiddleNode();
    
    cout << "Middle node: " << ptrToNum(middle) << endl;
    
    checkTestResult(middle->value == 2);
}