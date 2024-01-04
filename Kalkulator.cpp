#include "Kalkulator.h"


int main() {
    while (true) {
        int sourceBase, targetBase;
        string sourceNumber;

        // Menu wyboru systemu liczbowego źródłowego
        cout << "Choose source numeric system:" << endl;
        cout << "1. Binary" << endl;
        cout << "2. Octal" << endl;
        cout << "3. Decimal" << endl;
        cout << "4. Hexadecimal" << endl;
        cout << "0. Exit" << endl;

        cout << endl;

        sourceBase = getInteger("Choice: ", 0, 4);

        cout << endl;

        if (sourceBase == 0) {
            cout << "Program terminated." << endl;
            break;
        }

        if (sourceBase < 1 || sourceBase > 4) {
            std::cerr << "Invalid choice for source numeric system." << endl;
            return EXIT_FAILURE;
        }

        if (sourceBase == 1 || sourceBase == 2 || sourceBase == 3 || sourceBase == 4){
        cout << "Enter number in the source numeric system: ";
        cin >> sourceNumber;

        cout << endl;

        if (!isValidInput(sourceNumber, sourceBase)) {
            cerr << "Invalid input. Please enter a valid numeric value for the chosen base." << endl;
            cout << endl;
            continue;  // Powrót do pętli wyboru systemu

          
            }
        }

        // Menu wyboru systemu liczbowego docelowego
        cout << "Choose target numeric system:" << endl;
        cout << "1. Binary" << endl;
        cout << "2. Octal" << endl;
        cout << "3. Decimal" << endl;
        cout << "4. Hexadecimal" << endl;
        cout << "0. Exit" << endl;

        cout << endl;

        targetBase = getInteger("Choice: ", 0, 4);

        if (targetBase == 0) {
            cout << "Program terminated." << endl;
            break;
        }

        if (targetBase < 1 || targetBase > 4) {
            std::cerr << "Invalid choice for target numeric system." << endl;
            return EXIT_FAILURE;
        }

        int decimalNumber;

        switch (sourceBase) {
        case 1:
            decimalNumber = std::stoi(sourceNumber, nullptr, 2);
            break;
        case 2:
            decimalNumber = std::stoi(sourceNumber, nullptr, 8);
            break;
        case 3:
            decimalNumber = std::stoi(sourceNumber);
            break;
        case 4:
            decimalNumber = std::stoi(sourceNumber, nullptr, 16);
            break;
        default:
            std::cerr << "Invalid choice for source numeric system." << endl;
            return EXIT_FAILURE;
        }

        std::string result;

        switch (targetBase) {
        case 1:
            result = toBinary(decimalNumber);
            break;
        case 2:
            result = toOctal(decimalNumber);
            break;
        case 3:
            result = std::to_string(decimalNumber); // Decimal
            break;
        case 4:
            result = toHexadecimal(decimalNumber);
            break;
        default:
            std::cerr << "Invalid choice for target numeric system." << endl;
            return EXIT_FAILURE;
        }

        // Wyświetlenie wyniku
        cout << "Result: " << result << endl;
        cout << endl;
    }

    return EXIT_SUCCESS;
}

