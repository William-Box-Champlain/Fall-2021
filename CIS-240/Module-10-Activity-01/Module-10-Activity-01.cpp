/**
 * @file Module-10-Activity-01.cpp
 * @brief This assignment demonstrates utilizing a custom exception to signal an error.
 */
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/**
 * @brief Custom exception to signal specific errors in calculating the square root.
 */
class SqrtException { };

/**
 * @brief Calculates the (int) square root of a number
 * 
 *  Will throw exceptions:
 *   
 * @param number The number to calculate the square root for. 
 * @return int The square root. 
 * 
 * TODO If number is less than zero it should throw (sqrtexception) exception given above.
 * TODO if a square root can not be found, throw "square root not found" as a string.
 * 
 * @throws SqrtException If square root can not be computed.
 * @throws std::string if square root can not be found.
 * 
 */
int Sqrt(int number)
{
    // TODO check for value number and throw execption if needed.
    if(number <= 0) throw SqrtException();
    // Check all integers less or equal to number to see if one of is a square root
    for (int r = 0; r*r <= number; r++)
    {
        if (r*r == number) 
            return r;           
    }
    //TODO no square root, so throw a STRING exception
    throw std::string("square root not found");
}

int main()
{
    int number;
    cout << "Enter an integer: ";
    cin >> number;

    // TODO Try to find its square root and catch the thrown exceptions.
    try {
        int root = Sqrt(number);
        cout << "Square root is " << root;
    }
    catch (SqrtException e) {
        cout << "The number " << number << " has no square root.";
    }
    catch (std::string e) {
        cout << e << endl;
    }
    //cout << "The number " << number << " has no square root.";
    return 0;
}