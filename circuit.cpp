#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

double add_row(std::vector<double> &v){
    double sum = 0;
    for (std::size_t i = 0; i < v.size(); ++i){
        sum += v[i];
    }
    return sum;
}

std::pair<std::vector<std::vector<double>>, std::vector<double>> create_matrix(std::vector<std::vector<double>> &conductance, double v_dd){

    std::size_t num_nodes = conductance.size();
    std::vector<std::vector<double>> A(num_nodes-2, std::vector<double>(num_nodes-2));
    std::vector<double> B(num_nodes-2, 0);
    
    for (auto i = 1; i < num_nodes - 1; ++i){
        for (auto j = 0; j < num_nodes; ++j){
            if (i == j) A[i-1][j-1] = add_row(conductance[i]);
            else if (j == 0) B[i-1] = conductance[i][0] * v_dd;
            else if (j == num_nodes - 1) continue;
            else {
                A[i-1][j-1] = -conductance[i][j];
            }
        }
    }

    return std::make_pair(A, B);
}

void print_vector(std::vector<double> &v){
    for (double i : v){
        std::cout << i << std::endl;
    }
}

void print_matrix(std::vector<std::vector<double>> &matrix){
    for (std::size_t i = 0; i < matrix.size(); ++i){
        for (std::size_t j = 0; j < matrix.front().size(); ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool check_symmetry(std::vector<std::vector<double>> &v){
    if (v.size() != v.front().size()) return false;
    for (auto i = 0; i < v.size(); ++i){
        for (auto j = i; j < v.size(); ++j){
            if (v[i][j] != v[j][i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    std::cout << "Please input number of nodes" << std::endl;
    std::size_t num_nodes;
    std::cin >> num_nodes;
    std::cout << "Please input conductance values" << std::endl;
    std::vector<std::vector<double>> conductance_matrix;
    for (std::size_t i = 0; i < num_nodes; ++i){
        std::vector<double> row;
        for (std::size_t j = 0; j < num_nodes; ++j){
            double conductance;
            std::cin >> conductance;
            row.push_back(conductance);
        }
        conductance_matrix.push_back(row);
    }
    std::cout << "Here is the conductance matrix:" << std::endl;
    print_matrix(conductance_matrix);
    assert(check_symmetry(conductance_matrix));
    std::cout << std::endl << "Here is the calculated coefficients:" << std::endl;
    std::pair<std::vector<std::vector<double>>, std::vector<double>> coefficients = create_matrix(conductance_matrix, 1);
    print_matrix(coefficients.first);
    std::cout << std::endl;
    print_vector(coefficients.second);
}