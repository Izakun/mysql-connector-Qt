#include <QCoreApplication>
#include <QtSql>
#include <QtCore>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase::database().close();

    // Create connexion to database
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("");

    if(db.open())
        std::cout << "Connexion successfully" << std::endl;
    else
        std::cout << "Connexion fail" << std::endl;

    std::string id;

    QSqlQuery query(db);
    query.exec("SELECT * FROM test");

    if(query.size()>0){
        while (query.next()) {
            id = query.value("name").toString().toUtf8().constData();

            std::cout << id << std::endl;
        }
    }
    else
        std::cout << "No raw in database" << std::endl;

    return a.exec();
}
