#include <iostream>
#include <string>

using namespace std;

/*
Single Responsibility Principle

A Class should do one thing and therefore it should have only a single reason to change

*/

class Book
{


public:
    Book(string name, string authorName, int year, int price, string isbn)
    {
        this.name = name;
        this.authorName = authorName;
        this.year = year;
        this.price = price;
        this.isbn = isbn;
    }
private:
    string name;
    string authorName;
    int year;
    int price;
    string isbn;
}

class Invoice
{

private:
    Book book;
    int quantity;
    double discountRate;
    double taxRate;
    double total;

public:
    Invoice(Book book, int quantity, double discountRate, double taxRate)
    {
        this.book = book;
        this.quantity = quantity;
        this.discountRate = discountRate;
        this.taxRate = taxRate;
        this.total = this.calculateTotal();
    }

public:
    double calculateTotal()
    {
        double price = ((book.price - book.price * discountRate) * this.quantity);

        double priceWithTaxes = price * (1 + taxRate);

        return priceWithTaxes;
    }

    // For SRP, this class should not have the logical to print. The class only have to "know" how to calculate the invoice
    void printInvoice()
    {
        System.out.println(quantity + "x " + book.name + " " + book.price + "$");
        System.out.println("Discount Rate: " + discountRate);
        System.out.println("Tax Rate: " + taxRate);
        System.out.println("Total: " + total);
    }

    // And also should not have the save system in the invoice class
    void saveToFile(string filename)
    {
        // Creates a file with given name and writes the invoice
    }
}
/* 
THE SRP FIX
*/

class InvoicePrinter {
    private:
        Invoice invoice;

    public:
    InvoicePrinter(Invoice invoice) {
        this.invoice = invoice;
    }

    public:
    void print() {
        System.out.println(invoice.quantity + "x " + invoice.book.name + " " + invoice.book.price + " $");
        System.out.println("Discount Rate: " + invoice.discountRate);
        System.out.println("Tax Rate: " + invoice.taxRate);
        System.out.println("Total: " + invoice.total + " $");
    }
}

class InvoicePersistence {
    private: 
        Invoice invoice;

    public:
    InvoicePersistence(Invoice invoice) {
        this.invoice = invoice;
    }
    void saveToFile(string filename) {
        // Creates a file with given name and writes the invoice
    }
}

int main () {
    Book myBook("MyBook", "me", 2000, 20, "dunno");
}