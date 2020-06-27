#include <NumberGuesser101.h>

int main()
{
    isGameOver = false;
    max = 50;
    maxLives = 5;
    lives = maxLives;
    StartNewGame();
}

void StartNewGame()
{
    std::cout << "Welcome to Number Guesser 101\n";
    std::cout << "I am thinking of a number between 1 and " << max << "... Can you guess what it is?\n";
    SetAnswer();
    Play();
    if (isGameOver) {
        PlayAgain();
    }
}

void SetAnswer()
{
    srand((unsigned)time(0));
    answer = rand() % max + 1;
}

void Play()
{
    std::cout << "Lives: " << lives << std::endl;
    int guess = GetPlayerGuess();
    CheckAnswer(guess);
}

int GetPlayerGuess()
{
    std::cout << "Enter a guess: ";
    int playerGuess;
    try {
        std::string playerInput;
        std::cin >> playerInput;
        playerGuess = std::stoi(playerInput);
    }
    catch(std::exception e) {
        std::cout << "Come on now... ";
        playerGuess = 0;
    }
    return playerGuess;
}

void CheckAnswer(const int& guess)
{
    std::cout << "You guessed " << guess << std::endl;
    if (guess == answer)
    {
        std::cout << "YOU WIN!\n";
        isGameOver = true;
        return;
    }
    else if (guess > answer)
    {
        std::cout << "Too high!\n";
    }
    else
    {
        std::cout << "Too low!\n";
    }
    --lives;

    if (lives == 0)
    {
        GameOver();
    }
    else
    {
        Play();
    }
}

void GameOver()
{
    std::cout << "You are out of lives! GAME OVER\n";
    isGameOver = true;
}

void PlayAgain()
{
    std::string c;
    do {
        std::cout << "Play again? (y/n) ";
        std::cin >> c;
    } while (c != "y" && c != "n");

    if (c == "y")
    {
        lives = maxLives;
        system("CLS");
        StartNewGame();
    }
    else if (c == "n")
    {
        std::cout << c;
        std::cout << "Goodbye!\n";
    }
}
