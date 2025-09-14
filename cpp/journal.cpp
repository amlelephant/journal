#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <thread>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
#include <filesystem>
#include <dirent.h>
#include <conio.h>   // For _getch() and _kbhit()
#include <windows.h> // For system() and Sleep()
#include <set>
#include <cctype>
#include <algorithm>

using namespace std;

struct FormField
{
    string label;
    string value;
};

// constructors
void boot();
void displayListFunctionality(const std::vector<std::string> &images, int highlight);
string displayMenu(vector<string> options);
bool check_password();
string encrypt_decrypt(string text, string pad);
string load(string filename);
void logger();
int countWords(string str);
void read();
void patch();
vector<string> displayForm(vector<FormField> &fields);
void home();
string extract_year(const string &date);

int countWords(string str)
{

    int numWords = 0;

    for (int x = 0; x < str.length(); x++)
    {
        if (isspace(str[x]))
        {
            numWords++;
        }
    }

    return numWords;
}

// section 1: encryption/decryption

void save(const string &filename, const string &data)
{
    ofstream file(filename, ios::binary);
    if (file)
    {
        file << data;
        cout << "Data saved to " << filename << " successfully." << endl;
    }
    else
    {
        cerr << "Error: Unable to open file " << filename << " for writing." << endl;
    }
    file.close();
}

string load(string filename)
{
    ifstream file;
    file.open(filename, ios::binary); // Open in binary mode
    string pad;

    if (file)
    {
        // Get the size of the file
        file.seekg(0, ios::end);
        streampos fileSize = file.tellg();
        file.seekg(0, ios::beg);

        // Read the entire contents of the file into the pad string
        pad.resize(fileSize);
        file.read(&pad[0], fileSize);
    }

    file.close();
    return pad;
}

string encrypt_decrypt(string text, string pad)
{
    string result;
    for (int i = 0; i < text.length(); i++)
    {
        result += text[i] ^ pad[i % pad.length()];
    }
    return result;
}

void encrypt_decrypt_images(const std::string &directoryPath)
{
    DIR *dir = opendir(directoryPath.c_str());
    if (dir != nullptr)
    {
        dirent *entry;
        while ((entry = readdir(dir)) != nullptr)
        {
            if (entry->d_type == DT_REG)
            {
                std::cout << "decrypt/encrypting " << entry->d_name << std::endl;
                string pad = load("ENTER HERE");
                string encryptedData = encrypt_decrypt(load(directoryPath + "/" + entry->d_name), pad);
                save(directoryPath + "/" + entry->d_name, encryptedData);
            }
        }
        closedir(dir);
    }
    else
    {
        std::cerr << "Error: Unable to open directory." << std::endl;
    }
}

void encrypt_decrypt_image(const std::string &fileName)
{
    string pad = load("ENTER HERE");
    string filePath = "ENTER HERE" + fileName;
    string encryptedData = encrypt_decrypt(load(filePath), pad);
    save(filePath, encryptedData);
}

// section 2: password protection on boot
bool check_password()
{
    string check_pad = load("ENTER HERE");
    string pad = load("ENTER HERE");
    string intendedResult = load("ENTER HERE");

    if (encrypt_decrypt(check_pad, pad) != intendedResult)
    {
        return false;
    }
    // get user passsword input

    vector<FormField> fields = {{"Password", ""}};

    vector<string> password = displayForm(fields);
    if (encrypt_decrypt(password[0], pad) != R"(SM\)")
    {
        return false;
    }
    return true;
}

// section 3 : features

void copyFile(const string &sourceFilePath, const string &destinationFilePath)
{
    ifstream sourceFile(sourceFilePath, ios::binary);
    ofstream destinationFile(destinationFilePath, ios::binary);

    if (sourceFile && destinationFile)
    {
        // Read and write contents of the file in chunks
        const int bufferSize = 4096;
        char buffer[bufferSize];
        while (!sourceFile.eof())
        {
            sourceFile.read(buffer, bufferSize);
            destinationFile.write(buffer, sourceFile.gcount());
        }
        cout << "File copied successfully." << endl;
    }
    else
    {
        cerr << "Failed to copy file." << endl;
    }

    sourceFile.close();
    destinationFile.close();

    // Encrypt the copied file
    string pad = load("ENTER HERE");
    string encryptedData = encrypt_decrypt(load(destinationFilePath), pad);
    save(destinationFilePath, encryptedData);
}

