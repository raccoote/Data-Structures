# File Word Counter in C++
This C++ program is designed to analyze and benchmark the performance of five different data structures—UnsortedArray, SortedArray, BinaryTree, AVLtree, and HashTable—in handling text data. The program begins by simplifying a given text file, converting it to lowercase and removing unwanted characters(e.g. punctuation), thereby creating a clean version for subsequent operations. It then conducts benchmark tests on each data structure, focusing on insertion and search operations. For insertion, the program reads the simplified file and inserts words into each data structure, measuring the time taken for the process. The search benchmark involves randomly selecting words from the simplified file and searching for them within each data structure. The results, including search times and the number of occurrences, are printed to the console and an output file. This approach provides insights into the efficiency of different data structures for word insertion and retrieval, aiding in the evaluation of their performance characteristics in handling large textual datasets.


Displayed are the outcomes of the code tested on a modest file comprising 32,000 lines, which appear both in terminal and in an outcome file. It's noteworthy that conducting tests on more substantial files (exceeding 2 GB) would yield more pronounced effects on the execution times and disparities among the various data structures.

![image](https://github.com/raccoote/Data-Structures/assets/74006924/5267962c-3cec-4c1d-877d-1455228b8cf5)

![image](https://github.com/raccoote/Data-Structures/assets/74006924/2efce202-b1a3-4b38-a759-547b5ee8748b)


