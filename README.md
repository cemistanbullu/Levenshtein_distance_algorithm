# Plagiarism Calculation
![plagiarism-detection-mechanism](https://user-images.githubusercontent.com/31565915/107192886-40d1cb80-69ff-11eb-9bb6-2cb8cb06b558.jpg)

### Aim:
###### Main goal is calculating the similarity rate beetween uploaded files and main file. At the end you get percentage rate and top 5 similar sentences between txt files.

##### The program is based on the levenshtein distance algorithm. 
### Features:
- You can compare how many files you want. There is no specific limitation. 
- After the comparison you get similarity rate. 
- It prints top 5 similar sentences.

### Steps:
1. Calculating the similarity ratio between two strings using the levensthein distance algorithm.
2. To keep the distances, a two dimensional matrix of the size of the two strings is created and all elements set to 0 at the beginning.
3. Both strings are filled on their own sides. i.e. first row and first column.
4. The operations of delete, add, subtract by navigating all elements are calculated and 1 is added if two characters are not equal.
5. The minimum answer is chosen.
6. Calculation of the similarity rate: length of longest string - difference / length of longest string.
7. The number of files to be compared is entered and the files are entered sequentially.
8. Main file is entered and divided into sentences.
9. The compared files are read and their similarities are calculated. A vector to store these raitos is created. Sentences are compared with the main file. 
10. Top 5 similar sentences are printed to the screen.
