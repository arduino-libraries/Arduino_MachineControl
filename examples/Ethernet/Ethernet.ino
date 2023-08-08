/*
 * Portenta Machine Control - Ethernet HTTP Request Example
 *
 * This sketch provides a demonstration of testing the Ethernet port on the Machine Control.
 * It shows how to create an HTTP request as a client, sending it to a remote server and
 * receiving the response. This example illustrates the basics of making HTTP requests using the Ethernet interface.
 *
 * Circuit:
 *  - Portenta H7
 *  - Portenta Machine Control
 *
 * Initial author: Riccardo Rizzo @Rocketct
 */

#include <PortentaEthernet.h>
#include <Ethernet.h>
#include <SPI.h>

EthernetClient client;
char server[] = "www.ifconfig.io"; // name address (using DNS)

unsigned long beginMicros, endMicros;
unsigned long byteCount = 0;
bool printWebData = true; // set to false for better speed measurement

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ;
    }

    Serial.println("Ethernet example for H7 + PMC");

    if (Ethernet.begin() == 0) {
        Serial.println("Failed to configure Ethernet using DHCP");
        while(1);
    } else {
        Serial.print("DHCP assigned IP ");
        Serial.println(Ethernet.localIP());
    }

    // give the Ethernet interface a second to initialize:
    delay(1000);
    Serial.print("connecting to ");
    Serial.print(server);
    Serial.println("...");

    // if you get a connection, report back via serial:
    if (client.connect(server, 80)) {
        Serial.print("connected to ");
        Serial.println(client.remoteIP());
        
        // Make a HTTP request:
        client.println("GET / HTTP/1.1");
        client.println("Host: ifconfig.io");
        client.println("User-Agent: curl/7.64.1");
        client.println("Connection: close");
        client.println("Accept: */*");
        client.println();
    } else {
        // if you didn't get a connection to the server:
        Serial.println("connection failed");
    }

    beginMicros = micros();
}

void loop() {
    // if there are incoming bytes available
    // from the server, read them and print them:
    int len = client.available();
    if (len > 0) {
        byte buffer[80];
        if (len > 80)
            len = 80;
        client.read(buffer, len);
        if (printWebData) {
            Serial.write(buffer, len); // show in the serial monitor (slows some boards)
        }
        byteCount = byteCount + len;
    }

    // if the server's disconnected, stop the client:
    if (!client.connected()) {
        endMicros = micros();
        Serial.println();
        Serial.println("disconnecting.");
        client.stop();
        Serial.print("Received ");
        Serial.print(byteCount);
        Serial.print(" bytes in ");
        float seconds = (float)(endMicros - beginMicros) / 1000000.0;
        Serial.print(seconds, 4);
        float rate = (float)byteCount / seconds / 1000.0;
        Serial.print(", rate = ");
        Serial.print(rate);
        Serial.print(" kbytes/second");
        Serial.println();

        // do nothing forevermore:
        while (true) {
            delay(1);
        }
    }
}
