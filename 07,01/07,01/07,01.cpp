#include <iostream>

template<typename T>
class DynamicArray {
private:
    T* arr;
    int size;
public:
    DynamicArray(int sz) : size(sz) {
        arr = new T[size];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    T sum() const {
        T total = 0;
        for (int i = 0; i < size; ++i) {
            total += arr[i];
        }
        return total;
    }

    T& operator[](int index) {
        return arr[index];
    }
};

class Point {
public:
    int x;
    int y;
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

int main() {
    DynamicArray<int> intArray(5);
    intArray[0] = 1;
    intArray[1] = 2;
    intArray[2] = 3;
    intArray[3] = 4;
    intArray[4] = 5;

    DynamicArray<double> doubleArray(4);
    doubleArray[0] = 1.1;
    doubleArray[1] = 2.2;
    doubleArray[2] = 3.3;
    doubleArray[3] = 4.4;

    DynamicArray<char> charArray(3);
    charArray[0] = 'a';
    charArray[1] = 'b';
    charArray[2] = 'c';

    DynamicArray<Point> pointArray(2);
    pointArray[0] = Point(1, 2);
    pointArray[1] = Point(3, 4);

    std::cout << "Sum of intArray: " << intArray.sum() << std::endl;
    std::cout << "Sum of doubleArray: " << doubleArray.sum() << std::endl;

    std::cout << "Points in pointArray: ";
    for (int i = 0; i < 2; ++i) {
        std::cout << "(" << pointArray[i].x << ", " << pointArray[i].y << ") ";
    }
    std::cout << std::endl;

    return 0;
}
