#include <iostream>
#include <string>
#include <vector>

using namespace std;

class shoppingCart
{
    string cname;  //customer name
    vector<double> cost;  //costs of products
    vector<string> pname;  //names of products
    static int counter;  //total item count on all carts

public:

    shoppingCart(string cname="");  //constructor
    shoppingCart(const shoppingCart &a);  //copy constructor
    ~shoppingCart();

    string getCustomer() const;   //returns customer name
    void addItem(string _pname, double _cost);  //its pretty obvious
    void removeItem(string _pname); //also..
    int size() const; // returns size of vector which means how many items in one cart
    double totalCost() const;  //total cost of a one cart
    static int getItemCount();  //returns total item count

    double& operator[](string _pname); //returns the price of an item of given name from the cart if it exist
    friend ostream& operator<< (ostream &out,const shoppingCart &a); // cout << overload
    shoppingCart& operator=(const shoppingCart &a);  //assignment operator overload which helps us to write a=b and cart a becomes the same as cart b removes all items in and replaces with the ones in b

};
