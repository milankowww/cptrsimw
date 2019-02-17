# cptrsimw
*a vintage 1994 hardware emulator for a computer that never existed*

This is a nostalgic story of a beautiful fail.

Back in 1994, while on high school, my dream was to build my own computer from scratch. I guess it was everybody's dream back then. At first, I tried to design the CPU from scratch, using the freely available logic components. After some time, this proved to be very complex and time consuming.

So instead, together with a friend, we started designing a PCB for our own computer, using off the shelf i8080 CPU. The MS-DOS software we used for this failed

We had the board developed, we drilled the holes, soldered the components... and nothing. We never managed to get the machine running, because we had no equipment, no oscilloscope, no logical analyzer, nothing.

But while waiting for the PCB, I have decided to create a firmware for the computer, thus I have coded the one and only hardware emulator for said computer, including the Z80 CPU and peripherials, and a debugger. The coding took one night only, and 25 years later, I still wonder how I managed to pull this off.

## Source code

- The Intel 8080 CPU emulator is written in a pidgin of i8086 assembly language and Pascal, and resides in cptrsim0.inc.
- The disassembler is in cptrsim1.inc
- The emulated hardware, debugger, and a single stepping main loop is in cptrsimw.pas

## How to build and use the code

- Find a working machine with MS DOS and Turbo Pascal.
- Load the code.
- Compile.
- Send me a pull request with .exe :D
- Run the resulting .exe.



You will now see a debugger screen, and you can single step the application.
