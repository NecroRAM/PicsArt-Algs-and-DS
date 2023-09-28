#include <iostream>
#include <vector>

struct entry
{
    int _key, _value;
    bool isSet;

    entry(int key = -1, int value = -1)
        : _key(key)
        , _value(value)
    {
        isSet = !(key < 0 and value < 0);
    }

    entry& operator=(entry& rhs)
    {
        this->_key = rhs._key;
        this->_value = rhs._value;
        this->isSet = rhs.isSet;
        return *this;
    }
};

class MyHashMap 
{
private:
    std::vector<std::vector<entry>> hm;
    const double threshold = 0.75;
    int load = 0;
    unsigned int hash(int value, std::size_t size) 
    {
        const unsigned int FNV_OFFSET_BASIS = 2166136261;
        const unsigned int FNV_PRIME = 16777619;

        unsigned int hash = FNV_OFFSET_BASIS;
        unsigned char* data = reinterpret_cast<unsigned char*>(&value);

        for (size_t i = 0; i < sizeof(int); ++i) 
        {
            hash ^= data[i];
            hash *= FNV_PRIME;
        }
        return hash % size;
    }
    auto contains(const int key)
    {
        unsigned const int h = hash(key, hm.size());
        return std::find_if(hm[h].begin(), hm[h].end(), [&](entry el) { return el.isSet; });
    }
    void rehash()
    {
        std::vector<std::vector<entry>> nhm(hm.size() * 2);
        for (auto& el : hm)
            for (auto& en : el)
                nhm[hash(en._key, nhm.size())].emplace_back(entry(en._key, en._value)).isSet = true;
        hm = std::move(nhm);
    }
public:
    MyHashMap(int size = 11)
        : hm(size, std::vector<entry>(1, (-1, -1)))
    {
        std::cout << "hm created\n";
    }

    void print()
    {
        for (auto& el : hm)
            for (auto& entry : el)
                std::cout << '[' << entry._key << ',' << entry._value << "], ";
        std::cout << '\n';
    }

    void put(int key, int value) 
    {
        auto it = this->contains(key);
        if (it != hm[hash(key, hm.size())].end())
            it->_value = value;
        else
        {
            hm[hash(key, hm.size())].emplace_back(entry(key, value)).isSet = true;
            ++load;

            if (load / hm.size() > threshold)
                this->rehash();
        }
    }
    
    int get(int key) 
    {
        return (this->contains(key) != hm[hash(key, hm.size())].end() ? this->contains(key)->_value : -1);
    }
    
    void remove(int key) 
    {
        auto it = this->contains(key);

        if (it != hm[hash(key, hm.size())].end())
            it->isSet = false;
    }
};

int main()
{
    MyHashMap hm;
    hm.remove(27);
    std::cout << ".\n";
    hm.put(65, 65);
    std::cout << ".\n";
    hm.remove(19);
    std::cout << ".\n";
    hm.remove(0);
    std::cout << ".\n";
    std::cout << hm.get(18) << '\n';
    hm.remove(3);
    std::cout << ".\n";
    hm.put(42, 0);
    std::cout << ".\n";
    std::cout << hm.get(19) << '\n';
    hm.remove(42);
    std::cout << ".\n";
    hm.put(17, 90);
    std::cout << ".\n";
    hm.put(31, 76);
    std::cout << ".\n";
    hm.put(48, 71);
    std::cout << ".\n";
    hm.put(5, 50);
    std::cout << ".\n";
    hm.put(7, 68);
    std::cout << ".\n";
    hm.put(73, 74);
    std::cout << ".\n";
    hm.put(85, 18);
    std::cout << ".\n";
    hm.put(74, 95);
    std::cout << ".\n";
    hm.put(84, 82);
    std::cout << ".\n";
    hm.put(59, 29);
    std::cout << ".\n";
    hm.put(71, 71);
    std::cout << ".\n";
    hm.remove(42);
    std::cout << ".\n";
    hm.put(51, 40);
    std::cout << ".\n";
    hm.put(33, 76);

    hm.print();

    std::cout << ".\n";
    std::cout << hm.get(17) << '\n';
    hm.put(89, 95);
    std::cout << ".\n";
    std::cout << hm.get(95) << '\n';
    hm.put(30, 31);

    hm.print();

    std::cout << ".\n";
    hm.put(37, 99);
    std::cout << ".\n";
    std::cout << hm.get(51) << '\n';
    std::cout << hm.get(71) << '\n';

}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */