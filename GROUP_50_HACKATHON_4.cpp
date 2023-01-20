// This programme processes hospital billing
// for many patients during their check out
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

// The price of food
// Displayed in Malaysian Ringgit
const double PRICE_FOOD = 10;

// Function header to display types of room and their respective prices
void displayRoom(string roomType[], double roomPrice[])
{
	cout << fixed << setprecision(2);

	cout << "            ---------------------------------\n"
	     << "                     HOSPITAL EXPENSES		\n" 
	     << "            ---------------------------------\n";
	     
	//Display the room types and the rates
	cout << "---------------------------------------------------------\n";
	cout << "|                 Hospital's daily rate                 |\n";
	cout << "---------------------------------------------------------\n";
	
	for(int i = 0; i < 5; i++)
	{
		cout << "|" << i+1 << "| " << setw(25) << roomType[i] 
			 << ": $ " << setw(9) << roomPrice[i] << " per day. " << setw(5)<< "|" << endl;
	}
	
	cout << "---------------------------------------------------------\n";
}

// Function header to display types of surgery and their respective rates
void displaySurgery(string surgeryType[], double surgeryPrice[])
{
	cout << "\n-----------------------------------------------------------------------\n";
	cout << "|                           SURGERY CHARGES                           |" ;
	
	//Display the types of surgeries and the rates 
	cout << "\n-----------------------------------------------------------------------\n";
	
	for(int i = 0; i < 5; i++)
	{
		cout << "|" << i+1 << "| " << setw(42) << surgeryType[i] 
			 << ": $ " << setw(8) << surgeryPrice[i] << " per day. " << setw(3)<< "|" << endl;
	}
	cout << "-----------------------------------------------------------------------\n\n";
}

// Function header to display types of medications and their respective rates
void displayMedic(string medicType[], double medicPrice[])
{
	cout << "\n----------------------------------------------------------\n"
	     << "|                   MEDICATION CHARGES                   |\n" 
         << "----------------------------------------------------------\n";
	
	//Display the types of medication and the prices of it
	for(int i = 0; i < 5; i++)
	{
		cout << "|" << i+1 << "| " << setw(30) << medicType[i] 
			 << ": $ " << setw(8) << medicPrice[i] << " per day. " << setw(2)<< "|" << endl;
	}
	cout << "----------------------------------------------------------\n\n";
}

// Function header to display the types of service and their respective rates
void displayService(string serviceType[], double servicePrice[])
{
	cout << "\n------------------------------------------------\n"
	     << "|                SERVICE CHARGES               |\n" 
         << "------------------------------------------------\n";
	
	//Display the types of services and the prices of it
	for(int i = 0; i < 5; i++)
	{
		cout << "|" << i+1 << "| " << setw(20) << serviceType[i] 
			 << ": $ " << setw(8) << servicePrice[i] << " per day. " << setw(2)<< "|" << endl;
	}
	
    cout << "------------------------------------------------\n\n";
}

// Function header to display total charges for each patient
void displayCharges(string name[], double stayCharge[], double surgeryFee[], double medicationFee[], double serviceFee[], double totalCharge[], int size)
{
	cout << fixed << setprecision(2);
	cout << "\n\n\t----------------------------------------------\n"
		 << "\t\tTotal Charges For Each Patient\n"
		 << "\t----------------------------------------------\n\n";
	
	for(int i = 0; i < size; i++)
	{
		cout << setw(30) << "Name : " << setw(15) <<  name[i] << endl << endl;
		cout << setw(30) << "Hospital Stay Charges : $" << setw(10) << stayCharge[i] << endl;
		cout << setw(30) << "Surgery Charges : $" << setw(10) << surgeryFee[i] << endl;
		cout << setw(30) << "Medication Charges : $" << setw(10) << medicationFee[i] << endl;
		cout << setw(30) << "Service Charges : $" << setw(10) << serviceFee[i] << endl;
		cout << setw(45) << "---------------\n";
		cout << setw(30) << "Total Charges = $" << setw(10) << totalCharge[i] << endl << endl;
		cout << "\t----------------------------------------------\n";
	}
	
	system("pause");
	system("cls");
}

