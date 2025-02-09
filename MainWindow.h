#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDateEdit>
#include <QRadioButton>
#include <QTextEdit>
#include <QMessageBox>
#include <QGroupBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QDialog>
#include <Generator.h>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * @brief setCode
     */
    void setCode();

public slots:
    /**
     * @brief nameToConstructLabel
     * @param nameValue
     */
    void nameToConstructLabel(QString nameValue);

    /**
     * @brief displayConstructLabel
     */
    void displayConstructLabel();

    /**
     * @brief displayDestructLabel
     */
    void displayDestructLabel();

    /**
     * @brief openClassGenerator
     */
    void openClassGenerator();

private:
    QLineEdit       *_nameLine, *_parentLine, *_authorLine;
    QTextEdit       *_briefText;
    QDateEdit       *_date;
    QPushButton     *_generateBtn, *_quitBtn;
    QRadioButton    *_ifndefineRadio, *_pragmaOnceRadio;
    QCheckBox       *_constructCheck, *_destructCheck;
    QLabel          *_constructLabel, *_destructLabel;
    QString         _codeString;

    QVBoxLayout     *_mainVBox, *_attributeVBox, *_optionVBox;
    QHBoxLayout     *_protectHBox, *_buttonHBox;
    QGroupBox       *_defGroup, *_optionGroup, *_commentGroup;
    QFormLayout     *_defForm, *_optionForm, *_commentForm;

    Generator       *_generatorWindow;
};
