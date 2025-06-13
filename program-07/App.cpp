

#include "Procedure.h"
#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// function prototypes.

void ProcedureCost(string procedureName, Procedure &proc);
void display(const vector<Patient> &patients);

int main()
{

  int numPatients;
  string PatientName;
  string ProcedureName;
  string DoctorName;
  Procedure proc;

  cout << "How Many Patients: ";
  cin >> numPatients;
  vector<Patient> patients(numPatients);

  for (int i = 0; i < numPatients; ++i)
  {

    

    cout << "Patient " << i + 1 << endl;
    cout << " Enter Patient Name: ";
    getline(cin >> ws, PatientName);
    patients[i].setPatientName(PatientName);

    cout << "Enter Procedure Name: ";
    getline(cin >> ws, ProcedureName);
   

    cout << "Enter The Doctor to perform " << ProcedureName << ": ";
    getline(cin >> ws, DoctorName);
    
    ProcedureCost(ProcedureName, proc);
    proc.setProcedureName(ProcedureName);
    proc.setDoctor(DoctorName);

   


    //assign the procedure object to the patient.
    patients[i].setProcedure(proc);
  }
  display(patients);

  cout << "Enter Patient Name (quit to end)): ";
  string searchName;
  while (getline(cin >> ws, searchName) && searchName != "quit")
  {

    cout << "Enter percent of insurance covered: ";
    double insurancePercent;
    cin >> insurancePercent;
    
    bool found = false;
    for (const auto &patient : patients)
    {
      if (patient.getPatientName() == searchName)
      {
       
        cout << "Procedures: " << patient.getProcedure().getProcedureName() << endl;
        cout << "Doctor: " << patient.getProcedure().getDoctor() << endl;
        cout << "Cost of the Procedure: $" << fixed << setprecision(2) << patient.getProcedure().getProcedureCost() << endl;
        double patientCost = patient.getProcedure().patientCost(insurancePercent);
        cout << "Patient Cost: $" << fixed << setprecision(2) << patientCost << endl;
        found = true;
        
      }
    }
    if (!found)
    {
      cout << "Patient not found." << endl;
    }
    cout << "Enter Patient Name (quit to end)): ";
  }



  
  return 0;
}

// Function to display patient information, in a neatly formatted table.

void display(const vector<Patient> &patients)
{

  cout << left << setw(15) << "Patient Name"
       << setw(15) << "Procedure"
       << setw(15) << "Doctor"
       << right << setw(10) << "Cost" << endl;

  for (const auto &patient : patients)
  {

    cout << left << setw(15) << patient.getPatientName()
         << setw(17) << patient.getProcedure().getProcedureName()
         << setw(17) << patient.getProcedure().getDoctor()
         << right << fixed << setprecision(2) << setw(10) << patient.getProcedure().getProcedureCost()
         << endl;
  }
}


void ProcedureCost(string procedureName , Procedure &proc) {

  

  if(procedureName == "X-Ray"){
    proc.setProcedureCost(250.00);
  }
  else if(procedureName == "MRI"){
    proc.setProcedureCost(550.00);
  }  
  else if(procedureName == "Cat Scan"){
    proc.setProcedureCost(780);
  }
  else{
    cout << "Invalid Procedure Name" << endl;

  }


}