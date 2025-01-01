#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

const string clear_screen = "\033[2J\033[H"; // Clear Screen Linux
const int SIZE = 20;
string cart[SIZE];
string restraunt[SIZE];
int price[SIZE], cart_items = 0, discount = 0; 
float final_price = 0.0;
bool is_cod = false;
string OS = "LINUX"; // LINUX or WINDOWS

string coupons[5] = {"NUTECH90", "EID50", "FRIDAY10", "RAMADAN20", "RAMADAN40"}, couponCode;

struct restraunts {
    string deal[5];
    int price[5];
};

int menu(){
    int input;
    cout << "| TheFoodApp |" << endl << endl;

    cout << "1. Savour\n2. Cheezious\n3. Ranchers\n4. Burger Lab\n5. Crumble\n";
    if(cart_items != 0){
        cout << "6. Checkout\n0. Exit\n\n";
    } else {
        cout << "0. Exit\n\n" << endl;
    }
    
    cout << "Please choose a Restraunt: ";
    cin >> input;

    return input;
}

void add_to_cart(string item_name, string restraunt_name, int amount){
    int space_left = 0; // Use to find the space left in the Cart
    for(int i = 0; i < SIZE; ++i){
        if(cart[i] == ""){
            space_left += 1;
        }
    }

    cart[(SIZE - space_left)] = item_name;
    price[(SIZE - space_left)] = amount;
    restraunt[(SIZE - space_left)] = restraunt_name;
    cart_items += 1;
}

void checkout(){
    float total_price_of_items = 0.0, delivery_charges = 0;
    
    for(int i = 0; i < cart_items; ++i){
        cout << cart[i] << "\t\tRs " << price[i] << "\t\t" << restraunt[i] << endl;
        total_price_of_items += price[i];
    }

    if(cart_items <= 5){
        delivery_charges = 99.99;
    } else {
        delivery_charges = 149.99;
    }

    cout << endl << "Total Price: Rs " << total_price_of_items << endl;
    if(discount != 0){
        final_price = total_price_of_items + (float(total_price_of_items) * 0.05) - (float(total_price_of_items) * (float(discount)/100.0)) + delivery_charges;
        cout << "Tax: Rs " << float(total_price_of_items) * 0.05 << endl;
        cout << "Discount: Rs " << float(total_price_of_items) * (float(discount)/100.0) << " [" << couponCode << "]" << endl;
        cout << "Delivery Charges: Rs " << delivery_charges << endl;
        cout << "Total Payable Amount: Rs " << final_price << endl;
    } else {
        final_price = total_price_of_items + (float(total_price_of_items) * 0.05) + delivery_charges;
        cout << "Tax: Rs " << float(total_price_of_items) * 0.05 << endl;
        cout << "Delivery Charges: Rs " << delivery_charges << endl;
        cout << "Total Payable Amount: Rs " << final_price << endl;
    }
}

bool added_to_cart(){
    bool input;
    cout << "Item Successfully Added to Cart\n\n";
    cout << "0. Checkout\n1. Continue Shopping\n\n";
    cout << "Do You Want to Continue Shopping or Checkout: ";
    cin >> input;
    return input;
}

bool add_item_input(string deal_name){
    bool input;
    cout << deal_name << endl << endl;
    cout << "0. No\n1. Yes\n\nDo you want to add this item to Cart?: ";
    cin >> input;
    return input;
}

void time_wait(int seconds, string msg) {
    time_t start_time = time(NULL);
    while (seconds >= 0) {
        if(OS == "LINUX") cout << clear_screen; else system("cls");
        cout << msg << endl << endl << "Please Wait: " << seconds << " seconds" << endl;
        
        time_t current_time = time(NULL);
        while (difftime(current_time, start_time) < 1) {
            current_time = time(NULL);
        }

        start_time = current_time;
        --seconds;
    }
}

int string_to_int(const string& str) {
    int num = 0;
    for (int c = 0; c < str.length(); ++c) {
        if (str[c] < '0' || str[c] > '9') break;
        num = num * 10 + (str[c] - '0');
    }
    return num;
}

restraunts savour = {
    {"Deal 1 [Pulao + Kabab]", "Deal 2 [Pulao + Kabab + Chicken]", "Deal 3 [Pulao + Kabab + Chicken Choice]", "Deal 4 [1 Savour Krispo + 1 Chicken Piece + 1 Frech Fries + 1 Drink]", "Deal 5 [2 Savour Krispo + 2 Chicken Pieces + 2 Frech Fries + 2 Drinks]"},
    {330, 485, 650, 885, 1745}
};

