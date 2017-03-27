#include "client.h"

Client::Client():m_buf(100, 0), m_ep(address_type::from_string("127.0.0.1"), 6688)
{
    start();
}

void Client::run()
{
    m_io.run();
}

void Client::start()
{
    sock_ptr sock(new socket_type (m_io));
    sock->async_connect(m_ep,
                        [this, sock] (const error_code& ec)
    {
        if(ec)
            return;
        sock->async_read_some(buffer(m_buf),
                              [this, sock] (const error_code& ec, std::size_t)
        {
            read_handler(ec, sock);
        }
                              );
    }
                        );
}

void Client::read_handler(const Client::error_code &ec, Client::sock_ptr sock)
{
    if(ec)
        return;
    cout << &m_buf[0] << endl;
    sock->async_read_some(buffer(m_buf),
                          [this, sock] (const error_code& ec, std::size_t)
    {
        read_handler(ec, sock);
    }
                          );
}
