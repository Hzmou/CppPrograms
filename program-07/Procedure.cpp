
/*
  * this is an implementation of the Procedure.h header file. It models a procedure in a hospital. 
  Private data stores the procedure name, doctor, and procedure cost. 
*/

#include "Procedure.h"
#include <iostream>
using namespace std;


// default constructor.
Procedure::Procedure()
    : m_procedureName(""), m_doctor(""), m_procedureCost(0.0) {}

// Parameterized constructor.
Procedure::Procedure(std::string name, std::string doctor, double cost)
    : m_procedureName(name), m_doctor(doctor) {
    m_procedureCost = (cost < 0) ? 0.0 : cost;
}


// getters for the class. 
string Procedure::getProcedureName() const{
    return m_procedureName;
}
string Procedure:: getDoctor() const{
    return m_doctor;
}
double Procedure::getProcedureCost() const{
    return m_procedureCost;
}

// setters for the class.

void Procedure::setProcedureName(string name){
    m_procedureName = name;
}

void Procedure::setDoctor(string doctor){
    m_doctor = doctor;
}
void Procedure::setProcedureCost(double cost){
    m_procedureCost = (cost < 0) ? 0.0 : cost;

}