void logger()
{
    // takes user input, encrypts it, and logs it to the file on the removable drive
    string pad = load("ENTER HERE");
    string input;

    cin.ignore();

    cout << "Enter text to log: ";
    getline(cin, input);

    // get the date
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string date = to_string(ltm->tm_mon + 1) + "/" + (ltm->tm_mday < 10 ? "0" : "") + to_string(ltm->tm_mday) + "/" + to_string(ltm->tm_year + 1900);

    string total = date + " " + input;

    vector<FormField> fields = {
        {"Path to file (if none type none)", "ENTER HERE"},
        {"Photo Name (with extension)", ""}};

    vector<string> results = displayForm(fields);

    string imgPath = results[0];
    string photoName = results[1];
    // cout << imgPath << photoName;
    if (imgPath != "none")
    {
        const string destinationFilePath = "ENTER HERE" + photoName;
        copyFile(imgPath, destinationFilePath);
        total += " " + imgPath;
    }

    // open the log file and read the contents, then decrypt it, then append the new entry, then encrypt it, then write it back to the file
    string encrypted = load("ENTER HERE");
    string decrypted = encrypt_decrypt(encrypted, pad);
    decrypted += "\n" + total;
    encrypted = encrypt_decrypt(decrypted, pad);

    ofstream file;
    file.open("E:/minecheck/log.txt", ios::binary);
    file << encrypted << endl;
    file.close();

    // Replace "X:" with the drive letter of the USB drive you want to eject
    // std::string driveLetter = "E:";

    // Use "rundll32.exe" with the "shell32.dll" to eject the USB drive
    // std::string ejectCommand = "rundll32.exe shell32.dll,Control_RunDLL hotplug.dll";

    // Append the drive letter to the command
    // ejectCommand += " " + driveLetter;

    // Execute the command to eject the USB drive
    // std::system(ejectCommand.c_str());

    home();
}

string extract_year(const string &date)
{
    stringstream ss(date);
    string token;
    vector<string> parts;

    while (getline(ss, token, '/'))
    {
        parts.push_back(token);
    }

    if (parts.size() == 3)
    {
        return parts[2]; // The year
    }
    else
    {
        return ""; // Invalid format
    }
}

std::string strip(const std::string &s)
{
    auto start = std::find_if(s.begin(), s.end(),
                              [](unsigned char ch)
                              { return !std::isspace(ch); });

    auto end = std::find_if(s.rbegin(), s.rend(),
                            [](unsigned char ch)
                            { return !std::isspace(ch); })
                   .base();

    if (start >= end)
    {
        return "";
    }

    return std::string(start, end);
}

string normalize_date(const string &date)
{
    stringstream ss(date);
    string part;
    vector<string> parts;

    while (getline(ss, part, '/'))
    {
        parts.push_back(part);
    }

    if (parts.size() != 3)
    {
        return ""; // invalid date format
    }

    int month = stoi(parts[0]);
    int day = stoi(parts[1]);
    int year = stoi(parts[2]);

    ostringstream formatted;
    formatted << setw(2) << setfill('0') << month << "/"
              << setw(2) << setfill('0') << day << "/"
              << setw(4) << setfill('0') << year;

    return formatted.str();
}

bool match_year_month(const string &date, const string &target_year, const string &target_month)
{
    stringstream ss(date);
    string part;
    vector<string> parts;

    while (getline(ss, part, '/'))
    {
        parts.push_back(part);
    }

    if (parts.size() != 3)
        return false;

    // Normalize month: "1" => "01", "12" => "12"
    string month = parts[0].size() == 1 ? "0" + parts[0] : parts[0];
    string year = parts[2];

    //cout << "month: " << month << " year: " << year << endl;
    
    

    bool result = year == target_year && month == target_month;

   

    return (year == target_year && month == target_month);
}

