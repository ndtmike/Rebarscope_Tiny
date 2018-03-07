REM Rebarscope_Tiny.bat >Rebarscope_Tiny.txt 2>&1 
REM to run and save results
ECHO on
copy "Rebarscope_Tiny.hex" "C:\AVR_Dude"
cd C:\AVR_Dude
avrdude -c usbtiny -p t84 -U flash:w:Rebarscope_Tiny.hex -v