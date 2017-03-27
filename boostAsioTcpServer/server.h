#ifndef SERVER_H
#define SERVER_H

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/placeholders.hpp>
#include <boost/asio/error.hpp>
#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace boost;                                    using namespace boost::asio;
using namespace boost::asio::placeholders;                using namespace boost::system;
using std::cout;                                          using std::endl;
using std::string;                                        using std::vector;

class Server
{
    typedef Server this_type;
    typedef ip::tcp::acceptor acceptor_type;
    typedef ip::tcp::endpoint endpoint_type;
    typedef ip::tcp::socket socket_type;
    typedef boost::shared_ptr<socket_type> sock_ptr;
    typedef boost::system::error_code error_code;
    typedef vector<char> buffer_type;
public:
    Server();
    void run();
    void accept();
private:
    io_service                    m_io;
    acceptor_type                 m_acceptor;
    buffer_type                   m_buf;
    string                        m_result_str;
};

#endif // SERVER_H
