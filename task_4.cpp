#include <iostream>


template < typename T >
T input(T array[])
{
    T sum;
    std::cout << "Fill the array (8): ";

    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
        sum += array[i];
    }

    std::cout << "Result: ";

    return sum / 8;
}


int main()
{
    std::cout << "For int array: \n";
    int arr_1[8];
    std::cout << input(arr_1) << "\n";


    std::cout << "For double array: \n";
    double arr_2[8];
    std::cout << input(arr_2) << "\n";
    

    std::cout << "For float array: \n";
    double arr_3[8];
    std::cout << input(arr_3) << "\n";
}

