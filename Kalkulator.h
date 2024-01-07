#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using std::cout, std::endl, std::string, std::cin;

class NumberConverter {
public:
    NumberConverter() = default;
    ~NumberConverter() = default;

   string toBinary(int decimal) const;
   string toOctal(int decimal) const;
   string toHexadecimal(int decimal) const;
    int getInteger(const string& prompt, int min, int max) const;
    bool isValidInput(const string& input, int base) const;
};

string NumberConverter::toBinary(int decimal) const {
    std::stringstream ss;
    while (decimal) {
        ss << (decimal % 2);
        decimal /= 2;
    }
    string binary = ss.str();
    reverse(binary.begin(), binary.end());
    return binary.empty() ? "0" : binary;
}

string NumberConverter::toOctal(int decimal) const {
    std::stringstream ss;
    ss << std::oct << decimal;
    return ss.str();
}

string NumberConverter::toHexadecimal(int decimal) const {
    std::stringstream ss;
    ss << std::hex << std::uppercase << decimal;
    return ss.str();
}

int NumberConverter::getInteger(const string& prompt, int min, int max) const {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a valid integer." << endl;
        }
        else {
            break;
        }
    }

    return value;
}

bool NumberConverter::isValidInput(const string& input, int base) const {
    for (char c : input) {
        int digit;
        if (base == 1) {
            digit = c - '0';
            if (digit != 0 && digit != 1) {
                return false;
            }
        }
        else if (base == 2) {
            digit = c - '0';
            if (digit < 0 || digit > 7) {
                return false;
            }
        }
        else if (base == 3) {
            if (!isdigit(c)) {
                return false;
            }
        }
        else if (base == 4) {
            if (!isxdigit(c)) {
                return false;
            }
        }
    }
    return true;
}
