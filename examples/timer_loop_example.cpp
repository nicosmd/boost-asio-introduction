#include <iostream>
#include <boost/asio.hpp>

namespace async = boost::asio;


void async_function(async::steady_timer* timer)
{
    static auto counter = 0;
    timer->expires_after(std::chrono::seconds(1));
    timer->async_wait([timer](const boost::system::error_code&)
    {
        std::cout << "Hello World: " << counter << std::endl;
        ++counter;
        async_function(timer);
    });
}

int main()
{
    async::io_context io;
    async::steady_timer t(io);

    async_function(&t);

    io.run();
}
