
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

char stars = '*';
char space = ' ';
char userInput;
int Qsmall, Qmedium, Qlarge;

const int costSmall = 175;
const int costMedium = 190;
const int costLarge = 200;


void ShowUsage();
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);

int main()
{
    std::cout << setw(90) << setfill(stars) << stars << endl;
    std::cout << setw(30) << setfill(stars) << stars << "Welcome to my Johnny Utah's PointBreak Surf Shop" << setw(12) << setfill(stars) << stars << endl;
    std::cout << setw(90) << setfill(stars) << stars << endl;
    std::cout << setw(90) << setfill(space) << space << endl;
    std::cout << setw(90) << setfill(space) << space << endl;

    ShowUsage();

    std::cout << setw(90) << setfill(space) << space << endl;

    std::cout << "Please enter selection: ";
    std::cin >> userInput;

    while (userInput != 'q' && userInput != 'Q')
    {
        switch (userInput)
        {
        case 'S':
        case 's':
            ShowUsage();


        case 'P':
        case 'p':
        {
            MakePurchase(Qsmall, Qmedium, Qlarge);
            std::cout << '\n';
        }


        case 'C':
        case 'c':
            if (Qsmall == 0 && Qmedium == 0 && Qlarge == 0)
            {
                std::cout << "No purchases made yet.";
                std::cout << setw(90) << setfill(space) << space << endl;

            }
            else
            {
                DisplayPurchase(Qsmall, Qmedium, Qlarge);
                std::cout << setw(90) << setfill(space) << space << endl;

            }

        case 'T':
        case 't':
            if (Qsmall == 0 && Qmedium == 0 && Qlarge == 0)
            {
                std::cout << "No purchases made yet." << endl;
                std::cout << setw(90) << setfill(space) << space << endl;

            }
            else
            {
                DisplayTotal(Qsmall, Qmedium, Qlarge);
                std::cout << setw(90) << setfill(space) << space << endl;

            }

        }

        std::cout << "Please enter selection: ";
        std::cin >> userInput;


    }
    std::cout << "Thank you" << endl;
    std::cout << setw(90) << setfill(space) << space << endl;

    return 0;

}











void ShowUsage()
{
    std::cout << "To show program usage 'S' " << endl;
    std::cout << "To purchase a surfboard press 'P' " << endl;
    std::cout << "To display current purchases press 'C' " << endl;
    std::cout << "To display total amount due press 'T' " << endl;
    std::cout << "To quit the program press 'Q' " << endl;
}

void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
    iTotalSmall = 0;
    iTotalMedium = 0;
    iTotalLarge = 0;
    static char purchaseType;
    int Qsize = 0;

    std::cout << "Please enter the quantity and type of the surfboard you would like to purchase: ";
    std::cin >> Qsize;
    std::cin >> purchaseType;
    std::cout << setw(90) << setfill(space) << space << endl;




    switch (purchaseType)
    {
    case 's':
        iTotalSmall = iTotalSmall + Qsize;


    case 'm':
        iTotalMedium = iTotalMedium + Qsize;


    case 'l':
        iTotalLarge = iTotalLarge + Qsize;

    }


}

void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
    if (tolower(userInput) == 'c')
    {
        if (iTotalSmall >= 1)
        {
            std::cout << "Total Small surfs sold: " << iTotalSmall << endl;
            std::cout << setw(90) << setfill(space) << space << endl;

        }
        else if (iTotalMedium >= 1)
        {
            std::cout << "Total Medium surfs sold: " << iTotalMedium << endl;
            std::cout << setw(90) << setfill(space) << space << endl;

        }

        else if (iTotalLarge >= 1)
        {
            std::cout << "Total Large surfs sold: " << iTotalLarge << endl;
            std::cout << setw(90) << setfill(space) << space << endl;

        }
    }
}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{

    double totalCostSmall = 0;
    double totalCostMedium = 0;
    double totalCostLarge = 0;
    double totalCost = 0;

    if (tolower(userInput) == 't')
    {
        if (iTotalSmall >= 1)
        {
            totalCostSmall = iTotalSmall * costSmall;
            std::cout << "Total number of small surfboard is " << iTotalSmall << " at a total of: " << totalCostSmall << endl;

            totalCost = totalCost + totalCostSmall;


        }

        else if (iTotalMedium >= 1)
        {
            totalCostMedium = iTotalMedium * costMedium;
            std::cout << "Total number of medium surfboard is " << iTotalMedium << " at a total of : " << totalCostMedium << endl;

            totalCost = totalCost + totalCostMedium;
        }

        else if (iTotalLarge >= 1)
        {
            totalCostLarge = iTotalLarge * costLarge;
            std::cout << "Total number of large surfboard is " << iTotalLarge << " at a total of: " << totalCostLarge << endl;
            totalCost = totalCost + totalCostLarge;

        }

        std::cout << "Your total amount due is " << totalCost << endl;
        std::cout << setw(90) << setfill(space) << space << endl;
    }


}