void searchByDate(string date){
    // open the log file and split it into a list of the lines
    string pad = load("E:/minecheck/pad.txt");
    string log = load("E:/minecheck/log.txt");
    string decrypted = encrypt_decrypt(log, pad);

    vector<string> lines;
    string line;
    for (int i = 0; i < decrypted.length(); i++)
    {
        if (decrypted[i] == '\n')
        {
            lines.push_back(line);
            // cout << line;
            line = "";
        }
        else
        {
            line += decrypted[i];
        }
    }
    lines.push_back(line);

    // find the lines that match the date

    vector<string> matches;
    for (int i = 0; i < lines.size(); i++)
    {

        if (normalize_date(lines[i].substr(0, 10)) == date)
        {
            matches.push_back(lines[i]);
        }
    }
    if (matches.size() == 0)
    {
        cout << "no matches found";
    }
    else
    {
        
        for (int i = 0; i < matches.size(); i++)
        {
            cout << matches[i] << endl
                 << endl;
        }
    }
}

void read()
{
    // asks if you want to read from a specific day or the whole log
    string pad = load("E:/minecheck/pad.txt");
    string input;
    string result;
    string date;

    string choice = displayMenu({"Read All", "Search Specific", "Browse", "Back"});

    if (choice == "Read All")
    {
        input = "all";
    }
    else if (choice == "Search Specific")
    {
        input = "specific";
        cout << endl
             << "Enter date (mm/dd/yyyy): ";
        cin >> date;
    }
    else if (choice == "Browse")
    {
        // open the log file and split it into a list of the lines
        string pad = load("ENTER HERE");
        string log = load("ENTER HERE");
        string decrypted = encrypt_decrypt(log, pad);

        vector<string> lines;
        string line;
        for (int i = 0; i < decrypted.length(); i++)
        {
            if (decrypted[i] == '\n')
            {
                lines.push_back(line);
                // cout << line;
                line = "";
            }
            else
            {
                line += decrypted[i];
            }
        }
        lines.push_back(line);

        // find the lines that match the date
        vector<string> allDates;
        vector<string> matches;
        for (int i = 0; i < lines.size(); i++)
        {
            allDates.push_back(normalize_date(lines[i].substr(0, 10)));
        }
        //system("pause");
        set<string> yearsUnique;

        for (int x = 0; x < allDates.size(); x++)
        {
            string year = extract_year(strip(allDates[x]));

            if (year.size() > 2 && stoi(year) > 1900)
            {
                yearsUnique.insert(year);
            }
        }

        vector<string> yearForMenu;

        for (auto it = yearsUnique.begin(); it != yearsUnique.end(); ++it)
        {
            // cout << ' ' << *it;
            yearForMenu.push_back(*it);
        }

        string yearSelectChoice = displayMenu(yearForMenu);

        vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

        string monthSelectChoice = displayMenu(months);

        int index = 0;
        for (int z = 0; z < months.size(); z++)
        {
            if (monthSelectChoice == months[z])
            {
                z++;
                index = z;
                break;
            }
        }

        vector<string> datesInMonth;

        //cout << yearSelectChoice << " " << "0" + to_string(index) << endl;

        string yearComparable;

        if (index < 10){
            yearComparable = "0" + to_string(index);
        } else{
            yearComparable = to_string(index);
        }

        for (int x = 0; x < allDates.size(); x++)
        {
            if (match_year_month(allDates[x], yearSelectChoice, yearComparable))
            {

                datesInMonth.push_back(allDates[x]);
            }
        }

        if (datesInMonth.size() > 0){        

            string datSelectChoice = displayMenu(datesInMonth);

            searchByDate(datSelectChoice);        
        } else {
            cout << endl << "No dates were logged in this month" << endl;
        }


        system("pause");
        home();
    }
    else
    {
        input == "back";
    }

    if (input == "all")
    {
        // reads the log file and returns a vector of strings
        string pad = load("ENTER HERE");

        string log = load("ENTER HERE");
        string decrypted = encrypt_decrypt(log, pad);

        int wordCount = countWords(decrypted);

        cout << "Words: " << to_string(wordCount) << endl;

        cout << "Characters: " << to_string(decrypted.length()) << endl;

        cout << decrypted << endl;

        system("pause");
        home();
    }
    else if (input == "specific")
    {
        cout << endl
             << "Searching for " << date << endl;

        // open the log file and split it into a list of the lines
        string pad = load("E:/minecheck/pad.txt");
        string log = load("E:/minecheck/log.txt");
        string decrypted = encrypt_decrypt(log, pad);

        vector<string> lines;
        string line;
        for (int i = 0; i < decrypted.length(); i++)
        {
            if (decrypted[i] == '\n')
            {
                lines.push_back(line);
                // cout << line;
                line = "";
            }
            else
            {
                line += decrypted[i];
            }
        }
        lines.push_back(line);

        // find the lines that match the date

        vector<string> matches;
        for (int i = 0; i < lines.size(); i++)
        {

            if (lines[i].substr(0, 10) == date)
            {
                matches.push_back(lines[i]);
            }
        }
        if (matches.size() == 0)
        {
            cout << "No matches found" << endl;
        }
        else
        {
            cout << endl
                 << "Matches found: " << endl
                 << endl;
            for (int i = 0; i < matches.size(); i++)
            {
                cout << matches[i] << endl
                     << endl;
            }
        }

        system("pause");
        home();
    }
    else
    {
        home();
    }
}

