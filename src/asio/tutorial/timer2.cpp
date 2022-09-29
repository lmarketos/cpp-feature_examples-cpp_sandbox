#include <boost/asio.hpp>
#include <chrono>
#include <iostream>
#include <thread>

void print(const boost::system::error_code &) { std::cout << "print\n"; }

int main() {
  boost::asio::io_context io;

  using namespace std::chrono_literals;
  boost::asio::steady_timer t(io, 5s);
  std::cout << "before\n";
  t.async_wait(&print);
  io.run();
  std::cout << "after\n";
}
