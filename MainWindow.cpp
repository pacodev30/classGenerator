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

    _protect = new QCheckBox("#ifndef", this);
        _protect->setChecked(true);
    _construct = new QCheckBox("Generate a default construct", this);
        _construct->setChecked(true);
    _destruct = new QCheckBox("Generate a destruct", this);

    _generateBtn = new QPushButton("Generate class", this);
        _generateBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    _quitBtn = new QPushButton("Quit", this);
        _quitBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // INIT LAYOUTS
    _mainVBox = new QVBoxLayout(this);
    _groupDef = new QGroupBox("Class generator", this);

    _formDef = new QFormLayout(this);
    _formComment = new QFormLayout(this);
    _optionVBox = new QVBoxLayout(this);

    _groupOption = new QGroupBox("Options", this);
    _groupComment = new QGroupBox("Comments", this);
    _groupComment->setCheckable(true);

    _buttonHBox = new QHBoxLayout(this);
        _buttonHBox->setAlignment(Qt::AlignRight);

    // CONNECTS
        QObject::connect(_generateBtn, SIGNAL(clicked(bool)), this, SLOT(classGenerator()));
        QObject::connect(_quitBtn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

    // MANAGE LAYOUTS
    setLayout(_mainVBox);
        _mainVBox->addWidget(_groupDef);
            _groupDef->setLayout(_formDef);
                _formDef->addRow("Name *", _nameLine);
                _formDef->addRow("Parent class", _parentLine);
        _mainVBox->addWidget(_groupOption);
            _groupOption->setLayout(_optionVBox);
                _optionVBox->addWidget(_protect);
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

void MainWindow::classGenerator()
{
    qDebug("Generate");
}
