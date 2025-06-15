

#include "Procedure.h"
#include "Patient.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// function prototypes.

// function to set the cost of the procedure based on the name.
void ProcedureCost(string procedureName, Procedure &proc);
// function to display patient information.
void display(const vector<Patient> &patients);

int main()
{

  int numPatients;      // number of patients, also the size  of our vector of patients.
  string PatientName;   // name of the patient.
  string ProcedureName; // name of the procedure.
  string DoctorName;    // name of the doctor.
  Procedure proc;       // object Procedure to hold the procedure information, and then assign it to the patient.

  // prompt user for number of patients.
  cout << "How Many Patients: ";
  cin >> numPatients;
  vector<Patient> patients(numPatients); // vector of patients of size numPatients.

  // sentinetal loop to get patient information.
  for (int i = 0; i < numPatients; ++i)
  {

    cout << "Patient " << i + 1 << endl; // display the patient number.
    cout << " Enter Patient Name: ";
    getline(cin >> ws, PatientName);
    patients[i].setPatientName(PatientName); // set the patient name in the patient object.

    cout << "Enter Procedure Name: ";
    getline(cin >> ws, ProcedureName);

    cout << "Enter The Doctor to perform " << ProcedureName << ": ";
    getline(cin >> ws, DoctorName);

    ProcedureCost(ProcedureName, proc);   // set the cost of the procedure based on the name.
    proc.setProcedureName(ProcedureName); // set the procedure name in the procedure object.
    proc.setDoctor(DoctorName);           // set the doctor name in the procedure object.

    // assign the procedure object to the patient
    patients[i].setProcedure(proc);
  }
  display(patients); // display all the patients information in a neatly formatted table.
  cout << endl;

  // search for a patient by name and display their procedure information.
  // and the total cost of the procedure based on the insurance percent covered.
  cout << "Patient information: " << endl;
  cout << "-------------------" << endl;
  cout << endl;

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

      // check if the patient name matches the search name.
      // display the procedure information and the total cost of the procedure
      // based on the insurance percent covere for that specific patient.
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

/*
 * Function to display patient information in a neatly formatted table.
 * @param patients vector of Patient objects to be displayed.
 * This function displays the patient name, procedure name, doctor name, an;opd cost of the procedure.
 * author : Hamza Zmou
 */

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

/*
 * Function to set the cost of the procedure based on the name.
 * @param procedureName name of the procedure.
 * Author: Hamza Zmou
 */

void ProcedureCost(string procedureName, Procedure &proc)
{

  if (procedureName == "X-Ray")
  {
    proc.setProcedureCost(250.00);
  }
  else if (procedureName == "MRI")
  {
    proc.setProcedureCost(550.00);
  }
  else if (procedureName == "Cat Scan")
  {
    proc.setProcedureCost(780);
  }
  else
  {
    cout << "Invalid Procedure Name" << endl;
  }
}