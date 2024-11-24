#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <bitset>
#include <fstream>
#include <sstream>

using namespace std;
vector<vector<uint8_t>> groupBits(const string& input, int rows, int columns) {
    int pages = rows/8;
    vector<vector<uint8_t>> output(pages, vector<uint8_t>(columns, 0));

    for (int num_col = 0; num_col < columns; ++num_col) {
        for (int num_page = 0; num_page < pages; ++num_page) {
            uint8_t byte = 0;
            for (int bit = 0; bit < 8; ++bit) {
                int index = (num_page * 8 + bit) * columns + num_col;
                byte |= (input[index] - '0') << bit;
            }
            output[num_page][num_col] = byte;
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
    int N, M;
    string row, input;

    cout << "Enter the number of rows N (must be a multiple of 8): ";
    cin >> N;
    cout << "Enter the number of columns M: ";
    cin >> M;
    cout << endl;
    
    if ((N % 8) != 0) {
        cerr << "Error: N must be a multiple of 8" << endl;
        return 1;
    }
    
    cout << "Enter the binary matrix of " << N << " rows and " << M << " columns, "
         << "each row must be saparated by spaces or newlines:" << endl;

    for (int i = 0; i < N; i++) {
        cin >> row;
        input += row;
    }

    if (input.size() != N * M) {
        cerr << "Error: The input string length does not match size: " 
             << N << " * "<< M << " = " << N * M << endl;
        return 1;
    }

    auto bytemap = groupBits(input, N, M);

    ofstream headerFile("drawing.h");

    if (!headerFile) {
        cerr << "Error: Could not create header" << endl;
        return 1; 
    }

    stringstream headerContent;
    int bytes_array = (N/8 * M);
    headerContent << "#ifndef DRAWING_H" << "\n#define DRAWING_H";
    headerContent << "\n#define PAGES "<< N/8 << "\n#define COLUMNS " << M; 
    headerContent << "\nchar drawing[" << bytes_array << "] = {\n";
    insertMatrix(bytemap, headerContent);
    headerContent << "};" << "\n#endif\n";

    headerFile << headerContent.str();
    headerFile.close();

    cout << "Header file created!" << endl;
    return 0;
}