// Function header to total up charges for all patients
void calcTotalCharge(double totalCharge[], string name[], int size)
{
	double total = 0;
	
	cout << fixed << setprecision(2);
	cout << "\n\n\t----------------------------------------------\n" ;
	cout << "\t\tTotal Charges For All Patients\n"
		 << "\t----------------------------------------------\n\n";
		 
	for (int i = 0; i < size; i++)
	{
		cout << setw(20) << name[i] << " : $" << setw(10) << totalCharge[i] << endl;	
	}
	
	cout << setw(35) << "-------------" << endl;
	
	for (int i = 0; i < size; i++)
	{
		total += totalCharge[i];
	}
	
	cout << setw(24) << "Total = $" << setw(10) << total << endl << endl;
	
	cout << "\tThe total charges for all the patients is $" << total << endl << endl;
	
	system("pause");
	system("cls");
}

// Function header to let admin input the number of patients
int numPatient()
{
	int no_patient;
	
	cout << "Enter the number of patients: ";
	cin >> no_patient;	
	cin.ignore();
	
	cout << endl;
	
	system("pause");
	system("cls");
	
	return no_patient;
}

// Function header to let admin input the number of meals ordered
double food()
{
	int meal;
	double foodCharge;

	cout << "\nEnter the number of meals ordered: ";
	cin >> meal;
	
	cout << endl;
	
	foodCharge = PRICE_FOOD * meal;
	
	return foodCharge;
}

// Function header to let admin input the number, the type
// and the number of days stayed 
double room(int size, double *roomCharge, int *hospitalStay)
{
	//initialize string array to type of room
	string roomType[5] = {"Single Superior Suite", "Super Single Room", "Golden Suite",
						  "VVIP Suite", "Full Set Gold Suites"};
	
	//initialize double array to prices of room type			  						  				  
	double roomPrice[5] = {650.00, 300.00, 1288.00, 1688.00, 3688.00};
	
	int numType, roomStayed, numDay;
	*roomCharge = 0;
	*hospitalStay = 0; 	// variable points to the total number of days of each patient stayed.
	
	displayRoom(roomType, roomPrice); // Display types of room and their respective prices
	
	cout << "Enter the number of type of room stayed: ";
	cin >> numType;
	
	cout << endl;
	
	for(int j = 0; j < numType; j++)
	{
		cout << "(e.g. Enter '1' if the patient stayed in " << roomType[0] << ")\n";
		cout << "Enter the type of room stayed: ";
		cin >> roomStayed;
		
		cout << endl;
		
		cout << "Enter the number of day stayed in " << roomType[roomStayed-1] << ": ";
		cin >> numDay;
		
		cout << endl;
		
		*roomCharge += (roomPrice[roomStayed-1] * numDay);
		
		*hospitalStay += numDay;
	}
}

// Function header to let admin input the number and the type
// of surgeries that the patient underwenr
double surgery(int size, double *surgeryCharge)
{
	//initialize string array to type of surgery
	string surgeryType[5] = {"Minor dermatological surgery (Skin biopsy)", "Cataract surgery", "Heart bypass surgery",
						     "Breast surgery", "Hip replacement"};
						     
	//initialize double array to prices of surgery			  						  
	double surgeryPrice[5] = {1239.00, 3000.00, 66700.00, 29800.00, 42000.00};
	
	int numSurgery, type;
	*surgeryCharge = 0;	// this variable points to the total number of days of each patient stayed.
		
	displaySurgery(surgeryType, surgeryPrice); // Display the types of surgeries and their respective prices
	
    cout << "P/S If the patient underwent cataract surgery for both eyes, it will count as 2 surgeries.\n"
         << "Enter the number of surgery(s) the patient underwent: ";
    
    while(!cin >> numSurgery)
    {
    	cout << "Invalid input. Please enter a number again.";
    	cin.clear();
    	cin.ignore();
    	
	}
	cin >> numSurgery;
	
	cout << endl;
	
	cout << "Enter the type of surgery that the patient undergo: \n";
	cout << "(e.g. Enter '2 3' if the patient had undergone " << surgeryType[1] << " and " << surgeryType[2] << "): ";
	
	for(int j = 0; j < numSurgery; j++)
	{
		cin >> type;
		
		cout << endl;
		
		*surgeryCharge += surgeryPrice[type-1];
	}
}

