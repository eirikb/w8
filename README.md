w8
==

This is the mother of all Proof Of Concepts.

It's a JavaScript kernel with the name w8.<
w8 either means 'weight' because it's a light weight kernel on top of a heavy weight VM,
or 'wait' because it might be horrible slow in runtime or to produce.

Build
-----

This will probably work:
    $ sudo apt-get install build-essential
    $ sudo apt-get install grub2
    $ sudo apt-get install qemu
    $ make
    $ make run

Write to USB
------------
Put a stick in your computer and run
    $ sudo dd if=w8.iso of=/dev/sdX

Note
----
At the moment this will be utmost minimum needed code to get something running!
Trying to keep it as simple as possible in the beginning
