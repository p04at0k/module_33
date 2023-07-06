#include <iostream>
#include <ctime>
#include <stdexcept>
#include <algorithm>

class Field
{
    private:

    std::string arr[9] = {"0","0","0","0","0","0","0","0","0"};
    
    public:

    void set_fish()
    {
        int j = std::rand() % 9;
        arr[j] = "fish";
    }

    void set_boots()
    {
        int remainingBoots = 3;
        while (remainingBoots > 0) 
        {
            int j = std::rand() % 9;
            if (arr[j] == "0") 
            {
                arr[j] = "boot";
                remainingBoots--;
            }
        }    
    }

    void get_field()
    {
        for(int i = 0; i < 9; i++)
        {
            std::cout << arr[i] << " ";
        }

        std::cout << "\n";
    }

    void catching_fish(const int& sector)
    {
       if (arr[sector] == "fish")  throw std::runtime_error("You caught af fish!");
       else if(arr[sector] == "boot") throw std::runtime_error("You caught a boot!");  
    }
};


int main()
{
    std::srand(std::time(nullptr));

   Field field;
   field.set_fish();
   field.set_boots();

    try
    {
        while(true)
        {
            int sector;
            std::cout << "Throw a rod on: ";
            std::cin >> sector;

            if(sector < 0 || sector > 8) 
            {
                std::cout << "Sector out of range\n";
                continue;
            }       
            
            field.catching_fish(sector);
        }
    }
        
    catch(const std::runtime_error& x)
    {
        std::cout << x.what() << "\n";
    }

}
