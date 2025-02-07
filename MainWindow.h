#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void classGenerator();

private:
    QLineEdit *_nameLine, *_parentLine, *_authorLine;
    QCheckBox *_protect, *_construct, *_destruct;
    QDateEdit *_dateComment;
    QTextEdit *_textComment;
    QPushButton *_generateBtn, *_quitBtn;


    QVBoxLayout *_mainVBox, *_attributeVBox, *_optionVBox;
    QHBoxLayout *_buttonHBox;
    QGroupBox *_groupDef, *_groupOption, *_groupComment;
    QFormLayout *_formDef, *_formComment;
};
