add_executable(timer1_ex timer1.cpp)
add_executable(timer2_ex timer2.cpp)

install(TARGETS timer1_ex timer2_ex DESTINATION bin/asio)

