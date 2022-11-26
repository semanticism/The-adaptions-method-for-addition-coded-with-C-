# The adaptions method for addition coded with C++
------




It's a method that works like this:
We represent any number representation in a base with vectors like this: X/*100+Y/*10+Z -> (X,Y,Z) (the below vectors for example are symbols for representations in the second radix)
(0,0,1)

(0,1,1)

(0,1,10BIN=2)

Now we've got to convert that into something that can be converted in binary, so with this case you would do this:

(0,1+1,0+0)

(0,10BIN,0+0)

(1+0,0+0,0)

(1,0,0)

Conclusion: 1+11BIN=100BIN

While implementation 2 is more optimized I've included both for research pourposes, perhaps for example, Minecraft redstoners could convert this to a Minecraft circuit and software engineers working for other platforms could translate this code to their plataform and people could make an algorithm with a more generalized pourpose based on a part of what I wrote.
