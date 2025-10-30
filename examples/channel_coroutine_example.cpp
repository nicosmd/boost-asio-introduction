#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/experimental/channel.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>

namespace async = boost::asio;

async::awaitable<void> producer(async::experimental::channel<void(boost::system::error_code, int)>& channel)
{
    for (int counter = 0; ; ++counter) {
        co_await channel.async_send(boost::system::error_code{}, counter, async::use_awaitable);
    }
}

async::awaitable<void> consumer(async::experimental::channel<void(boost::system::error_code, int)>& channel)
{
    for (;;) {
        auto [ec, value] = co_await channel.async_receive(async::use_awaitable);
        if (!ec) {
            std::cout << "Received: " << value << std::endl;
        }
    }
}

int main()
{
    async::io_context io;

    // Create a channel with buffer capacity of 10
    async::experimental::channel<void(boost::system::error_code, int)> channel(io, 10);

    // Start producer and consumer as coroutines
    async::co_spawn(io, producer(channel), async::detached);
    async::co_spawn(io, consumer(channel), async::detached);

    io.run();
}