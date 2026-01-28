# ProjectEuler0006
My work on 

problem #6 of projecteuler.net:

Sum Square Difference

The sum of the squares of the first ten natural numbers is,

$$1^2 + 2^2 + ... + 10^2 = 385.$$

The square of the sum of the first ten natural numbers is,

$$(1 + 2 + ... + 10)^2 = 55^2 = 3025.$$

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is $3025 - 385 = 2640$.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

Completed on Sat, 20 Feb 2021, 18:04

#######################################################################################
Please note: Project Euler's policy allows publication of solutions for the first 100 problems,
that's why I am sharing my work here for reference and educational purposes.
#######################################################################################

There's an old trick in school algebra that I really love:

$$(k - 1)^2 = k^2 - 2k + 1 \Rightarrow 2k - 1 = k^2 - (k - 1)^2.$$

If we sum these, iterating $k$ from $1$ to $n$:

$$2 \sum\limits_{k = 1}^n k - \sum\limits_{k = 1}^n 1 = 2 \sum\limits_{k = 1}^n k - n = \sum\limits_{k = 1}^n [k^2 - (k - 1)^2].$$

The RHS is "telescopic", all terms will cancel each other except for the highest and the lowest, namely $n^2$ and $0^2$. So we get:

$$2 \sum\limits_{k = 1}^n k - n = n^2 \Rightarrow \sum\limits_{k = 1}^n k = \frac{n(n+1)}{2}.$$

Well, duh. A familiar formula for the arithmetic progression or triangular numbers or whatever. But the point is, we can do exactly the same operation with expansions of higher powers. For the cube:

$$(k - 1)^3 = k^3 - 3 k^2 + 3 k - 1  \Rightarrow 3 k^2 - 3 k + 1 = [k^3 - (k - 1)^3];$$

$$3 \sum\limits_{k = 1}^n k^2 - 3 \sum\limits_{k = 1}^n k + \sum\limits_{k = 1}^n 1 = 3 \sum\limits_{k = 1}^n k^2 - 3\frac{n(n+1)}{2}  + n = \sum\limits_{k = 1}^n [k^3 - (k - 1)^3] = n^3;$$

$$\sum\limits_{k = 1}^n k^2 = \frac{1}{3}(n^3 - n + 3\frac{n(n+1)}{2} ) = \frac{1}{6}(2n^3 - 2n + 3n^2 + 3n) = \frac{1}{6}n(2n^2 + 3n + 1) = \frac{n(n+1)(2n+1)}{6}.$$

So the answer to the problem:

$$\left ( \sum\limits_{k = 1}^{100} k \right )^2 - \sum\limits_{k = 1}^{100} k^2 = \frac{100^2 \cdot 101^2}{4} - \frac{100 \cdot 101 \cdot 201}{6}.$$

Thus the calculation is trivial:

```python
N = 100
print(N**2*(N+1)**2//4 - N*(N+1)*(2*N+1)//6)
```

