#include <iostream>
#include "card.h"
using namespace std;

int shoppingCart::counter = 0;

int main()
{
    shoppingCart a, b("cagkan"); //declarations of a and b as type of shoppingCart class, a without customer name declared so its empty string

    cout << a; // prints a easily thanks to overload

    a.addItem("apple", 10); // adds item to cart a

    a["apple"]; //returns the price of apple

    cout << "size: " << a.size() << endl; // number of items in the cart

    b=a; //adds all items from b to a

    cout << b;
    b.addItem("weed",35); //adding another precious item

    cout << "size: " << b.size() << endl; // printing the size of b cart

    cout << b;

    cout << "total cost: " << b.totalCost() << endl;



    return 0;
}