// Function header to let admin input the number and the type
// of the medicines that the patients took
double medication(int size, double *medicationCharge)
{
	//initialize string array to type of medication
	string medicType[5] = {"Paracetamol 500mg tablet", "Metoprolol 100mg tablet", "Amlodipine 10mg tablet",
						     "Atorvastatin 20mg tablet", "Adrenaline auto-injector(AAI)"};
	
	//initialize double array to prices of medicines			  
	double medicPrice[5] = {50.00, 10.90, 230.50, 137.80, 1199.00};
	
	int numMedic, type;
	*medicationCharge = 0;	// this variable points to the total number of days of each patient stayed.
		
	displayMedic(medicType, medicPrice); // Display the types of medications and their respective prices
	
   	cout << "Enter the number of medicines that the patient took: ";
	cin >> numMedic;
	
	cout << endl;
	
	cout << "Enter the type of medicines that the patient took: \n";
	cout << "(e.g. Enter '1 2' if the patient had taken " << medicType[0] << " and " << medicType[1] << "): ";
	
	for(int j = 0; j < numMedic; j++)
	{
		cin >> type;
		
		cout << endl;
		
		*medicationCharge += medicPrice[type-1];
	}
}

// Function header to let admin input the number and the types
// of the services that the patients used
double services(int size, double *serviceCharge)
{
	//initialize string array to type of services
	string serviceType[5] = {"Ambulance", "General anaesthesia", "MRI Scan",
						     "CT Scan", "First consultation"};
						     
	//initialize double array to prices of services			  						  
	double servicePrice[5] = {220.00, 1200.00, 1599.00, 970.00, 220.00};
	
	int numService, type;
	*serviceCharge = 0;	// this variable points to the total number of days of each patient stayed.
		
	displayService(serviceType, servicePrice); // Display the types of services and their respective prices
		
   	cout << "Enter the number of services that the patient used: ";
	cin >> numService;
	
	cout << endl;
	
	cout << "Enter the type of services that the patient used: \n";
	cout << "(e.g. Enter '1 2' if the patient had taken " << serviceType[0] << " and " << serviceType[1] << "): ";
	
	for(int j = 0; j < numService; j++)
	{
		cin >> type;

		cout << endl;
		
		*serviceCharge += servicePrice[type-1];
	}
}

// Function header to compare the bills among the patients
// and determine one with the highest bill
int highest(string name[], double arr[], int size)
{
    // Initialize maximum element and index/subscript
    int maxBill = arr[0];
    int maxIndex = 0;
 	int maxIndex1, maxIndex2;

	//sort out the largest element in the array
    for (int i = 1; i < size; i++)
    {
    	if (arr[i] > maxBill)
    	{
            maxIndex = i;
		}
          
    	else if (arr[i] == maxBill)
    	{
    		maxIndex1 = maxIndex;
    		maxIndex2 = i;
    		maxIndex = -1;
		}
	}
	
	cout << "\n\n\t----------------------------\n"
		 << "\t\tHighest Bill\n"
		 << "\t----------------------------\n\n";
		 
	if(maxIndex >= 0)
    {
		cout << "\t" << name[maxIndex] << " paid the highest bill. ($" << arr[maxIndex] << ")" << endl << endl;
	}
	else
    {
		cout << "\t" << name[maxIndex1] << " and " << name[maxIndex2] << endl;
		cout << "\tpaid the highest bill ($" << arr[maxIndex1] << ")" << endl << endl;
	}

   	system("pause");
	system("cls");
}