int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns = 80;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return columns;
}

int getConsoleHeight()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows = 25; // Default height
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    return rows;
}

void printCentered(string text, bool highlighted = false)
{
    int consoleWidth = getConsoleWidth();
    int padding = (consoleWidth - text.length()) / 2;
    if (highlighted == true)
    {
        cout << string(max(0, padding), ' ') << "\033[7m" << text << "\033[0m";
    }
    else
    {
        cout << string(max(0, padding), ' ') << text;
    }
}

vector<string> displayForm(vector<FormField> &fields)
{
    int currentField = 0;
    char inputChar;

    while (true)
    {
        system("cls");

        // Calculate the width of the form dynamically based on the longest label and value
        int maxLabelLength = 0;
        int maxValueLength = 0;
        for (const auto &field : fields)
        {
            maxLabelLength = max(maxLabelLength, (int)field.label.length());
            maxValueLength = max(maxValueLength, (int)field.value.length());
        }
        int fieldWidth = maxLabelLength + maxValueLength + 10; // Add padding for borders and spaces

        // Calculate the number of lines to print before the form to center it vertically
        int formHeight = fields.size() + 2; // Number of fields + top and bottom borders
        int consoleHeight = getConsoleHeight();
        int paddingLines = (consoleHeight - formHeight) / 2;

        // Print padding lines for vertical centering
        for (int i = 0; i < paddingLines; ++i)
        {
            cout << endl;
        }

        // Top border
        printCentered("+" + string(fieldWidth - 2, '-') + "+\n");

        // Display fields
        for (int i = 0; i < fields.size(); ++i)
        {
            string paddedValue = fields[i].value + string(fieldWidth - 5 - fields[i].label.length() - fields[i].value.length(), ' ');

            if (i == currentField)
            {
                printCentered("| " + fields[i].label + ": " + paddedValue + " |" + "\n", true);
            }
            else
            {
                printCentered("| " + fields[i].label + ": " + paddedValue + " |" + "\n");
            }
        }
        // Bottom border
        printCentered("+" + string(fieldWidth - 2, '-') + "+\n");

        inputChar = _getch(); // Get input without echo

        if (inputChar == 224 || inputChar == 0 || inputChar == -32)
        {                         // Arrow keys are detected
            inputChar = _getch(); // Get the next character to determine the specific arrow key

            if (inputChar == 72)
            { // Up arrow
                if (currentField > 0)
                    currentField--;
            }
            else if (inputChar == 80)
            { // Down arrow
                if (currentField < fields.size() - 1)
                    currentField++;
            }
        }
        else if (inputChar == 13)
        {          // Enter key
            break; // Finish form input
        }
        else if (inputChar == 8)
        { // Backspace key
            if (!fields[currentField].value.empty())
            {
                fields[currentField].value.pop_back();
            }
        }
        else if (isprint(inputChar))
        { // Printable character
            if ((90 - (fields[currentField].value.length() + fields[currentField].label.length())) > 0)
            {
                fields[currentField].value += inputChar;
            }
        }
    }

    vector<string> results;
    for (const auto &field : fields)
    {
        results.push_back(field.value);
    }

    return results;
}

