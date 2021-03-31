# fillit

![2021-03-19 14 02 32](https://user-images.githubusercontent.com/52679439/111863021-22bc8c80-8916-11eb-89b8-917c42d4b541.gif)


Fillit is a project who let you discover and/or familiarize yourself with a recurring problematic in programming : searching for the optimal solution among a huge set of pos- sibilities. In this particular project, you will be charged of creating an algorithm which fits some Tetriminos together into the smallest possible square.

A Tetriminos is a 4-blocks geometric figure that most of you might knows thanks to the popular game Tetris.
![Screen Shot 2021-03-02 at 12 23 00 AM](https://user-images.githubusercontent.com/52679439/109619422-9d4f7480-7aed-11eb-970c-9c9e65bc80d9.png)


Fillit does not consist of recoding Tetris, even if it’s still a variant of this game. Your program will take a file as parameter which contains a list of Tetriminos and arrange them to create the smallest square possible. Obviously, your main goal is to find this smallest square in the minimal amount of time, despite a exponentially growing number of possibilities each time a piece is added.
Then, you will have to think carefully about your data structures and your solving algorithm, if you want your program answers before the next millenium.

In this project, my roles were to verify and validate if the input had passed, saved the data that is read from the text file to the right data structure, prevent all possible error cases from happening and to free all the memory that were dynamically used during run time at the end.
Each input was composed of 16 ‘.’ characters, 4 ‘#’ characters and new line characters at the end of each line. Additionally, It should be composed by the Tetriminoes blocks and the maximum blocks should be within 25. If it’s not validate input, It returns an error and ends. To verify if it was a valid block was one of the hardest challenges. After writing a bunch of simulations, I came up with the idea to count the total number of side touches. Valid Tetriminoes blocks have a total of 6 sides touching between each block. Then I had to decide which data structure I should use. I tried with a 3d array and failed many times. Then I switched to ‘node linked list’ because it is easy to add new elements dynamically. I read the text file with the previous project ‘get_next_file’ and saved each line of block to 2d array.

Detailed description of this project written by [Beth Locke](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909)