restraunts cheezious = {
    {"Deal 1 [2 Bazinga, Regular Fries, 2 Regular Drinks]", "Deal 2 [2 Bazinga Burger, 2 pcs Chicken, Large Fries, 2 Regular Drink]", "Deal 3 [3 Bazinga Burger, Large Fries, 1 Liter Drink]", "Deal 4 [3 Bazinga Burger, 3 pcs Chicken, 1 Liter Drink]", "Deal 5 [3 Bazinga Burger, 1 Cheezious Special Pizza, 1 Liter Drink]"},
    {1250, 1750, 1850, 2150, 3350}
};

restraunts ranchers = {
    {"Deal 1 [4x Crunch Burgers + 1 Ltr Drink]", "Deal 2 [Any 2 Burgers & 2 Drinks]", "Deal 3 [2 Large Pan Pizza + 1.5 Ltr Drink]", "Deal 4 [8x Crunch Burgers + 1 Large Pizz + 2 Ltr Drink]", "Deal 5 [10x Crunch Burgers + 2 Large Pizzas + 1 Small Pizza]"},
    {999, 1399, 1999, 2899, 3999}
};

restraunts burger_lab = {
    {"Deal 1 [Dynamite & Softdrink]", "Deal 2 [OG Smash with Free Drink]", "Deal 3 [2 Zinger Burgers + 1 Fries]", "Deal 4 [4 Zinger Burgers + Large Fries + 1 Ltr Drink]", "Deal 5 [8 Zinger Burgers + 2 Large Fries + 2 Ltr Drink]"},
    {750, 850, 1390, 2990, 4499}
};

restraunts crumble = {
    {"Deal 1 [Classic Chocolate Chip]", "Deal 2 [Double Chocolate]", "Deal 3 [Chocolate Hazelnut Filled]", "Deal 4 [NYC Brownie]", "Deal 5 [Red Velvet]"},
    {1950, 1950, 1950, 1950, 1950}
};

