#include <QtWidgets>
#include "TicTacToe.h"
#include <QtCore>


Cell::Cell(int x, int y, const QString &text, QWidget* parent):
                                                QPushButton(text, parent),
                                                x_axis(x),
                                                y_axis(y) {}

TicTacToe::TicTacToe(QWidget* pwgt): QWidget(pwgt) {
        n_move = 1;
        buttons = new Cell*[9];
        QGridLayout* layout = new QGridLayout();
        layout->setSpacing(0);
        layout->setMargin(0);

        for (int i=0;i<3;i++) {
                for (int j=0;j<3;j++) {
                        Cell* btn = createButton(i, j);
                        layout->addWidget(btn, i, j);
                        buttons[i*3+j] = btn;
                }
        }
        setLayout(layout);
}

Cell* TicTacToe::createButton(int x, int y) {
        Cell* btn = new Cell(x, y, "");
        btn->setMinimumSize(40, 40);
        connect(btn, SIGNAL(clicked()), SLOT(slotButtonClicked()));
        return btn;
}

void TicTacToe::slotButtonClicked() {
        // Объявить указатель на кнопку(Cell), взять ее из sender()
        // использовать этот указатель в условиях
        if (n_move%2==1 && ((Cell*)sender())->text()=="") {
                n_move++;
                ((Cell*)sender())->setText("X");
        } else if (n_move%2==0 && ((Cell*)sender())->text()=="") {
                n_move++;
                ((Cell*)sender())->setText("O");
        }

        checkEnd();
}

void TicTacToe::checkEnd() {
        int WINS[8][3] = {{0, 1, 2},
                         {3, 4, 5},
                         {6, 7, 8},
                         {0, 3, 6},
                         {1, 4, 7},
                         {2, 5, 8},
                         {0, 4, 8},
                         {2, 4, 6}};

        for (int i=0;i<8;i++) {
                if ((buttons[WINS[i][0]]->text() == buttons[WINS[i][1]]->text()) &&
                    (buttons[WINS[i][0]]->text() == buttons[WINS[i][2]]->text()) &&
                    (buttons[WINS[i][0]]->text() != "")) {
                            endGame(buttons[WINS[i][0]]->text());
                            return;
                    }
        }
}

void TicTacToe::endGame(const QString &text) {
        qDebug() << "Конец игры. Выиграл " << text;
        for (int i=0;i<9;i++) {
                buttons[i]->setText("");
        }
        n_move = 1;
}
