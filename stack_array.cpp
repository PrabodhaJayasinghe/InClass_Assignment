#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

const int max_size=20;

class Stack {

    private:
        int top;
        int arr[max_size];
    public:

        Stack(){
            top=-1;
        }

        bool isFull(){
            return top==max_size-1;
        }

        bool isEmpty(){
            return top==-1;
        }

        void push(int value){
            if(isFull()){
                cout<<"Stack Overflow\n";
            }else{
                top++;
                arr[top]=value;
            }

        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack Underflow\n";
                return -1;
            }else{
                int value=arr[top];
                top--;
                return value;
            }
        }
        int StackTop(){
            if(isEmpty()){
                return -1;
            }else{
                return arr[top];

            }
        }
         void display(){
                if(!isEmpty()){
                    for(int i=top;i>-1;i--){
                        cout<<arr[i]<<" ";
                    }
                    cout<<endl;
                }

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
