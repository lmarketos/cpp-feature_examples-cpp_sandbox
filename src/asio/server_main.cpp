#include <iostream>
#include <boost/asio.hpp>

int main() 
{
  try
  {
    std::cout << "server_main\n";
    boost::asio::io_service io_service;

    io_service.post([](){std::cout << "Worker!\n";});
    io_service.run();
  }
  catch (...) {
    std::cerr << "Exception\n";
  }
}
