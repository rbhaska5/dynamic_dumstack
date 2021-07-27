# dynamic_dumstack

Exercise Objectives
1. To learn the basic programming technique in Linux kernel.
2. To practice the mechanisms and data structures of system call, and other Linux kernel objects

Linux kernel dump_stack() function can give a call trace from process stack. To enable dump_stack() function, the kernel must be built with certain config options enabled. Then, dump_stack() function is inserted into source code and can get invoked at execution time.

In this assignment, two new syscalls are implemented to insert and remove dump_stack in the execution path of kernel programs. In other words, the insertion and deletion of dump_stack is done dynamically, without re-building the kernel. The basic technique is to use kprobe to invoke dump_stack() in a pre-handler.



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
