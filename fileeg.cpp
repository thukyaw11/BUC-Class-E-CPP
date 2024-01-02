#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string line;

    // Writing to file
    ofstream myfile;
    myfile.open("example.txt");
    myfile << "Writing to a file with cpp ";
    myfile.close();

    // Reading from file
    ifstream infile;
    infile.open("example.txt");

    if (infile.is_open()) {
        while (getline(infile, line)) {
            cout << line << endl;
        }
        infile.close();
    } else {
        cout << "Unable to open file";
    }

    return 0;
}
