#ifndef CAR_DETAILS_H
#define CAR_DETAILS_H

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cassert>
using namespace std;

#define assertm(exp, msg) assert(((void)msg, exp))
#define MAX_DISCOUNT 30000

enum vehicle_model
{
    POLO_TRENDLINE = 0,
    POLO_HIGHLINE,
    VIRTUS_TRENDLINE,
    VIRTUS_HIGHLINE,
    TAIGUN_TRENDLINE,
    TAIGUN_HIGLINE,
    TAIGUN_TOPLINE,
    RESERVED
};

vehicle_model car_model_enum;
map<vehicle_model,double> vehicle_db;

const int Rto  = 113990;
const int Ins  =  47300;
const int Tcs  =  11000;
const int Acc  =  15000;

string       car_model;
bool         insurance_opt                = false;
bool         accs_opt                     = false;
double       dealer_discount_rs           = 0;
int          dealer_discount_per          = 0;
int          final_price                  = 0;

//Final discount
double       discounted_rs                = 0;

//Function prototyping
void setup_map();
void reset();
void convert_car_model_to_enum();
void print_menu_car_price();
void print_menu_extra_price();
void get_car_model();
void get_insurance();
void get_accessories();
string remove_punc(string resp);
void get_dealerDiscount();
void print_finalPrice();


//Initializing car models price
void setup_map()
{
    vehicle_db[POLO_TRENDLINE]   =  870000;
    vehicle_db[POLO_HIGHLINE]    = 1090000;
    vehicle_db[VIRTUS_TRENDLINE] = 1105000;
    vehicle_db[VIRTUS_HIGHLINE]  = 1308000;
    vehicle_db[TAIGUN_TRENDLINE] = 1489000;
    vehicle_db[TAIGUN_HIGLINE]   = 1542000;
    vehicle_db[TAIGUN_TOPLINE]   = 1771000;
}

// Function to reset values
void reset()
{
    insurance_opt           = false;
    accs_opt                = false;
    dealer_discount_rs      = 0;
    dealer_discount_per     = 0;
    discounted_rs           = 0;
    final_price             = 0;
    car_model_enum          = RESERVED;
}

//Function to convert number to Indian currency foramt
string ind_for(int num)
{
    string its = to_string(num);
    string csi;
    int count = 0;

    for(int i= its.size() - 1; i >= 0 ; i--)
    {
        if(count == 3)
        {
            csi = ',' + csi;
        }
        else if(count != 1 && count%2 == 1)
        {
            csi = ',' + csi;
        }
        csi = its[i] + csi;
        count++;
    }
    return csi;
}

//Function to convert input name to corresponding enum value
void convert_car_model_to_enum()
{
    if(car_model == "Polo Trendline" || car_model == "polo trendline" || car_model == "Polo trendline")
    {
        car_model_enum = POLO_TRENDLINE;
    }
    else if(car_model == "Polo Highline" || car_model == "polo highline" || car_model == "Polo highline")
    {
        car_model_enum = POLO_HIGHLINE;
    }
    else if(car_model == "Virtus Trendline" || car_model == "virtus trendline" || car_model == "Virtus trendline")
    {
        car_model_enum = VIRTUS_TRENDLINE;
    }
    else if(car_model == "Virtus Highline" || car_model == "virtus highline" || car_model == "Virtus highline")
    {
        car_model_enum = VIRTUS_HIGHLINE;
    }
    else if(car_model == "Taigun Trendline" || car_model == "taigun trendline" || car_model == "Taigun trendline")
    {
        car_model_enum = TAIGUN_TRENDLINE;
    }
    else if(car_model == "Taigun Highline" || car_model == "taigun highline" || car_model == "Taigun highline")
    {
        car_model_enum = TAIGUN_HIGLINE;
    }
    else if(car_model == "Taigun Topline" || car_model == "taigun topline" || car_model == "Taigun topline")
    {
        car_model_enum = TAIGUN_TOPLINE;
    }
    else
    {
        car_model_enum = RESERVED;
        printf("Please choose car model from above list: \n"); // Unexpected input
        get_car_model();
    }
}

// Function to print Car price table
void print_menu_car_price()
{
    printf("     CAR MODEL WITH EX-SHOWROOM PRICE        \n");
    printf("---------------------------------------------\n");
    printf(" |%-20s| %-20s|\n", "Car Model", "Cost(Showroom Price)");
    printf("---------------------------------------------\n");
    printf(" |%-20s| %-20s|\n", "Polo Trendline", "8.70 lakh");
    printf(" |%-20s| %-20s|\n", "Polo Highline", "10.09 lakh");
    printf(" |%-20s| %-20s|\n", "Virtus Trendline", "11.05 lakh");
    printf(" |%-20s| %-20s|\n", "Virtus Highline", "13.08 lakh");
    printf(" |%-20s| %-20s|\n", "Taigun Trendline", "14.89 lakh");
    printf(" |%-20s| %-20s|\n", "Taigun Highline", "15.42 lakh");
    printf(" |%-20s| %-20s|\n", "Taigun Topline", "17.71 lakh");
    printf("---------------------------------------------\n \n \n");

}

