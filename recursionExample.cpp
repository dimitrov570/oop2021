#include <iostream>

int fact(size_t n)
{
    if (n == 0){
        return 1;
    }

    return n * fact(n - 1);
}

/*  
    fact(4)
    4 * fact(3)
    4 * (3 * fact(2))
    4 * (3 * (2 * fact(1)))
    4 * (3 * (2 * (1 * fact(0))))
    4 * (3 * (2 * (1 * 1)))
    4 * (3 * (2 * 1))
    4 * (3 * 2)
    4 * 6
    24
*/

//опашкова рекурсия

int tailFact(size_t n, size_t res){
    if (n == 0) {
        return res;
    }

    return tailFact(n-1, n*res);
}

/*
    tailFact(4, 1)
    tailFact(3, 4)
    tailFact(2, 12)
    tailFact(1, 24)
    tailFact(0, 24)
    24    
*/
