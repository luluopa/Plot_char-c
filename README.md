# Matrix Reloaded

Matrix Reloaded is a C++ program that allows you to transform a matrix of numbers by adding additional elements between each pair of existing elements. The transformed matrix can then be saved to a text file.

## Installation

To use the Matrix Reloaded program, follow these steps:

### Clone the repository:

```shell
git clone https://github.com/your-username/matrix-reloaded.git
```
### Navigate to the project directory:

```shell
cd matrix-reloaded
```

### Compile the source code:

```shell
g++ matrix_reloaded.cpp -o matrix_reloaded
```

### Run the program:

```shell
Copy code
./matrix_reloaded
```

## Usage
Matrix Reloaded reads an input matrix of numbers from a file named bank.txt. Each line in the file represents a row in the matrix. The numbers should be provided without any separators.

### Example input:

73167176531330624919225119674426574742355349194934 </br>
96983520312774506326239578318016984801869478851843 </br>
85861560789112949495459501737958331952853208805511 </br>

After running the program, the transformed matrix will be saved to a file named new_bank.txt. Each line in the output file represents a row in the transformed matrix.

### Example output:

{7,3,1,6,7,1,7,6,5,3,1,3,3,0,6,2,4,9,1,9,2,2,5,1,1,9,6,7,4,4,2,6,5,7,4,7,4,2,3,5,5,3,4,9,1,9,4,9,3,4} </br>
{9,6,9,8,3,5,2,0,3,1,2,7,7,4,5,0,6,3,2,6,2,3,9,5,7,8,3,1,8,0,1,6,9,8,4,8,0,1,8,6,9,4,7,8,8,5,1,8,4,3} </br>
{8,5,8,6,1,5,6,0,7,8,9,1,1,2,9,4,9,4,9,5,4,5,9,5,0,1,7,3,7,9,5,8,3,3,1,9,5,2,8,5,3,2,0,8,8,0,5,5,1,1} </br>

## Contributing
Contributions to the Matrix Reloaded program are welcome. If you find any issues or have suggestions for improvements, please submit a pull request or open an issue in the GitHub repository.
When contributing, please follow the existing code style and ensure that your changes are thoroughly tested.

## License
This project is licensed under the MIT License.
