#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDialog>
#include <QMessageBox>
#include <Generator.h>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setCode();

public slots:
    void classGenerator();

private:
    QLineEdit *_nameLine, *_parentLine, *_authorLine;
    QRadioButton *_ifndefine, *_pragmaOnce;
    QCheckBox *_construct, *_destruct;
    QDateEdit *_dateComment;
    QTextEdit *_textComment;
    QPushButton *_generateBtn, *_quitBtn;
    QString _code;


    QVBoxLayout *_mainVBox, *_attributeVBox, *_optionVBox;
    QHBoxLayout *_protectHBox, *_buttonHBox;
    QGroupBox *_groupDef, *_groupOption, *_groupComment;
    QFormLayout *_formDef, *_formComment;

    Generator *_generatorWindow;
};
