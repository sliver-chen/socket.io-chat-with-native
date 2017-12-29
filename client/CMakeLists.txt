set(CLIENT_SRC
    client.cpp)
include_directories(inc/)
link_directories(lib/)
add_executable(client ${CLIENT_SRC})
target_link_libraries(client socketiopoco_shared PocoCppUnit PocoCrypto PocoData PocoDataMySQL PocoDataSQLite
    PocoFoundation PocoJSON PocoMongoDB PocoNet PocoNetSSL PocoRedis PocoUtil PocoXML PocoZip)

