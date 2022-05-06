#include"std_lib_facilities.h"

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// This function does not compile as we are trying to assign values to
// read-only references. We can safely discard it.
// void swap_cr(const int& a, const int& b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

int main()
{
    int x = 7;
    int y = 9;
    
    // swap_v(x, y);   // Compiles but does not swap anything, as expected since 
    //                 // swap_v only manages copies of its arguments.
    swap_r(x, y);   //  Compiles and swaps values as expected
    // swap_v(7, 9);   // Compiles but does nothing
    // swap_r(7, 9);   // Does not compile as a reference could not be initialized
    //                 // with an rvalue (literal) since there is no object that
    //                 // could be referenced.

    
    cout << "x is now " << x << " and y is now " << y << '\n';

    const int cx = 7;
    const int cy = 9;

    // swap_v(cx, cy); // Compiles since we are passing copies of variables, 
    //                 but it doesn't swap as it manages copies.
    // swap_r(cx, cy); // Does not compile. It seems that trying to make a non-const
    //                 // reference to a const variable is not fine.

    // These two calls also causes truncation of its arguments.
    // swap_v(7.7, 9.9);   // Compiles but does nothing. Same reason as swap_v(7,9)
    // swap_r(7.7, 9.9);   // Does not compile. Same reason as swap_r(7,9)

  
    cout << "cx is now " << cx << " and cy is now " << cy << '\n';

    double dx = 7;
    double dy = 9;

    // swap_v(dx, dy); // Compiles but does not swap. Same as previous swap_v calls.
    // swap_r(dx, dy); //  it does not compile. But, since we are facing
    //                 // an implicit conversion from double to int, what the 
    //                 // function is receiving is an rvalue and no reference can
    //                 // be made. 

     
    cout << "dx is now " << dx << " and dy is now " << dy << '\n';

    return 0;
}