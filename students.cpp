#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    string name;
    float marks;

    ofstream file("students.txt");  // create/open file

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        cin >> name;

        cout << "Enter marks: ";
        cin >> marks;

        // Writing to file
        file << name << " " << marks << endl;
    }

    file.close();  // close file

    cout << "\nData successfully written to file!" << endl;

    return 0;
}