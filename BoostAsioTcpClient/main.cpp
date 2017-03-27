#include <QCoreApplication>
#include "client.h"
#include "singleApplication.h"
int main(int argc, char *argv[])
{
    SingleApplication a(argc, argv);
    if(a.isRunning())
        return 0;
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
