#pragma once

#include <QWidget>
#include <QPushButton>

class Cell : public QPushButton {
  Q_OBJECT
private:
  int x_axis;
  int y_axis;

public:
  Cell(int x, int y, const QString &text, QWidget* parent = 0);
};

class TicTacToe : public QWidget {
  Q_OBJECT
private:
  int n_move;
  Cell** buttons;
  Cell* createButton(int x, int y);
  void checkEnd();
  void endGame(const QString &text);

public:
  TicTacToe(QWidget* pwgt=0);

public slots:
  void slotButtonClicked();
};
