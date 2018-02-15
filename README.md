# Corewar
Famous algorithm project involving a virtual machine, an assembler and pseudo assembly.

See subject/explanations: https://drive.google.com/file/d/1JKJoHPbT7F5vLDzjxGh2xOy2GjNcM_u6/view?usp=sharing

TLDR:
Pseudo assembly programs are fighting each other to dominate the memory of a virtual machine. The virtual machine exposes several functions that can be used by the pseudo assembly such as fork() which copies the program somewhere else, live() which allows the program to exist and standard asm functions like zjump, or/xor and so on... The virtual machine runs the "fighters" and allow them to co-exist in a shared cycled memory. The assembler reads and compiles the fighters and put them in the virtual machine. 

![a corewar running 4 pseudo assembly programs](http://blog.faby.rocks/content/images/2017/10/corewar.jpg)

The assembler was made by https://github.com/timurrustamov and the virtual machine by myself (Fabien Borel). 
No copy allowed, especially for other students. 
