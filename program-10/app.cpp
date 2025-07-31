

#include "Student.h"
#include "Graduate.h"
#include "Undergraduate.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// function prototypes.
vector<Student *> readFile(const string &filename); 
void display(vector<Student *> students, string studentType);

int main()
{
    vector<Student *> students = readFile("studentdata.txt");
    cout << "Number of students loaded: " << students.size() << endl;

    display(students, "Undergraduate");
    cout << endl;
    display(students, "Graduate");

    string major;

    cout << "Enter Major (quit to end): ";

    while (major != "quit")
    {

        cin >> major;

        for (auto s : students)
        {

            if (s->getMajor() == major)
            {

                if (dynamic_cast<Graduate *>(s))
                {
                    cout << left << setw(18) << s->getName() << "Graduate" << endl;
                }
                else if (dynamic_cast<Undergraduate *>(s))
                {
                    cout << left << setw(18) << s->getName() << "Undergraduate" << endl;
                }
            }
        }

         cout << "Enter Major (quit to end): ";
    }

    // Clean up memory
    for (auto s : students)
    {
        delete s;
    }

    return 0;
}

/*
 * Function to  read the students data into a vector of Student pointers.
 */

vector<Student *> readFile(const string &filename)
{

    vector<Student *> students;
    ifstream file(filename);
    string line;

    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return students;
    }

    while (getline(file, line))
    {

        istringstream iss(line);
        string type, id, name, major, advisor;
        int credits;

        getline(iss, type, ',');  // reading Type.
        getline(iss, id, ',');    // reading ID.
        getline(iss, name, ',');  // reading Name.
        getline(iss, major, ','); // reading Major.

        // reading credits.

        string creditsStr;

        getline(iss, creditsStr, ',');
        credits = stoi(creditsStr);

        // read the data into the vector of student pointers.
        // depending on the type of student we assign the vector a new value
        // with an object Undegraduate or Graduate.

        if (type == "Graduate")
        {
            getline(iss, advisor, ',');
            students.push_back(new Graduate(id, name, major, credits, advisor));
        }
        else if (type == "Undergraduate")
        {

            students.push_back(new Undergraduate(id, name, major, credits));
        }
    }

    return students;
}

/*
 * A function to display the students information in a formatted table.
 */
void display(vector<Student *> students, string studentType)
{
    if (studentType == "Undergraduate")
    {
        cout << "Undergraduate Student Report\n";
        cout << "Identification     Name      Major     Credits Earned Credits Needed Year\n";
        for (auto s : students)
        {
            Undergraduate *u = dynamic_cast<Undergraduate *>(s);
            if (u)
            {
                cout << u->getIdentification() << " "
                     << left << setw(18) << u->getName()
                     << setw(6) << u->getMajor()
                     << setw(14) << u->getCredits()
                     << setw(15) << u->creditsNeeded()
                     << u->yearStatus() << endl;
            }
        }
    }
    else if (studentType == "Graduate")
    {
        cout << "Graduate Student Report\n";
        cout << "Identification Name           Major Credits Earned Credits Needed Thesis Advisor\n";
        for (auto s : students)
        {
            Graduate *g = dynamic_cast<Graduate *>(s);
            if (g)
            {
                cout << g->getIdentification() << " "
                     << left << setw(18) << g->getName()
                     << setw(6) << g->getMajor()
                     << setw(14) << g->getCredits()
                     << setw(15) << g->creditsNeeded()
                     << g->getThesisAdvisor() << endl;
            }
        }
    }
}