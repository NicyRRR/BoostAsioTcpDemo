#include <QCoreApplication>
#include "client.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    try
    {
        cout << "client start." << endl;
        Client cl;
        cl.run();
    }
    catch (std::exception& e)
    {
        cout << e.what() << endl;
    }
    return a.exec();
}
