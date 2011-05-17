w8
==

This is the mother of all Proof Of Concepts.

It's a JavaScript kernel with the name w8.<br>
w8 either means 'weight' because it's a light weight kernel on top of a heavy weight VM,
or 'wait' because it might be horrible slow in runtime or to produce.

Build
-----

This should get you going:

    $ sudo apt-get install build-essential xorriso grub2 qemu
    $ svn checkout http://v8.googlecode.com/svn/trunk v8
    $ cd v8; scons; cd ..
    $ make

You need to point to the v8-directory since that is used directly by Makefile and kernel.cpp

Write to USB
------------
Put a stick in your computer and run

    $ sudo dd if=w8.iso of=/dev/sdX

Note
----
At the moment this will be utmost minimum needed code to get something running!
Trying to keep it as simple as possible in the beginning
