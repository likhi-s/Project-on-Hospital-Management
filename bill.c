#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bill.h"
#define USER_ID "Billing_officer"
#define USER_PASSWORD "billing@123"
#define MAX_BILLS 500

int verify_billing_user()
{
    char user_id[15];
    char user_pass[15];
    int option;
    int choice;
    struct bill bills[MAX_BILLS];
    int total_bills = load_bill_data(bills);
    printf("user ID:\n");
    scanf("%s",&user_id);
    printf("User password:\n");
    scanf("%s",&user_pass);

    if (strcmp(user_id, USER_ID) == 0 && strcmp(user_pass, USER_PASSWORD) == 0)
    {
        while(1)
        {
            printf("enter the option:\n");
            printf("1.Add bill\n2.Update bill\n3.Display bill\n4.Search by ID\n5.Save Data and exit\n");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                if(total_bills < MAX_BILLS)
                {
                    add_bill(&bills[total_bills++]);
                }
                else
                {
                    printf("limit reached\n");
                }
                break;
            case 2:
                if(total_bills >0)
                {
                    int bill_id;
                    printf("Enter bill ID to update:");
                    scanf("%d",&bill_id);
                    int bill_found =0;
                    for(int bill_index = 0; bill_index < total_bills; bill_index++)
                    {
                        if(bills[bill_index].bill_id == bill_id);
                        {
                            update_bill_details(&bills[bill_index]);
                            bill_found=1;
                        }
                    }
                    if(!bill_found)
                    {
                        printf("bill id not found.\n");
                    }
                }
                else
                {
                    printf("No bills found.\n");
                }
                break;
            case 3:
                display_bill_details(bills,total_bills);
                break;
            case 4:
                search_bill_by_patient_id(bills,total_bills);
                break;
            case 5:
                save_bill_data(bills,total_bills);
                printf("Saved bill Data and exiting\n");
                return 0;
                break;
            default:
                printf("Invalid option\n");
                break;
            }
        }
    }
    else
    {
        printf("invalid user id or password,select choice:\n");
        printf("1.forgot password.\n2.view bill\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("contact HR Manager for changes\n");
        }
        else if (choice==2)
        {
            printf("invalid credentials.You can just view bill.\n");
            display_bill_details(bills,total_bills);;
        }
        else
        {
            printf("invalid choice\n");
        }
    }
    return 1;
}

void add_bill(struct bill *b)
{
    printf("Enter Bill ID:\n");
    scanf("%d",&b->bill_id);
    printf("Enter Patient ID:\n");
    scanf("%d",&b->patient_id);
    printf("Enter Treatment ID:\n");
    scanf("%d",&b->treatment_id);
    printf("Enter Consultation Fee:\n");
    scanf("%f",&b->consultation_fee);
    printf("Enter Pharmacy Fee:\n");
    scanf("%f",&b->pharmacy_fee);
    printf("Enter Room Fee:\n");
    scanf("%f",&b->room_fee);
    printf("Enter Bill Date(DD/MM/YYYY):\n");
    scanf("%s",&b->bill_date);
    calculate_bill(b);
    printf("Bill added Successfully\n");
}


void update_bill_details(struct bill *b)
{
    int choice;
    printf("which details you want to update?\n");
    printf("1.Bill ID\n2.Patient ID\n3.Treatment ID\n4.consultation fee\n5.pharmacy fee\n6.room fee\n7.Bill date\n");
    printf("Enter Choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter New Bill ID:\n");
        scanf("%d",b->bill_id);
        break;
    case 2:
        printf("Enter New Patient ID:\n");
        scanf("%d",b->patient_id);
        break;
    case 3:
        printf("Enter New Treatment ID:\n");
        scanf("%d",b->treatment_id);
        break;
    case 4:
        printf("Enter New Consulation fee:\n");
        scanf("%f",b->consultation_fee);
        break;
    case 5:
        printf("Enter New Pharmacy Fee:\n");
        scanf("%f",b->pharmacy_fee);
        break;
    case 6:
        printf("Enter new Room fee:\n");
        scanf("%f",&b->room_fee);
    case 7:
        printf("Enter new Bill Date:\n");
        scanf("%s",&b->bill_date);
    default:
        printf("Invalid choice\n");
    }
    calculate_bill(b);
    printf("Updated bill Successfully\n");
}

void display_bill_details(struct bill bills[],int total_bills)
{
    if(total_bills ==0)
    {
        printf("no bills Available\n");
    }
    else
    {
        for(int bill_index =0; bill_index < total_bills;bill_index++)
        {
            printf("Bill Id:%d\n", bills[bill_index].bill_id);
            printf("Patient ID:%d\n",bills[bill_index].patient_id);
            printf("Treatment Id:%d\n",bills[bill_index].treatment_id);
            printf("Consultation Fee:%f\n",bills[bill_index].consultation_fee);
            printf("Pharmacy fee:%f\n",bills[bill_index].pharmacy_fee);
            printf("Room Fee:%f\n",bills[bill_index].room_fee);
            printf("Total Bill Amount:%f",bills[bill_index].total_bill_amount);
            printf("Bill date:%s\n",bills[bill_index].bill_date);
        }
    }
}



void search_bill_by_patient_id(struct bill bills[], int total_bills)
{
    int search_id;
    printf("Enter Patient Id to search:");
    scanf("%d",&search_id);
    int bill_found =0;
    for(int bill_index =0; bill_index < total_bills;bill_index++)
    {
        if(bills[bill_index].patient_id == search_id)
        {
            printf("bill with Patient Id %d found and details are as follows\n",search_id);
            printf("Bill Id:%d\n", bills[bill_index].bill_id);
            printf("Patient ID:%d\n",bills[bill_index].patient_id);
            printf("Treatment Id:%d\n",bills[bill_index].treatment_id);
            printf("Consultation Fee:%f\n",bills[bill_index].consultation_fee);
            printf("Pharmacy fee:%f\n",bills[bill_index].pharmacy_fee);
            printf("Room Fee:%f\n",bills[bill_index].room_fee);
            printf("Total Bill Amount:%f",bills[bill_index].total_bill_amount);
            printf("Bill date:%s\n",bills[bill_index].bill_date);

        }
    }
}
void calculate_bill(struct bill *b)
{
    b->total_bill_amount = b->consultation_fee + b->pharmacy_fee + b->room_fee;
}

void save_bill_data(struct bill bills[],int total_bills)
{
    FILE *file;
    file = fopen("bill_data.txt","w");
    if(file == NULL)
    {
        printf("error in opening bill data file\n");
    }
    fwrite(&total_bills,sizeof(int),1,file);
    fwrite(bills,sizeof(struct bill),total_bills,file);
    fclose(file);
    printf("Bill Data saved Succeddfully\n");
}


int load_bill_data(struct bill bills[])
{
    FILE *file;
    file = fopen("bill_data.txt","r");
    if(file == NULL)
    {
        printf("error in loading bill data file\n");
    }
    int total_bills;
    fwrite(&total_bills,sizeof(int),1,file);
    fwrite(bills,sizeof(struct bill),total_bills,file);
    fclose(file);
    printf("Bill data loaded Succeddfully %d bills found\n",total_bills);
    return total_bills;
}