// Function header to compare the bills among the patients
// and determine one with the lowest bill
int lowest(string name[], double arr[], int size)
{
    // Initialize minimum element and index/subscript
    int minBill = arr[0];
    int minIndex = 0;
 	int minIndex1, minIndex2;

	//sort out the smallest element in the array
    for (int i = 1; i < size; i++)
    {
    	if (arr[i] < minBill)
    	{
            minIndex = i;
		}
          
    	else if (arr[i] == minBill)
    	{
    		minIndex1 = minIndex;
    		minIndex2 = i;
    		minIndex = -1;
		}
	}
	
	cout << "\n\n\t----------------------------\n"
		 << "\t\tLowest Bill\n"
		 << "\t----------------------------\n\n";
		 
	if(minIndex >= 0)
    {
		cout << "\t" << name[minIndex] << " paid the lowest bill. ($" << arr[minIndex] << ")" << endl << endl;
	}
	else
    {
		cout << "\t" <<name[minIndex1] << " and " << name[minIndex2] << endl;
		cout << "\tpaid the lowest bill ($" << arr[minIndex1] << ")" << endl << endl;
	}
	
   	system("pause");
	system("cls");
}

// Function header to compute the 
// average hospital stay for a patient
void averageHospitalStay(int dayArray[], int size)
{
	int totalDay = 0;
	for (int i = 0; i < size; i++)
	{
		totalDay += dayArray[i];
	}
	
	double average = totalDay / size; // Formula to compute the average hospital stay

	cout << "\n\n\t-------------------------------------\n" ;
	cout << "\t\tAverage Hospital Stay\n"
		 << "\t-------------------------------------\n\n";
		 
	cout << fixed << setprecision(2);
	cout << "\tThe average hospital stay for a patient is " << average << " days." << endl << endl;
	
	system("pause");
	system("cls");
}

// Function header to calculate the total charges for each category
double calcCategoryCharge(double stayCharge[], double surgeryFee[], double medicationFee[], double serviceFee[], int size)
{
    double totalStayCharge = 0;
    double totalSurgeryFee = 0;
    double totalMedicationFee = 0;
    double totalServiceFee = 0;
	
	cout << fixed << setprecision(2);
	cout << "\n\n\t----------------------------------------------\n" ;
	cout << "\t\tTotal Charges For Each Category\n"
		 << "\t----------------------------------------------\n\n";
		 
	for (int i = 0; i < size; i++)	
	{
		totalStayCharge += stayCharge[i];
		totalSurgeryFee += surgeryFee[i];
		totalMedicationFee += medicationFee[i];
		totalServiceFee += serviceFee[i];	
	} 
	
    cout << setw(40) << "Total Hospital Stay Charge : $" << setw(10) << totalStayCharge << endl;	
    cout << setw(40) << "Total Surgery Charge : $" << setw(10) << totalSurgeryFee << endl;	
    cout << setw(40) << "Total Medication Charge : $" << setw(10) << totalMedicationFee << endl;	
    cout << setw(40) << "Total Service Charge : $" << setw(10) << totalServiceFee << endl << endl;
	
	system("pause");
	system("cls");
}

