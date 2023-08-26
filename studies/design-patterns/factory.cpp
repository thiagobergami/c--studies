/*  */
#include <string>
#include <iostream>

using namespace std;

class Product
{
public:
    virtual ~Product(){};
    virtual std::string Operation() const = 0; // const = 0 means that method is pure virutal.
};
class Book : public Product
{
public:
    std::string Operation() const override
    {
        return "{Result of the Book}";
    }
};

class Toy : public Product
{
public:
    std::string Operation() const override
    {
        return "{Result of the Toy}";
    }
};

class Creator
{
public:
    virtual ~Creator(){};
    virtual Product *FactoryMethod() const = 0;

    std::string SomeOperation() const
    {
        Product *product = this->FactoryMethod();

        std::string result = "Creator: " + product->Operation();
        delete product;
        return result;
    }
};

class BookCreator : public Creator
{
public:
    Product *FactoryMethod() const override
    {
        return new Book();
    }
};

class ToyCreator : public Creator
{
public:
    Product *FactoryMethod() const override
    {
        return new Toy();
    }
};

void ClientCode(const Creator &creator)
{
    std::cout << "Client: I'm not aware of the creator's class. \n"
              << creator.SomeOperation() << std::endl;
};

int main()
{
    std::cout << "App launched with BookCreator.\n";
    Creator *bookCreator = new BookCreator();
    ClientCode(*bookCreator);
    std::cout << std::endl;
    std::cout << "App: Launched with the ToyCreator.\n";
    Creator *toyCreator = new ToyCreator();
    ClientCode(*toyCreator);

    delete bookCreator;
    delete toyCreator;
    return 0;
};


