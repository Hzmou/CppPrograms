
/*
 * This is cpp program that uses structures to store data about speakers at a conference.
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

/* struct to represent a speakers information.
 * It contains the speaker's name, phone number, topic, and fee.
 * The struct is defined with public access by default.
 */

struct Speaker
{

  string name;
  string phone;
  string topic;
  double fee;
};

// function prototypes.
void display(vector<Speaker> speakers);
int search(vector<Speaker> pool, string target);

int main()
{

  ifstream input;
  input.open("speakers.txt");
  if (!input)
  {
    cerr << "Error opening file." << endl;
    return 1;
  }
  vector<Speaker> speakers;
  string line;
  while (getline(input, line))
  {

    istringstream iss(line);
    Speaker temp;

    getline(iss, temp.name, ',');
    getline(iss, temp.phone, ',');
    getline(iss, temp.topic, ',');

    string feeStr;
    getline(iss, feeStr);
    temp.fee = stod(feeStr);

    speakers.push_back(temp);
  }

  input.close();
  display(speakers);

  int n;
  cout << "How many speakers are needed? ";
  cin >> n;
  cin.ignore();

  vector<Speaker> seminars(n);

  for (int i = 0; i < n; ++i)
  {

    cout << "\n Enter search phrase: ";
    string phrase;
    getline(cin, phrase);

    int index = search(speakers, phrase);

    if (index == -1)
    {

      //cout << "There are not speakers available. \n";
      seminars[i] = Speaker{}; // empty the Seminars vector.
    }

    seminars[i] = speakers[index];
    speakers.erase(speakers.begin() + index);
  }

  double total = 0.0;

  cout << endl;

  for (int i = 0; i < n; ++i)
  {

    cout << "Seminar " << (i + 1) << ": ";

    if (seminars[i].name.empty())
    {

      cout << endl;
    }
    else
    {

      cout << left << setw(20) << seminars[i].name
           << setw(18) << ((seminars[i].phone.find("(207)") != string::npos) ? seminars[i].phone : "")
           << setw(35) << seminars[i].topic
           << right << setw(8) << fixed << setprecision(2) << seminars[i].fee << endl;
      total += seminars[i].fee;
    }
  }
  cout << "Total fees: " << fixed << setprecision(2) << total << endl;
}

void display(vector<Speaker> speakers)
{

  cout << left << setw(20) << "Speaker Name"
       << setw(18) << "Phone"
       << setw(35) << "Topic"
       << right << setw(8) << "Fee" << endl;

  for (const auto &s : speakers)
  {

    string phoneOut = (s.phone.find("(207)") != string::npos) ? s.phone : "";
    cout << left << setw(20) << s.name
         << setw(18) << phoneOut
         << setw(35) << s.topic
         << right << setw(8) << fixed << setprecision(2) << s.fee << endl;
  }
}

int search(vector<Speaker> pool, string target)
{

  vector<Speaker> matches;

  for (const auto &s : pool)
  {
    if (s.topic.find(target) != string::npos)
    {
      matches.push_back(s);
    }
  }

  if (matches.empty())
  {
    cout << "No Speakers found for this topic.";
    return -1;
  }

  display(matches);

  cout << "Enter the speaker name of your choice: ";
  string choice;
  getline(cin >> ws, choice);

  // find the speaker in the pool and return its index.

  for (size_t i = 0; pool.size(); ++i)
  {

    if (pool[i].topic.find(target) != string::npos && pool[i].name == choice)
    {
      return static_cast<int>(i);
    }
  }

  cout << "Speaker not found in the choice. \n";
  return -1;
}