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
    string name, input, row;

    cerr << "- Enter the name for the array: ";
    cin >> name;
    cerr << endl;

    cerr << "- Enter the number of rows N (must be a multiple of 8): ";
    cin >> N;
    cerr << endl;
    
    cerr << "- Enter the number of columns M: ";
    cin >> M;
    cerr << endl;
    
    if ((N % 8) != 0) {
        cerr << "> ERROR: N must be a multiple of 8" << endl;
        return 1;
    }
    
    cerr << "- Enter the binary matrix of " << N << " rows and " << M << " columns, "
         << "each row must be saparated by spaces or newlines:" << endl;

    int i = 0;

    while (cin >> row) {
        
        int row_size = row.size();

        if (i >= N) {
            cerr << "> WARNING: number of rows is greater than " << N << ", ignoring final rows." << endl;
            break;
        }

        if (row_size < M) {
            cerr << "> ERROR: Row " <<  i + 1 << " has length: "<< row_size 
                 << ", should be: " << M << "." << endl;
            return 1;
        }

        if (row_size > M) {
            cerr << "> WARNING: Row " << i + 1 << " has length: " << row_size 
                 << ", ignoring last " << row_size - M << " character/s." << endl;
            row.erase(M);
        }

        input += row;
        i++;
    }

    if (i < N) {
        cerr << "> ERROR: number of rows is: " << i << "but N is set to: " << N << endl;
        return 1;
    }

    auto bytemap = groupBits(input, N, M);

    int pages = N/8;
    int cols = M;
    int bytes_array = (pages * cols);
    cout << "\nchar "<< name << "[" << bytes_array << "] = {\n";
    stringstream array;
    insertMatrix(bytemap, array);
    cout << array.str();
    cout << "};\n";
    cout << "// nombre: "<< name << ", filas: " << pages << ", columnas: " << cols << endl; 
    cout << endl;


    cerr << "- Header file for \'" << name << "\' created!" << endl;
    return 0;
}
