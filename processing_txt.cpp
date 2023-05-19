#include <iostream>
#include <fstream>

class StringMatrix {
private:
    char** matrix;
    int numRows, numCols;

public:
    StringMatrix(int numRows, int numCols) : numRows(numRows), numCols(numCols) {
        matrix = new char*[numRows];
        for (int i = 0; i < numRows; i++) {
            matrix[i] = new char[numCols];
        }
    }

    ~StringMatrix() {
        for (int i = 0; i < numRows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    int getNumRows() const {
        return numRows;
    }

    int getNumCols() const {
        return numCols;
    }

    void setChar(int row, int col, char c) {
        matrix[row][col] = c;
    }

    char getChar(int row, int col) const {
        return matrix[row][col];
    }

    const char* getRow(int row) const {
        return matrix[row];
    }
};

int findNumCols(std::ifstream* file) {
    int numCols = 0;
    file->clear();
    file->seekg(0, std::ios::beg);
    char test;
    while (file->get(test)) {
        if (test == '\n') {
            break;
        }
        numCols++;
    }
    return numCols;
}

int findNumRows(std::ifstream* file, int numCols) {
    int numCharacters = 0;
    file->clear();
    file->seekg(0, std::ios::beg);
    while (file->good()) {
        file->get();
        numCharacters++;
    }
    return (numCharacters / numCols);
}

void copyStringFromTextFile(StringMatrix* matrix, std::ifstream* file) {
    file->clear();
    file->seekg(0, std::ios::beg);
    int row = 0, col = 0;
    char test;
    while (file->good()) {
        file->get(test);
        if (test == '\n') {
            row++;
            col = 0;
        }
        else {
            matrix->setChar(row, col++, test);
        }
    }
}

void transformMatrix(StringMatrix* newMatrix, const StringMatrix* oldMatrix) {
    int controlCheck = 0, auxiliary = 0;
    for (int i = 0; i < newMatrix->getNumRows(); i++) {
        for (int j = 0; j < newMatrix->getNumCols(); j++) {
            if (j == 0 || j == newMatrix->getNumCols() - 1) {
                newMatrix->setChar(i, j, '{');
                if (j == newMatrix->getNumCols() - 1) {
                    newMatrix->setChar(i, j, '}');
                }
            }
            else {
                if (controlCheck % 2 != 0) {
                    newMatrix->setChar(i, j, ',');
                }
                else {
                    newMatrix->setChar(i, j, oldMatrix->getChar(i, auxiliary++));
                }
                controlCheck++;
            }
        }
        auxiliary = 0;
        controlCheck = 0;
    }
}

int main() {
    std::ifstream file("bank.txt");

    int numCols = findNumCols(&file);
    int numRows = findNumRows(&file, numCols);

    StringMatrix newMatrix(numRows, numCols);
    copyStringFromTextFile(&newMatrix, &file);

    int newNumCols = numCols + 2 + numCols - 1;

    StringMatrix reloadedMatrix(numRows, newNumCols);
    transformMatrix(&reloadedMatrix, &newMatrix);

    std::ofstream newFile("new_bank.txt");
    for (int i = 0; i < reloadedMatrix.getNumRows(); i++) {
        newFile << reloadedMatrix.getRow(i);
        newFile << "\n";
    }

    return 0;
}
