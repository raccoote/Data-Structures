# Data Structures in C++
This C++ code implements a word counter program using five different data structures: UnsortedArray, SortedArray, BinaryTree, AVLtree, and HashTable. The purpose of the program seems to be to read a text file, create a simplified version of it by removing punctuation and converting all words to lowercase. The program aims to compare the performance of these data structures in terms of insertion and search operations.

Let's break down the main components of the code:

**1. Data Structures Initialization:**

```
UnsortedArray a;
SortedArray b;
BinaryTree c;
AVLtree d;
HashTable e;
```

The program initializes instances of five different data structures.

**2. File Handling:**

```
string filename = "small-file.txt"; // original file to be opened
string filename2 = "simplified " + filename; // copy of original file in which the simplified words (neither punctuation nor uppercase) will be saved
```

The code specifies the names of the original file (small-file.txt) and a simplified copy of the file. The simplified copy is expected to contain words without punctuation and in lowercase.

**3. File Copy and Word Simplification:**

```
int lineCount = 0;
if (!simplifiedCopyFile(filename, filename2))
{
    return 1; // could not open file or could not create copy
}
```

The program calls a function simplifiedCopyFile to create a simplified version of the original file. If the file operation fails, the program returns with an error code.

**4. Benchmarking Insertion:**

```
benchmarkInsertClock<BinaryTree>(c, filename2);
benchmarkInsertClock<AVLtree>(d, filename2);
benchmarkInsertClock<HashTable>(e, filename2);
```

The code benchmarks the insertion performance of the simplified words into each of the three data structures: BinaryTree, AVLtree, and HashTable.

**5. Random Word Selection:**


```
string * randomWords;
int wordCount = e.size;
randomWords = randomWordsFromFile(randomWords, filename2, NUM_OF_TEST_SEARCHES, wordCount);
```
The program selects a number of random words (specified by NUM_OF_TEST_SEARCHES) from the simplified file for later search operations.

**6. Benchmarking Search:**

```

cout << "Performing benchmark tests for "<< NUM_OF_TEST_SEARCHES << " words." << endl;
benchmarkSearchClock<BinaryTree>(c, randomWords, false);
benchmarkSearchClock<AVLtree>(d, randomWords, false);
benchmarkSearchClock<HashTable>(e, randomWords, true);
```
The code performs search operations for the selected random words on each data structure and prints the time taken for these operations. The last argument in the function calls determines whether or not to print the search results to the terminal window.

**7.Finish:**

```

cout << "-----------------" << endl;
cout << "Program has successfully finished and will now terminate." << endl;
return 0;
```
The program prints a termination message and exits with a return code of 0, indicating successful execution.
