
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
void display(vector<Speaker> speakers);          // displays the list of speakers.
int search(vector<Speaker> pool, string target); // searches for speakers based on a topic and returns the index of the selected speaker.
string toLower(const string& str); // converts a string to lowercase for case-insensitive comparison.

int main()
{

  ifstream input;             // input file stream to read from the speakers.txt file.
  input.open("speakers.txt"); // open the file for reading.

  // check if the file was opened successfully.
  if (!input)
  {
    cerr << "Error opening file." << endl;
    return 1;
  }

  // vector to store the speakers information.
  // Each speaker is represented by a Speaker struct.
  // The vector allows dynamic resizing as speakers are added or removed.
  // The vector is initialized to hold Speaker objects.
  // The vector is used to store the speakers information read from the file.
  vector<Speaker> speakers;
  string line;
  while (getline(input, line))
  {

    istringstream iss(line); // create an input string stream to parse the line.
    // create a temporary Speaker object to hold the parsed data.
    // The temporary object is used to store the speaker's information.
    Speaker temp;

    getline(iss, temp.name, ',');  // read the speaker's name until the first comma.
    getline(iss, temp.phone, ','); // read the speaker's phone number until the second comma..
    getline(iss, temp.topic, ','); // read the speaker's topic until the third comma.

    // read the speaker's fee until the end of the line.
    // The fee is read as a string and then converted to a double.
    string feeStr;
    getline(iss, feeStr);
    temp.fee = stod(feeStr);

    speakers.push_back(temp);
  }

  // close the input file stream after reading all the speakers. and then display the list of speakers.
  input.close();
  display(speakers); // display the list of speakers.
  cout << endl;

  // Ask the user how many speakers are needed for the seminar.

  int n;
  cout << "How many speakers are needed? ";
  cin >> n;
  cin.ignore();
  // declare a vector to hold the selected speakers for the seminar.
  // its size is set to n which is the number of speakers needed.
  vector<Speaker> seminars(n);

  //

  for (int i = 0; i < n; ++i)
  {

    cout << "\n Enter search phrase: "; // prompt the user to enter a search phrase for the speaker's topic.
    // The search phrase is used to find speakers based on their topics.
    string phrase;
    getline(cin, phrase);

    int index = search(speakers, phrase); // call the search function to find speakers based on the search phrase.
    // The search function returns the index of the selected speaker in the speakers vector.
    // and displays the list of speakers matching the search phrase.

    if (index == -1)
    {

      // cout << "There are not speakers available. \n";
      seminars[i] = Speaker{}; // empty the Seminars vector.
    }

    seminars[i] = speakers[index];            // assign the selected speaker to the seminars vector.
    speakers.erase(speakers.begin() + index); // remove the selected speaker from the speakers vector to avoid duplicates.
    
  }

  double total = 0.0;

  cout << endl;

  for (int i = 0; i < n; ++i)
  {

    cout << "Seminar " << (i + 1) << ": ";
    // display the seminar number and the speaker's information.

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
  // display the total fees for the selected speakers.
  cout << "Total fees: " << fixed << setprecision(2) << total << endl;
}

// function to convert a string to lowercase.
string toLower(const string& str) {
    string result = str;
    for (char& c : result) c = tolower(c);
    return result;
}

/*
   * Function to display the list of speakers.
   * It takes a vector of Speaker objects as input and prints their information in a formatted manner.

*/
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

/*
 * Function to search for speakers based on a topic.
 * It takes a vector of Speaker objects and a target topic as input.
 * It returns the index of the selected speaker in the vector.
 * it calls the display function to show the list of speakers matching the topic.
 * If no speakers are found, it returns -1.
 */

  int search(vector<Speaker> pool, string target)
{
    vector<Speaker> matches;
    string targetLower = toLower(target);

    for (const auto &s : pool)
    {
        if (toLower(s.topic).find(targetLower) != string::npos)
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

    string choiceLower = toLower(choice);

    for (size_t i = 0; i < pool.size(); ++i)
    {
        if (toLower(pool[i].topic).find(targetLower) != string::npos &&
            toLower(pool[i].name) == choiceLower)
        {
            return static_cast<int>(i);
        }
    }

    cout << "Speaker not found in the choice. \n";
    return -1;
}