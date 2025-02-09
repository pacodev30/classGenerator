#include <MainWindow.h>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // INIT WIDGETS
    _nameLine = new QLineEdit(this);
    _parentLine = new QLineEdit(this);

    _ifndefineRadio = new QRadioButton("ifndefine", this);
    _pragmaOnceRadio = new QRadioButton("pragma once", this);
    _pragmaOnceRadio->setChecked(true);

    _constructLabel = new QLabel(this);
    _destructLabel = new QLabel(this);
    _constructCheck = new QCheckBox("Generate a construct", this);
        _constructCheck->setChecked(true);
    _destructCheck = new QCheckBox("Generate a destruct", this);
        _destructCheck->setChecked(false);

    _authorLine = new QLineEdit(this);
    _date = new QDateEdit(QDate::currentDate(), this);
    _briefText = new QTextEdit(this);

    _generateBtn = new QPushButton("Generate class", this);
        _generateBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    _quitBtn = new QPushButton("Quit", this);
        _quitBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // INIT LAYOUTS
    _mainVBox = new QVBoxLayout(this);

    _defGroup = new QGroupBox("Class generator", this);
    _defForm = new QFormLayout(this);
    _commentForm = new QFormLayout(this);


    _optionGroup = new QGroupBox("Options", this);
    _commentGroup = new QGroupBox("Comments", this);
        _commentGroup->setCheckable(true);
    _optionVBox = new QVBoxLayout(this);
    _optionForm = new QFormLayout(this);

    _protectHBox = new QHBoxLayout(this);
    _buttonHBox = new QHBoxLayout(this);
        _buttonHBox->setAlignment(Qt::AlignRight);

    // MANAGE LAYOUTS
    setLayout(_mainVBox);
        _mainVBox->addWidget(_defGroup);
            _defGroup->setLayout(_defForm);
                _defForm->addRow("Name *", _nameLine);
                _defForm->addRow("Parent class", _parentLine);

        _mainVBox->addWidget(_optionGroup);
            _optionGroup->setLayout(_optionVBox);
                _optionVBox->addLayout(_protectHBox);
                    _protectHBox->addWidget(_ifndefineRadio);
                    _protectHBox->addWidget(_pragmaOnceRadio);
                _optionVBox->addLayout(_optionForm);
                    _optionForm->addRow(_constructCheck, _constructLabel);
                _optionForm->addRow(_destructCheck, _destructLabel);

        _mainVBox->addWidget(_commentGroup);
            _commentGroup->setLayout(_commentForm);
                _commentForm->addRow("Author", _authorLine);
                _commentForm->addRow("Date", _date);
                _commentForm->addRow("Briefing", _briefText);
            _mainVBox->addLayout(_buttonHBox);
                _buttonHBox->addWidget(_generateBtn);
                _buttonHBox->addWidget(_quitBtn);

    // CONNECTS
    connect(_generateBtn, SIGNAL(clicked(bool)), this, SLOT(openClassGenerator()));
    connect(_quitBtn, SIGNAL(clicked(bool)), qApp, SLOT(quit()));

    connect(_nameLine, SIGNAL(textChanged(QString)), this, SLOT(nameToConstructLabel(QString)));
    connect(_constructCheck, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(displayConstructLabel()));
    connect(_destructCheck, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(displayDestructLabel()));
}

MainWindow::~MainWindow() {}


void MainWindow::displayConstructLabel()
{
    _constructCheck->isChecked() ? _constructLabel->show() : _constructLabel->hide();
}

void MainWindow::displayDestructLabel()
{
    _destructCheck->isChecked() ? _destructLabel->show() : _destructLabel->hide();
}

void MainWindow::nameToConstructLabel(QString nameValue)
{
    displayConstructLabel();
    displayDestructLabel();
    _constructLabel->setText(nameValue + "()");
    _destructLabel->setText("~" + _nameLine->text() + "()");
}

void MainWindow::openClassGenerator()
{
    if(_nameLine->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Name is empty");
        return;
    }
    MainWindow::setCode();
    _generatorWindow = new Generator(_codeString, this);
    _generatorWindow->exec();
}

void MainWindow::setCode()
{
    // INCLUDE
    if(!_codeString.isEmpty())
        _codeString.clear();

    if(_ifndefineRadio->isChecked()) {
        _codeString.append("#ifndef " + _nameLine->text().toUpper() + "_H \n");
        _codeString.append("#define " + _nameLine->text().toUpper() + "_H \n\n");
    }

    if(_pragmaOnceRadio->isChecked())
        _codeString.append("# pragma once \n");

    if(!_parentLine->text().isEmpty())
        _codeString.append("# include \"" + _parentLine->text() + ".h\" \n\n");

    // COMMENT
    if(_commentGroup->isChecked()){
        _codeString.append("/** \n");
        if(!_authorLine->text().isEmpty())
            _codeString.append("/* @author " + _authorLine->text() + "\n");
        if(!_date->text().isEmpty())
            _codeString.append("/* @date " + _date->text() + "\n");
        if(!_briefText->document()->isEmpty())
            _codeString.append("/* @brief " + _briefText->document()->toPlainText() + "\n");
        _codeString.append("*/ \n");
    }

    // CLASS
    _codeString.append("class " + _nameLine->text());

    if(!_parentLine->text().isEmpty())
        _codeString.append(" : public " + _parentLine->text());

    _codeString.append("\n{ \n public: \n");

    if(_constructCheck->isChecked())
        _codeString.append("   " + _nameLine->text() + "(); \n");

    if(_destructCheck->isChecked())
        _codeString.append("   ~" + _nameLine->text() + "(); \n");

    _codeString.append("\nprivate: \n\n}; \n");

    if(_ifndefineRadio->isChecked())
        _codeString.append("#endif");

}


