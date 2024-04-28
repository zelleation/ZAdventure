#include "homewindow.h"
#include "ui_homewindow.h"
#include "choicebutton.h"
#include <QTimer>
#include <QLabel>

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomeWindow)
{
    ui->setupUi(this);
    this->setFixedSize(64*18,64*9);
    this->setWindowIcon(QIcon(":/user/rsc/user/user_stand.png"));

    levelsWindow = new LevelsWindow;
    connect(levelsWindow,&LevelsWindow::return_to_homewindow,this,[=](){

        QTimer::singleShot(360,this,[=](){
            levelsWindow->hide();
            this->show();
        });

    });
    ChoiceButton * startBtn = new ChoiceButton(":/icon/rsc/Menu/Buttons/Play.png");
    startBtn->setParent(this);
    startBtn->move(64*8,64*7);
    connect(startBtn,&ChoiceButton::clicked,[=](){
        qDebug()<<"startBtn clicked";
        startBtn->move_down();
        startBtn->move_up();

    });

    ChoiceButton * levelsBtn = new ChoiceButton(":/icon/rsc/Menu/Buttons/Levels.png");
    levelsBtn->setParent(this);
    levelsBtn->move(64*9,64*7);
    connect(levelsBtn,&ChoiceButton::clicked,[=](){
        qDebug()<<"levelsBtn clicked";
        levelsBtn->move_down();
        levelsBtn->move_up();

        QTimer::singleShot(360,this,[=](){
            this->hide();
            levelsWindow->show();
        });

    });

    ChoiceButton * achievementBtn = new ChoiceButton(":/icon/rsc/Menu/Buttons/Achievements.png");
    achievementBtn->setParent(this);
    achievementBtn->move(64*10,64*7);
    connect(achievementBtn,&ChoiceButton::clicked,[=](){
        qDebug()<<"achievementBtn clicked";
        achievementBtn->move_down();
        achievementBtn->move_up();

    });

    ChoiceButton * soundBtn = new ChoiceButton(":/icon/rsc/Menu/Buttons/Volume.png",":/icon/rsc/Menu/Buttons/No_volume.png");
    soundBtn->setParent(this);
    soundBtn->move(64*17+16,64*8+32);
    connect(soundBtn,&ChoiceButton::clicked,[=](){
        qDebug()<<"soundBtn clicked";
        soundBtn->changeImg();
    });


    ChoiceButton * settingsBtn = new ChoiceButton(":/icon/rsc/Menu/Buttons/Settings.png");
    settingsBtn->setParent(this);
    settingsBtn->move(64*16+16,64*8+32);
    connect(settingsBtn,&ChoiceButton::clicked,[=](){
        qDebug()<<"settingsBtn clicked";

        settingsBtn->move_down();
        settingsBtn->move_up();
    });
}

void HomeWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/background/rsc/Background/background_yellow.png");
    painter.drawPixmap(0,0,pix);
    QPixmap pix_text;
    pix_text.load(":/text/rsc/text/title.png");
    painter.drawPixmap(64*4,64*1,pix_text);
    QPixmap pix_img;
    pix_img.load(":/background/rsc/Background/HomeAnimation.png");
    painter.drawPixmap(64*4,64*3,pix_img);

}

HomeWindow::~HomeWindow()
{
    delete ui;
}
