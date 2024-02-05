// File Word Counter using 5 different data structures
// :)

#include <iostream>

#include "functions.h"
#include "UnsortedArray.cpp"
#include "SortedArray.cpp"
#include "BinaryTree.cpp"
#include "AVLtree.cpp"
#include "HashTable.cpp"

using namespace std;


int main()
{
    // data structures
    UnsortedArray a;
    SortedArray b;
    BinaryTree c;
    AVLtree d;
    HashTable e;

    // files to be used
    string filename = "small-file.txt"; // original file to be opened
    string filename2 = "simplified " + filename; // copy of original file in which the simplified words (neither punctuation nor uppercase) will be saved

    // open original file and create a simplified copy
    int lineCount = 0;
    if (!simplifiedCopyFile(filename, filename2))
    {
        return 1; // could not open file or could not create copy
    }


    // insert the data (from the simplified file, filename2) to each data-structure (a, b, c, d, e) and print the results to filename3
    //benchmarkInsertClock<UnsortedArray>(a, filename2);
    //benchmarkInsertClock<SortedArray>(b, filename2);
    benchmarkInsertClock<BinaryTree>(c, filename2);
    benchmarkInsertClock<AVLtree>(d, filename2);
    benchmarkInsertClock<HashTable>(e, filename2);


    // find 1000(=NUM_OF_TEST_SEARCHES) random words from the simplified file, not neccasarily different (the number of test searches is declared in functions.h header)
    string * randomWords;
    int wordCount = e.size;
    randomWords = randomWordsFromFile(randomWords, filename2, NUM_OF_TEST_SEARCHES, wordCount);

    // performs 1000 searches for each data structure (a, b, c, d, e), time results are also shows in filename3. 3rd argument is a bool whether or not to print the search results to terminal window
    cout << "Performing benchmark tests for "<< NUM_OF_TEST_SEARCHES << " words." << endl;
    //benchmarkSearchClock<UnsortedArray>(a, randomWords, false);
    //benchmarkSearchClock<SortedArray>(b, randomWords, false);
    benchmarkSearchClock<BinaryTree>(c, randomWords, false);
    benchmarkSearchClock<AVLtree>(d, randomWords, false);
    benchmarkSearchClock<HashTable>(e, randomWords, true);


    // finish
    cout << "-----------------" << endl;
    cout << "Program has successfully finished and will now terminate." << endl;
    return 0;
}
