// Kalkulator.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using std::cout, std::endl, std::string, std::cin, std::cerr;



string toBinary(int decimal) {
    std::stringstream ss;
    while (decimal) {
        ss << (decimal % 2);
        decimal /= 2;
    }
    string binary = ss.str();
    reverse(binary.begin(), binary.end());
    return binary.empty() ? "0" : binary;
}

string toOctal(int decimal) {
    std::stringstream ss;
    ss << std::oct << decimal;
    return ss.str();
}

string toHexadecimal(int decimal) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << decimal;
    return ss.str();
}

int getInteger(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value < min || value > max) {
            cin.clear(); // Resetuj stan błędu
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Wyczyść bufor wejściowy
            cerr << "Invalid input. Please enter a valid integer." << endl;
        }
        else {
            break;
        }
    }

    return value;
}

bool isValidInput(const std::string& input, int base) {
    // Funkcja sprawdzająca, czy wejściowy ciąg jest poprawny dla wybranego systemu liczbowego
    for (char c : input) {
        int digit;
        if (base == 1) {
            // System binarny
            digit = c - '0';
            if (digit != 0 && digit != 1) {
                return false;
            }
        }
        else if (base == 2) {
            // System ósemkowy
            digit = c - '0';
            if (digit < 0 || digit > 7) {
                return false;
            }
        }
        else if (base == 3) {
            // System dziesiętny
            if (!isdigit(c)) {
                return false;
            }
        }
        else if (base == 4) {
            // System szesnastkowy
            if (!isxdigit(c)) {
                return false;
            }
        }
    }
    return true;
}