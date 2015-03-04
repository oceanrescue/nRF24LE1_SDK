nRF24LE1_SDK
============

SDK for the Nordic nRF24LE1 for use with SDCC

Three things were added to SDK:
- eeprom routine
- millis() and micros() functions based on Timer1
- serial routine to simplify debug with printf()/scanf()

NOTE
=====
- Original nRF24LE1 SDK you could find at [Brennen's blog](http://blog.diyembedded.com).
This fork looks like version 4 of that SDK. Previouse version 3.0 you could find 
[here](http://www.diyembedded.com/lib/nrf24le1/nrf24le1_sdk_v3.0.zip).

- In addition AES cryptography for nRF24LE1 could be found [here](http://www.diyembedded.com/lib/cryptography/cryptography_v3.0.zip).
