#include <iostream>
#include <iomanip>

using namespace std;
char stars = '*';
char space = ' ';
char userInput;
int iTotalsmall;
int iTotalmedium;
int iTotallarge;
int iTotalextrasmall;


//Constant Variables for the cost of each size surfboards
const double costSmall = 175.00;
const double costMedium = 190.00;
const double costLarge = 200.00;
const double costExtraSmall = 20000.00;

//Functions used in this program
void ShowUsage(); //Shows how to use the program
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalExtraSmall); //Asks user the typeand amount of surfboards they want to purchase
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int& iTotalExtraSmall); //Shows the number and type of surfboard the user chose
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int& iTotalExtraSmall); //Shows the total price of buying the sufboards
int main()
{
    //Welcome Message:
    std::cout << setw(90) << setfill(stars) << stars << endl;
    std::cout << setw(30) << setfill(stars) << stars << "Welcome to my Johnny Utah's PointBreak Surf Shop" << setw(12) << setfill(stars) << stars << endl;
    std::cout << setw(90) << setfill(stars) << stars << endl;
    std::cout << setw(90) << setfill(space) << space << endl;
    std::cout << setw(90) << setfill(space) << space << endl;

    std::cout << fixed << setprecision(2); //Sets the costs to two decimal points

    ShowUsage(); //Shows the user how to use the program
    std::cout << setw(90) << setfill(space) << space << endl;

    std::cout << "Please enter selection: "; //Asks the user to select a choice
    std::cin >> userInput; //Takes the input

    while (userInput != 'q' && userInput != 'Q') //Code will stop when the user presses 'q'
    {
        switch (userInput)
        {
        case 'S':  //If the user chooses 's', it will shows the instruction set of using thee program
        case 's':
            ShowUsage();

        case 'P': //If the user chooses 'p' then it'll ask what type and amount of surfboard the user wants
        case 'p':
            {
                MakePurchase(iTotalsmall, iTotalmedium, iTotallarge, iTotalextrasmall);
                std::cout << '\n';
            }
        case 'C':
        case 'c': //If the user inputs 'c' then it'll show the amount of surfboards the user wanted to buy
                if (iTotalsmall == 0 && iTotalmedium == 0 && iTotallarge == 0 && iTotalextrasmall == 0) //If the user didn't make a choice yet and pressed 'c' then it'll say the following phrase
                {
                    std::cout << "No purchases made yet.";
                    std::cout << setw(90) << setfill(space) << space << endl;
                }
                else
                {
                    DisplayPurchase(iTotalsmall, iTotalmedium, iTotallarge, iTotalextrasmall);
                    std::cout << setw(90) << setfill(space) << space << endl;
                }
            //When the user chooses 't'..
        case 'T':
        case 't':
            if (iTotalsmall == 0 && iTotalmedium == 0 && iTotallarge == 0 && iTotalextrasmall == 0) //If the user didn't choose any surfboard to buy then it won't show any total cost
            {
                std::cout << "No purchases made yet." << endl;
                std::cout << setw(90) << setfill(space) << space << endl;
            }
            else
            {
                DisplayTotal(iTotalsmall, iTotalmedium, iTotallarge, iTotalextrasmall);
                std::cout << setw(90) << setfill(space) << space << endl;
            }
        }
        std::cout << "Please enter selection: "; //After taking the first input and giving the outputs, it'll ask the user to enter a choice again
        std::cin >> userInput;

    }
    std::cout << "Thank you" << endl;
    std::cout << setw(90) << setfill(space) << space << endl;
    return 0;
}
void ShowUsage()  //Shows how to use the program
{
    std::cout << "To show program usage 'S' " << endl;
    std::cout << "To purchase a surfboard press 'P' " << endl;
    std::cout << "To display current purchases press 'C' " << endl;
    std::cout << "To display total amount due press 'T' " << endl;
    std::cout << "To quit the program press 'Q' " << endl;
}
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalExtraSmall) //Asks the user to enter a choice
{

    static char purchaseType; //Takes input on the size
    int Qsize = 0; //Takes input on the amount

    std::cout << "Please enter the quantity and type (S = small, M = medium, L = large, XXXS = Extra Small) of surfboard you would like to purchase : ";
    std::cin >> Qsize;
    std::cin >> purchaseType;

    std::cout << setw(90) << setfill(space) << space << endl;


    if (tolower(purchaseType) == 's') //When the user chooses a small surfboard..
        iTotalSmall = iTotalSmall + Qsize;  //Adds the value to the variable 'iTotalSmall' based on the user input

    if (tolower(purchaseType) == 'm')  //When the user chooses a medium surfboard..
            iTotalMedium = iTotalMedium + Qsize;  //Adds the value to the variable 'iTotalMedium' based on the user input

    if (tolower(purchaseType) == 'l')  //When the user chooses a large surfboard..
            iTotalLarge = iTotalLarge + Qsize; //Adds the value to the variable 'iTotalLarge' based on the user input

    if (tolower(purchaseType) == 'xxxs') //When the user chooses a extra small surfboard..
            iTotalExtraSmall = iTotalExtraSmall * Qsize; //Adds the value to the variable 'iTotalExtraSmall' based on the user input

}
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int& iTotalExtraSmall) //Shows how many surfboards the user chose to buy upon pressing 'c'
{
    if (tolower(userInput) == 'c') //This code will work only if the user chooses a small surfboard that is at least 1 or more.
    {
        if (iTotalSmall >= 1)  
        {
            std::cout << "Total number of small surfboard is " << iTotalSmall;
            std::cout << setw(90) << setfill(space) << space << endl;
        }
        if (iTotalMedium >= 1) //This code will work only if the user chooses a medium surfboard that is at least 1 or more.
        {
            std::cout << "Total number of medium surfboard is " << iTotalMedium;
            std::cout << setw(90) << setfill(space) << space << endl;
        }
        if (iTotalLarge >= 1)     //This code will work only if the user chooses a large surfboard that is at least 1 or more.
        {
            std::cout << "Total number of large surfboard is " << iTotalLarge;
            std::cout << setw(90) << setfill(space) << space << endl;
        }
        if (iTotalExtraSmall >= 1) //This code will work only if the user chooses a extra large surfboard that is at least 1 or more.
        {
            std::cout << "Total number of extra small surfboard is " << iTotalExtraSmall;
            std::cout << setw(90) << setfill(space) << space << endl;
        }
    }


}
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int& iTotalExtraSmall) //Shows the total cost of buying the surfboards
{
    //Varibles for calculating the total cost of buying each size sufboards
    double totalCostSmall = 0.00;
    double totalCostMedium = 0.00;
    double totalCostLarge = 0.00;
    double totalCostExtraSmall = 0.00;

    double totalCost = 0.00; //Combines the cost of all sizes and displays the final price.


        if (tolower(userInput) == 't') //This code will work only when the user presses 't' in the showUsage() part
        {
            if (iTotalSmall >= 1)  //This part of the code will wrok when there is more than 1 small surfboards chosen.
            {
                totalCostSmall = iTotalSmall * costSmall; // Multiplies 175.00 with the qantity chosen at the makePurchase() part
                std::cout << "The total number of small surfboard is " << iTotalSmall << " at a total of $ " << double(totalCostSmall) << endl;
                totalCost = totalCost + totalCostSmall;  //Adds the value to the variable totalCost
            }
            if (iTotalMedium >= 1)  //This part of the code will wrok when there is  more than 1 medium surfboards chosen.
            {
                totalCostMedium = iTotalMedium * costMedium;  //Multiplies 190.00 with the qantity chosen at the makePurchase() part
                std::cout << "The total number of medium surfboard is " << iTotalMedium << " at a total of $ " << double(totalCostMedium) << endl;
                totalCost = totalCost + totalCostMedium; //Adds the value to the variable totalCost
            }
            if (iTotalLarge >= 1)  //This part of the code will wrok when there is more than 1 large surfboards chosen.
            {
                totalCostLarge = iTotalLarge * costLarge;  //Multiplies 200.00 with the qantity chosen at the makePurchase() part
                std::cout << "The total number of large surfboard is " << iTotalLarge << " at a total of $ " << double(totalCostLarge) << endl;
                totalCost = totalCost + totalCostLarge;  //Adds the value to the variable totalCost
            }
            if (iTotalExtraSmall >= 1)
            {
                totalCostExtraSmall = iTotalExtraSmall * costExtraSmall;
                std::cout << "The total number of extra small surfboard is " << iTotalExtraSmall << " at a cost of $ " << double(totalCostExtraSmall) << endl;
                totalCost = totalCost + totalCostExtraSmall;
            }
            std::cout << "Amount due: " << double(totalCost) << endl; //Shows the total of buying all surboards combined
            std::cout << setw(90) << setfill(space) << space << endl;
        }
}