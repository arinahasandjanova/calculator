#include "calc.h"

int main() {
    std::string expression;

    std::cout << "\n---------Welcome to our, working on the strenght of the goddess, calculator---------\n\n        Remember, that we can help you only with math problems for 6th grade       \n\n";
    do{
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~Please type your math expression~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n                        if you want to escape just say stop                          \n";
        std::getline(std::cin, expression);

        if (expression == "stop")
        {
            std::cout << "\n``Thank you for using our program, but we hope next time you'll choose another one``\n\n";
            break;
        }

        try {
            if (expression.empty()) {
                throw std::invalid_argument("you didn't write anything, try again:(");
            }
            
            std::string exp2 = isValidExpression(expression);

            if (exp2 == "") {
                throw std::invalid_argument("wrong input");
            }

            double result = evaluateExpression(exp2);
            std::cout << "your result: " << result << std::endl;

        } catch (const std::exception& e) {
            std::cerr << "error: " << e.what() << std::endl;
        }
    } while (true);

    return 0;
}