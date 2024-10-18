# Function to add two matrices
def add_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result
# Function to subtract two matrices
def subtract_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result
# Function to multiply two matrices
def multiply_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            sum = 0
            for k in range(len(matrix2)):
                sum += matrix1[i][k] * matrix2[k][j]
            row.append(sum)
        result.append(row)
    return result
# Function to transpose a matrix
def transpose_matrix(matrix):
    result = []
    for i in range(len(matrix[0])):
        row = []
        for j in range(len(matrix)):
            row.append(matrix[j][i])
        result.append(row)
    return result
# Function to display a matrix
def display_matrix(matrix):
    for row in matrix:
        print(row)

def main():
    # Input matrices
    matrix1 = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]
    ]
    matrix2 = [
        [9, 8, 7],
        [6, 5, 4],
        [3, 2, 1]
    ]
    print("Matrix 1:")
    display_matrix(matrix1)
    print("\nMatrix 2:")
    display_matrix(matrix2)
    
    # a) Addition of two matrices
    print("\nMatrix Addition:")
    addition_result = add_matrices(matrix1, matrix2)
    display_matrix(addition_result)
    # b) Subtraction of two matrices
    print("\nMatrix Subtraction:")
    subtraction_result = subtract_matrices(matrix1, matrix2)
    display_matrix(subtraction_result)
    # c) Multiplication of two matrices
    print("\nMatrix Multiplication:")
    multiplication_result = multiply_matrices(matrix1, matrix2)
    display_matrix(multiplication_result)
    # d) Transpose of a matrix
    print("\nTranspose of Matrix 1:")
    transpose_result = transpose_matrix(matrix1)
    display_matrix(transpose_result)
if __name__ == "__main__":
    main()
