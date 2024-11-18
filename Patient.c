#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "patient.h"

int verify_user()
{
#define USER_ID "receptionist"
#define USER_PASSWORD "password123"

    char user_id[15];
    char user_pass[15];
    int option;
    int choice;

    struct patient patients[MAX_PATIENTS];
    int total_patients = load_patient_data(patients);

    printf("User Id:\n");
    scanf("%s", user_id);
    printf("User Password:\n");
    scanf("%s", user_pass);

    if (strcmp(user_id, USER_ID) == 0 && strcmp(user_pass, USER_PASSWORD) == 0)
    {
        while (1)
        {
            printf("enter the option:\n");
            printf("1. Register patient\n 2. Update patient\n3. Display patients\n4. Search by ID\n5. Search by Name\n6. Exit\n");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                if (total_patients < MAX_PATIENTS)
                {
                    register_patient(&patients[total_patients++]);
                } else
                {
                    printf("limit Reached\n");
                }
                break;
            case 2:
                if (total_patients > 0)
                {
                    int patient_id;
                    printf("enter patient id to update: ");
                    scanf("%d", &patient_id);
                    int found = 0;
                    for (int  patient_index = 0;  patient_index < total_patients;  patient_index++)
                    {
                        if (patients[ patient_index].patient_id == patient_id)
                        {
                            update_patient(&patients[ patient_index]);
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                    {
                        printf("patient id not found.\n");
                    }
                }
                else
                {
                    printf("Invalid patient id.\n");
                }
                break;
            case 3:
                display_patient(patients, total_patients);
                break;
            case 4:
                search_by_patient_id(patients, total_patients);
                break;
            case 5:
                search_by_patient_name(patients, total_patients);
                break;
            case 6:
                 save_data(patients, total_patients);
                 printf("saved the patient data and exiting.\n");
                return 0;
            default:
                printf("invalid option.\n");
            }
        }
    }
    else
    {
        printf("invalid user id or password,select choice:\n");
        printf("1.forgot password.\n2.view patient\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("contact admin for changes\n");
        }
        else if (choice==2)
        {
            printf("invalid credentials.You can just view patients.\n");
            display_patient(patients, total_patients);
        }
        else
        {
            printf("invalid choice\n");
        }
    }
    return 0;
}


void register_patient(struct patient *p)
{
    printf("enter patient ID: ");
    scanf("%d", &p->patient_id);
    printf("enter patient name: ");
    scanf("%s", p->patient_name);
    printf("enter patient gender: ");
    scanf("%s", p->patient_gender);
    printf("enter patient age: ");
    scanf("%d", &p->patient_age);
    printf("enter patient address: ");
    scanf("%s", p->patient_address);
    printf("enter patient contact number: ");
    scanf("%s", p->patient_contact_number);
    printf("enter patient emergency contact number: ");
    scanf("%s", p->patient_emergency_contact_number);
    printf(" registeration of patient is  done\n");
}

void update_patient(struct patient *p)
{
    int choice;
    printf("which detials you want to update?\n");
    printf("1. Name\n2. Gender\n3. Age\n4. Address\n5. Contact number\n6. Emergency contact number\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("enter new patient name: ");
        scanf("%s", p->patient_name);
        break;
    case 2:
        printf("enter new patient gender: ");
        scanf("%s", p->patient_gender);
        break;
    case 3:
        printf("enter new patient age: ");
        scanf("%d", &p->patient_age);
        break;
    case 4:
        printf("enter new patient address: ");
        scanf("%s", p->patient_address);
        break;
    case 5:
        printf("enter new patient contact number: ");
        scanf("%s", p->patient_contact_number);
        break;
    case 6:
        printf("enter new patient emergency contact number: ");
        scanf("%s", p->patient_emergency_contact_number);
        break;
    default:
        printf("invalid choice.\n");
        break;
    }
    printf("required patient details updated\n");
}

void display_patient(struct patient patients[], int total_patients)
{
    if (total_patients == 0)
    {
        printf("no patients available.\n");
    }
    else
    {
        for (int  patient_index = 0;  patient_index < total_patients;  patient_index++)
        {
            printf("patient ID: %d\n", patients[ patient_index].patient_id);
            printf("patient name: %s\n", patients[ patient_index].patient_name);
            printf("patient gender: %s\n", patients[ patient_index].patient_gender);
            printf("patient age: %d\n", patients[ patient_index].patient_age);
            printf("patient address: %s\n", patients[ patient_index].patient_address);
            printf("patient contact number: %s\n", patients[ patient_index].patient_contact_number);
            printf("patient emergency contact number: %s\n", patients[ patient_index].patient_emergency_contact_number);
        }
    }
}

void search_by_patient_id(struct patient patients[], int total_patients)
{
    int search_id;
    printf("enter patient ID to search: ");
    scanf("%d", &search_id);
    int patient_found = 0;
    for (int  patient_index = 0;  patient_index < total_patients;  patient_index++)
    {
        if (patients[ patient_index].patient_id == search_id)
        {
            printf("patient found and details as follows:\n");
            printf("patient ID: %d\n", patients[ patient_index].patient_id);
            printf("patient name: %s\n", patients[ patient_index].patient_name);
            printf("patient gender: %s\n", patients[ patient_index].patient_gender);
            printf("patient age: %d\n", patients[ patient_index].patient_age);
            printf("patient address: %s\n", patients[ patient_index].patient_address);
            printf("patient contact number: %s\n", patients[ patient_index].patient_contact_number);
            printf("patient emergency contact number: %s\n", patients[ patient_index].patient_emergency_contact_number);
            patient_found = 1;
            break;
        }
    }
    if (!patient_found)
    {
        printf("we could'nt found the entered id %d\n", search_id);
    }
}

void search_by_patient_name(struct patient patients[], int total_patients)
{
    char search_name[200];
    printf("enter patient name to search: ");
    scanf("%s", search_name);
    int patient_found = 0;
    for (int  patient_index = 0;  patient_index < total_patients;  patient_index++)
    {
        if (strcmp(search_name, patients[patient_index].patient_name) == 0)
        {
            printf("patient with %s found:\n",search_name);
            printf("patient ID: %d\n", patients[patient_index].patient_id);
            printf("patient name: %s\n", patients[patient_index].patient_name);
            printf("patient gender: %s\n", patients[patient_index].patient_gender);
            printf("patient age: %d\n", patients[patient_index].patient_age);
            printf("patient address: %s\n", patients[patient_index].patient_address);
            printf("patient contact number: %s\n", patients[patient_index].patient_contact_number);
            printf("patient emergency contact number: %s\n", patients[patient_index].patient_emergency_contact_number);
            patient_found = 1;
            break;
        }
    }
    if (!patient_found)
    {
        printf("patient with name %s not found.\n", search_name);
    }
}


void save_data(struct patient patients[], int total_patients)
{
    FILE *file = fopen("patient_data.txt", "w");
    if (file == NULL)
    {
        printf("Error saving data to file.\n");
        return;
    }
    fwrite(&total_patients, sizeof(int), 1, file);  // size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
    fwrite(patients, sizeof(struct patient), total_patients, file);
    fclose(file);
    printf("Data saved successfully.\n");
}

int load_patient_data(struct patient patients[])
{
    FILE *file = fopen("patient_data.txt", "r");
    if (file == NULL)
    {
        printf("No data exist\n");
        return 0;
    }
    int total_patients = 0;
    fread(&total_patients, sizeof(int), 1, file);//size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
    fread(patients, sizeof(struct patient), total_patients, file);
    fclose(file);
    printf("patient data loaded sucessfully %d patients found.\n", total_patients);
    return total_patients;
}
