//
//  tictactoe.cpp
//  
//
//  Created by arvind sudarsanam on 2/12/15.
//
//

#include "tictactoe.h"

int main(void)
{
    tictactoe ttt;
    string s;
    cout << "RED vs BLACK\nRED starts first\n";
    cout << "entries are of the form i,j (1,1 <= i,j <= 3,3)\n";
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        while (1)
        {
            cout << "Entry for RED:";
            cin >> s;
            if (ttt.entryIntoBoxPos(s,RED))
            {
                if (ttt.findWinner() == RED)
                {
                    cout << "RED Wins!!!!!!\n And Game ends!!\n";
                    return 0;
                }
                break;
            }
        }
        ttt.print();
        if (i == 3)
        {
            cout << "It is a draw!!!!!!\n And Game ends!!";
            return 1;
        }
        while (1)
        {
            cout << "Entry for BLACK:";
            cin >> s;
            if (ttt.entryIntoBoxPos(s,BLACK))
            {
                if (ttt.findWinner() == BLACK)
                {
                    cout << "BLACK Wins!!!!!!\n And Game ends!!\n";
                    return 0;
                }
                break;
            }
        }
        ttt.print();
    }
    return 1;
}
