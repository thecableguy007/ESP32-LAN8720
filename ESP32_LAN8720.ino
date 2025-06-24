#include <ETH.h>

/ Ethernet settings
#define ETH_TYPE ETH_PHY_LAN8720
#define ETH_ADDR          1                     // PHY address (usually 0 or 1)
#define ETH_POWER_PIN     -1                    // Power control pin (NOT a GPIO PIN!)
// Define GPIO pins for Ethernet
#define ETH_CLK_MODE ETH_CLOCK_GPIO17_OUT       // RMII clock output on GPIO17
#define ETH_MDC_PIN       23                    // MDC pin
#define ETH_MDIO_PIN      18                    // MDIO pin


// Configure static IP (optional)
IPAddress IP(192, 168, 1, 100);
IPAddress GW(192, 168, 1, 1);
IPAddress SN(255, 255, 255, 0);
IPAddress DNS(192, 168, 1, 10);

void setup() {
  Serial.begin(115200);

  // Initialize Ethernet with custom PHY
  if (!ETH.begin(ETH_PHY_LAN8720, ETH_ADDR, ETH_MDC_PIN, ETH_MDIO_PIN, ETH_POWER_PIN, ETH_CLK_MODE)) {
    Serial.println("Failed to initialize Ethernet");
    return;
  }

  ETH.config(IP, GW, SN, DNS);
  Serial.println("Ethernet initialized");
}

void loop() {
  if (ETH.linkUp()) {
    Serial.print("IP Address: ");
    Serial.println(ETH.localIP());
    Serial.print("Subnet Mask: ");
    Serial.println(ETH.subnetMask());
    Serial.print("Gateway IP: ");
    Serial.println(ETH.gatewayIP());
    Serial.print("DNS IP: ");
    Serial.println(ETH.dnsIP());

  } else {
    Serial.println("Ethernet link down");
  }
  delay(1000);
}