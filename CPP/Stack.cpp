//Making a stack in c++ using an object-oriented approach

#include <iostream>

class Stack{
    public:
        //attributes
        int top;
        int *pArr;
        int size;
        
        //constructor
        Stack(int size){
            this -> size = size;
            this -> pArr = (int *)malloc(size * sizeof(int));
            this -> top = -1;
        }
        
        //methods
        void push(int num){
            if (this -> top >= this -> size){
                std::cout << "Stack overflow!" << std::endl;
            }
            else{
                *(pArr + ++(this -> top)) = num;
            }
        }
        
        void pop(){
            if (this -> top == -1){
                std::cout << "Stack underflow" << std::endl;
            }
            else{
                std::cout << "Popped: " << *(pArr + this -> top) << std::endl;
                this -> top--;
            }
        }
        
        void display(){
            for (int i = 0; i <= top; i++){
                std::cout << *(pArr + i) << " ";
            }
            std::cout << '\n';
        }
};

int main(){
    
    Stack stack(5);
    stack.push(9);
    stack.display();
    stack.push(3);
    stack.push(11);
    stack.push(14);
    stack.display();
    stack.pop();
    stack.display();
    
    return 0;
}
