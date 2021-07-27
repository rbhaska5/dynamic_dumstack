# dynamic_dumstack

Name - Rachana Bhaskar
ASU ID - 1217402615


///////////////////////////////////////////////////////////

files included:

Makefile
trail.patch
main.c
readme.txt

///////////////////////////////////////////////////////////

Instructions to run - 

1. Copy the patch file (trail.patch) to your kernel source
2. (under kernel  - old folder), use command "patch -p1 < trail.patch" to make sure that kernel is not harmed
3. Build the kernel (enable Y for dynamic_dump_stack if asked)
4. Copy bzImage onto your SD card

///////////////////////////////////////////////////////////

Instructions to make - 

If required,
(environment setup – cd /opt/iot-devkit/1.7.2/
                   - run command “ source environment-setup-i586-poky-linux “  )

1. Command for compiling the code - make

2. Copy the test file [tester] using the following command(secure copy) -  
        scp <file name> root@192.162.1.5:/home
3.  (board) run the copied tester file using command ./tester

//////////////////////////////////////////////////////////
