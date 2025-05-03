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
        //   | - Convert binary number in list to decimal           |
        //   +======================================================+

        int binaryToDecimal()
        {
            Node* current = head;
            int num = 0;

            while (current != nullptr)
            {
                num = num * 2 + current->value;
                current = current->next;
            }
            
            return num;
        }
};

// Helper function for pass/fail
auto checkTestResult = [](bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
};

int main()
{
    cout << "\n------ Test: BinaryToDecimalAllOnes ------\n";
        
    LinkedList list(1);
    list.append(1);
    list.append(1);
    list.append(1);
    
    cout << "BINARY:    ";
    list.printList();
    
    int decimal = list.binaryToDecimal();
    
    cout << "DECIMAL:   " << decimal << endl;
    
    checkTestResult(decimal == 15);
}