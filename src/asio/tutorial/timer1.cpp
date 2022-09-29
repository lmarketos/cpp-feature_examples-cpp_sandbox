#include <boost/asio.hpp>
#include <boost/version.hpp>
#include <chrono>
#include <iostream>
#include <thread>

int main() {
  std::cout << "Boost version: " << BOOST_VERSION / 100000 << "."
            << BOOST_VERSION / 100 % 1000 << "." << BOOST_VERSION % 100 << '\n';
  boost::asio::io_context io;

  using namespace std::chrono_literals;
  boost::asio::steady_timer t(io, 5s);
  std::this_thread::sleep_for(6s);
  std::cout << "before\n";
  t.wait();
  std::cout << "after\n";
}
