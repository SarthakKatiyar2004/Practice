#Exercise 3.3

#a. Create and store a three-dimensional array with six layers of a
#4 × 2 matrix, filled with a decreasing sequence of values between
#4.8 and 0.1 of the appropriate length.

A <- array(seq(from = 4.8, to = 0.1, length.out = 72), dim = c(4,2,6))

#b. Extract and store as a new object the fourth- and first-row ele-
#ments, in that order, of the second column only of all layers
#of (a).

B <- A[c(4,1),2,]

#c.Use a fourfold repetition of the second row of the matrix formed
#in (b) to fill a new array of dimensions 2 × 2 × 2 × 3.

C <- array(rep(B[2,], times = 4), dim = c(2,2,2,3))

#d. Create a new array comprised of the results of deleting the sixth
#layer of (a).

D <- A[,,-6]

#e.Overwrite the second and fourth row elements of the second
#column of layers 1, 3, and 5 of (d) with −99.

D[c(2,4), 2, c(1,3,5)] <- -99
