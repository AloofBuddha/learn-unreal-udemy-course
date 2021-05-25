#include <iostream>
#include <ctime>

#define DEBUG true

void PrintIntroduction(int Difficulty) 
{
    std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room...\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers in the code\n";
    if (DEBUG)
    {
        std::cout << "The three numbers are: " << CodeA << ", " << CodeB << ", " << CodeC << std::endl;
    }
    std::cout << "+ The codes add up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    // store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You guessed correctly! Moving to the next level!\n\n";
        return true;
    }
    else
    {
        std::cout << "You guessed incorrectly! But good news, you can try again!\n\n";
        return false;
    }
}

int main()
{
    // seed rand with the current unix time
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer

        if (bLevelComplete)
        {
            // TODO increase level difficulty
            LevelDifficulty++;
        }
    }

    std::cout << "You beat the game! Congratulations!" << std::endl;

    return 0;
}