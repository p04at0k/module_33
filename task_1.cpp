#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

using namespace std;

class Basket
{
    private:

    map<string,int> cart;
    map<string,int> database;

    void validation(const string& line,const string& key,const int& value) 
    {

        if(get_map(line).count(key) == 0)
        {
            throw invalid_argument("Current product wasn't found");
        }

        int available_number = get_map(line).at(key);

        if (available_number < value)
        {
            throw invalid_argument("Sorry, there are no such number of product.");
        }
    }

    public:

    void set_base(const string& key,const int& value)
    {
        database.insert(make_pair(key,value));
    }

    void display_map(const string& line)
    {
        for (const auto& element : get_map(line))
        {
            cout << "Article: "<< element.first << " goods: " << element.second << "\n";
        }

        cout << "\n";
    }

    map<string,int> get_map(const string& line)
    {
        return line == "database" ? database : cart;
    }


    void add(const string& key,int value)
    {

        validation("database", key, value);

        database[key] -= value;

        if (database[key] == 0)  
        {
            database.erase(key);
        }
        
        cart[key] += value;
    }

    void remove(const string& key,int value)
    {
        validation("cart", key, value);

        cart[key] -= value;

        if (cart[key] == 0) 
        {
            cart.erase(key);
        }
        
        database[key] += value;

    }

};


int main()
{
    cout << "Input article and number of goods for base(type '-1' to exit): \n";

    Basket basket;

    while(true)
    {   
        string key;
        int value;

        cin >> key;
        if (key == "-1") break;

        try
        {
           cin >> value;
           if (value < 1 ) throw value;
           else basket.set_base(key,value);
        }

        catch(...) 
        {
            cout << "Incorrect number of product\n";
        }
    }

    basket.display_map("database");

    while(true)
    {     
        try
        {
            string line,key;
            int value;

            cout << "Input operation name and parameters: ";
            cin >> line;
            if (line == "exit") break;
            cin >> key >> value;
            
            if (value < 1) 
            {
                throw invalid_argument("value < 1");
            }
            else if (line == "add") 
            {
               basket.add(key,value);
            }
            else if (line == "remove") 
            {
              basket.remove(key,value);
            }
            else cout << "Incorrect operation\n"; 
        }

        catch(const invalid_argument& x)
        {
            cerr << x.what() << "\n";
        }
    }

   cout << "\n";

   cout << "Base\n";
   basket.display_map("database");
   cout << "Cart\n";
   basket.display_map("cart");

}
