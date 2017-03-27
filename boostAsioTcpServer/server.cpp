#include "server.h"

Server::Server(): m_acceptor(m_io, endpoint_type(ip::tcp::v4(), 6688))
{
    accept();
}

void Server::run()
{
    m_io.run();
}

void Server::accept()
{
    sock_ptr sock(new socket_type(m_io));
    m_acceptor.async_accept(
                *sock,
                [this, sock] (const error_code& ec)
    {
        if(ec)
            return;
        sock->async_send(
                    buffer("hello asio"),
                    [] (const error_code&, std::size_t)
        {
            cout << "send message complete." << endl;
        }
                    );
        accept();        //再次启动异步接受连接
    }
    );
}
