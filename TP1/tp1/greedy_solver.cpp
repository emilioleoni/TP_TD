#include "greedy_solver.h"


GreedySolver::GreedySolver() {}

GreedySolver::GreedySolver(TaxiAssignmentInstance &instance) {
    this->_instance = instance;
    this->_objective_value = 0;
    this->_solution_status = 0;
    this->_solution_time = 0;
}

void GreedySolver::setInstance(TaxiAssignmentInstance &instance) {
    this->_instance = instance;
}

void GreedySolver::solve() {
    auto start_time = std::chrono::high_resolution_clock::now();
    int cantidad=this->_instance.n;
    for (int j=0; j<cantidad; j++){
        int conductor=0;
        double minimo=100000;
        for (int i=0; i<cantidad; i++){
            if(minimo>this->_instance.dist[i][j] && _solution.isTaxiAssigned(i)==false){
                minimo=this->_instance.dist[i][j];
                int conductor=i;
            }
        }
        this->_objective_value=+minimo;
        this->_solution.assign(conductor,j);    
    }  
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    this->_solution_time = elapsed_time.count();
    this->_solution_status = 1;
}

double GreedySolver::getObjectiveValue() const {
    return this->_objective_value;
}

TaxiAssignmentSolution GreedySolver::getSolution() const {
    return this->_solution;
}

int GreedySolver::getSolutionStatus() const {
    return this->_solution_status;
}

double GreedySolver::getSolutionTime() const {
    return this->_solution_time;
}


