#ifndef SCOREBOARD_CPP
#define SCOREBOARD_CPP

#include "ScoreBoard.h"

template<typename T>
ScoreBoard<T>::ScoreBoard() {}

template<typename T>
ScoreBoard<T>::~ScoreBoard() {}

template<typename T>
void ScoreBoard<T>::addScore(std::string user, T score) {
    if (scores.exists(user)){
        if (score > scores.at(user))
            scores.set(user,score);
        return;
    }
    scores.set(user,score);
}

template<typename T>
void ScoreBoard<T>::removeScore(std::string user) {
    scores.removeAt(user);
}

template<typename T>
T ScoreBoard<T>::getScore(std::string user) {
    return scores.at(user);
}

template<typename T>
T ScoreBoard<T>::getHighScore() {
    T highScore = T(); // Initialize to the default value of T

    std::string* temp = scores.getKeys();
    int size = scores.size();

    for (int i = 0; i < size; i++) {
        T currentScore = scores.at(temp[i]);
        if (currentScore > highScore) {
            highScore = currentScore;
        }
    }

    return highScore;
}


template<typename T>
Tuple<int, std::string*> ScoreBoard<T>::getHighScoreUser() {
    return scores.keysWithValue(getHighScore());
}

#endif