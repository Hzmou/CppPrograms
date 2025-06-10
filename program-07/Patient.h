#pragma once
#include "Procedure.h"
#include <string>

class Patient
{ public:
	// name is empty string, default Procedure object
	Patient();
	// name and Procedure object are set
	Patient (std::string name, Procedure proc);

	// accessors
	std::string getPatientName() const;
	Procedure getProcedure() const;

	// mutators
	void setPatientName(std::string name);
	void setProcedure (Procedure proc);

  private:
	std::string m_patientName;	// patient name
	Procedure m_procedure;		// Procedure for this patient
};

