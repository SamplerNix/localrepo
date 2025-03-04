#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void circleCalculations() {
    float radius, area, circumference;
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    area = M_PI * pow(radius, 2);
    circumference = 2 * M_PI * radius;

    cout << fixed << setprecision(2);
    cout << "Area: " << area << endl;
    cout << "Circumference: " << circumference << endl;
}

void evaluateExpression() {
    double a, b, c, d, e, result;
    cout << "Enter values for a, b, c, d, e: ";
    cin >> a >> b >> c >> d >> e;

    result = pow((a + b * c - d / e), 2);
    cout << "Result: " << result << endl;
}

void checkPrime() {
    int num;
    cout << "Enter a number to check for prime: ";
    cin >> num;

    if (num <= 1) {
        cout << "Not prime" << endl;
        return;
    }
    if (num <= 3) {
        cout << "Prime" << endl;
        return;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        cout << "Not prime" << endl;
        return;
    }
    cout << "Prime" << endl;
}

void incrementDemonstration() {
    int i = 5, postInc, preInc;
    postInc = i++;
    cout << "Post-increment: " << postInc << ", i: " << i << endl;

    i = 5;
    preInc = ++i;
    cout << "Pre-increment: " << preInc << ", i: " << i << endl;
}
void arrayCalculations() {
    vector<int> nums(10);
    int evenSum = 0, oddProduct = 1;
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; ++i) {
        cin >> nums[i];
        if (nums[i] % 2 == 0) {
            evenSum += nums[i];
        } else {
            oddProduct *= nums[i];
        }
    }
    cout << "Sum of evens: " << evenSum << ", Product of odds: " << oddProduct << endl;
}
void matrixTranspose() {
    vector<vector<int>> matrix(3, vector<int>(3));
    cout << "Enter elements of the 3x3 matrix: ";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Transpose:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}
void stringAnalysis() {
    string input;
    int vowels = 0, consonants = 0, digits = 0, specialChars = 0;
    cout << "Enter a string: ";
    cin.ignore(); 
    getline(cin, input);

    for (char c : input) {
        if (isalpha(c)) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(c)) {
            digits++;
        } else if (!isspace(c)) {
            specialChars++;
        }
    }
    cout << "Vowels: " << vowels << ", Consonants: " << consonants
         << ", Digits: " << digits << ", Special chars: " << specialChars << endl;
}

void printPattern() {
    int rows;
    cout << "Enter number of rows for the pattern: ";
    cin >> rows;

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << j << " ";
        }
        cout << endl;
    }
}
void performOperation() {
    int a, b;
    char op;
    cout << "Enter two integers and an operator (+, -, *, /): ";
    cin >> a >> b >> op;

    switch (op) {
        case '+': cout << "Result: " << a + b << endl; break;
        case '-': cout << "Result: " << a - b << endl; break;
        case '*': cout << "Result: " << a * b << endl; break;
        case '/': cout << "Result: " << (b != 0 ? to_string(a / b) : "Division by zero") << endl; break;
        default: cout << "Invalid operator" << endl;
    }
}

int main() {
    circleCalculations();
    evaluateExpression();
    checkPrime();
    incrementDemonstration();
    arrayCalculations();
    matrixTranspose();
    stringAnalysis();
    printPattern();
    // dynamicBindingDemo();
    performOperation();

    return 0;
}