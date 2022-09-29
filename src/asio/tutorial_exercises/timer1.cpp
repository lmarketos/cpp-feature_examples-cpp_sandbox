#include <boost/asio.hpp>
#include <chrono>
#include <iostream>

int main() {
  boost::asio::io_context context;
  boost::asio::steady_timer timer(context);

  using namespace std::chrono_literals;
  timer.expires_from_now(2s);

  std::cout << "Before...\n";

  timer.wait();

  std::cout << "...After\n";
}
