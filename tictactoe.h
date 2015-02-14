//
//  tictactoe.h
//  
//
//  Created by arvind sudarsanam on 2/12/15.
//
//

#ifndef ____tictactoe__
#define ____tictactoe__

#include <iostream>
#include <map>

using namespace std;

typedef enum {EMPTY, RED, BLACK} box_entry;
class tictactoe
{
private:
    box_entry boxes[9];
    map<string, int> boxpos2index;
public:
    tictactoe()
    {
        for (int i = 0; i < 9; boxes[i++] = EMPTY);
        initBoxpos2Index();
    }
    void initBoxpos2Index(void)
    {
        boxpos2index["1,1"] = 0;
        boxpos2index["1,2"] = 1;
        boxpos2index["1,3"] = 2;
        boxpos2index["2,1"] = 3;
        boxpos2index["2,2"] = 4;
        boxpos2index["2,3"] = 5;
        boxpos2index["3,1"] = 6;
        boxpos2index["3,2"] = 7;
        boxpos2index["3,3"] = 8;
    }
    bool entryIntoBoxPos(const string &s, const box_entry &be)
    {
        int index = boxpos2index[s];
        if ((index < 0) || (index > 8))
        {
            cout << "Entry out of bounds\n";
            return false;
        }
        if (boxes[index] != EMPTY)
        {
            cout << "Box already filled\n";
            return false;
        }
        boxes[index] = be;
        return true;
    }
    box_entry findWinner(void)
    {
        string temp("");
        // check in rows
        for (int i = 0; i < 9; i++)
        {
            if (i%3 == 0)
                temp = temp + "x";
            if (boxes[i] == EMPTY)
                temp = temp + "e";
            else if (boxes[i] == RED)
                temp = temp + "r";
            else
                temp = temp + "b";
        }
        if (temp.find("rrr") != string::npos)
            return RED;
        if (temp.find("bbb") != string::npos)
            return BLACK;
        temp = "";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int k = i + j*3;
                if (k%3 == 0)
                    temp = temp + "x";
                if (boxes[k] == EMPTY)
                    temp = temp + "e";
                else if (boxes[k] == RED)
                    temp = temp + "r";
                else
                    temp = temp + "b";
            }
        }
        if (temp.find("rrr") != string::npos)
            return RED;
        if (temp.find("bbb") != string::npos)
            return BLACK;
        temp = "";
        // In diagonals
        for (int i = 0; i < 3; i++)
        {
            int k = i + i*3;
            if (k%3 == 0)
                temp = temp + "x";
            if (boxes[k] == EMPTY)
                temp = temp + "e";
            else if (boxes[k] == RED)
                temp = temp + "r";
            else
                temp = temp + "b";
        }
        
        if (temp.find("rrr") != string::npos)
            return RED;
        if (temp.find("bbb") != string::npos)
            return BLACK;
        temp = "";
        for (int i = 0; i < 3; i++)
        {
            int k = (2-i) + i*3;
            if (k%3 == 0)
                temp = temp + "x";
            if (boxes[k] == EMPTY)
                temp = temp + "e";
            else if (boxes[k] == RED)
                temp = temp + "r";
            else
                temp = temp + "b";
        }
        if (temp.find("rrr") != string::npos)
            return RED;
        if (temp.find("bbb") != string::npos)
            return BLACK;
        return EMPTY;
    }
    void print(void)
    {
        cout << "**********************\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int k = i + j*3;
                if (boxes[k] == EMPTY)
                    cout << " x ";
                else if (boxes[k] == RED)
                    cout << " R ";
                else
                    cout << " B ";
            }
            cout << "\n";
        }
        cout << "**********************\n";
    }
};

#endif /* defined(____tictactoe__) */
