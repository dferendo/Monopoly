//
// Created by dylan on 16/11/2016.
//

#ifndef MONOPOLY_MONOPOLY_H
#define MONOPOLY_MONOPOLY_H

#include <vector>

class Monopoly {

private:

    /**
     * Read a chapter from a UserManual.txt file. Chapters in the file are divided by
     * an empty line.
     * @param chapterNumber The number of chapter.
     */
    void readFromFile(int chapterNumber);
public:

    /**
     * Starts the Game. User can use either start to game or read the user manual.
     */
    void start();

    /**
     * Play the monopoly game.
     */
    void play();

    /**
     * Read the user manual with the assumptions made.
     */
    void userManual();
};
#endif //MONOPOLY_MONOPOLY_H
