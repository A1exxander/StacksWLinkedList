
#include <iostream>


class Stack {
private:

    struct Node {
        int data{};
        Node* nextNode;
    };

    Node* m_head{};
    Node* m_tail{};

public:
    Stack() : m_head{ nullptr }, m_tail{ nullptr }
    { 
    }

    int getData(){
        int data;
        std::cout << "\nEnter a number : ";
        std::cin >> data;
        return data;
    }

    void push(int data) {
        Node* temp{ new Node }; // As we are inserting a node, lets create one on heap
        temp->data = data; // set data
        temp->nextNode = nullptr; // set next to null

        if (m_head == nullptr) { // If head is empty, we will insert at the head and tail
            m_head = temp;
            m_tail = temp;
        }
        else { // Else, we will move onto tails next node and set temp it to temp, and then move the tail to next node 
            m_tail->nextNode = temp;
            m_tail = m_tail->nextNode;
            m_tail->nextNode = nullptr;
        }
        
        std::cout << "\nSuccessfully pushed :  " << m_tail->data;

    }

    void pop() {

        if (m_head == nullptr) {
            std::cout << "\nCannot pop! Stack is empty\n";
        }        
        else if (m_head == m_tail) {
            std::cout << "Popped : " << m_tail->data;
            delete m_tail; // We will just delete tail and not head as theyre pointing to the same object and deleting one will deallocate the other, else we would get an exception
            m_tail = nullptr;
            m_head = nullptr;
        }
        else {

            Node* temp = m_head; // Temp will traverse the list to the tail, we need to search thru as it isnt really a reliable method to get the node before tail assuming we have a singly linked list  
            while (temp->nextNode != m_tail ) {
                temp = temp->nextNode;
            }
            temp->nextNode = nullptr;

            std::cout << "Popped : " << m_tail->data << " ";
            delete m_tail;
            m_tail = temp;
        }
    }

    void peek() const {
        if (m_head != nullptr) {
            std::cout << "At top : " << (*m_tail).data;
        }
        else {
            std::cout << "\nCannot peak! Stack is empty";
        }
    
    }

    void purge() {
        if (m_head != nullptr) {
            Node* temp{nullptr};
            while (m_head->nextNode != nullptr) {
                temp = m_head;
                m_head = m_head->nextNode;
                delete temp;
            }
            delete m_head;
            m_head = nullptr;
            std::cout << "\nPurged!";
        }
        else {
            std::cout << "\nStack is empty!";
        }
    }

    void printStack() const {
    
        if (isEmpty()) {
            std::cout << "\n\nStack is empty! ";
        }
        else {

            Node* temp{ m_head };

            std::cout << "\n\nCurrent Stack : ";

            while (temp != nullptr) {

                std::cout << temp->data << " ";
                temp = temp->nextNode;

            }
        }
    }

    bool contains(int data) const {
    
        Node* current{ m_head };
        while (current != nullptr || current->data != data) {           
            current = current->nextNode;
        }
        if (current != nullptr && current->data == data)
            return true;
        else
            return false; // If we cannot find the desire data;

    }

    bool isEmpty() const {
        if (m_head == nullptr)
            return true;
        else 
            return false;
    }

};

int menuChoice();

int main(){

    Stack s;
    bool repeatMenu{ true };

    while (repeatMenu) {

        switch (menuChoice()) {
        
        case 1:
            s.push(s.getData());
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4: 
            s.purge();
            break;
        default : 
            std::cout << "\nExiting\n";
            repeatMenu = false;
        }

        s.printStack();

    }

}

int menuChoice() {

    int choice{};
    std::cout << "\n\n1. Push\n2. Pop\n3. Peek\n4. Purge\n5. Exit\n\nChoice : ";
    std::cin >> choice;
    return choice;

}