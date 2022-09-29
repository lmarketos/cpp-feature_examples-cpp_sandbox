#include <boost/asio.hpp>
#include <chrono>
#include <iostream>
#include <thread>
namespace asio = boost::asio;
using namespace std::chrono_literals;

void handler(const boost::system::error_code &e) {
  if (!e)
    std::cout << "Expired\n";
  else
    std::cout << "Error: " << e.message() << "\n";
}

int main() {
  asio::io_context context;
  asio::steady_timer timer(context, 2s);
  timer.async_wait(&handler);

  std::cout << "Before...\n";
  context.run();
  std::cout << "...After\n";

  // Do it again but cause an error
  timer.expires_from_now(2s);
  timer.async_wait(&handler);

  // Cancel the timer after 1 sec to cause an error to be sent to the handler
  // Don't do it with a thread, this whole thing is about asio! Add another
  // timer to the context. auto t =
  // std::jthread([&timer2](){std::this_thread::sleep_for(1s);timer2.cancel();});
  asio::steady_timer timer2(context, 1s);
  timer2.async_wait(
      [&timer](const boost::system::error_code &) { timer.cancel(); });

  context.restart();

  std::cout << "Before error...\n";
  context.run();
  std::cout << "...After error\n";
}
