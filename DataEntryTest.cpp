/*
CSIS1600
DataEntryTest.cpp
A06 - Data Entry Functions
*/

#include "C:\\CSIS1600\\MyCPPUtils\\dataChecks.cpp"
using namespace dataChecks;

void testValidInt();
void testValidDouble();

int main()
{
    char selection;
    do
    {
        system("cls");
        cout << "\n1. Test valid int\n2. Test valid double\n3. Exit\n\nSelection: ";
        cin >> selection;
        switch(selection)
        {
            case '1': testValidInt(); break;
            case '2': testValidDouble(); break;
            case '3': break;
            default:
                cout << "invalid choice..." << endl;
                system("pause");
        }
    }while(selection != '3');

    return 0;
}

void testValidInt()
{
    int i;
    char YN = 'Y';

    while(toupper(YN) == 'Y')
    {
        system("cls");
        cout << "\nEnter an integer value: ";
        i = getInt();
        cout << "\n" << i << " is a valid integer!" << endl;
        cout << "\nAgain (Y/N): ";
        cin >> YN;
    }
}

void testValidDouble()
{

    double d;
    char YN = 'Y';

    while(toupper(YN) == 'Y')
    {
        system("cls");
        cout << "\nEnter a double value: ";
        d = getDouble();
        cout << "\n" << d << " is a valid double!" << endl;
        cout << "\nAgain (Y/N): ";
        cin >> YN;
    }
}
