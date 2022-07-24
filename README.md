# circuit-matrix-generator

Conductance the inverse of resistance. Conductance matrix `C[i][j]` represents the conductance between nodes `i` and `j`. If `i == j`, `C[i][j] = 0`. If nodes `i` and `j` are not directly connected via series resistors, `C[i][j] = 0`.

![Inked214 Screenshot](https://user-images.githubusercontent.com/97299316/163731221-494a93b7-89c9-4f7c-8df3-abe970092117.jpg)

Compile the program with `make`.
Create sample output by running `./circuit <conductance_test.txt`.
Otherwise run `./circuit < YOUR_INPUT_MATRIX_FILE`

The program will output the matrix to the command line, as well as generate a MATLAB file that solves the equations.
