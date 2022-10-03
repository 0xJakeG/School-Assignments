//
//  QuickSort_Skeleton.cpp
//
//  Created by Bahamon, Julio on 6/25/19.
//  UNC Charlotte
//  Copyright © 2019 Bahamon, Julio. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;



//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};


void displayList(patient array[], int size)
{
    for(int i = 0; i < size; i++)
        {
            cout << "\t\tAge: " << array[i].age << "\t\tName: " << array[i].name 
                 << "\t\tBalance: $" << array[i].balance << endl; 
        }
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY AGE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE AGE OF THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S AGE
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE

int compareAge(const void *a,const void *b)
{
    int x = ((struct patient *)a)->age;
    int y = ((struct patient *)b)->age;
    
    if(x < y)
        return -1;
    else if(x == y) 
        return 0;
    else return 1;

}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY BALANCE DUE

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE BALANCE FOR THE FIRST PATIENT IS LESS
//         THAN THE SECOND PATIENT'S BALANCE
//       0 IF THE BALANCES ARE EQUAL
//       1 OTHERWISE

int compareBal(const void* b1, const void* b2)
{
	 int x = ((struct patient *)b1)->balance;
     int y = ((struct patient *)b2)->balance;
	   
	 if(x < y)
        return -1;
    else if(x == y) 
        return 0;
    else 
        return 1;
}

//  TODO:
//  IMPLEMENT A FUNCTION THAT COMPARES TWO PATIENTS BY NAME

//  THE FUNCTION RETURNS AN INTEGER AS FOLLOWS:
//      -1 IF THE NAME OF THE FIRST PATIENT GOES BEFORE
//         THE SECOND PATIENT'S NAME
//       0 IF THE AGES ARE EQUAL
//       1 OTHERWISE
//
//  HINT: USE THE strncmp FUNCTION
//  (SEE http://www.cplusplus.com/reference/cstring/strncmp/)

int compareName(const void * name1, const void * name2) {
    char *x = ((struct patient *) name1) -> name;
    char *y = ((struct patient *) name2) -> name;

    if(strncmp(x, y, 20) < 0){
        return -1;
    } else if(strncmp(x, y, 20) == 0) {
        return 0;
    } else {
        return 1;
    }
}

//  The main program
int main()
{
    int total_patients = 5;
    
    //  Storing some test data
    struct patient patient_list[5] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 2100},
        {32, "Tyra Banks    ", 750},
        {62, "Maria O'Donell", 375},
        {53, "Pablo Picasso ", 615}
    };
    
    
    cout << "Patient List: " << endl;
    
    //  TODO: 
    //  IMPLEMENT THE CODE TO DISPLAY THE CONTENTS
    //  OF THE ARRAY BEFORE SORTING
    
    displayList(patient_list, total_patients);
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT AGE
    qsort(patient_list, total_patients , sizeof(patient_list[0]), compareAge );
    
    cout << "Patient List - Sorted by Age: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY AGE
    
    displayList(patient_list, total_patients);
    
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT BALANCE
    
    qsort(patient_list, total_patients , sizeof(patient_list[2]), compareBal );
    
    cout << "Patient List - Sorted by Balance Due: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY BALANCE
    
    displayList(patient_list, total_patients);
    cout << endl;
    
    
    cout << "Sorting..." << endl;
    
    //  TODO:
    //  CALL THE qsort FUNCTION TO SORT THE ARRAY BY PATIENT NAME
    
    cout << "Patient List - Sorted by Name: " << endl;
    
    //  TODO:
    //  DISPLAY THE CONTENTS OF THE ARRAY
    //  AFTER SORTING BY NAME
    
    qsort(patient_list, total_patients , sizeof(patient_list[1]), compareName );
    
    displayList(patient_list, total_patients);
    
    cout << endl;
    
    return 0;
}
