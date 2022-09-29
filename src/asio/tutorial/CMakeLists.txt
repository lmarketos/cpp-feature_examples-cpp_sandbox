add_executable(timer1 timer1.cpp)
add_executable(timer2 timer2.cpp)
add_executable(timer3 timer3.cpp)
#add_executable(timer3_5 timer3.5.cpp)
add_executable(asio_client client_main.cpp)
add_executable(asio_server server_main.cpp)

install(TARGETS timer1 timer2 timer3 asio_client asio_server DESTINATION bin/asio)

