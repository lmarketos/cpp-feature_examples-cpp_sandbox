#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <chrono>
#include <iostream>
#include <thread>
using namespace std::chrono_literals;

void print(boost::asio::steady_timer &t, int &count) {
  if (count < 5) {
    std::cout << "print: " << count << "\n";
    ++(count);
    t.expires_at(t.expiry() + 1s);
    t.async_wait(
        [&t, &count](const boost::system::error_code &) { print(t, count); });
  }
}

int main() {
  boost::asio::io_context io;
  int count{0};

  boost::asio::steady_timer t(io, 1s);
  std::cout << "before\n";
  t.async_wait(print(t, count));
  io.run();
  std::cout << "after: " << count << "\n";
}
