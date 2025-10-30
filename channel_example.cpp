#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/experimental/channel.hpp>

namespace async = boost::asio;

void producer(async::experimental::channel<void(boost::system::error_code, int)>& channel)
{
    static int counter = 0;

    channel.async_send(
        boost::system::error_code{},
        counter,
        [&channel](boost::system::error_code ec) {
            if (!ec) {
                ++counter;
                producer(channel);
            }
        }
    );
}

void consumer(async::experimental::channel<void(boost::system::error_code, int)>& channel)
{
    channel.async_receive(
        [&channel](boost::system::error_code ec, int value) {
            if (!ec) {
                std::cout << "Received: " << value << std::endl;
                consumer(channel);
            }
        }
    );
}

int main()
{
    async::io_context io;

    // Create a channel with buffer capacity of 10
    async::experimental::channel<void(boost::system::error_code, int)> channel(io, 10);

    // Start producer and consumer
    producer(channel);
    consumer(channel);

    io.run();
}