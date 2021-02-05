/* Overloading using Matrix 
 * File:   main.cpp
 * Author: Rosita Emakpo 
 *
 * Created on December 1, 2020, 7:51 PM
 * Use each text file to test each case in command line arguments.
 */


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// pow(a,b)


using namespace std;
#define SIZE 10


class Matrix{

private:
    int data[SIZE][SIZE];
    int dim;
    
public:
    /**
     * No arguments constructor assume dimension is SIZE
     */
    Matrix() {
        dim = SIZE;
    }
    
    /**
     * Matrix of size given by m
     * @param m
     */
    Matrix(int m) {
        dim = m;
    }
    
    /**
     * Create a matrix by copying from the two dimensional array
     * 
     * @param x
     * @param dim
     */
    Matrix(int x[][SIZE], int dim) {
        for(int row = 0 ; row < SIZE ; row++) {
            for(int col = 0 ; col < SIZE ; col++) {
                data[row][col] = x[row][col];
            }
        }
        this->dim = dim;
    }
    
    int getDim() {
        return dim;
    }
    
    void read_file(istream &in);
    Matrix operator+(Matrix &);
    
    Matrix operator-(Matrix &);
    
    Matrix operator*(Matrix &);
    
    Matrix operator++(); // pre
    
    Matrix operator++(int); // post
    
    Matrix operator~();
    
    Matrix operator^(Matrix &);
    
    friend ostream & operator<<(ostream &out, const Matrix & m);
    
};


// 1. Addition +
Matrix Matrix::operator+(Matrix &b) {
    for(int row = 0 ; row < SIZE ; row++) {
        for(int col = 0 ; col < SIZE ; col++) {
            data[row][col] += b.data[row][col];
        }
    }
    return *this;
}


// 2. Subtraction -
Matrix Matrix::operator-(Matrix &b) {
    for(int row = 0 ; row < SIZE ; row++) {
        for(int col = 0 ; col < SIZE ; col++) {
            data[row][col] -= b.data[row][col];
        }
    }
    return *this;
}


//3. Multiplication *
Matrix Matrix::operator*(Matrix &b) {
    for(int i = 0 ; i < SIZE ; i++) {
        for(int j = 0 ; j < SIZE ; j++) {
            int sum = 0;
            for(int k = 0 ; k < dim ; k++) {
                sum += (data[i][k] * b.data[k][j]);
            }
            data[i][j] = sum;
        }
    }
    return *this;
}


//4.  Pre Increment ++x
Matrix Matrix::operator++() {
    for(int row = 0 ; row < SIZE ; row++) {
        for(int col = 0 ; col < SIZE ; col++) {
            data[row][col] += 1;
        }
    }
    return *this;
}




//5.  Post Increment x++

Matrix Matrix::operator++(int ) {
    Matrix tmp(data, dim);
   
    operator++();
    return tmp;
}



//6. Transpose ~

 Matrix Matrix::operator~() {
    Matrix tmp(data, dim);
    for(int i = 0 ; i < SIZE ; i++) {
        for(int j = 0 ; j < SIZE ; j++) {
            int sum = 0;
            for(int k = 0 ; k < dim ; k++) {
                tmp.data[i][j] = data[j][i];
            }
        }
    }
    return tmp;
}
 
 
 






//7. Positive exponential ^

Matrix Matrix::operator^(Matrix &b) {
    for(int i = 0 ; i < SIZE ; i++) {
        for(int j = 0 ; j < SIZE ; j++) {
            int sum = 0;
            for(int k = 0 ; k < dim ; k++) {
                sum += (data[i][k] * b.data[k][j]);
            }
            data[i][j] = pow(data[i][j], b.data[i][j]);
        }
    }
    return *this;
}







//8. Output <<
ostream & operator<<(ostream &out, const Matrix & m)
 {
    for(int row = 0 ; row < m.dim ; row++) {
        for(int col = 0 ; col < m.dim ; col++) {
            out << m.data[row][col];
            out << " " ;
        }
        out << endl;
    }
    
    return out;
}

void Matrix::read_file(istream &in) {
    
    for(int row = 0 ; row < dim ; row++) {
        for(int col = 0 ; col < dim ; col++) {
            in >> data[row][col];
        }
    }
}

void do_operations(istream &in, Matrix &a) {
    string s;
    int op;
    cout << "do_operations" << endl;
    cout << a;
    Matrix b(a.getDim());
     
    while(in >> s) {
        cout << s << endl;
        in >> op;
        cout << op << endl;;
        switch(op) {
            case 1:
                // addition
                b.read_file(in);
               
                cout << a + b;
                break;
                
             case 2:
                // subtraction
                b.read_file(in);
                cout << a - b;   
                break;
                         
            case 3:
                // Multiplication  
                b.read_file(in);
                cout << b << endl;
                cout << a * b;   
                break;   
            
            // Use text file input4.txt    
            case 4:
                // Pre increment
                cout << ++a;   
                break; 
            // ALso use text file input4.txt      
            case 5:
                // Post increment
                cout << a++ << endl;  
                cout << a << endl;
                break; 
                
            case 6:
                // Transpose ~
                b.read_file(in);
                cout << b << endl;
                cout << ~a << endl;
                cout << ~b << endl;
                break;
                
            case 7:
                // Post increment
                b.read_file(in);
                cout << b << endl;
                cout << (a ^ b) << endl; 
                cout << b;
                break;      
        }
                
    }
}

/*
 * main 
 */
int main(int argc, char *argv[]) {
    
    if(argc == 2) {
        /* we have a file as the input*/
        ifstream in(argv[1]);
        int dim;
        in >> dim;
        Matrix m(dim);
        m.read_file(in);
        
        do_operations(in, m);
        in.close();
    }
    else {
        int dim ;
        cin >> dim;
        Matrix m(dim);
        m.read_file(cin);
        do_operations(cin, m);
    }
    
    return 0;
}

