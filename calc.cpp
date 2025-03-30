#include "calc.h"

std::string isValidExpression(const std::string& input) {
    std::regex norma1{R"((?:(?: *(?:[\-]?\d+[\.]?\d*) *(?:[\-+*\^/]| *))*))"};
    std::regex norma2{R"(\s+)"};
    
    if(std::regex_match(input, norma1)) {
        return std::regex_replace(input, norma2, "");
    }
    return "";
}

bool isValidOp(const char& c) {
    if (!(c == '+' || c == '-' || c == '*' || c == '/'|| c == '^' || c == '.')) {
        return false;
    }
    return true;
}

double applyOperation(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("division by zero");
            }
            return a / b;
        case '^': return std::pow(a, b);
        default: throw std::invalid_argument("no available operator");
    }
}

double evaluateExpression(const std::string& expression) {
    std::vector<double> numbers;
    std::vector<char> operators;
    std::string currentNumber;
    char lastChar = '+';

    for (char currentChar : expression) {
        if(lastChar == '.' && currentChar == '.') {
            throw std::invalid_argument("wrong expresssion");
        }
        if (isdigit(currentChar) || (currentChar == '.' && currentNumber.find(currentChar) == std::string::npos)) {
            currentNumber += currentChar;
        } else {
            if(currentChar == '.' && currentNumber.find(currentChar) != std::string::npos) {
                throw std::invalid_argument("wrong expresssion!!");
            }
            if (currentChar == '-' && isValidOp(lastChar) && currentNumber.find(currentChar) == std::string::npos) {
                currentNumber += currentChar;
                continue;
            }else if(currentChar == '-' && currentNumber.find(currentChar) != std::string::npos){
                throw std::invalid_argument("wrong expression!--");
            }
            if (!currentNumber.empty()) {
                try {
                    double a = std::stod(currentNumber);
                    //std::cout<<a<<"\n";
                    numbers.push_back(a);
                } catch (const std::exception&) {
                    throw std::invalid_argument("can't convert a number");
                }
                currentNumber.clear();
            }

            if (std::string("+-*/^").find(currentChar) != std::string::npos) {
                if (numbers.size() == operators.size()) {
                    throw std::invalid_argument("wrong expression");
                }
                operators.push_back(currentChar);
            } else {
                throw std::invalid_argument(std::string("wrong operator") + currentChar);
            }
        }
        lastChar = currentChar;
    }

    if (!currentNumber.empty()) {
        try {
            numbers.push_back(std::stod(currentNumber));
        } catch (const std::exception&) {
            throw std::invalid_argument("can't convert a number" + currentNumber);
        }
    }

    if (numbers.size() != operators.size() + 1) {
        throw std::invalid_argument("wrong expression");
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '^') {
            numbers[i] = applyOperation(numbers[i], numbers[i + 1], '^');
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        if (operators[i] == '*' || operators[i] == '/') {
            numbers[i] = applyOperation(numbers[i], numbers[i + 1], operators[i]);
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            --i;
        }
    }

    for (size_t i = 0; i < operators.size(); ++i) {
        numbers[i] = applyOperation(numbers[i], numbers[i + 1], operators[i]);
        numbers.erase(numbers.begin() + i + 1);
        operators.erase(operators.begin() + i);
        --i;
    }

    return numbers[0];
}
