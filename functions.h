#include <iostream>
#include <fstream> // file handling
#include <string.h>
#include <ctype.h> // isalpha (for simplify function)
#include <stdlib.h> // srand, rand
#include <time.h>
using namespace std;


#define NUM_OF_TEST_SEARCHES 1000 // how many random word searches will be executed in the end
const string filename3 = "general-stats.txt"; // file where general info and benchmark clock times of each data structure are stored (insertion and search times)

// converts string to lowercase and removes unwanted characters
string simplify(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        // if uppercase convert to lowercase (e.g. 'HeLLo' -> 'hello')
        if(str[i] >= 65 && str[i] <= 90)
        {
            str[i] = str[i] + 32;
        }
        // if it is a single dash in a word (e.g. 'life-changing')
        else if(str[i] == '-' && isalpha(str[i + 1]) && isalpha(str[i - 1]))
        {
            //do nothing
        }
        // if it is not a letter (e.g. '3: so--you were...' -> 'so you were')
        else if(!isalpha(str[i]))
        {
            str[i] = ' '; // remove it ( NOTE : basically turns it to spacebar character, which is later ignored because we use << operator to read file word by word)
        }
    }
    return str;
}

string * randomWordsFromFile(string * list, string filename, int n, int wordCount) // takes random n words from file and saves them to the list
{
    cout << "Fetching Random Words";
    srand(time(NULL)); // randomize seed
    int num;
    string word;
    list = new string[n];
    ifstream file;
    file.open(filename);
    int i = 0;
    while(i < n)
    {
        num = rand() % 100;

            if(file >> word)
            {
                if(num < 5) // 5 % probability to add word
                {
                    list[i] = word;
                    i++;
                }
            }
            else
            {
                file.close();
                file.open(filename);
                file >> list[i];
                i++;
            }
    }
    file.close();
    cout << " . . . DONE." << endl;
    return list;
}


//creates a copy of file but in a simplified form, meaning without any punctuation or uppercase letters (check simplify function above)
bool simplifiedCopyFile(string filename_original, string filename_copy)
{
    clock_t start;
    start = clock();
    long double duration;
    int lineCount = 0;
    string line;
    ifstream file;

    file.open(filename_original); // open original file in reading mode
    if(!file.is_open())
    {
        cout << "File error when opening file. Quitting . . ." << endl;
        return false;
    }

    ofstream simplified_file, output_file;
    simplified_file.open(filename_copy, ios::out | ios::trunc); // create a file in writing mode, if the file already exists overwrite it (trunc)
    output_file.open(filename3, ios::out | ios::trunc); // create output file
    if(!simplified_file.is_open() || !output_file.is_open())
    {
        cout << "File error when creating copy file. Quitting . . ." << endl;
        return false;
    }
    cout << "Creating a copy of " << filename_original;
    while(getline(file, line))  // get line from original file
    {
        line = simplify(line);  // remove things like punctuation and numbers from the line
        simplified_file << line << endl;  // insert the line to our copy file
        lineCount++;
        /*
        if(lineCount % 5000 == 0) //loading animation to reassure the user that our program has not crashed but is just processing the file

        {
            cout << " .";
        }
        */
    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << " DONE." << endl;
    cout << "Copied Original file and simplified it in " << duration << " secs." << endl;
    cout << "Total Lines : " << lineCount << endl; // print the total files
    output_file << "Copied Original file and simplified it in " << duration << " secs." << endl;
    output_file << "Total Lines : " << lineCount << endl;
    file.close();
    simplified_file.close();
    output_file.close();
    return true;
}


// inserts all words from file to database and prints the time needed in the output file
template <class X> void benchmarkInsertClock(X &database, string filename)
{
    ifstream file;
    file.open(filename, ios::in);
    clock_t start;
    long double duration;
    int wordCount = 0;
    string word;
    cout << "Creating Data Structure";
    start = clock();
    while(file >> word)
    {
        database.insert(word);
        wordCount++;
        /*
        if(wordCount % 10000 == 0) // loading animation to reassure the user that our program has not crashed but is just inserting the data (this can take long in big files)
        {
            cout << " .";
        }
        */
    }
    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << " DONE." << endl;
    cout << database <<" has been completed in "<< duration << " secs" << endl;
    ofstream output_file;
    output_file.open(filename3, ios::out | ios::app);
    output_file << database <<" has been completed in "<< duration << " secs" << endl;
    output_file.close();
    file.close();
}


// searches database for every item that exists in list and prints the time needed in the output file
template <class X> void benchmarkSearchClock(const X &database, string * list, bool printSearchResults)
{
    clock_t start;
    long double duration;
    start = clock();
    int times;

    for(int i = 0;i < NUM_OF_TEST_SEARCHES;i++)
    {
        times = database.search(list[i]);
        if (times == -1)
        {
            cout << "WORD '" << list [i] <<"' NOT FOUND!" << endl;
        }
        if(printSearchResults)
        {
            cout << list[i] << " -> " << times << endl;  // prints search results
        }
    }

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "-----------------" << endl;
    cout << database << " performed " << NUM_OF_TEST_SEARCHES <<" searches in "<< duration << " secs" << endl;
    ofstream output_file;
    output_file.open(filename3, ios::out | ios::app);
    output_file << "-----------------" << endl;
    output_file  << database << " performed " << NUM_OF_TEST_SEARCHES <<" searches in "<< duration << " secs" << endl;
    output_file.close();
}
