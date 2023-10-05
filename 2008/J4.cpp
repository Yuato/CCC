#include <bits/stdc++.h>
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string prefixToPostfix(const std::string& prefixExpression) {
    std::stack<char> operatorStack;
    std::string postfixExpression = "";

    for (int i = prefixExpression.length() - 1; i >= 0; --i) {
        char currentChar = prefixExpression[i];
        if (isdigit(currentChar)) {
            postfixExpression = currentChar + postfixExpression;
        } else if (isOperator(currentChar)) {
            while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                   precedence(operatorStack.top()) >= precedence(currentChar)) {
                postfixExpression = operatorStack.top() + postfixExpression;
                operatorStack.pop();
            }
            operatorStack.push(currentChar);
        }
    }

    while (!operatorStack.empty()) {
        postfixExpression = operatorStack.top() + postfixExpression;
        operatorStack.pop();
    }

    return postfixExpression;
}

int main() {
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == ".")
            break;

        std::string postfix = prefixToPostfix(line);
        std::cout << postfix << std::endl;
    }

    return 0;
}