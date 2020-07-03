# LibreWorx
Charging station repair card.

Base on work of Andreas B
https://github.com/andreasb242/Libreductioner

Tested and working with Landroid Worx WR106SI.

# Usage
LED Green : mower on station and battery full
LED Green blinking : mower on station and battery charging
LED Blue : mower in action
LED Red : Loop Break

# Extension / Support for other mower
If you have another mower, or would like to improve the Board: Create a Pull request!

# How it Works
Radio signal for perimetric -> work of Andreas B
For mower detect base station 
-when mower mow: 2 pin for charge mower connect to GND
-When mower arrive and active switch: delay 500ms and after connect mower power to 24VDC ( limit to 1A with L200CV ) 

# Board / Circuit
The Board / Circuit is created with EasyEda.

https://easyeda.com/feiltom/libreductioner

