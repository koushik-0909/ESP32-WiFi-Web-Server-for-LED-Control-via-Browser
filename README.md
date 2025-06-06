# ESP32-WiFi-Web-Server-for-LED-Control-via-Browser

This project creates a simple web server using the ESP32 that allows you to control an LED connected to GPIO5 through a web browser over WiFi.

## Features

- Connects ESP32 to a WiFi network.
- Hosts a web page accessible via the ESP32’s IP address.
- Controls an LED ON/OFF using web page buttons.
- Easy to use interface with basic HTML links.

## Hardware Required

- ESP32 Development Board
- LED connected to GPIO5 with a suitable resistor
- USB cable for programming and power

## How to Use

1. Update the `ssid` and `password` variables in the code with your WiFi credentials.
2. Connect an LED to GPIO5 (pin 5) with an appropriate resistor.
3. Upload the code to your ESP32 using the Arduino IDE.
4. Open the Serial Monitor at 115200 baud to find the ESP32 IP address.
5. Open a web browser and enter the IP address to access the control page.
6. Click "Turn ON" or "Turn OFF" links to control the LED.

## Code Overview

- Uses the built-in `WiFi` library to connect to the WiFi network.
- Starts a TCP server on port 80.
- Listens for HTTP GET requests to turn the LED ON or OFF.
- Serves a simple HTML page with links for controlling the LED.

## Notes

- Ensure your ESP32 board is properly selected in the Arduino IDE.
- Adjust `ledPin` if you want to use a different GPIO pin.
- This example can be expanded to control multiple devices or add more web features.

## License

This project is open for personal and educational use. Feel free to modify and share!

