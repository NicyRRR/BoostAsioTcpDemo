#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {
        cout << "server start." << endl;
        Server srv;
        srv.run();
    }
    catch (std::exception& e)
    {
        cout << e.what() << endl;
    }
    return a.exec();
}