int main(){
    int restraunt_input, deal_input, exit_app = false;
    bool control = true, extra_input;

    while(control){
        if(OS == "LINUX") cout << clear_screen; else system("cls");;
        restraunt_input = menu();
        
        switch(restraunt_input){
            // Case Savour
            case 1:
            if(OS == "LINUX") cout << clear_screen; else system("cls");
        
            cout << "[Savour]" << endl << endl;
            cout << "1. " << savour.deal[0] << " | Rs. " << savour.price[0] << "\n2. " << savour.deal[1] << " | Rs. " << savour.price[1] << "\n3. " << savour.deal[2] << " | Rs. " << savour.price[2] << "\n4. " << savour.deal[3] << " | Rs. " << savour.price[3] << "\n5. " << savour.deal[4] << " | Rs. " << savour.price[4] << endl << endl;
        
            cout << "Please choose a deal: ";
            cin >> deal_input;

            switch(deal_input){
                // Savour Deal 01
                case 1:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 1")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(savour.deal[0], "Savour", savour.price[0]);
                
                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
                
                // Savour Deal 02
                case 2:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 2")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(savour.deal[1], "Savour", savour.price[1]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Savour Deal 03
                case 3:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 3")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(savour.deal[2], "Savour", savour.price[2]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Savour Deal 04
                case 4:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 4")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(savour.deal[3], "Savour", savour.price[3]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Savour Deal 05
                case 5:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 5")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(savour.deal[4], "Savour", savour.price[4]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
            }
            break;

            // Case Cheezious
            case 2:
            if(OS == "LINUX") cout << clear_screen; else system("cls");
        
            cout << "[Cheezious]" << endl << endl;
            cout << "1. " << cheezious.deal[0] << " | Rs. " << cheezious.price[0] << "\n2. " << cheezious.deal[1] << " | Rs. " << cheezious.price[1] << "\n3. " << cheezious.deal[2] << " | Rs. " << cheezious.price[2] << "\n4. " << cheezious.deal[3] << " | Rs. " << cheezious.price[3] << "\n5. " << cheezious.deal[4] << " | Rs. " << cheezious.price[4] << endl << endl;
        
            cout << "Please choose a deal: ";
            cin >> deal_input;

            switch(deal_input){
                // Cheezious Deal 01
                case 1:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 1")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(cheezious.deal[0], "Cheezious", cheezious.price[0]);
                
                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
                
                // Cheezious Deal 02
                case 2:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 2")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(cheezious.deal[1], "Cheezious", cheezious.price[1]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Cheezious Deal 03
                case 3:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 3")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(cheezious.deal[2], "Cheezious", cheezious.price[2]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Cheezious Deal 04
                case 4:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 4")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(cheezious.deal[3], "Cheezious", cheezious.price[3]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Cheezious Deal 05
                case 5:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 5")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(cheezious.deal[4], "Cheezious", cheezious.price[4]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
            }
            break;

            // Case Ranchers
            case 3:
            if(OS == "LINUX") cout << clear_screen; else system("cls");
        
            cout << "[Ranchers]" << endl << endl;
            cout << "1. " << ranchers.deal[0] << " | Rs. " << ranchers.price[0] << "\n2. " << ranchers.deal[1] << " | Rs. " << ranchers.price[1] << "\n3. " << ranchers.deal[2] << " | Rs. " << ranchers.price[2] << "\n4. " << ranchers.deal[3] << " | Rs. " << ranchers.price[3] << "\n5. " << ranchers.deal[4] << " | Rs. " << ranchers.price[4] << endl << endl;
        
            cout << "Please choose a deal: ";
            cin >> deal_input;

            switch(deal_input){
                // Ranchers Deal 01
                case 1:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 1")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(ranchers.deal[0], "Ranchers", ranchers.price[0]);
                
                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
                
                // Ranchers Deal 02
                case 2:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 2")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(ranchers.deal[1], "Ranchers", ranchers.price[1]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Ranchers Deal 03
                case 3:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 3")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(ranchers.deal[2], "ranchers", ranchers.price[2]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Ranchers Deal 04
                case 4:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 4")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(ranchers.deal[3], "ranchers", ranchers.price[3]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Ranchers Deal 05
                case 5:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 5")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(ranchers.deal[4], "ranchers", ranchers.price[4]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
            }
            break;

            // Case Burger Lab
            case 4:
            if(OS == "LINUX") cout << clear_screen; else system("cls");
        
            cout << "[Burger Lab]" << endl << endl;
            cout << "1. " << burger_lab.deal[0] << " | Rs. " << burger_lab.price[0] << "\n2. " << burger_lab.deal[1] << " | Rs. " << burger_lab.price[1] << "\n3. " << burger_lab.deal[2] << " | Rs. " << burger_lab.price[2] << "\n4. " << burger_lab.deal[3] << " | Rs. " << burger_lab.price[3] << "\n5. " << burger_lab.deal[4] << " | Rs. " << burger_lab.price[4] << endl << endl;
        
            cout << "Please choose a deal: ";
            cin >> deal_input;

            switch(deal_input){
                // Burger Lab Deal 01
                case 1:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 1")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(burger_lab.deal[0], "Burger Lab", burger_lab.price[0]);
                
                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
                
                // Burger Lab Deal 02
                case 2:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 2")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(burger_lab.deal[1], "Burger Lab", burger_lab.price[1]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Burger Lab Deal 03
                case 3:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 3")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(burger_lab.deal[2], "Burger Lab", burger_lab.price[2]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Burger Lab Deal 04
                case 4:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 4")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(burger_lab.deal[3], "Burger Lab", burger_lab.price[3]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Burger Lab Deal 05
                case 5:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 5")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(burger_lab.deal[4], "Burger Lab", burger_lab.price[4]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
            }
            break;

            // Case Crumble
            case 5:
            if(OS == "LINUX") cout << clear_screen; else system("cls");
        
            cout << "[Crumble]" << endl << endl;
            cout << "1. " << crumble.deal[0] << " | Rs. " << crumble.price[0] << "\n2. " << crumble.deal[1] << " | Rs. " << crumble.price[1] << "\n3. " << crumble.deal[2] << " | Rs. " << crumble.price[2] << "\n4. " << crumble.deal[3] << " | Rs. " << crumble.price[3] << "\n5. " << crumble.deal[4] << " | Rs. " << crumble.price[4] << endl << endl;
        
            cout << "Please choose a deal: ";
            cin >> deal_input;

            switch(deal_input){
                // Burger Crumble 01
                case 1:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 1")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(crumble.deal[0], "Crumble", crumble.price[0]);
                
                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
                
                // Burger Crumble 02
                case 2:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 2")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(crumble.deal[1], "Crumble", crumble.price[1]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Burger Crumble 03
                case 3:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 3")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(crumble.deal[2], "Crumble", crumble.price[2]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Burger Crumble 04
                case 4:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 4")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(crumble.deal[3], "Crumble", crumble.price[3]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;

                // Burger Crumble 05
                case 5:
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                if(add_item_input("Deal 5")){
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                    add_to_cart(crumble.deal[4], "Crumble", crumble.price[4]);

                    if(!added_to_cart()){
                        control = false;
                    }
                }
                break;
            }
            break;

            // Case Checkout
            case 6:
            if(OS == "LINUX") cout << clear_screen; else system("cls");
            control = false;
            exit_app = false;
            break;

            // Case Exit
            case 0:
            if(OS == "LINUX") cout << clear_screen; else system("cls");
            control = false;
            exit_app = true;
            break;
        }
    }
    if(!exit_app){
        if(OS == "LINUX") cout << clear_screen; else system("cls");
        cout << cart_items << endl;

        if(cart_items != 0){
            checkout();
        
            cout << "\nDo You have a Coupon Code [0. No | 1. Yes]: ";
            cin >> extra_input;

                if(extra_input){
                    string coupon_code;
                    if(OS == "LINUX") cout << clear_screen; else system("cls");
                
                    cout << "Please Enter Your Coupon Code: ";
                    cin >> coupon_code;

                    for(int i = 0; i < (sizeof(coupons) / sizeof(coupons[0])); ++i){
                        if(coupon_code == coupons[i]){
                            string last_two_digits = coupons[i].substr(coupons[i].length() - 2, 2);
                            discount = string_to_int(last_two_digits);
                            couponCode = coupons[i];
                        }
                    }
                }
        
            if(discount != 0){
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                cout << "Coupon Code Successfully Applied\n\n";
                checkout();
            } else {
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                checkout();
            }
        } else {
            cout << "Your Cart is Empty\nThank you for using TheFoodApp";
        }

        if(OS == "LINUX") cout << clear_screen; else system("cls");
        cout << "0. Online\n1. Cash On Delivery\n\nPlease Select a Payment Method: ";
        cin >> extra_input;
    
        if(extra_input){
            final_price += (final_price * 0.03);
            is_cod = true;
        } else {
            if(OS == "LINUX") cout << clear_screen; else system("cls");
            string card_number;

            cout << "Enter Your 15 Digit Card Number: ";
            cin >> card_number;

            while(card_number.length() < 15){
                cout << "Invalid Card Number!!!\nPlease Try Again: ";
                cin >> card_number;
            }
            cout << "Your Payment Has Been Processed" ;
        }

        if(OS == "LINUX") cout << clear_screen; else system("cls");
        time_wait(20, "Your Food is being Ready");
        if(OS == "LINUX") cout << clear_screen; else system("cls");
        time_wait(5, "A Rider took your parcel");
        if(OS == "LINUX") cout << clear_screen; else system("cls");
        if(is_cod){
            string rider_coming = "Rider is Coming to Your Place. Plase take out Rs " + to_string(final_price);
            time_wait(10, rider_coming);

            if(OS == "LINUX") cout << clear_screen; else system("cls");
            time_t start_time = time(NULL);
            int seconds = 5;
            while (seconds >= 0) {
                cout << "Rider has reached your place. Please pay Rs " << final_price << " and Take your parcel" << endl << endl;
                if(OS == "LINUX") cout << clear_screen; else system("cls");
        
                time_t current_time = time(NULL);
                while (difftime(current_time, start_time) < 1) {
                    current_time = time(NULL);
                }

                start_time = current_time;
                --seconds;
            }
        } else {
            time_wait(10, "Rider is Coming to Your Place");
            if(OS == "LINUX") cout << clear_screen; else system("cls");
            time_t start_time = time(NULL);
            int seconds = 5;
            while (seconds >= 0) {
                if(OS == "LINUX") cout << clear_screen; else system("cls");
                cout << "Rider has reached your place. Please take your parcel" << endl << endl;
        
                time_t current_time = time(NULL);
                while (difftime(current_time, start_time) < 1) {
                    current_time = time(NULL);
                }

                start_time = current_time;
                --seconds;
            }
        }
        if(OS == "LINUX") cout << clear_screen; else system("cls");
        cout << "Parcel Delivered Successfully.\nThank You for Using TheFoodApp";
    
        cout << endl << endl;
    } else {
        if(OS == "LINUX") cout << clear_screen; else system("cls");
        cout << "Thank You for Using TheFoodApp" << endl;
    }
}