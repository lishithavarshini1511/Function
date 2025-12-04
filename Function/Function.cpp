#i#include <iostream>
using namespace std;

float getPrice(int RoomType);
float calculateDiscount(float Subtotal, int NumOfNights);
void computeAmounts(float PricePerNight, int NumOfNights, float& Subtotal, float& Discount);
float applyPromo(char PromoCode);
void displaySummary(float PricePerNight, int NumOfNights, float Subtotal, float Discount, float FinalTotal);
void displayMessage();

int main()
{
    int RoomType, NumOfNights;
    char PromoCode;

    cout << "__________________________________________________________\n";
    cout << "----------------------------------------------------------\n";
    cout << "            FTMK GRAND HOTEL BOOKING SYSTEM               \n";
    cout << "__________________________________________________________\n";
    cout << "----------------------------------------------------------\n";
    cout << "\t1. Standard Room - RM150.00 per night\n";
    cout << "\t2. Deluxe Room   - RM200.00 per night\n";
    cout << "\t3. Suite Room    - RM300.00 per night\n";
    cout << "__________________________________________________________\n";

    cout << "Enter room type (1-3): ";
    cin >> RoomType;

    cout << "Enter number of nights: ";
    cin >> NumOfNights;

    if (RoomType == 1)
        cout << "You selected Standard Room.\n";
    else if (RoomType == 2)
        cout << "You selected Deluxe Room.\n";
    else if (RoomType == 3)
        cout << "You selected Suite Room.\n";
    else
        cout << "Invalid room type selected.\n";

    cout << "Do you have a promo code? (Y/N): ";
    cin >> PromoCode;

    float PricePerNight, Subtotal, Discount, FinalTotal;

    PricePerNight = getPrice(RoomType);

    computeAmounts(PricePerNight, NumOfNights, Subtotal, Discount);

    Discount += applyPromo(PromoCode);

    FinalTotal = Subtotal - Discount;

    displaySummary(PricePerNight, NumOfNights, Subtotal, Discount, FinalTotal);

    displayMessage();

    return 0;
}

float getPrice(int RoomType)
{
    if (RoomType == 1) return 150.00;
    else if (RoomType == 2) return 200.00;
    else if (RoomType == 3) return 300.00;
    return 0;
}

float calculateDiscount(float Subtotal, int NumOfNights)
{
    if (NumOfNights >= 5)
        return Subtotal * 0.10;
    else
        return Subtotal * 0.05;
}

void computeAmounts(float PricePerNight, int NumOfNights, float& Subtotal, float& Discount)
{
    Subtotal = PricePerNight * NumOfNights;
    Discount = calculateDiscount(Subtotal, NumOfNights);
}

float applyPromo(char PromoCode)
{
    if (PromoCode == 'Y' || PromoCode == 'y')
        return 50.0;
    return 0.0;
}

void displaySummary(float PricePerNight, int NumOfNights, float Subtotal, float Discount, float FinalTotal)
{
    cout << "\n------------------- BOOKING SUMMARY -------------------\n";
    cout << "Price per Night : RM " << PricePerNight << endl;
    cout << "Nights Stayed   : " << NumOfNights << endl;
    cout << "Subtotal        : RM " << Subtotal << endl;
    cout << "Total Discount  : RM " << Discount << endl;
    cout << "Final Total     : RM " << FinalTotal << endl;
    cout << "-------------------------------------------------------\n";
}

void displayMessage()
{
    cout << "-----------------------------------------------------\n";
    cout << "VIP CUSTOMER : You are eligible for free airport pickup!\n";
    cout << "-----------------------------------------------------\n";
}
