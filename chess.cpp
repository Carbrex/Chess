#include "pieces.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

void DisplayBoard()
{
    cout << "\033[2J\033[1;1H";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != 0)
            {
                cout << setw(3) << board[i][j]->getname() << ((board[i][j]->getcolor())?'w':'b');
            }
            else
            {
                cout<<setw(4)<<0;
            }
            
        }
        cout << endl;
    }
}

bool move(int a[4])
{
    if (board[a[0]][a[1]]!=0)
    {
        board[a[0]][a[1]]->move({a[2],a[3]});
    }
    return 0;
}

int main()
{
    cout << "Hello World\n";
    pawn wpawn[] = {pawn(1, 0), pawn(1, 1), pawn(1, 2), pawn(1, 3), pawn(1, 4), pawn(1, 5), pawn(1, 6), pawn(1, 7)};
    pawn bpawn[] = {pawn(0, 0), pawn(0, 1), pawn(0, 2), pawn(0, 3), pawn(0, 4), pawn(0, 5), pawn(0, 6), pawn(0, 7)};
    queen bqueen(0), wqueen(1);
    king bking(0), wking(1);
    knight blknight(0, 1), brknight(0, 0), wlknight(1, 1), wrknight(1, 0);
    bishop blbishop(0, 1), brbishop(0, 0), wlbishop(1, 1), wrbishop(1, 0);
    rook blrook(0, 1), brrook(0, 0), wlrook(1, 1), wrrook(1, 0);
    DisplayBoard();
    bool n = 0;
    int a[4];
    do
    {
        cout << "Enter the position from which you want to move the piece : ";
        cin >> a[0] >> a[1];
        cin.clear();
        cout << "Enter the position where you want to move the piece : ";
        cin >> a[2] >> a[3];
        cin.clear();
        move(a);
        DisplayBoard();
        cout << "Do you want to make another move(0/1) : ";
        cin >> n;
        cin.clear();

    } while (n);

    return 0;
}

/**********************************************************************/
