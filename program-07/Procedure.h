#pragma once
#include <string>

class Procedure
{ public:
	// procedure name and doctor set to empty string
	// cost set to 0.00
	Procedure();			
	// procedure name and doctor set to user supplied values
	// cost set or 0.00 on negative value
	Procedure(std::string name, std::string doctor, double cost);

	// accessors
	std::string getProcedureName () const;
	std::string getDoctor () const;
	double getProcedureCost () const;

	// mutators
	void setProcedureName (std::string name);
	void setDoctor (std::string doctor);
	// cost set to 0 on negative value
	void setProcedureCost (double cost);	

	// return patient cost based on insurance percent covered
	// ex. insurance covers 80% so patient pays 20%
	double patientCost (double insurancePercent) const;

  private:
	std::string m_procedureName;	// name of procedure (ex. X-Ray)
	std::string m_doctor;			// name of doctor (ex. Dr. Li)
	double m_procedureCost;			// cost of procedure (ex. 250.00)
};