string displayMenu(vector<string> options)
{
    int highlight = 0;
    int c;

    while (true)
    {
        displayListFunctionality(options, highlight);

        c = _getch(); // Get character without echo

        if (c == 224)
        {                 // Arrow keys prefix
            c = _getch(); // Get the actual arrow key code

            switch (c)
            {
            case 72: // Up arrow
                if (highlight > 0)
                {
                    highlight--;
                }
                break;
            case 80: // Down arrow
                if (highlight < options.size() - 1)
                {
                    highlight++;
                }
                break;
            case 77: // w key
                if (highlight > 0)
                {
                    highlight--;
                }
                break;
            case 73: // s key
                if (highlight < options.size() - 1)
                {
                    highlight++;
                }
                break;
            }
        }
        else if (c == 13)
        { // Enter key
            return options[highlight];
        }
        else if (c == 'q')
        { // Quit on 'q'
            exit(0);
            break;
        }
    }

    return "exit";
}

void displayListFunctionality(const std::vector<std::string> &options, int highlight)
{
    system("cls"); // Clear console (Windows specific)

    // Get console dimensions
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int menuWidth = 32;                  // Width of the menu (including borders)
    int menuHeight = options.size() + 2; // Height of the menu (including borders)
    int xOffset = (columns - menuWidth) / 2;
    int yOffset = (rows - menuHeight) / 2;

    // Move the cursor to the vertical center
    for (int i = 0; i < yOffset; i++)
    {
        std::cout << std::endl;
    }

    // Draw top border
    std::cout << std::string(xOffset, ' ') << "+--------------------------------+" << std::endl;

    for (int i = 0; i < options.size(); i++)
    {
        std::cout << std::string(xOffset, ' ') << "| "; // Left border
        if (i == highlight)
        {
            // Highlighting with inverted colors
            std::cout << "\x1b[7m" << " > " << options[i] << "\x1b[0m"; // Highlight using ANSI escape codes
        }
        else
        {
            std::cout << "   " << options[i];
        }
        std::cout << std::string(25 - options[i].length(), ' ') << "   |" << std::endl; // Right border and padding
    }

    // Draw bottom border
    std::cout << std::string(xOffset, ' ') << "+--------------------------------+" << std::endl;
}

void images()
{
    system("cls");
    vector<string> menuitem = {"Encrypt/Decrypt All", "Encrypt/Decrypt Specific", "Enter Stand Alone", "Back"};
    string choice = displayMenu(menuitem);
    if (choice == menuitem[0])
    {
        system("cls");
        encrypt_decrypt_images("E:/minecheck/images");
        system("pause");
        encrypt_decrypt_images("E:/minecheck/images");
        home();
    }
    else if (choice == menuitem[1])
    {

        vector<FormField> fields = {
            {"Image Name (with extension)", ""}};

        vector<string> results = displayForm(fields);

        encrypt_decrypt_image(results[0]);
        home();
    }
    else if (choice == menuitem[2])
    {

        vector<FormField> fields = {
            {"Path to file", "ENTER HERE"},
            {"Photo Name (with extension)", ""}};

        vector<string> results = displayForm(fields);

        string imgPath = results[0];
        string photoName = results[1];
        cout << imgPath << photoName;
        const string destinationFilePath = "ENTER HERE" + photoName;
        copyFile(imgPath, destinationFilePath);
        home();
    }
    else if (choice == menuitem[3])
    {
        system("cls");
        home();
    }
}

