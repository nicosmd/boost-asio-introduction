#include <iostream>
#include <boost/asio.hpp>

namespace async = boost::asio;

int main()
{
    async::io_context io;

    async::post(io, [&io]() { std::cout << "Hello World" << std::endl; });

    io.run();
}
