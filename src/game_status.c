#include "game_status.h"

bool has_win(int board[4][4], int target)
{
    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        for (size_t j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == target)
                return true;
        }
    }
    return false;
}

// Check for lose status 
bool has_valid_move(int board[4][4])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0)
                return true;
            if (j + 1 < BOARD_SIZE)
            {
                if (board[i][j+1] == 0 || board[i][j] == board[i][j+1])
                    return true;
            }
            if (i + 1 < BOARD_SIZE)
            {
                if (board[i+1][j] == 0 || board[i][j] == board[i+1][j])
                    return true;
            }
        }
    }
    return false;
}
