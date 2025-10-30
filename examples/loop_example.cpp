#include <iostream>
#include <boost/asio.hpp>

namespace async = boost::asio;


void async_function(async::io_context& io)
{
    static auto counter = 0;
    async::post(io, [&io]()
    {
        std::cout << "Hello World: " << counter << std::endl;
        ++counter;
        async_function(io);
    });
}

int main()
{
    async::io_context io;

    async_function(io);

    io.run();
}
