#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char str[100];
    int i = 0;

    cout << "Enter a statement: ";
    cin.getline(str, 100);

    while (str[i] != '\0') {

        // Skip spaces
        if (isspace(str[i])) {
            i++;
            continue;
        }

        // Identifier or Keyword
        if (isalpha(str[i])) {
            string word = "";
            while (isalnum(str[i])) {
                word += str[i];
                i++;
            }

            // Simple keyword check
            if (word == "int" || word == "float" || word == "if" || word == "else" || word == "return")
                cout << word << " : Keyword\n";
            else
                cout << word << " : Identifier\n";
        }

        // Number (Constant)
        else if (isdigit(str[i])) {
            string num = "";
            while (isdigit(str[i])) {
                num += str[i];
                i++;
            }
            cout << num << " : Constant\n";
        }

        // Operators
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '=') {
            cout << str[i] << " : Operator\n";
            i++;
        }

        // Special Symbols
        else {
            cout << str[i] << " : Special Symbol\n";
            i++;
        }
    }

    return 0;
}