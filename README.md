# The "adaptions method" for addition coded with C++
------




It's a method that works like this:
We represent any number representation in a base with vectors like this: X\*100+Y\*10+Z -> (X,Y,Z) (the below vectors for example are symbols for representations in the base 2)
(0,0,1)

(0,1,1)

(0,1,10BIN=2)

Now we've got to convert that into something that can be converted in binary, so with this case you would do this:

(0,1+1,0+0)

(0,10BIN,0+0)

(1+0,0+0,0)

(1,0,0)

Conclusion: 1+11BIN=100BIN

Immplementation 2 is more optimized, instead of dectecting change, it sees if what is in all of the digit plaaces is legal
