# Synchronization-and-Mutual-Exclusion-WaterReaction-
Synchronization and Mutual Exclusion using various mutex and condition variables



# the various mutex and condition variables used:
used one mutex two times in the code first time to lock and unlock in the reaction_h
function, the last time in reaction_o to lock and unlock.

Used two condition variables one to notify we received h atom and signal the sleep thread (waited
thread on condition) that we have h atom and another one to notify that it done (we waited until have 2 h
and receive one o) and signal the sleep thread (waited thread on condition) and signal the two thread that the
make_water is done.


# how to compile and run the code :

- Open the terminal and go to the project directory .
- Write make in terminal .
- test it by using ./reaction x where x percentage of hydrogen .
- can use the test in make file by write (make run) in terminal.
