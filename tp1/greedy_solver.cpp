#include "greedy_solver.h"
#include  <iostream>
using namespace std;

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
    int cantidad = this->_instance.n;
    auto solucion = TaxiAssignmentSolution(_instance.n);
    std::vector<bool> conductores_ocupados(cantidad, false);
    for(int j=0; j<cantidad; j++){
        int conductor = 0;
        double minimo = INT_MAX;
        for(int i=0; i<cantidad; i++){
            if(minimo>this->_instance.dist[i][j] && conductores_ocupados[i]==false){
                minimo = this->_instance.dist[i][j];
                conductor = i;
            }
        }
        conductores_ocupados[conductor] = true;
        this->_objective_value += minimo;
        solucion.assign(conductor, j);
    }
    for(int i=0; i<solucion.getN(); i++){
        std::cout << "Pasajero "<< i << " Taxi " << solucion.getAssignedTaxi(i) << " " << endl;
    }
    cout << "Costo total FCFS: " << this->_objective_value << endl;
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


