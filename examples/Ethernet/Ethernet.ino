#include "EthernetInterface.h"
EthernetInterface net;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;

    Serial.println("Ethernet example for H7 + PMC");

    // Bring up the ethernet interface
    net.connect();

    // Show the network address
    SocketAddress addr;
    net.get_ip_address(&addr);
    Serial.print("IP address: ");
    Serial.println(addr.get_ip_address() ? addr.get_ip_address() : "None");

    // Open a socket on the network interface, and create a TCP connection to mbed.org
    TCPSocket socket;
    socket.open(&net);

    net.gethostbyname("ifconfig.io", &addr);
    addr.set_port(80);
    socket.connect(addr);

    String request;
    request += "GET / HTTP/1.1\r\n";
    request += "Host: ifconfig.io\r\n";
    request += "User-Agent: curl/7.64.1\r\n";
    request += "Accept: */*\r\n";
    request += "Connection: close\r\n";
    request += "\r\n";

    auto scount = socket.send(request.c_str(), request.length());
    Serial.print("Sent ");
    Serial.print(scount);
    Serial.println(" bytes: ");
    Serial.print(request);

    // Receive a simple HTTP response
    const size_t rlen { 64 };
    char rbuffer[rlen + 1] {};
    size_t rcount;
    size_t rec { 0 };
    String response;

    while ((rec = socket.recv(rbuffer, rlen)) > 0) {
        rcount += rec;
        response += rbuffer;
        memset(rbuffer, 0, rlen);
    }
    Serial.print("Received ");
    Serial.print(rcount);
    Serial.println(" bytes: ");
    Serial.println(response);

    const String clTag = "Content-Length: ";
    auto clIndex = response.indexOf(clTag);
    clIndex += clTag.length();
    auto cl = response.substring(clIndex, clIndex + 2);
    const String bodyTag = "\r\n\r\n";
    auto bodyIndex = response.indexOf(bodyTag);
    if (bodyIndex != -1) {
        bodyIndex += bodyTag.length();
        auto body = response.substring(bodyIndex, bodyIndex + cl.toInt());
        Serial.print("My public IPv4 Address is: ");
        Serial.println(body);
    }


    // Close the socket to return its memory and bring down the network interface
    socket.close();

    // Bring down the ethernet interface
    net.disconnect();
    Serial.println("Done");
}

void loop()
{
}
