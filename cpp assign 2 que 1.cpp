
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:

    Product()
    {
        productId = 0;
        name = "";
        price = 0;
        quantity = 0;
    }

    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    double totalValue() const
    {
        return price * quantity;
    }

    bool isLowStock(int threshold) const
    {
        if (quantity < threshold)
            return true;
        else
            return false;
    }

    string getName() const
    {
        return name;
    }

    void displayDetails() const
    {
        cout << left << setw(10) << productId
             << setw(15) << name
             << right << setw(10) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue();
    }
};


double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate)
{
    double amount = qty * unitPrice;
    return amount + (amount * taxRate);
}


double applyDiscount(double price, double discountPercent = 10.0)
{
    double discount = price * discountPercent / 100;
    return price - discount;
}


int main()
{
    Product items[5];

    cout << "--- Enter Details for 5 Products ---" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        items[i].acceptDetails();
    }

    cout << "\n===== INVENTORY REPORT =====" << endl;

    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << right << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value" << endl;

    for (int i = 0; i < 5; i++)
    {
        items[i].displayDetails();

        if (items[i].isLowStock(10))
        {
            cout << "  <- LOW STOCK";
        }

        cout << endl;
    }



    int highIdx = 0;

    for (int i = 1; i < 5; i++)
    {
        if (items[i].totalValue() > items[highIdx].totalValue())
        {
            highIdx = i;
        }
    }

    cout << "\nHighest Value Product : "
         << items[highIdx].getName()
         << " (Rs. "
         << fixed << setprecision(2)
         << items[highIdx].totalValue()
         << ")" << endl;

    int userThreshold;

    cout << "\nEnter threshold to find low stock items: ";
    cin >> userThreshold;

    cout << "Low Stock (threshold: "
         << userThreshold << ") : ";

    bool first = true;

    for (int i = 0; i < 5; i++)
    {
        if (items[i].isLowStock(userThreshold))
        {
            if (!first)
                cout << ", ";

            cout << items[i].getName();
            first = false;
        }
    }

    cout << endl;


    cout << "\n--- Testing Overloaded Functions ---" << endl;

    cout << "Reorder Cost (Int: 20 items @ 15.00): "
         << reorderCost(20, 15.00) << endl;

    cout << "Reorder Cost (Double: 4.5kg @ 12.50): "
         << reorderCost(4.5, 12.50) << endl;

    cout << "Reorder Cost (Taxed: 10 items @ 100.00 + 5% tax): "
         << reorderCost(10, 100.00, 0.05) << endl;


    cout << "Discounted Price (Default 10% on 250.0): "
         << applyDiscount(250.0) << endl;

    cout << "Discounted Price (Custom 20% on 250.0): "
         << applyDiscount(250.0, 20.0) << endl;

    return 0;
}

