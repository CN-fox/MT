#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
    class Config;
}

class Config : public QWidget {
    Q_OBJECT
public:
    Config(QWidget *parent = 0);
    ~Config();
    static QFile * getconfigFile();
    static QString getSdkPath();
    static QString getProductPath();
    static QString getName();
    static QString getEmail();
    static QString getPWD();
    static QString getScript();
    static bool getDebug();
    static bool checkProductPath(const QString);

protected:
    void changeEvent(QEvent *e);

public slots:
    void openDir();
    void openSdk();

signals:
    void config_change();

private:
    Ui::Config *ui;
    QString createDir();
    void init();
    void createBuildScript();
    static QString getValue(char*,QString);

private slots:
    void on_save_accepted();
};

#endif // CONFIG_H
