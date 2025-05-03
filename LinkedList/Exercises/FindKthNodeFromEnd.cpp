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
        //   | - Find the k-th node from the end of the list        |
        //   +======================================================+

        Node* findKthFromEnd(int k)
        {
            Node* slow = head;
            Node* fast = head;

            for (int i = 0; i < k; i++)
            {
                if (fast == nullptr) return nullptr;
                fast = fast->next;
            }

            while (fast != nullptr)
            {
                slow = slow->next;
                fast = fast->next;
            }
            
            return slow;
        }
};

// Function to convert nullptr to string for easy comparison
auto ptrToNum = [](Node* ptr) -> string {
    return (ptr == nullptr) ? "nullptr" : to_string(ptr->value);
};

// Helper function to check test result
auto checkTestResult = [](bool condition) {
    cout << (condition ? "PASS" : "FAIL") << endl;
};

int main()
{
    cout << "\n------ LinkedList Test: KSecondFromEnd ------\n";
        
    LinkedList list(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    
    list.printList();
    
    Node* result = list.findKthFromEnd(2);
    
    cout << "Kth from end: " << ptrToNum(result) << endl;
    
    checkTestResult(result && result->value == 4);
}