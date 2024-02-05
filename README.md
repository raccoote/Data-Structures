# File Word Counter in C++
This C++ program is designed to analyze and benchmark the performance of five different data structures—UnsortedArray, SortedArray, BinaryTree, AVLtree, and HashTable—in handling text data. The program begins by simplifying a given text file, converting it to lowercase and removing unwanted characters(e.g. punctuation), thereby creating a clean version for subsequent operations. It then conducts benchmark tests on each data structure, focusing on insertion and search operations. For insertion, the program reads the simplified file and inserts words into each data structure, measuring the time taken for the process. The search benchmark involves randomly selecting words from the simplified file and searching for them within each data structure. The results, including search times and the number of occurrences, are printed to the console and an output file. This approach provides insights into the efficiency of different data structures for word insertion and retrieval, aiding in the evaluation of their performance characteristics in handling large textual datasets.

Let's break down the main components of the code:

**1. Data Structures Initialization:**

```c
UnsortedArray a;
SortedArray b;
BinaryTree c;
AVLtree d;
HashTable e;
```

The program initializes instances of five different data structures.

**2. File Handling:**

```c
string filename = "small-file.txt"; // original file to be opened
string filename2 = "simplified " + filename; // copy of original file in which the simplified words (neither punctuation nor uppercase) will be saved
```

The code specifies the names of the original file (small-file.txt) and a simplified copy of the file. The simplified copy is expected to contain words without punctuation and in lowercase.

**3. File Copy and Word Simplification:**

```c
int lineCount = 0;
if (!simplifiedCopyFile(filename, filename2))
{
    return 1; // could not open file or could not create copy
}
```

The program calls a function simplifiedCopyFile to create a simplified version of the original file. If the file operation fails, the program returns with an error code.

**4. Benchmarking Insertion:**

```c
benchmarkInsertClock<BinaryTree>(c, filename2);
benchmarkInsertClock<AVLtree>(d, filename2);
benchmarkInsertClock<HashTable>(e, filename2);
```

The code benchmarks the insertion performance of the simplified words into each of the three data structures: BinaryTree, AVLtree, and HashTable.

**5. Random Word Selection:**


```c
string * randomWords;
int wordCount = e.size;
randomWords = randomWordsFromFile(randomWords, filename2, NUM_OF_TEST_SEARCHES, wordCount);
```
The program selects a number of random words (specified by NUM_OF_TEST_SEARCHES) from the simplified file for later search operations.

**6. Benchmarking Search:**

```c

cout << "Performing benchmark tests for "<< NUM_OF_TEST_SEARCHES << " words." << endl;
benchmarkSearchClock<BinaryTree>(c, randomWords, false);
benchmarkSearchClock<AVLtree>(d, randomWords, false);
benchmarkSearchClock<HashTable>(e, randomWords, true);
```
The code performs search operations for the selected random words on each data structure and prints the time taken for these operations. The last argument in the function calls determines whether or not to print the search results to the terminal window.

**7.Finish:**

```c
cout << "-----------------" << endl;
cout << "Program has successfully finished and will now terminate." << endl;
return 0;
```
The program prints a termination message and exits with a return code of 0, indicating successful execution.

**8.Finish:**

Displayed are the outcomes of the code tested on a modest file comprising 32,000 lines, which appear both in terminal and in an outcome file. It's noteworthy that conducting tests on more substantial files (exceeding 2 GB) would yield more pronounced effects on the execution times and disparities among the various data structures.

![image](https://github.com/raccoote/Data-Structures/assets/74006924/5267962c-3cec-4c1d-877d-1455228b8cf5)

![image](https://github.com/raccoote/Data-Structures/assets/74006924/2efce202-b1a3-4b38-a759-547b5ee8748b)