// Function header to let admin access to many options from the menu
int displayFunction(string name[], double stayCharge[], double surgeryFee[], double medicationFee[], double serviceFee[], double totalCharge[], int dayHStay[], int size)
{
	int option;
	do
    {
        cout << "\n\n\t\t--------------------------------------\n"
             << "\t\t\tHospital Billing System\n"
            << "\t\t--------------------------------------\n\n";
            
        cout << "\t\tWhat you want to do?\n\n";
        cout << "\t1. To generate each category charges and total charges for each patient\n"
             << "\t2. To calculate the total charges for all patients\n"
             << "\t3. To calculate the total charges for each category\n"
             << "\t4. To find who pay the highest bill\n"
             << "\t5. To find who pay the lowest bill\n"
             << "\t6. To calculate the average of hospital stay\n"
             << "\t7. All of the above\n"
             << "\t8. Exit\n\n";

        cout << "Enter your option: "; // Let admin input their option
        cin >> option;
        
        system("cls");
        
        switch(option)
        {
            case 1:
                displayCharges(name, stayCharge, surgeryFee, medicationFee, serviceFee, totalCharge, size);
                break;
                
            case 2:
                calcTotalCharge(totalCharge, name, size);
                break;
                
            case 3:
                calcCategoryCharge(stayCharge, surgeryFee, medicationFee, serviceFee, size);
                break;
                
            case 4:
                highest(name, totalCharge, size);
                break;
                
            case 5:
                lowest(name, totalCharge, size);
                break;
                
            case 6:
                averageHospitalStay(dayHStay, size);
                break;
                
            case 7:
                displayCharges(name, stayCharge, surgeryFee, medicationFee, serviceFee, totalCharge, size);
                calcTotalCharge(totalCharge, name, size);
                calcCategoryCharge(stayCharge, surgeryFee, medicationFee, serviceFee, size);			
                highest(name, totalCharge, size);
                lowest(name, totalCharge, size);
                averageHospitalStay(dayHStay, size);
                break;	
                
            case 8:
                exit(0);
                break;        
        }
    } 
    while (option != 8);
}

//Main function
int main()
{
	int size = numPatient();	//size == number of patient
	string name[size];			//string array to store name of patients
	double roomCharge;		
	double foodCharge[size];	//double array to store food charges of each patient
	int hospitalStay;
	double roomFee[size];		//double array to store room charges of each patient
	int dayHStay[size]; 		//double array day of hospital stay of each patient
	double stayCharge[size];	//double array to store hospital stay charges of each patient
	double surgeryCharge;
	double surgeryFee[size];	//double array to store surgery charges of each patient
	double medicationCharge;
	double medicationFee[size];	//double array to store medication charges of each patient
	double serviceCharge;
	double serviceFee[size];	//double array to store service charges of each patient
	double totalCharge[size];	//double array to store total charges of each patient
	
	//let the admin to input the information of patient one by one
	for(int i = 0; i < size; i++)
	{
		cout << "Enter the NAME of the patient. \n\n" ;
		cout << "Patient " << i+1 << ": ";
		getline(cin, name[i]);
		
		foodCharge[i] = food();
		
		cin.ignore();
	
		//call 'room' function
		room(size, &roomCharge, &hospitalStay);
		roomFee[i] = roomCharge;		//total room fee for each patient in an array
		stayCharge[i] = roomFee[i] + foodCharge[i];		//total hospital stay charge for each patient in an array
		dayHStay[i] = hospitalStay;		//total day stay for each patient in an array
		
		system("cls");
		
		//call 'surgery' function
		surgery(size, &surgeryCharge);
		surgeryFee[i] = surgeryCharge;	//total surgery fee for each patient in an array
		
        system("cls");	
        
		//call 'medication' function	
		medication(size, &medicationCharge);
		medicationFee[i] = medicationCharge;	//total medication fee for each patient in an array
		
        system("cls");
		
		//call 'service' function
		services(size, &serviceCharge);
		serviceFee[i] = serviceCharge;	//total service fee for each patient in an array
		
        system("cls");
		
		totalCharge[i] = stayCharge[i] + surgeryFee[i] + medicationFee[i] + serviceFee[i];
		
		cin.ignore();
	}
	
	system("pause");
	system("cls");
	
	//call 'displayFunction' function
	displayFunction(name, stayCharge, surgeryFee, medicationFee, serviceFee, totalCharge, dayHStay, size);	
	
	return 0;
}
