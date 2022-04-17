# circuit-matrix-generator

Conductance the inverse of resistance. Conductance matrix `C[i][j]` represents the conductance between node `i` and `j`. If `i == j` then `C[i][j] = 0`.   

![Inked214 Screenshot](https://user-images.githubusercontent.com/97299316/163731221-494a93b7-89c9-4f7c-8df3-abe970092117.jpg)

For the following circuit, first compile the program with `make`, then run as `./circuit <conductance_test.txt`.

To confirm results, input the results into MATLAB as `A` and `B` then run `linsolve(A, B)`. You should get similar numbers as the top left of the screenshot.
