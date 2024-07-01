#Exercise 2.1 of "The Book of R"

#Question 1
((6*2.3)+42)/(3^(4.2-3.62))

#Question 3
(mean(25.2,15,16.44,15.3,18.6)/2)^(0.5)

#Question 4
log(0.3)

#Question 5
exp(x = log(0.3))

#Exercise 2.2

#Question 1
x <- 3^2 + 4^(1/8)

#Question 2
x <- x/2.33
print(x)

#Question 3
y <- -8.2*10^-13

#Question 4
print(x*y)

#Exercise 2.3

#Question 1
a <- seq(from = 5, to = -11, by = -0.3)

#Question 2
a <- seq(from = -11, to = 5, by = 0.3)

#Question 3
b <- rep( x = c(-1, 3, -5, 7, -9), times = 2, each = 10)
print(sort(b))

#Question 4
d <- c(seq(from = 6, to = 12), rep(5.3, times = 3), -3, seq(from = 102, to = length(b), length.out = 9))
