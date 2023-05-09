#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Stack{
    private:
        Node* top;
    public:
        Stack(){
            this->top=NULL;
        }
        bool isEmpty() {
            return top == NULL;
        }   
        void push(int value){
            Node* newNode =new Node(value);
            if(isEmpty()){
                top = newNode;
            }else{
                newNode->next = top;
                top = newNode;
            }
        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack underfolw\n";
                return -1;
            }else{
               int value=top->data;
               Node* temp =top;
               top = top->next;
               delete temp;
               return value; 
            }
        }    
        int StackTop(){
            if(isEmpty()){
                return -1;
            }else{
                return top->data;

            }
        }

        void display(){
            Node*value = top;
            while(value != NULL){
                cout<<value->data<<" ";
                value=value->next;
            }
            cout<<endl;
        }

};
int main() {

    auto start = high_resolution_clock::now();
    Stack stk;
    stk.push(8);
    stk.push(10);
    stk.push(8);
    stk.push(10);
    stk.push(5);
    stk.push(11);
    stk.push(15);
    stk.push(23);
    stk.push(6); 
    stk.push(18);
    stk.push(20);
    stk.push(17);
    stk.display();
    for(int i=0; i<5;i++){
        stk.pop();
    } 
    stk.display();
    stk.push(4);
    stk.push(30);
    stk.push(3);
    stk.push(1);
    stk.display();
    auto end = high_resolution_clock::now();
    auto duration =duration_cast<microseconds>(end - start);
    cout << "Time taken iteration: " << duration.count() << " microseconds" << endl;

    return 0;
}