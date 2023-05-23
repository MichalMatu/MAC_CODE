#include <WiFi.h>

String macToShortString(uint8_t mac[])
{
  String characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  String shortString = "";

  // Convert MAC address to a base36 string
  unsigned long long macValue = 0;
  for (int i = 0; i < 6; i++)
  {
    macValue <<= 8;
    macValue |= mac[i];
  }

  while (macValue > 0)
  {
    shortString = characters[macValue % 36] + shortString;
    macValue /= 36;
  }

  return shortString;
}

void setup()
{
  Serial.begin(115200);

  // Set your desired MAC address here
  uint8_t mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

  // Convert MAC address to a short string
  String shortString = macToShortString(mac);

  Serial.println("Short MAC Address: " + shortString);
}

void loop()
{
  // Your code here
}
