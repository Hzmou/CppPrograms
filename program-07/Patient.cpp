

#include "Patient.h"
#include <iostream>
using namespace std;

  /* This is the implementation of the Patient class. */

// default constructor.

Patient::Patient()
    : m_patientName(""), m_procedure() {}

// parameterized constructor.
Patient::Patient(string name, Procedure procedure)
    : m_patientName(name), m_procedure(procedure) {}
// accessors for the class.

string Patient:: getPatientName()const{
    return m_patientName;
}

Procedure Patient:: getProcedure() const{
    return m_procedure;
}

// mutators for the class.
void Patient:: setPatientName(string name){
    m_patientName = name;
}
void Patient:: setProcedure(Procedure proc){
    m_procedure = proc;
}