//Function to print Insurance, Accessories, RTO, TCS cost
void print_menu_extra_price()
{
    printf("                     EXTRAS                       \n");
    printf("--------------------------------------------------\n");
    printf(" |%-25s| %-20s|\n", "Fee Type", "Cost");
    printf("--------------------------------------------------\n");
    printf(" |%-25s| %-20s|\n", "RTO", "1,13,990");
    printf(" |%-25s| %-20s|\n", "Insurance", "47,300");
    printf(" |%-25s| %-20s|\n", "TCS charges", "11,000");
    printf(" |%-25s| %-20s|\n", "Additional Accessories", "15,000");
    printf("--------------------------------------------------\n \n \n");

}

//Function to get car model input
void get_car_model()
{
    printf("Select car model: ");
    getline(cin,car_model);
    printf("\n");
    convert_car_model_to_enum();
}

//Function to check buying insurance status
void get_insurance()
{
    string resp;
    printf("Do you need insurace: ");
    cin >> resp;
    if(resp == "Yes" || resp == "YES" || resp == "yes" || resp == "y" || resp == "Y")
    {
        insurance_opt = true;
    }
    else if (resp == "No" || resp == "NO" || resp == "no" || resp == "n" || resp == "N")
    {
        insurance_opt = false;
    }
    else
    {
        printf("Input Valid: [Yes/No] \n");
        //recursively call same until correct response come
        get_insurance();
    }
    printf("\n");
}

//Function to check buying accessories status
void get_accessories()
{
    string resp;
    printf("Do you need Additional Accessories: ");
    cin >> resp;
    if(resp == "Yes" || resp == "YES" || resp == "yes" || resp == "y" || resp == "Y")
    {
        accs_opt = true;
    }
    else if (resp == "No" || resp == "NO" || resp == "no" || resp == "n" || resp == "N")
    {
        accs_opt = false;
    }
    else
    {
        printf("Input Valid: [Yes/No] \n");
        //recursively call same until correct response come
        get_accessories();
    }
    printf("\n");
}

// Function to remove punctual from string
string remove_punc(string resp)
{
    for (int i = 0, len = resp.size(); i < len; i++)
    {
        if (ispunct(resp[i]))
        {
            resp.erase(i--, 1);
            len = resp.size();
        }
    }
    return resp;
}

//Function to calculate the discount
void get_dealerDiscount()
{
    string resp;
    if(accs_opt == true || insurance_opt == true)
    {
        double discount;
        cout <<"Dealer Discount: ";
        cin >> resp;
        if(resp[resp.length()-1] == '%')
        {
            dealer_discount_per = stoi(remove_punc(resp));
            discount            = vehicle_db[car_model_enum] * ((double)dealer_discount_per/100);
            while(discount > MAX_DISCOUNT)
            {
                printf("Maximum discount can't be > Rs. 30000, provide discount < Rs. 30000: ");
                cin >> resp;
                if(resp[resp.length()-1] == '%')
                {
                    dealer_discount_per = stoi(remove_punc(resp));
                    discount            = vehicle_db[car_model_enum] * ((double)dealer_discount_per/100);
                }
                else
                {
                    discount = stoi(remove_punc(resp));
                }
            }
            discounted_rs = discount;
        }
        else
        {
            dealer_discount_rs = stoi(remove_punc(resp));
            while(dealer_discount_rs > MAX_DISCOUNT)
            {
                printf("Maximum discount can't be > Rs. 30000, provide discount < Rs. 30000: ");
                cin >> resp;

                if(resp[resp.length()-1] == '%')
                {
                    dealer_discount_per = stoi(remove_punc(resp));
                    discount            = vehicle_db[car_model_enum] * ((double)dealer_discount_per/100);
                    dealer_discount_rs   = discount;
                }
                else
                {
                    dealer_discount_rs = stoi(remove_punc(resp));
                }

            }
            discounted_rs = dealer_discount_rs;
        }
    }
    else
    {
        cout <<"Dealer Discount: ";
        cin >> resp;

        dealer_discount_rs = stoi(remove_punc(resp));

        while(dealer_discount_rs > 0)
        {
            printf("Any one of the additional features have to be added and 0 discount has to be added. \n");
            cout << "Dealer Discount: ";
            cin >> resp;
            dealer_discount_rs = stoi(remove_punc(resp));
        }
        discounted_rs = 0;
    }
    printf("\n");
}

//Function to print the final price
void print_finalPrice()
{
    final_price = 0;
    final_price =  vehicle_db[car_model_enum] + Rto + Tcs;
    final_price =  final_price + (insurance_opt ? Ins : 0);
    final_price =  final_price  + (accs_opt ? Acc : 0);
    final_price =  final_price  - discounted_rs;

    //We can print the price with comma separator but need to implement the logic
    cout<<setprecision(2)<<fixed<<"Total Cost: "<<ind_for(final_price)<<"("<<car_model<<": "<<ind_for(vehicle_db[car_model_enum])
        <<" + "<<ind_for(Rto)<<"(RTO)"<<" + "<<ind_for(Tcs)<<"(TCS)"<<" + "<<ind_for(Acc)<<"(Additional Accessories)"<<" - "<<ind_for(discounted_rs)
        <<"(Dealer Discount)"<<endl<<endl<<endl;

    cin.get();
}

#endif
