#include "Shop.hpp"

void Shop::addProduct(StoreItem *item)
{
    Fruit *fruitPtr = dynamic_cast<Fruit *>(item);
    if (fruitPtr)
    {
        container.push_back(new Fruit(*fruitPtr));
        return;
    }
    Vegetable *vegetablePtr = dynamic_cast<Vegetable *>(item);
    if (vegetablePtr)
    {
        container.push_back(new Vegetable(*vegetablePtr));
    }
}

void Shop::removeProduct(unsigned int index)
{
    if (index < container.size())
    {
        delete container[index];
        container.erase(container.begin() + index);
    }
}

void Shop::changePrice(unsigned int index, double newPrice)
{
    if (index < container.size())
    {
        container[index]->setPrice(newPrice);
    }
}

void Shop::changeNameOfProduct(unsigned int index, const std::string &newName)
{
    if (index >= container.size())
    {
        return;
    }
    StoreItem *itemPtr = dynamic_cast<StoreItem *>(container[index]);
    if (itemPtr)
    {
        itemPtr->setName(newName);
    }
}

void Shop::printAll() const
{
    for (int i = 0; i < container.size(); i++)
    {
        container[i]->print();
    }
}

Fruit Shop::mostCaloricFruit() const
{
    if (container.size() == 0)
    {
        return Fruit();
    }

    int index = -1;
    unsigned int maxCalories = 0;

    for (int i = 0; i < container.size(); i++)
    {
        Fruit *fruitPtr = dynamic_cast<Fruit *>(container[i]);
        if (fruitPtr)
        {
            if (container[i]->getCalories() > maxCalories)
            {
                maxCalories = container[i]->getCalories();
                index = i;
            }
        }
    }
    if (index == -1)
    {
        return Fruit();
    }
    Fruit *fruitPtr = dynamic_cast<Fruit *>(container[index]);
    return *fruitPtr;
}