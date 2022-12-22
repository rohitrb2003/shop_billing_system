#include <iostream>
#include <process.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
class head
{
    char Iname[50][50];

public:
    int totalitems;
    float Qty[3];
    float price[3];
    int vatprice[3];
    int tprice[3];
    void input();
    void output();
};
class vat : public head
{
    float vats;

public:
    void vatcal();
    void outputs();
    void sum();
};
//      INPUT FUNCTION
void head::input()
{

    system("CLS");
    cout << "Price:";
    cout << "\t   1) Veg Kolhapuri : 210\n";
    cout << "\t   2) Jeera Rice : 170\n";
    cout << "\t   3) Veg Hyderabadi Biryani : 210\n";
    cout << "\t   4) Butter Roti : 30\n";
    cout << "\t   5) Punjabi Rice Thali : 250 ( 2 Roti+1 Sukha Bhaji+1 Paneer Bhaji+1 Jeera Rice+1 Papad+1 Curd/1 Raita )\n";
    cout << "\t   6) Tomato Soup : 130\n";
    cout << "\t   7) Palak Soup : 140\n";
    cout << "\t   8) Veg Clear Soup : 135\n";
    cout << "\t   9) Paneer Paratha : 105\n";
    cout << "\t   10) Dal Khichdi : 200\n";
    cout << "\nEnter number of items= ";
    cin >> totalitems;

    for (int i = 0; i < totalitems; i++)
    {
        cout << "\nEnter name of item " << i + 1 << ": ";
        cin >> Iname[i];
        cout << "Enter quantity: ";
        cin >> Qty[i];
        cout << "Enter price of item " << i + 1 << ": ";
        cin >> price[i];
        tprice[i] = Qty[i] * price[i];
    }
}
//     OUTPUT FUNCTION
void head::output()
{
    int a;

    ifstream infile("COUNT.TXT");
    infile >> a;

    ofstream outfile("COUNT.TXT");
    a += 1;
    outfile << a;
    outfile.close();

    {
        ofstream outfile("HIS.TXT", ios::app);
        outfile << endl
                << "Bill No.: " << a << endl;
        outfile << "------------------------------------------------------------------------" << endl;
        cout << "\n";
        cout << "Name of Item\tQuantity   Price  Total Price\n";
        for (int i = 0; i < totalitems; i++)
        {
            outfile << "Name: " << Iname[i] << " Qty: " << Qty[i] << " Price: " << tprice[i] << endl;
            cout << Iname[i] << "\t\t" << Qty[i] << "\t   " << price[i] << "\t   " << tprice[i] << '\n';
        }

        outfile << "------------------------------------------------------------------------" << endl;
        outfile.close();
    }
}
//     VAT CALCULATION
void vat::vatcal()
{
    input();
    for (int i = 0; i < totalitems; i++)
    {
        if (price[i] <= 100.00)
        {
            vatprice[i] = tprice[i] + (0.03 * tprice[i]);
        }
        else
        {
            vatprice[i] = tprice[i] + (0.1 * tprice[i]);
        }
    }
}
//      VAT OUTPUTS
void vat::outputs()
{
    output();

    float cash = 0, sum = 0, qty = 0, sumt = 0;

    for (int i = 0; i < totalitems; i++)
    {
        sumt += tprice[i];
        sum += vatprice[i];
        qty += Qty[i];
    }
    cout << "\nTotal:";
    cout << "\n------------------------------------------------------------------------------";
    cout << "\n\tQuantity= " << qty << "\t\t Sum= " << sumt << "\tWith Vat:" << sum;
    cout << "\n------------------------------------------------------------------------------";

pay:

    cout << "\n\n\t\t\t * * * * PAYMENT SUMMARY * * * * \n";
    cout << "\n\t\t\tTotal cash given: ";
    cin >> cash;

    if (cash >= sum)
        cout << "\n\t\t\tTotal cash repaid: " << cash - sum << '\n';

    else
    {
        cout << "\n\t\t\tCash given is less than total amount!!!";

        goto pay;
    }
}

//      PROTECTION PASSWORD

int passwords()
{

    char p1, p2, p3;
    cout << "\n\t\t\t\t\t\t\t<<<-----Welcome To Friend's Cafe----->>>";
    cout << "\n\n\t\t\t\t\t\t\t\tENTER THE PASSWORD: ";

    cin >> p1;
    cout << "*";
    cin >> p2;
    cout << "*";
    cin >> p3;
    cout << "*";

    if ((p1 == 's' || p1 == 'S') && (p2 == 'i' || p2 == 'I') && (p3 == 'd' || p3 == 'D'))

        return 1;

    else
        return 0;
}
// END of Password.
//      THE MAIN FUNCTION OF PROGRAM
int main()
{
    vat obj;
    char opt, ch;
    int a = 1;
    ifstream fin;

    a == passwords();
    if (!a)
    {
        for (int i = 1; i < 5; i++)
        {
            cout << "\nWrong password try once more\n";
            if (passwords())
            {
                goto last;
            }
            else
            {
                cout << "\n\n\t\t\t all attempts failed.....";
                cout << "\n\n\n\t\t\t see you.................. ";
                exit(0);
            }
        }
        cout << "\t\t\t sorry all attempts failed............. \n \t\t\tinactive";
    }
    else
    {
    last:;
        do
        {
        start:
            system("PAUSE");
            system("CLS");
            cout << "Menu Card / Items:\n";
            cout << "\t          1) Veg Kolhapuri : 210\n";
            cout << "\t          2) Jeera Rice : 170\n";
            cout << "\t          3) Veg Hyderabadi Biryani : 210\n";
            cout << "\t          4) Butter Rotimerchant : 30\n";
            cout << "\t          5) Punjabi Rice Thali : 250 ( 2 Roti+1 Sukha Bhaji+1 Paneer Bhaji+1 Jeera Rice+1 Papad+1 Curd/1 Raita )\n";
            cout << "\t          6) Tomato Soup : 130\n";
            cout << "\t          7) Palak Soup : 140\n";
            cout << "\t          8) Veg Clear Soup : 135\n";
            cout << "\t          9) Paneer Paratha : 105\n";
            cout << "\t          10) Dal Khichdi : 200\n";
            cout << "\n\t\t\t\t\t\t\t---------------------------";
            cout << "\n\t\t\t\t\t\t\t Billing Management System";
            cout << "\n\t\t\t\t\t\t\t---------------------------";
            cout << "\n\t\t\t\t\t\t\t   What you want to do?\n";
            cout << "\n\t\t\t\t\t\t\t1.\tTo enter new entry\n\t\t\t\t\t\t\t2.\tTo view previous entries\n\t\t\t\t\t\t\t3.\tExit\n";
            cout << "\n\nEnter your option: ";
            cin >> opt;
            switch (opt)
            {
            case '1':
                obj.vatcal();

                obj.outputs();
                goto start;
            case '2':

                fin.open("HIS.TXT", ios::in);
                while (fin.get(ch))
                {
                    cout << ch;
                }
                fin.close();

                goto start;
            case '3':
                exit(0);
            default:
                cout << "\a";
            }

        } while (opt != 3);
    }
    return 0;
}