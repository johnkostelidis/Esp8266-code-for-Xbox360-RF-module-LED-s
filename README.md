ESP82-66 Code for Xbox 360 RF Module LED Control.

A lightweight ESP8266-based implementation for controlling the front LED of Xbox 360 RF modules via custom RF protocol emulation.

**Overview**
This project provides ESP8266 coede that enables communication with Xbox 360 RF modules to control their front LED behavior — mimicking the original console's LED response during boot and active states.

While the Xbox 360 RF module has been largely obsolete, there remains a passionate community of modders and tinkerers who have explored its RF protocol for retro gaming and hardware hacking. This code fills a niche: a functional, open-source ESP8266 solution for RF LED control, which is notably absent in existing public repositories.

**Inspiration & Technical Debt**
This project is built upon the foundational work of several independent modders and hardware enthusiasts, particularly:

[ViolentLamps](https://www.electromaker.io/profile/ViolentLambs) on [Electromaker](https://www.electromaker.io/project/view/xbox-360-rf-module-controlled-with-an-arduino-1?srsltid=AfmBOopbEvx2Dx-Q9JaapNqt6Rql97wlUG_CUoiBJImBMzv6FiqKZLs8) — whose detailed guide on building DIY RF modules remains one of the most comprehensive resources available. Their work preserved critical design and assembly insights from now-defunct forums and documentation.
[AppliedCarbon](https://www.appliedcarbon.org/xboxrf.html) — for sharing and preserving the original serial command set used to control the RF module's LED behavior. These command sequences are essential for accurate protocol emulation and are the backbone of this implementation.
The protocol itself is based on a serial RF command structure (typically via TTL UART), with specific byte patterns that trigger LED states (e.g., power-on, idle, standby). This code decodes and retransmits these commands through the ESP8266’s UART interface.

**Current Functionality**
- Initialization of the RF module and LED state setup
-  Boot sequence emulation (LEDs flash on power-up)
-  Basic state control (on/off, blink patterns)

 Full console-like behavior (e.g., game state transitions, dynamic LED responses) remains unimplemented


**Goals for Future Development**
Full emulation of Xbox 360 console LED behavior (including state transitions during gameplay or standby)
Support for configurable LED patterns via user-defined parameters
Optional integration with external triggers (e.g., gamepad input, system events)
Modular design to support future protocol extensions or hardware variants

**Disclaimer**
This project is developed as a community-driven experiment and is not officially supported.

Maintenance and updates are not guaranteed.

The code is provided "as-is" for educational and hobbyist use only.
**Use at your own risk — improper configuration may result in module damage or unintended behavior.**


**Acknowledgments**
Special thanks to ViolentLamps and AppliedCarbon for preserving critical technical knowledge from defunct sources. Their efforts have made this kind of hardware hacking possible today.

