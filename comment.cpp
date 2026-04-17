#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("input.cpp");     // input C++ file
    ofstream outFile("comments.txt"); // output file

    char ch, next;

    if (!inFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    while (inFile.get(ch)) {
        // Detect single-line comment //
        if (ch == '/') {
            next = inFile.peek();

            // Single-line comment
            if (next == '/') {
                outFile << ch;
                inFile.get(ch); // consume second '/'
                outFile << ch;

                while (inFile.get(ch) && ch != '\n') {
                    outFile << ch;
                }
                outFile << endl;
            }

            // Multi-line comment /* */
            else if (next == '*') {
                outFile << ch;
                inFile.get(ch); // consume '*'
                outFile << ch;

                while (inFile.get(ch)) {
                    outFile << ch;
                    if (ch == '*' && inFile.peek() == '/') {
                        inFile.get(ch);
                        outFile << ch;
                        break;
                    }
                }
                outFile << endl;
            }
        }
    }

    inFile.close();
    outFile.close();

    cout << "Comments extracted successfully!" << endl;
    return 0;
}