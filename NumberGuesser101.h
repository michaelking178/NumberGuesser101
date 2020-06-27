#pragma once

#include <iostream>
#include <ctime>
#include <string>

void StartNewGame();
void SetAnswer();
int GetPlayerGuess();
void CheckAnswer(const int& guess);
void Play();
void GameOver();
void PlayAgain();

int maxLives;
int lives;
int max;
int answer;
bool isGameOver;