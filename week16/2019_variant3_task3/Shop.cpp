#include "Shop.hpp"

void Shop::addProduct(StoreItem* product)
{
    Shoes* shoePtr = dynamic_cast<Shoes*>(product);
    if(shoePtr != nullptr)
    {
        container.push_back(new Shoes(*shoePtr));
    }

    TShirt* shirtPtr = dynamic_cast<TShirt*>(product);
    if(shirtPtr != nullptr)
    {
        container.push_back(new TShirt(*shirtPtr));
    }
}

void Shop::changeName(const char* newName, size_t index)
{
    if(index > container.size())
    {
        throw std::invalid_argument("Index out of range");
    }
    container[index]->setName(newName);    
}

void Shop::changePrice(double newPrice, size_t index)
{
    if(index > container.size())
    {
        throw std::invalid_argument("Index out of range");
    }
    container[index]->setPrice(newPrice);    
}

void Shop::printAllProducts() const
{
    for(int i = 0; i < container.size(); ++i)
    {
        container[i]->print();
        std::cout << '\n';
    }
}

void Shop::removeProduct(size_t index)
{
    if(index > container.size())
    {
        throw std::invalid_argument("Index out of range");
    }

    delete container[index];
    container.erase(container.begin() + index);
}

Shop::~Shop()
{   
    for(int i = 0; i < container.size(); ++i)
    {
        delete container[i];
    }
}