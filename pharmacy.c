#include"pharmacy.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define USER_ID "pharmacist"
#define USER_PASSWORD "pharmacy@123"
#define MAX_MEDICINES 3000

int verify_pharmacy_user()
{
    char user_id[15];
    char user_pass[15];
    int option;
    int choice;
    struct pharmacy medicines[MAX_MEDICINES];
    int total_medicines = load_medicine_data(medicines);
    printf("Enter User Id:\n");
    scanf("%s",&user_id);
    printf("Enter User Password:\n");
    scanf("%s",&user_pass);

    if (strcmp(user_id, USER_ID) == 0 && strcmp(user_pass, USER_PASSWORD) == 0)
    {
        while(1)
        {
            printf("Enter The Option:\n");
            printf("1.Add medicine\n2.Update Medicine\n3.Display Medicine\n4.Search by Id\n5.Search by Name\n6.Check Stock\n7.Save data and exit\n");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                if(total_medicines < MAX_MEDICINES)
                {
                    add_medicine(&medicines[total_medicines++]);
                }
                else
                {
                    printf("limit reached\n");
                }
                break;
            case 2:
                if(total_medicines >0)
                {
                    int medicine_id;;
                    printf("enter medicine id to update:\n");
                    scanf("%d",&medicine_id);
                    int medicine_found =0;
                    for(int medicine_index = 0; medicine_index <total_medicines; medicine_index++)
                    {
                        if(medicines[medicine_index].medicine_id == medicine_id)
                        {
                            update_medicine_details(&medicines[medicine_index]);
                            medicine_found = 1;
                            break;
                        }
                    }
                    if(!medicine_found)
                    {
                        printf("medicine id not found.\n");
                    }
                }
                else
                {
                    printf("no medicines found");
                }
                break;
            case 3:
                display_medicine_details(medicines,total_medicines);
                break;
            case 4:
                search_by_medicine_id(medicines,total_medicines);
                break;
            case 5:
                search_by_medicine_name(medicines,total_medicines);
                break;
            case 6:
                check_stock(medicines,total_medicines);
                break;
            case 7:
                save_medicine_data(medicines,total_medicines);
                printf("Saved medicine Data and exiting\n");
                return 0;
                break;
            default:
                printf("invalid option\n");
                break;
            }
        }
    }
    else
    {
        printf("invalid user id or password, select choice:\n");
        printf("1.forget password\n2.View medicines");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("contact HR Manager for changes\n");
        }
        else if(choice ==2)
        {
            printf("invalid credentials. you can just view the medicines\n");
            display_medicine_details(medicines,total_medicines);
        }
        else
        {
            printf("invalid choice\n");
        }
    }
    return 1;
}

