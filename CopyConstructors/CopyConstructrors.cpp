// CopyConstructors.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <string>

class A
{


public:
    
    A(const int _rows, const int _cols, const int _int_value = 10, const std::string& _str_value = "String") : rows(_rows), cols(_cols) {
        arr = new int*[rows]; 
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols]; 
        }

        this->int_value = new int; 
        *this->int_value = _int_value; 

        this->str_value = new std::string; 
        *this->str_value = _str_value; 

        setArrayValues();
    }
private:
    int** arr; 
    int rows;  
    int cols;  
    int* int_value; 
    std::string* str_value;

public:
    
    A(const A& other) : rows(other.rows), cols(other.cols) {
        arr = new int*[rows]; 
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols]; 
            for (int j = 0; j < cols; j++) {
                arr[i][j] = other.arr[i][j]; 
            }
        }

        int_value = new int; 
        *int_value = *other.int_value; 

        str_value = new std::string; 
        *str_value = *other.str_value; 
    }

    
    A& operator=(const A& other) {
        if (this != &other) {
            
            for (int i = 0; i < rows; i++) {
                delete[] arr[i];
            }
            delete[] arr;
            delete int_value;
            delete str_value;

           
            rows = other.rows;
            cols = other.cols;
            arr = new int*[rows];
            for (int i = 0; i < rows; i++) {
                arr[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    arr[i][j] = other.arr[i][j]; 
                }
            }

            int_value = new int;
            *int_value = *other.int_value; 

            str_value = new std::string;
            *str_value = *other.str_value; 
        }

        return *this;
    }

    
    ~A() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i]; 
        }
        delete[] arr; 

        delete int_value; 
        delete str_value; 
    }

    void setArrayValues() const
    {
        int value = 0; 
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = value; 
                value++; 
            }
        }
    }
    
    
    void displayArray() const
    {
        std::cout << "Array values:" << '\n';
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << '\n';
        }
    }

    
    void displayInt() const
    {
        std::cout << "Int value: " << *int_value << '\n';
    }
    
    void displayString() const
    {
        std::cout << "String value: " << *str_value << '\n';
    }

    // function to display all variables
    void displayAll() const
    {
        displayArray();
        displayInt();
        displayString();
    }

};


int main()
{
    A a = A(3, 4);

     a.displayAll();

    A b = A(2,3, 6, "Hello");

    b.displayAll();
    b = a;

    b.displayAll();
}


