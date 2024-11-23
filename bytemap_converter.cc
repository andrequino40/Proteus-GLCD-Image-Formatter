#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;
vector<vector<uint8_t>> groupBits(const string& input, int rows) {
    int pages = rows/8;
    vector<vector<uint8_t>> output(pages, vector<uint8_t>(64, 0));

    for (int col = 0; col < 64; ++col) {
        for (int row = 0; row < pages; ++row) {
            uint8_t byte = 0;
            for (int bit = 0; bit < 8; ++bit) {
                int index = (row * 8 + bit) * 64 + col;
                byte |= (input[index] - '0') << bit;
            }
            output[row][col] = byte;
        }
    }
    return output;
}

void printMatrix(const vector<vector<uint8_t>>& matrix) {
    for (const auto& row : matrix) {
        for (uint8_t byte : row) {
            cout << "0x" << hex << setfill('0') << setw(2) << (int)byte << ", ";
        }
        cout << endl;
    }
}

void insertMatrix(const vector<vector<uint8_t>>& matrix, stringstream& ss) {
    for (const auto& row : matrix) {
        ss << "\t";
        for (uint8_t byte : row) {
            ss << "0x" << hex << setfill('0') << setw(2) << (int)byte << ", ";
        }
        ss << "\n";
    }
}

int main() {
    int N;
    string row, input;

    cout << "Enter the number of rows (must be a multiple of 8): ";
    cin >> N;
    cout << endl;
    
    if ((N % 8) != 0) {
        cerr << "Error: N must be a multiple of 8" << endl;
        return 1;
    }
    
    cout << "Enter the binary matrix of " << N << " rows and 64 columns, "
         << "each row must be saparated by spaces or newlines:" << endl;

    for (int i = 0; i < N; i++) {
        cin >> row;
        input += row;
    }

    if (input.size() != N * 64) {
        cerr << "Error: The input string length does not match size: " 
             << N << " * 64 = " << N * 64 << endl;
        return 1;
    }

    auto bytemap = groupBits(input, N);

    ofstream headerFile("drawing.h");

    if (!headerFile) {
        cerr << "Error: Could not create header" << endl;
        return 1; 
    }

    stringstream headerContent;
    headerContent << "#ifndef DRAWING_H\n" << "#define DRAWING_H\n" << "char drawing[512] = {\n";
    insertMatrix(bytemap, headerContent);
    headerContent << "};\n" << "#endif\n";

    headerFile << headerContent.str();
    headerFile.close();

    cout << "Header file created!" << endl;
    return 0;
}
