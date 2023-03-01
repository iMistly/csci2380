#include "Node.h"

class LinkedList{
    public:
        Node* head; //The last pushed Node //The top of the list
        Node* tail; //The first pushed Node //The end of the list

        LinkedList(){
            tail = nullptr;
            head = nullptr;
        }

        void addNode(float inValue){
            Node* newNode = new Node(inValue);
            if(head!=nullptr){
                tail->next = newNode;
                tail = newNode;
            }
            else{
                head = newNode;
                tail = head;
            }
        }

        void printList(){
            Node* tmp = head;
            if(tmp==nullptr)
                cout << "It's empty.\n";
            else{
                while(tmp!=nullptr){
                    cout << tmp->value << ' ';
                    tmp = tmp->next;
                }
            }
            cout << '\n';
        }

        void removeNode(float inValue){
            Node* current = head;
            Node* previous = head;

            while(current!=nullptr){                
                if(current->value == inValue){
                    previous->next = current->next;
                    delete current;
                    break;
                }
                previous = current;
                current = current->next;
            }
        }
};