#include <iostream>
using namespace std;

struct stud{
    long long unsigned enrNo;
    char name[20];
    float marks;
};

int AddData(struct stud, FILE*);
int RemoveData(long long unsigned);
struct stud SearchData(long long unsigned, FILE*);
int UpdateData(long long unsigned);
void LeaveDash(void);
void WrongInput(void);

int main(){
    FILE * fp;
    int ch = 0;

    struct stud s; long long unsigned search, update;

    fp = fopen("Files/Data.csv", "a+");
    if(fp == NULL){
        cout << "Error opening file!" << endl;
        return 1;
    }

    printf("WELCOME TO THE CLASS DASHBOARD\n");
    printf("What would you like to do?\n");
    printf("1) Add a Student's Data (+).\n");
    printf("2) Remove a Student's Data (-).\n");
    printf("3) Search for a Student's Data (O-).\n");
    printf("4) Update a Student's Data (^).\n");

    do{
        printf("\nENTER YOUR CHOICE (ENTER 0 to Leave...): ");
        scanf("%d", &ch);
        
        if (ch == 1){
            printf("\nEnter Enrollment Number: ");
            scanf("%llu", &s.enrNo);

            printf("Enter Name: ");
            getchar();
            gets(s.name);

            printf("Enter Marks: ");
            scanf("%f", &s.marks);
        
            if(AddData(s, fp)){
                printf("DATA ADDED! DO YOU WANT TO DO SOMETHING ELSE?\n");
            }

            else{
                printf("SOME ERROR OCCURED... WOULD YOU LIKE TO TRY AGAIN! OR DO SOMETHING ELSE?\n");
            }
        }
        else if (ch == 2){
            // RemoveData();
        }
        else if (ch == 3){
            printf("\nEnter the Enrollment Number of the Student to be Search: ");
            scanf("%llu", &search);

            s = SearchData(search, fp);
            printf("\nENROLLMENT NUMBER: %llu", s.enrNo);
            printf("\nNAME: ");
            puts(s.name);
            printf("MARKS: %.2f\n", s.marks);
        }
        else if (ch == 4){
            // UpdateData();
        }
        else if (ch == 0){
            LeaveDash();
        }
        else{
            WrongInput();
        }      
    } while(ch!=0);

    fclose(fp);

    return 0;
}

int AddData(struct stud s, FILE* infile){
    fprintf(infile, "%llu,", s.enrNo);
    fputs(s.name, infile);
    fprintf(infile, ",%.2f,\n", s.marks);

    return 1;
}

int RemoveData(long long unsigned){
    
}

struct stud SearchData(long long unsigned search, FILE* infile){
    struct stud s = {0, "", 0.0}; // Initialize with default values

    return s;
}

int UpdateData(long long unsigned){
    
}

void LeaveDash(void){
    printf("\nTHANKS FOR USING THE SERVICE!\nHOPE TO SEE YOU AROUND!!\n");
}

void WrongInput(void){
    printf("\nSORRY! WRONG INPUT!\nTRY AGAIN!!\n");
}