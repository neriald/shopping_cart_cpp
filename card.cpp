#include "card.h"
#include <iostream>
#include <string>

shoppingCart::shoppingCart(string _cname)
{
    cname = _cname;
}

shoppingCart::shoppingCart(const shoppingCart &a)
{
    cname = a.cname;
    cost = a.cost;
    pname = a.pname;
    counter+= pname.size();
}

shoppingCart::~shoppingCart()
{
    counter -= pname.size();
    pname.clear();
    cost.clear();
}

string shoppingCart::getCustomer() const
{
    return cname;
}

void shoppingCart::addItem(string _pname, double _cost)
{
    pname.push_back(_pname);
    cost.push_back(_cost);
    counter++;
}

void shoppingCart::removeItem(string _pname)
{
    for(unsigned i=0; i<pname.size(); i++)
    {
        if(pname[i] == _pname)
        {
            pname.erase(pname.begin()+i);
            cost.erase(cost.begin()+i);
            counter--;
        }
        else
            throw "no product called with this name is it possible you re seeing things may be you should get some rest we have beds at the back side would you like me to tuck you in?";
    }
}

int shoppingCart::size() const
{
    return pname.size();
}

double shoppingCart::totalCost() const
{
    double temp=0;
    for(unsigned i=0; i<cost.size(); i++)
        temp+=cost[i];
    return temp;
}

int shoppingCart::getItemCount()
{
    return counter;
}


ostream& operator<< (ostream &out, const shoppingCart &a)
{
    out << "Customer Name: " << a.cname << endl;
    out << "Products; " << endl;
    for(unsigned i=0; i<a.pname.size(); i++)
    {
        out << a.pname[i] << "  $" << a.cost[i] << endl;
    }
}


shoppingCart& shoppingCart::operator=(const shoppingCart &a)
{
    counter -= pname.size();
    counter += a.pname.size();

    pname=a.pname;
    cost=a.cost;
}

double& shoppingCart::operator[](string _pname)
{
    for(unsigned i=0; i<pname.size(); i++)
    {
        if(_pname == pname[i])
            cout << "price of " << _pname << ": " << cost[i] << endl;
    }
}


//MONDAY 12.30 OFFICE HOURS
