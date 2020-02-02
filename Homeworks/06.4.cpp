/*  Reid Harry
    2/2/2020
    The Collatz Conjecture (see: https://en.wikipedia.org/wiki/Collatz_conjecture) states that
    starting with any positive integer applying the described function will eventually result in 
    the number 1. The function (which you will name "collatz_function") takes an integer and returns
    half that integer (if it is even) or 3 times that number plus 1 (if it is odd). Additionally,
    write a function (named "collatz_persistence") that returns the number of applications of the 
    collatz_function required to yield a 1.
*/

int collatz_function(int num){
    if(num % 2 != 0){
        // odd case
        return (num * 3 + 1);
    }else
    {
        // even case
        return (num / 2);
    }
}

int collatz_persistence(int num){
    int counter = 0;

    // loop that runs until the number has been whittled down to 1 and tracks how many iterations it takes
    while(num != 1){
        num = collatz_function(num);
        counter++;
    }

    return counter;
}