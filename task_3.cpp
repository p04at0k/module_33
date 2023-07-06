#include <iostream>
#include <vector>

template<typename KeyType, typename ValueType>
struct RegistryEntry
{
    KeyType key;
    ValueType value;

    RegistryEntry(const KeyType& _key, const ValueType& _value) : key(_key), value(_value) {}
};

template<typename KeyType, typename ValueType>
class Registry
{
private:
    std::vector<RegistryEntry<KeyType, ValueType>> map;

public:
    void add(const KeyType& key, const ValueType& value)
    {
        map.emplace_back(key, value);
    }

    void remove(const KeyType& key)
    {
        for(int i = 0;i < map.size();i++)
        {
            if(map[i].key == key) 
            {
                map.erase(map.begin() + i);
            }
        }
    }

    void print() const
    {
        for (const auto& entry : map)
        {
            std::cout << "Key: " << entry.key << ", Value: " << entry.value << std::endl;
        }
    }

    void find(const KeyType& key) const
    {
        std::cout << "Value(s) of your key: ";

        for(const auto& [first,second] : map)
        {
            if (first == key) 
            {
                std::cout << second << " ";
            } 
        }
        std::cout << "\n";
    }
};


int main()
{
    
    Registry<int, std::string> registry;

    int key;
    std::string value;

    std::string command;
    while (true)
    {
        std::cout << "Enter a command (add, remove, print, find) or 'exit' to quit: ";
        std::cin >> command;

        if (command == "add")
        {
            std::cout << "Enter key and value: ";
            std::cin >> key >> value;
            registry.add(key, value);
        }
        else if (command == "remove")
        {
            std::cout << "Enter key to remove entries: ";
            std::cin >> key;
            registry.remove(key);
        }
        else if (command == "print")
        {
            registry.print();
        }
        else if (command == "find")
        {
            std::cout << "Enter key to find entries: ";
            std::cin >> key;
            registry.find(key);
        }
        else if (command == "exit")
        {
           return 0;
        }
        else
        {
            std::cout << "Invalid command. Try again." << std::endl;
        }

    }
}