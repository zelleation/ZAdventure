#ifndef LEVELSWINDOW_H
#define LEVELSWINDOW_H

#include <QMainWindow>

class LevelsWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit LevelsWindow(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);



signals:
    void return_to_homewindow();
};

#endif // LEVELSWINDOW_H
