// RUN COMMANDS:
// g++ cpp_assign.cpp
// a.exe input\sample_input.in
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class userDeatails
{
public:
    string lastName;
    string firstName;
    string middleName;
    string nickName;
    string houseNo;
    string streetAddress;
    string City;
    string State;
    string Zip;
    void set(string value, int count)
    {
        switch (count)
        {
        case 1:
            lastName = value;
            break;
        case 2:
            firstName = value;
            break;
        case 3:
            middleName = value;
            break;
        case 4:
            nickName = value;
            break;
        case 5:
            houseNo = value;
            break;
        case 6:
            streetAddress = value;
            break;
        case 7:
            City = value;
            break;
        case 8:
            State = value;
            break;
        case 9:
            Zip = value;
            break;
        }
    }
};

string getSubStr(string data, int pos, int size)
{
    return data.substr(pos, size);
}
string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int main(int argc, char **argv)
{
    ifstream myfile;
    string filename = argv[1];
    myfile.open(filename.c_str());
    string inputLines;
    int userDataBytes[] = {15, 15, 15, 10, 5, 20, 15, 15, 6};
    int userDataBytesIndex[] = {0, 15, 30, 45, 55, 60, 80, 95, 110};
    int countLines = 0, i = 0;
    vector<string> user_data_vector;

    if (myfile.is_open())
    {

        while (getline(myfile, inputLines))
        {
            for (int i = 0; i < 9; i++)
            {
                user_data_vector.push_back(getSubStr(inputLines, userDataBytesIndex[i], userDataBytes[i]));
            }
            user_data_vector.push_back("ENDOFLINE");
            countLines += 1;
        }
    }

    int countUserDetails = 1, z = 0;
    userDeatails ud[countLines];

    for (string data : user_data_vector)
    {
        if (data != "ENDOFLINE")
        {
            ud[z].set(data, countUserDetails);
            countUserDetails += 1;
        }
        else
        {
            countUserDetails = 1;
            z += 1;
        }
    }
    //     Sample output
    //    myFname myLname,
    //    houseNo myStreet,
    //    myCity, myState myZip
    ofstream writeFileEnvelope;
    writeFileEnvelope.open("writeFileEnvelope.txt");
    for (int i = 0; i < countLines; i++)
    {
        writeFileEnvelope << removeSpaces(ud[i].firstName) << " " << removeSpaces(ud[i].lastName) << "," << endl;
        writeFileEnvelope << removeSpaces(ud[i].houseNo) << " " << removeSpaces(ud[i].streetAddress) << "," << endl;
        writeFileEnvelope << removeSpaces(ud[i].City) << ", " << removeSpaces(ud[i].State) << " " << removeSpaces(ud[i].Zip) << "\n"
                          << endl;
        cout << endl;
    }
    writeFileEnvelope.close();
    // myFname myLname      houseNo myStreet      myCity, myState myZip
    ofstream writeFileFixedFile;
    writeFileFixedFile.open("writeFileFixedFile.txt");
    for (int i = 0; i < countLines; i++)
    {
        writeFileFixedFile << removeSpaces(ud[i].firstName) << " " << removeSpaces(ud[i].lastName) << "\t" << removeSpaces(ud[i].houseNo) << " " << removeSpaces(ud[i].streetAddress) << "\t" << removeSpaces(ud[i].City) << ", " << removeSpaces(ud[i].State) << " " << removeSpaces(ud[i].Zip) << "\n"
                           << endl;
    }
    writeFileFixedFile.close();
    // "myFname myLname","houseNo myStreet","myCity, myState myZip"
    ofstream writeFileCSVFormat;
    writeFileCSVFormat.open("writeFileCSVFormat.txt");
    for (int i = 0; i < countLines; i++)
    {
        writeFileCSVFormat << "\"" << removeSpaces(ud[i].firstName) << " " << removeSpaces(ud[i].lastName) << "\", \"" << removeSpaces(ud[i].houseNo) << " " << removeSpaces(ud[i].streetAddress) << "\", \"" << removeSpaces(ud[i].City) << ", " << removeSpaces(ud[i].State) << " " << removeSpaces(ud[i].Zip) << "\"\n"
                           << endl;
    }
    writeFileCSVFormat.close();

    return 0;
}
