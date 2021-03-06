# Test file for "Lab2_introToAvr"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

#Tests for availability of parking spaces: for PINA ...
#bbbb 1111 should yield 0
#bbbb 0111 should yield 1
#bbbb 0011 should yield 2
#bbbb 0001 should yield 3
#bbbb 0000 should yield 4
#Final test (0xFF)  added for completeness
test "PIN[A-C] : 0x8D, 0x00, 0x00 => PORTD : "
setPINA 0xFF
setPINB 0xFF
setPINC 0xFF
expectPORTD 0xFD
checkResult


test "PIN[A-C] : 0x00, 0x00, 0x00 => PORTD : 0x00"
setPINA 0x00
setPINB 0x00
setPINC 0x00
expectPORTD 0x00
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