void add_medicine(struct pharmacy *p)
{
    printf("Enter Medicine Id:\n");
    scanf("%d",&p->medicine_id);
    printf("Enter Medicine NAme:\n");
    scanf("%s",&p->medicine_name);
    printf("Enter Medicine Cost:\n");
    scanf("%f",&p->medicine_cost);
    printf("Enter Stock_quantity:\n");
    scanf("%d",&p->medicine_stock_quantity);
    printf("Enter Medicine Type(tablet/injection:\n");
    scanf("%s",&p->medicine_type);
    printf("Enter Medicine dosage:\n");
    scanf("%f",&p->medicine_dosage);
    printf("medicine added Successfully\n");
}
void update_medicine_details(struct pharmacy *p)
{
    int choice;
    printf("which details need to update?\n");
    printf("1.ID\n2.name\n3.cost\n4.stock quantity\n5.type\n6.dosage\n");
    printf("enter choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter new Medicine Id:\n");
        scanf("%d",p->medicine_id);
        break;
    case 2:
        printf("Enter new Medicine Name:\n");
        scanf("%s",p->medicine_name);
        break;
    case 3:
        printf("Enter new Medicine Cost:\n");
        scanf("%f",p->medicine_cost);
        break;
    case 4:
        printf("Enter new Stock_quantity:\n");
        scanf("%d",p->medicine_stock_quantity);
        break;
    case 5:
        printf("Enter new Medicine Type(tablet/injection:\n");
        scanf("%s",p->medicine_type);
        break;
    case 6:
        printf("Enter new Medicine dosage:\n");
        scanf("%f",p->medicine_dosage);
        break;
    default:
        printf("invalid choice\n");
        break;
    }
    printf("medicine details updated Successfully\n");
}
void display_medicine_details(struct pharmacy medicines[],int total_medicines)
{
    if(total_medicines == 0)
    {
        printf("No medicines Available\n");
    }
    else
    {
        for(int medicine_index =0 ; medicine_index < total_medicines; medicine_index++)
        {
            printf("Medicine ID:%d\n",medicines[medicine_index].medicine_id);
            printf("Medicine Name:%s\n",medicines[medicine_index].medicine_name);
            printf("Medicine cost:%f\n",medicines[medicine_index].medicine_cost);
            printf("Medicine Stock Quantity:%d\n",medicines[medicine_index].medicine_stock_quantity);
            printf("Medicine type:%s\n",medicines[medicine_index].medicine_type);
            printf("medicine dosage:%f\n",medicines[medicine_index].medicine_dosage);

        }
    }
}
void search_by_medicine_id(struct pharmacy medicines[],int total_medicines)
{
    int search_id;
    printf("Enter Medicine Id to search:");
    scanf("%d",&search_id);
    int medicine_found =0;
    for (int medicine_index = 0; medicine_index < total_medicines; medicine_index++)
    {
        if(medicines[medicine_index].medicine_id == search_id)
        {
            printf("medicine with %d ID found and details are as follows\n",search_id);
            printf("Medicine ID:%d\n",medicines[medicine_index].medicine_id);
            printf("Medicine Name:%s\n",medicines[medicine_index].medicine_name);
            printf("Medicine cost:%f\n",medicines[medicine_index].medicine_cost);
            printf("Medicine Stock Quantity:%d\n",medicines[medicine_index].medicine_stock_quantity);
            printf("Medicine type:%c\n",medicines[medicine_index].medicine_type);
            printf("medicine dosage:%f\n",medicines[medicine_index].medicine_dosage);
            medicine_found = 1;
        }
    }
    if(!medicine_found)
    {
        printf("we could'nt found the entered medicine id %d\n",search_id);
    }
}
void search_by_medicine_name(struct pharmacy medicines[],int total_medicines)
{
    char search_name[100];
    printf("enter medicine name to search:");
    scanf("%s",search_name);
    int medicine_found = 0;
    for (int medicine_index = 0; medicine_index < total_medicines; medicine_index++)
    {
        if(strcmp(search_name,medicines[medicine_index].medicine_name)==0)
        {
            printf("medicine with %s name found and details are as follows\n",search_name);
            printf("Medicine ID:%d\n",medicines[medicine_index].medicine_id);
            printf("Medicine Name:%s\n",medicines[medicine_index].medicine_name);
            printf("Medicine cost:%f\n",medicines[medicine_index].medicine_cost);
            printf("Medicine Stock Quantity:%d\n",medicines[medicine_index].medicine_stock_quantity);
            printf("Medicine type:%c\n",medicines[medicine_index].medicine_type);
            printf("medicine dosage:%f\n",medicines[medicine_index].medicine_dosage);
            medicine_found = 1;
        }
    }
    if(!medicine_found)
    {
        printf("we could'nt found the entered medicine name %s\n",search_name);
    }

}
void check_stock(struct pharmacy medicines[], int total_medicines)
{
    int min_stock_limit = 50;

    printf("Checking stock for medicines below %d:\n", min_stock_limit);

    int low_stock_found = 0;

    for (int medicine_index = 0; medicine_index < total_medicines; medicine_index++)
    {
        if (medicines[medicine_index].medicine_stock_quantity < min_stock_limit)
        {
            printf("medicine ID:%d\n", medicines[medicine_index ].medicine_id);
            printf("medicine Name:%s\n", medicines[medicine_index ].medicine_name);
            printf("medicine stock Quantity:%d\n", medicines[medicine_index ].medicine_stock_quantity);
            printf("medicine Cost:%f\n", medicines[medicine_index ].medicine_cost);
            printf("medicine Type:%s\n", medicines[medicine_index ].medicine_type);
            printf("medicine dosage:%f\n", medicines[medicine_index ].medicine_dosage);
            low_stock_found = 1;
        }
    }

    if (!low_stock_found)
    {
        printf("All medicines have sufficient stock.\n");
    }
}


void save_medicine_data(struct pharmacy medicines[],int total_medicines)
{
    FILE *file;
    file = fopen("pharmacy_data.txt","w");
    if(file == NULL)
    {
        printf("Error in opening file");
    }
    fwrite(&total_medicines,sizeof(int),1,file);
    fwrite(medicines,sizeof(struct pharmacy),total_medicines,file);
    fclose(file);
    printf("Pharmacy data saved successfully\n");
}

int load_medicine_data(struct pharmacy medicines[])
{
    FILE *file;
    file = fopen("pharmacy_data.txt","r");
    if(file == NULL)
    {
        printf("Error in opening file");
    }
    int total_medicines;
    fread(&total_medicines,sizeof(int),1,file);
    fread(medicines,sizeof(struct pharmacy),total_medicines,file);
    fclose(file);
    printf("Pharmacy data loaded successfully %d Medicines found.\n",total_medicines);
    return total_medicines;
}

















