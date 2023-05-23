#include <WiFi.h>

void shortStringToMac(String shortString, uint8_t mac[])
{
  String characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // Convert short string to MAC address
  unsigned long long macValue = 0;
  for (char c : shortString)
  {
    macValue *= 36;
    macValue += characters.indexOf(c);
  }

  for (int i = 5; i >= 0; i--)
  {
    mac[i] = macValue & 0xFF;
    macValue >>= 8;
  }
}

void setup()
{
  Serial.begin(115200);

  // Set your desired short MAC address here
  String shortString = "2QIY9I";

  // Convert short MAC address back to original MAC address
  uint8_t mac[6];
  shortStringToMac(shortString, mac);

  // Print the original MAC address
  Serial.print("Original MAC Address: ");
  for (int i = 0; i < 6; i++)
  {
    Serial.print(mac[i], HEX);
    if (i < 5)
    {
      Serial.print(":");
    }
  }
  Serial.println();
}

void loop()
{
  // Your code here
}
