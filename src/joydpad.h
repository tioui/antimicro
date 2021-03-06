#ifndef JOYDPAD_H
#define JOYDPAD_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "joydpadbutton.h"

class JoyDPad : public QObject
{
    Q_OBJECT
public:
    explicit JoyDPad(QObject *parent = 0);
    explicit JoyDPad(int index, int originset, QObject *parent=0);
    ~JoyDPad();

    enum JoyMode {StandardMode=0, EightWayMode};

    JoyDPadButton* getJoyButton(int index);
    QHash<int, JoyDPadButton*>* getJoyButtons();

    int getCurrentDirection();
    int getJoyNumber();
    int getIndex();
    int getRealJoyNumber();
    virtual QString getName();
    void joyEvent(int value, bool ignoresets=false);

    void setJoyMode(JoyMode mode);
    JoyMode getJoyMode();

    void releaseButtonEvents();

    virtual bool isDefault();

    QHash<int, JoyDPadButton*>* getButtons();

    void readConfig(QXmlStreamReader *xml);
    void writeConfig(QXmlStreamWriter *xml);

    virtual QString getXmlName();

    static const QString xmlName;

protected:
    void populateButtons();

    QHash<int, JoyDPadButton*> buttons;
    int index;
    JoyDPadButton::JoyDPadDirections prevDirection;
    JoyDPadButton *activeDiagonalButton;
    int originset;
    JoyMode currentMode;

signals:
    void active(int index);
    void released(int index);

public slots:
    
};

#endif // JOYDPAD_H
