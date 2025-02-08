#include "Generator.h"
#include <QApplication>

Generator::Generator(const QString &data, QWidget *parent)
    : QDialog(parent), _data(data)
{
    _textEdit = new QTextEdit(this);
        _textEdit->setPlainText(data);
        _textEdit->setFont(QFont("Courrier"));
        _textEdit->setReadOnly(true);
        _textEdit->setLineWrapMode(QTextEdit::NoWrap);

    _quitBtn = new QPushButton("Close", this);
        _quitBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    _vBoxWindow = new QVBoxLayout(this);
    _hBoxValid = new QHBoxLayout(this);
    _hBoxValid->setAlignment(Qt::AlignRight);

    setLayout(_vBoxWindow);
        _vBoxWindow->addWidget(_textEdit);
        _vBoxWindow->addLayout(_hBoxValid);
            _hBoxValid->addWidget(_quitBtn);

    QObject::connect(_quitBtn, SIGNAL(clicked(bool)), this, SLOT(accept()));
}
