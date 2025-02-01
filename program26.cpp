#include <iostream>
using namespace std;

class Matrix {
private:
    double values[3][3]; 

public:
//input
    void inputMatrix() {
        cout << "Enter 9 values for the matrix (3x3):" << endl;
        for (int i = 0; i < 3; i++) {

            for (int j = 0; j < 3; j++) {
                
                cin >> values[i][j]; 
            }
        }
    }



//output
    void displayMatrix() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << values[i][j] << " "; 
            }
            cout << endl; 
        }
    }


    Matrix add(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.values[i][j] = values[i][j] + other.values[i][j]; 
            }
        }
        return result; 
    }

    // Function to subtract two matrices
    Matrix subtract(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.values[i][j] = values[i][j] - other.values[i][j]; 
            }
        }
        return result; 
    }


    Matrix multiply(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.values[i][j] = 0; 
                for (int k = 0; k < 3; k++) {
                    result.values[i][j] += values[i][k] * other.values[k][j]; 
                }
            }
        }
        return result; 
    }
};

int main() {
    Matrix m1, m2, result;

    // taking the matrix input from the user 
    cout << "Matrix 1:" << endl;
    m1.inputMatrix();
    cout << "Matrix 2:" << endl;
    m2.inputMatrix();

    
    cout << "Matrix 1:" << endl;
    m1.displayMatrix();
    cout << "Matrix 2:" << endl;
    m2.displayMatrix();


    result = m1.add(m2);
    cout << "Matrix 1 + Matrix 2:" << endl;
    result.displayMatrix();


    result = m1.subtract(m2);
    cout << "Matrix 1 - Matrix 2:" << endl;
    result.displayMatrix();


    result = m1.multiply(m2);
    cout << "Matrix 1 * Matrix 2:" << endl;
    result.displayMatrix();

    return 0;
}
