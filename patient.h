#ifndef PATIENT_H
#define PATIENT_H
#define MAX_PATIENTS 100
#define DATA_FILE "patients.txt"

struct patient
{
    int  patient_id;
    char patient_name[100];
    char patient_gender[10];
    int  patient_age;
    char patient_address[200];
    char patient_contact_number[15];
    char patient_emergency_contact_number[15];
};
int verify_user();
void register_patient(struct patient *p);
void update_patient(struct patient *p);
void display_patient(struct patient patients[], int total_patients);
void search_by_patient_id(struct patient patients[], int total_patients);
void search_by_patient_name(struct patient patients[], int total_patients);
void save_data(struct patient patient[], int total_patients);
int load_patient_data(struct patient patients[]);


#endif // PATIENT_H
