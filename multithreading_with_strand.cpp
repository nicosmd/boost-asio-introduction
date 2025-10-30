#include <iostream>
#include <boost/asio.hpp>

namespace async = boost::asio;


void async_function(async::io_context::strand& io)
{
    static auto counter = 0;
    async::post(io, [&io]()
    {
        std::cout << "Hello Async Func: " << counter << std::endl;
        ++counter;
        async_function(io);
    });
}

void other_async_function(async::io_context::strand& io)
{
    static auto counter = 0;
    async::post(io, [&io]()
    {
        std::cout << "Hello Other Async Func: " << counter << std::endl;
        ++counter;
        other_async_function(io);
    });
}

int main()
{
    async::io_context io;

    async::io_context::strand strand{io};

    async_function(strand);
    other_async_function(strand);

    std::thread j{[&io] { io.run(); }};

    io.run();
}
