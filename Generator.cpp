#include "Generator.h"
#include <QApplication>

Generator::Generator(const QString &data, QWidget *parent)
    : QDialog(parent), _data(data)
{
    setMinimumSize(QSize(300, 400));

    // WIDGETS
    _textEdit = new QTextEdit(this);
        _textEdit->setPlainText(data);
        _textEdit->setFont(QFont("Courrier"));
        _textEdit->setReadOnly(true);
        _textEdit->setLineWrapMode(QTextEdit::NoWrap);

    _quitBtn = new QPushButton("Close", this);
        _quitBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    // LAYOUTS
    _windowVBox = new QVBoxLayout(this);
    _buttonHBox = new QHBoxLayout(this);
    _buttonHBox->setAlignment(Qt::AlignRight);

    setLayout(_windowVBox);
        _windowVBox->addWidget(_textEdit);
        _windowVBox->addLayout(_buttonHBox);
            _buttonHBox->addWidget(_quitBtn);

    QObject::connect(_quitBtn, SIGNAL(clicked(bool)), this, SLOT(accept()));
}
