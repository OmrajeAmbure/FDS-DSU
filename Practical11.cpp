#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to convert infix expression to postfix
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> opStack;
    std::string postfix;
    
    for (char c : infix) {
        if (std::isspace(c)) continue; // Ignore spaces
        if (std::isalnum(c)) {
            postfix += c; // Append operand to postfix
        } else if (isOperator(c)) {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }
    
    // Pop all the operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }
    
    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(const std::string& postfix) {
    std::stack<int> valueStack;

    for (char c : postfix) {
        if (std::isdigit(c)) {
            valueStack.push(c - '0'); // Convert char to int
        } else if (isOperator(c)) {
            int rightOperand = valueStack.top(); valueStack.pop();
            int leftOperand = valueStack.top(); valueStack.pop();
            switch (c) {
                case '+':
                    valueStack.push(leftOperand + rightOperand);
                    break;
                case '-':
                    valueStack.push(leftOperand - rightOperand);
                    break;
                case '*':
                    valueStack.push(leftOperand * rightOperand);
                    break;
                case '/':
                    valueStack.push(leftOperand / rightOperand);
                    break;
            }
        }
    }

    return valueStack.top(); // Final result
}

int main() {
    std::string infix;

    std::cout << "Enter an infix expression (single characters only): ";
    std::getline(std::cin, infix);
    
    // Convert infix to postfix
    std::string postfix = infixToPostfix(infix);
    std::cout << "Postfix expression: " << postfix << std::endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    std::cout << "Evaluation of postfix expression: " << result << std::endl;

    return 0;
}

