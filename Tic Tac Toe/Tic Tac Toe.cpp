//Sebastian Diaz
//GAME-2303 2001

#include <iostream>
#include <sstream>

using namespace std;

class TicTacToe
{
public:
    // TTT board, empty by default
    char board[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // used for keeping track what's in each space, and what value each player has
    enum Entry
    {
        EMPTY = ' ',
        PLAYER_ONE = 'x',
        PLAYER_TWO = 'o'
    };

    // has the board been completely filled?
    bool isFull()
    {
        bool result = true;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == Entry::EMPTY)
                    result = false;
            }
        }

        return result;
    }

    // is a corner empty
    bool emptyCorner()
    {
        if (board[0][0] == EMPTY || board[0][2] == EMPTY || board[2][0] == EMPTY || board[2][2] == EMPTY)
        {
            return true;
        }
        else { return false; }
    }

    // choose a random open corner
    string chooseCorner()
    {
        int open = 0;
        string result = "";
        int num;

        if (board[0][0] == EMPTY) { open++; }
        if (board[0][2] == EMPTY) { open++; }
        if (board[2][0] == EMPTY) { open++; }
        if (board[2][2] == EMPTY) { open++; }

        if (open == 1)
        {
            if (board[0][0] == EMPTY) { result = "00"; }
            else if (board[0][2] == EMPTY) { result = "02"; }
            else if (board[2][0] == EMPTY) { result = "20"; }
            else if (board[2][2] == EMPTY) { result = "22"; }

        }
        else if (open == 2)
        {
            num = rand() % 2 + 1;
        }
        else if (open == 3)
        {
            num = rand() % 3;
        }
        else if (open == 4)
        {
            num = rand() % 4;
        }

        if (result == "")
        {
            if (board[0][0] == EMPTY) { if (num-- == 1) { result = "00"; } }
            if (board[0][2] == EMPTY) { if (num-- == 1) { result = "02"; } }
            if (board[2][0] == EMPTY) { if (num-- == 1) { result = "20"; } }
            if (board[2][2] == EMPTY) { if (num-- == 1) { result = "22"; } }
        }
        
        return result;
    }

    // will someone win?
    string willWin(Entry e)
    {
        int filled = 0;

        // first col
        if (board[0][0] == (char)e) { filled++; }
        if (board[0][1] == (char)e) { filled++; }
        if (board[0][2] == (char)e) { filled++; }

        if (filled == 2)
        {

            if (board[0][0] == Entry::EMPTY) { return "00"; }
            if (board[0][1] == Entry::EMPTY) { return "01"; }
            if (board[0][2] == Entry::EMPTY) { return "02"; }
        }

        filled = 0;

        // second col
        if (board[1][0] == (char)e) { filled++; }
        if (board[1][1] == (char)e) { filled++; }
        if (board[1][2] == (char)e) { filled++; }

        if (filled == 2)
        {

            if (board[1][0] == Entry::EMPTY) { return "10"; }
            if (board[1][1] == Entry::EMPTY) { return "11"; }
            if (board[1][2] == Entry::EMPTY) { return "12"; }
        }

        filled = 0;

        // third col
        if (board[2][0] == (char)e) { filled++; }
        if (board[2][1] == (char)e) { filled++; }
        if (board[2][2] == (char)e) { filled++; }

        if (filled == 2)
        {

            if (board[2][0] == Entry::EMPTY) { return "20"; }
            if (board[2][1] == Entry::EMPTY) { return "21"; }
            if (board[2][2] == Entry::EMPTY) { return "22"; }
        }

        filled = 0;

        // first row
        if (board[0][0] == (char)e) { filled++; }
        if (board[1][0] == (char)e) { filled++; }
        if (board[2][0] == (char)e) { filled++; }

        if (filled == 2)
        {

            if (board[0][0] == Entry::EMPTY) { return "00"; }
            if (board[1][0] == Entry::EMPTY) { return "10"; }
            if (board[2][0] == Entry::EMPTY) { return "20"; }
        }

        filled = 0;

        // second row
        if (board[0][1] == (char)e) { filled++; }
        if (board[1][1] == (char)e) { filled++; }
        if (board[2][1] == (char)e) { filled++; }

        if (filled == 2)
        {

            if (board[0][1] == Entry::EMPTY) { return "01"; }
            if (board[1][1] == Entry::EMPTY) { return "11"; }
            if (board[2][1] == Entry::EMPTY) { return "21"; }

        }

        filled = 0;

        // third row
        if (board[0][2] == (char)e) { filled++; }
        if (board[1][2] == (char)e) { filled++; }
        if (board[2][2] == (char)e) { filled++; }

        if (filled == 2)
        {

            if (board[0][2] == Entry::EMPTY) { return "02"; }
            if (board[1][2] == Entry::EMPTY) { return "12"; }
            if (board[2][2] == Entry::EMPTY) { return "22"; }
        }

        filled = 0;

        // diagonal 1
        if (board[0][0] == (char)e) { filled++; }
        if (board[1][1] == (char)e) { filled++; }
        if (board[2][2] == (char)e) { filled++; }

        if (filled == 2)
        {

            if (board[0][0] == Entry::EMPTY) { return "00"; }
            if (board[1][1] == Entry::EMPTY) { return "11"; }
            if (board[2][2] == Entry::EMPTY) { return "22"; }
        }

        filled = 0;

        // diagonal 2
        if (board[0][2] == (char)e) { filled++; }
        if (board[1][1] == (char)e) { filled++; }
        if (board[2][0] == (char)e) { filled++; }

        if (filled == 2)
        {

            if (board[0][2] == Entry::EMPTY) { return "02"; }
            if (board[1][1] == Entry::EMPTY) { return "11"; }
            if (board[2][0] == Entry::EMPTY) { return "20"; }
        }

        return "Empty";
    }

    // has someone won?
    bool isVictory(Entry e)
    {

        // first col
        if (board[0][0] == (char)e && board[0][1] == (char)e && board[0][2] == (char)e)
        {
            return true;
        }

        // second col
        else if (board[1][0] == (char)e && board[1][1] == (char)e && board[1][2] == (char)e)
        {
            return true;
        }

        // third col
        else if (board[2][0] == (char)e && board[2][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // first row
        else if (board[0][0] == (char)e && board[1][0] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        // second row
        else if (board[0][1] == (char)e && board[1][1] == (char)e && board[2][1] == (char)e)
        {
            return true;
        }

        // third row
        else if (board[0][2] == (char)e && board[1][2] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 1
        else if (board[0][0] == (char)e && board[1][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 2
        else if (board[0][2] == (char)e && board[1][1] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        return false;
    }

    // return size of the board; mostly just in case I wanted to make the board expandable
    int getSize()
    {
        return 3;
    }


    void dump()
    {
        cout << "----------------------------------------" << endl << endl;
        for (int i = 0; i < getSize(); i++)
        {
            for (int j = 0; j < getSize(); j++)
            {
                cout << " | " << board[i][j] << " | ";
            }

            cout << endl;
        }
        cout << "----------------------------------------" << endl << endl;
    }

};

static bool getHumanMove(int maxValue, TicTacToe::Entry human, TicTacToe& t)
{
    // check if player is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    int rowChoice = 0;
    int colChoice = 0;

    do {

        do {

            cout << "Enter column number (x) : 0 ... 2 : ";
            cin >> colChoice;
            cout << endl;

        } while (colChoice > maxValue || colChoice < 0);

        do {

            cout << "Enter row number (y) : 0 ... 2 : ";
            cin >> rowChoice;
            cout << endl;

        } while (rowChoice > maxValue || rowChoice < 0);


        if (t.board[rowChoice][colChoice] == t.EMPTY)
        {
            t.board[rowChoice][colChoice] = (char)human;

            return false;
        }

        else
        {
            cout << "Not a valid option! Please try again..." << endl;
        }


    } while (t.board[rowChoice][colChoice] != t.EMPTY);

    // move complete
    return false;
}

static bool getComputerMove(TicTacToe::Entry computer, TicTacToe& t)
{
    // check if computer is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    // handle computer's move

    int rowChoice = 0;
    int colChoice = 0;

    string computerWin = t.willWin(t.PLAYER_TWO);
    string humanWin = t.willWin(t.PLAYER_ONE);
    string computerCorner = t.chooseCorner();

    if (computerWin != "Empty")
    {
        rowChoice = stoi(computerWin.substr(0, 1));
        colChoice = stoi(computerWin.substr(1, 1));
    }
    else if (humanWin != "Empty")
    {
        rowChoice = stoi(humanWin.substr(0, 1));
        colChoice = stoi(humanWin.substr(1, 1));
    }
    else if (t.board[1][1] == t.EMPTY)
    {
        rowChoice = 1;
        colChoice = 1;

    }
    else if (t.emptyCorner())
    {
        rowChoice = stoi(computerCorner.substr(0, 1));
        colChoice = stoi(computerCorner.substr(1, 1));
    }
    else
    {
        do {

            // choose at random until we find a space that's empty
            do {

                rowChoice = rand() % ((t.getSize() - 0) + 1) + 0;

            } while (rowChoice > t.getSize() || rowChoice < 0);

            do {

                colChoice = rand() % ((t.getSize() - 0) + 1) + 0;

            } while (colChoice > t.getSize() || colChoice < 0);


            if (t.board[rowChoice][colChoice] == t.EMPTY)
            {
                t.board[rowChoice][colChoice] = (char)computer;

                return false;
            }

            else
            {
                //cout << "Not a valid option! Please try again..." << endl;
            }


        } while (t.board[rowChoice][colChoice] != t.EMPTY);
    }

    cout << "Column: " << colChoice << endl;
    cout << "Row: " << rowChoice << endl;
    
    // record move
    t.board[rowChoice][colChoice] = (char)computer;

    // move complete
    return false;
}

// ----------------------------
// main
// ----------------------------

int main()
{
    TicTacToe t;
    TicTacToe::Entry human = TicTacToe::PLAYER_ONE;
    TicTacToe::Entry computer = TicTacToe::PLAYER_TWO;

    int maxValue = t.getSize();

    cout << "----------------------------------------" << endl;

    cout << "You are '" << (char)human << "', " <<
        "the computer is: '" << (char)computer << "'" << endl;

    cout << "----------------------------------------" << endl << endl;

    // run the game until one player isn't able to go again
    do
    {
        // show board
        t.dump();
    } while (!getHumanMove(maxValue, human, t) && !getComputerMove(computer, t));


    t.dump();

    cout << endl;

    if (t.isVictory(human))
        cout << "Human Victory" << endl;

    else if (t.isVictory(computer))
        cout << "Computer Victory" << endl;

    else if (t.isFull())
        cout << "Tie" << endl;

    return(0);
}





