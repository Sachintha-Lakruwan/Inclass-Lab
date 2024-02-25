#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> elements;
    int maxSize;
    int top;
public:
    Stack(int size) : maxSize(size), top(-1) {}

    void push(int data) {
        if (top == maxSize - 1) {
            return;
        }
        top++;
        elements.push_back(data);
    }

    void pop() {
        if (top == -1) {
            return;
        }
        elements.pop_back();
        top--;
    }

    void stackTop() {
        if (top == -1) {
            return;
        }
    }

    void display() {
        if (top == -1) {
            return;
        }
        for (int i = top; i >= 0; --i) {
            std::cout << elements[i] << " ";
        }
        std::cout << "\n";
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }
};


int main() {
    Stack myStack(5);
    std::string instruction;

    while (true) {
        std::cin >> instruction;

        if (instruction == "push") {
            int data;
            std::cin >> data;
            myStack.push(data);
        } else if (instruction == "pop") {
            myStack.pop();
        }else if (instruction == "stackTop") {
            myStack.stackTop();
        } else if (instruction == "display") {
            myStack.display();
        } else if (instruction == "isEmpty") {
            if (myStack.isEmpty()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "isFull") {
            if (myStack.isFull()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "exit") {
            break;
        } else {
            std::cout << "Invalid instruction. Valid instructions: push, pop, display, exit.\n";
        }
    }

    return 0;
}