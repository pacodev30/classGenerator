#include "MainWindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // INIT WIDGETS
    _nameLine = new QLineEdit(this);
    _parentLine = new QLineEdit(this);
    _authorLine = new QLineEdit(this);
    _dateComment = new QDateEdit(QDate::currentDate(), this);
    _textComment = new QTextEdit(this);


    _ifndefine = new QRadioButton("ifndefine", this);
    _pragmaOnce = new QRadioButton("pragma once", this);
        _pragmaOnce->setChecked(true);

    _construct = new QCheckBox("Generate a default construct", this);
        _construct->setChecked(true);
    _destruct = new QCheckBox("Generate a destruct", this);

    _generateBtn = new QPushButton("Generate class", this);
        _generateBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    _quitBtn = new QPushButton("Quit", this);
        _quitBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // INIT LAYOUTS
    _mainVBox = new QVBoxLayout(this);

    _formDef = new QFormLayout(this);
    _formComment = new QFormLayout(this);
    _optionVBox = new QVBoxLayout(this);

    _groupDef = new QGroupBox("Class generator", this);

    _groupOption = new QGroupBox("Options", this);
    _groupComment = new QGroupBox("Comments", this);
    _groupComment->setCheckable(true);

    _protectHBox = new QHBoxLayout(this);
    _buttonHBox = new QHBoxLayout(this);
        _buttonHBox->setAlignment(Qt::AlignRight);

    // CONNECTS
    connect(_generateBtn, SIGNAL(clicked(bool)), this, SLOT(classGenerator()));
    connect(_quitBtn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

    // MANAGE LAYOUTS
    setLayout(_mainVBox);
        _mainVBox->addWidget(_groupDef);
            _groupDef->setLayout(_formDef);
                _formDef->addRow("Name *", _nameLine);
                _formDef->addRow("Parent class", _parentLine);

        _mainVBox->addWidget(_groupOption);
            _groupOption->setLayout(_optionVBox);
                _optionVBox->addLayout(_protectHBox);
                    _protectHBox->addWidget(_ifndefine);
                    _protectHBox->addWidget(_pragmaOnce);
                _optionVBox->addWidget(_construct);
                _optionVBox->addWidget(_destruct);

        _mainVBox->addWidget(_groupComment);
            _groupComment->setLayout(_formComment);
                _formComment->addRow("Author", _authorLine);
                _formComment->addRow("Date", _dateComment);
                _formComment->addRow("Description", _textComment);
            _mainVBox->addLayout(_buttonHBox);
                _buttonHBox->addWidget(_generateBtn);
                _buttonHBox->addWidget(_quitBtn);

}

MainWindow::~MainWindow() {}

void MainWindow::setCode()
{
    if(!_code.isEmpty())
        _code.clear();

    if(_ifndefine->isChecked()) {
        _code.append("#ifndef ");
        _code.append(_nameLine->text().toUpper());
        _code.append("_H \n");
        _code.append("#define ");
        _code.append(_nameLine->text().toUpper());
        _code.append("_H \n\n");
    }
    else if(_pragmaOnce->isChecked()) {
        _code.append("# pragma once \n\n");
    }

    _code.append("class ");
    _code.append(_nameLine->text());

    if(!_parentLine->text().isEmpty())
    {
        _code.append(": public ");
        _code.append(_parentLine->text());
    }
    _code.append("\n{ \n public: \n\n private: \n\n}; \n");

    if(_ifndefine->isChecked())
    {
        _code.append("#endif");
    }

}

void MainWindow::classGenerator()
{
    if(_nameLine->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Name is empty");
        return;
    }
    MainWindow::setCode();
    _generatorWindow = new Generator(_code, this);
    _generatorWindow->exec();
}
