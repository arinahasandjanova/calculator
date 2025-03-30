#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>
#include <regex>

std::string isValidExpression(const std::string& input);
bool isValidOp(const char& c);
double applyOperation(double a, double b, char op);
double evaluateExpression(const std::string& expression);