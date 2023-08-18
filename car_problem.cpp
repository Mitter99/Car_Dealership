#include "cardetails.h"

int main() 
{
    setup_map();
    while(1)
    {
        reset();
        print_menu_car_price();
        get_car_model();
        print_menu_extra_price();
        get_insurance();
        get_accessories();
        get_dealerDiscount();
        print_finalPrice();
        
    }
   
    return 0;
}


