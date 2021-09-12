# cpp-cube
A 2D CLI rubix cube game, made as a personal project for an 'intro to programming for engineers' course.
The code is fully commented.

The program presents a randomized, solveable 2D map of a standard rubix cube. Input can be given in syntax consistent with existing web-apps. A high-score algorithm is provided which retrieves and stores persistent scores with user initials. The scoring algorithm is designed to reward low times and low number of moves, such that either strategy will yield a "good" score.

The "cube" is represented by an unfolded, flattened 2D array of character values, which represent the first letter of each color normally present on a standard Rubix cude.

![image](https://user-images.githubusercontent.com/90524106/132968070-6f4d6e38-3538-404c-a52b-9ce801e60ba9.png)

Function routines were made for each type of move. In the case of slices, those function calls perform multiple subroutines of simpler moves to complete the slice move.

The cube is initialized as solved. Randomization is performed by performing a random number (between 30-50) of random move function calls, using a switch statement. In this way the cube is always solveable, since it is randomized by legal moves.

Winning states are checked after each input loop. Each face center value is checked against the surrounding values. If the entire array passes this check, then a win scenario is confirmed and the main loop progresses to the high-score function call. This function records user input in a string, the user's initials, and stores it next to the corresponding high-score value in a text file adjacent to the program binary - "hs.txt".

The high-score is calculated using a formula that rewards both fast solutions and low move-count solutions. The formula used will reward very fast solves with scores approaching 1,000,000. Similarly, very low move-count scores will also approach 1,000,000. Additionally, even very slow and high move-count wins will result in a non-zero score. This high-score system is intended to provide novice-users with a sense of progression, and high skill-level users may enjoy the scoring system as well.

It is also possible to uncomment a section of code that attempts to automatically solve the cube by performing the randomization function call until the cube passes the validation check. This method has never been successful in testing, even after being performed for 2.4e7 iterations. This section of code could also be modified to perform single, randomized moves between each validation check, rather than the entire randomization function.

Completed in spring 2021.
