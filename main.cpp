#include <QApplication>
#include "TicTacToe.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    TicTacToe   tictactoe;

    tictactoe.setWindowTitle("Крестики-нолики");
    tictactoe.resize(120, 120);

    tictactoe.show();

    return app.exec();
}
