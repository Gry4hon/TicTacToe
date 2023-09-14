#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

class CreatePlayer
{

private:
    string name;
    char playerCharacter;

public:
    CreatePlayer(string pName, char pChar)
    {
        name = pName;
        playerCharacter = pChar;
    }

    string getPlayerName()
    {
        return name;
    }

    char getPlayerChar()
    {
        return playerCharacter;
    }
};

class TicTacToeBoard
{
private:
    int winningCombos[8][3] = {
        // Horizontal
        {0, 2, 4},
        {5, 7, 9},
        {10, 12, 14},
        // Vertical
        {0, 5, 10},
        {2, 7, 12},
        {4, 9, 14},
        // across
        {0, 7, 14},
        {4, 7, 10}};
    int validPlays[9] = {0, 2, 4, 5, 7, 9, 10, 12, 14};


public:
    vector<char> gameTableRows = {
        '-', '|', '-', '|', '-',
        '-', '|', '-', '|', '-',
        '-', '|', '-', '|', '-'};

    void SetGameValue(int location, char theXorO)
    {
        gameTableRows.erase(gameTableRows.begin() + location);
        gameTableRows.insert(gameTableRows.begin() + location, theXorO);
        CheckGameBoardForWin(theXorO);
        ReCreateTable();
    }

    bool IsValidPlay(int numToCheck)
    {
        bool isValid = false;
        for (int i = 0; i < 9; i++)
        {
            if (numToCheck == validPlays[i])
            {
                isValid = true;
                break;
            }
        }

        return isValid;
    }

    char GetGameValue(int location)
    {
        return gameTableRows[location];
    }

    void ReCreateTable()
    {
        string gameTableDivider = "-----";

        for (int i = 0; i <= 15; i++)
        {
            if (i < 5)
            {
                cout << gameTableRows[i];
            }
            else if (i == 5)
            {
                cout << "\n";
                cout << gameTableDivider << "\n";
                cout << gameTableRows[i];
            }
            else if (i > 5 && i < 10)
            {
                cout << gameTableRows[i];
            }
            else if (i == 10)
            {
                cout << "\n";
                cout << gameTableDivider << "\n";
                cout << gameTableRows[i];
            }
            else if (i > 10 && i < 15)
            {
                cout << gameTableRows[i];
            }
            else if (i == 15)
            {
                cout << "\n";
            }
        }
    }

    void CheckGameBoardForWin(char playerChar)
    {
        for (int i = 0; i < 8; i++)
        {
            if (gameTableRows[winningCombos[i][0]] == playerChar &&
                gameTableRows[winningCombos[i][1]] == playerChar &&
                gameTableRows[winningCombos[i][2]] == playerChar)
            {
                cout << "\n";
                cout << "\n";
                cout << "***************************"
                     << "\n";
                cout << "Winner: " << playerChar << "\n";
                cout << "Won by having their " << playerChar << "'s in: "
                     << "\n";
                cout << "-" << winningCombos[i][0] << "\n";
                cout << "-" << winningCombos[i][1] << "\n";
                cout << "-" << winningCombos[i][2] << "\n";
                cout << "***************************"
                     << "\n";
                cout << "\n";
                exit(0);
            }
        }
    }
};

class TicTacToeGameMaster
{
private:
    TicTacToeBoard gameBoard;
    int numberOfPlayerTurns = 0;

public:
    void PlayerTurn(CreatePlayer player)
    {
            int playerLocationChoice;
            cout << player.getPlayerName() << " choose where to place your " << player.getPlayerChar() << ": ";
            cin >> playerLocationChoice;
            cout << "\n";
            gameBoard.SetGameValue(playerLocationChoice, player.getPlayerChar());
    }

    
};

int main()
{
    TicTacToeBoard gameBoard;
    TicTacToeGameMaster gameMaster;

    string playerOnesName;
    string playerTwosName;
    char choiceOfPlayerOne;
    char playerTwosChar;
    bool gameStarted = false;
    bool playerSelection = true;
    int playerTurn = 0;

    cout << "Welcome to tic tac toe!";
    cout << "\n";

    cout << "Please enter player one's name: ";
    cin >> playerOnesName;
    cout << "\n";

    cout << "Please enter player two's name: ";
    cin >> playerTwosName;
    cout << "\n";

    while (playerSelection)
    {
        cout << playerOnesName << " please select either x or o: ";
        cin >> choiceOfPlayerOne;
        cout << "\n";

        if (choiceOfPlayerOne == 'x')
        {
            playerTwosChar = 'o';
            playerSelection = false;
            gameStarted = true;
        }
        else if (choiceOfPlayerOne == 'o')
        {
            playerTwosChar = 'x';
            playerSelection = false;
            gameStarted = true;
        }
        else
        {
            cout << "\n";
            cout << "Thats not an x or o, please enter an x or an o and make sure caps lock is off :)"
                 << "\n";
            cout << "\n";
        }
    }

    CreatePlayer playerOne(playerOnesName, choiceOfPlayerOne);
    CreatePlayer playerTwo(playerTwosName, playerTwosChar);

    system("clear");

    while (gameStarted)
    {

        if (playerTurn % 2 == 0)
        {
            gameMaster.PlayerTurn(playerOne);
            playerTurn++;
        }
        else
        {
            gameMaster.PlayerTurn(playerTwo);
            playerTurn++;
        }
    }

    return 0;
}