void patch()
{
    vector<string> patch = {"V2.0:This is a complete C++ buildout of the previous python minesweeper. Added pretty much just journaling functionality with XOR encryption. Tbh i don't even know how the encryption algorithm works but somehow it does. Something to do with a key on the drive is cross referenced with another key on the drive so there is no raw keys. A potential downside to this is you can completely decrypt it if you know what you are doing. Most likely I'm not facing some cia level threats but just a thought.",
                            "V2.1: introduction of images into journaling. The path for the image is stored under each journal entry. each entry a prompt to give an image is provided. You can add images from anywhere in the system and it will copy the file and encrypt it using the same method as text. The decryption of these images works the same as the decryption of text. You can also enter images individually.",
                            "V2.2: added some cool input boxes and using the arrow keys to select things. Overall just made it smoother. Built out the image tab inside archives and deleted some features I knew I would never build out.",
                            "V2.3: added the browse feature where you can select specific days by scrolling through years and months. Makes the search feature more approachable - 07/06/2025"};
    for (int i = 0; i < patch.size(); ++i)
    {
        cout << patch[i] << endl
             << endl;
    }
    system("pause");
    home();
}

void exit()
{
    cout << "Exiting..." << endl;
    encrypt_decrypt_images("E:/minecheck/images");
    exit(0);
}

void boot()
{

    std::string welcomeFrames[] = {
        R"(
 /$$      /$$           /$$                                            
| $$  /$ | $$          | $$                                            
| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ 
| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$
| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \ $$| $$ \ $$ \ $$| $$$$$$$$
| $$$/ \  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/
| $$/   \  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$
|__/     \__/ \_______/|__/ \_______/ \______/ |__/ |__/ |__/ \_______/
                                                                        )",
        R"(
 /$$      /$$           /$$                                                      
| $$  /$ | $$          | $$                                                      
| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$           
| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$          
| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \ $$| $$ \ $$ \ $$| $$$$$$$$          
| $$$/ \  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/          
| $$/   \  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$       /$$
|__/     \__/ \_______/|__/ \_______/ \______/ |__/ |__/ |__/ \_______/      |__/
                                                                                 
                                                                       )",
        R"(
 /$$      /$$           /$$                                                                      
| $$  /$ | $$          | $$                                                                      
| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$                           
| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$                          
| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \ $$| $$ \ $$ \ $$| $$$$$$$$                          
| $$$/ \  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/                          
| $$/   \  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$       /$$       /$$      
|__/     \__/ \_______/|__/ \_______/ \______/ |__/ |__/ |__/ \_______/      |__/      |__/
                                                                      )",
        R"(
 /$$      /$$           /$$                                                                          
| $$  /$ | $$          | $$                                                                          
| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$                               
| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$                              
| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  \ $$| $$ \ $$ \ $$| $$$$$$$$                              
| $$$/ \  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/                              
| $$/   \  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$       /$$       /$$       /$$
|__/     \__/ \_______/|__/ \_______/ \______/ |__/ |__/ |__/ \_______/      |__/      |__/      |__/
                                                                                                     
                                                                        )",
    };
    // sleep for 3 seconds
    for (int frame = 0; frame < 4; ++frame)
    {
        // Clear the screen
        system("cls");

        std::cout << welcomeFrames[frame] << std::endl;

        // Sleep for 1 second
        sleep(1);
        // std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    system("cls");

    home();
}

void home()
{
    string choice = displayMenu({"Archives", "Patch Notes", "Exit"});
    if (choice == "Archives")
    {
        system("cls");
        string choice = displayMenu({"Logger", "Read entries", "Images", "Back"});
        if (choice == "Logger")
        {
            system("cls");
            logger();
        }
        else if (choice == "Read entries")
        {
            system("cls");
            read();
        }
        else if (choice == "Images")
        {
            system("cls");
            images();
        }
        else if (choice == "Back")
        {
            home();
        }
    }
    else if (choice == "Arsenal")
    {
        system("cls");
        displayMenu({"Exit"});
        std::cin >> choice;
    }
    else if (choice == "Patch Notes")
    {
        patch();
    }
    else if (choice == "Exit")
    {
        system("cls");
        exit(0);
    }
}

int main()
{
    if (!check_password())
    {
        cout << "Incorrect password or Key drive not detected!" << endl;
        return 0;
    }
    system("cls");
    boot();

    return 0;
}
