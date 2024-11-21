#ifndef PHARMACY_H
#define PHARMACY_H

struct pharmacy
{
    int medicine_id;
    char medicine_name[100];
    float medicine_cost;
    int medicine_stock_quantity;
    char medicine_type[20];// tablet/injection
    float medicine_dosage;
};

int verify_pharmacy_user();
void add_medicine();
void update_medicine_details();
void display_medicine_details();
void search_by_medicine_id();
void search_by_medicine_name();
void check_stock();
//file handling
void save_medicine_data();
int load_medicine_data();

#endif // PHARMACY_H
