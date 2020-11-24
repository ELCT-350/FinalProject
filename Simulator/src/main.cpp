#include "Diode.h"
#include "Resistor.h"
#include "IdealVoltageSourceAC.h"
#include "Ground.h"
#include "MnaSolver.h"

#include <fstream>
#include <iostream>

using namespace std;
using namespace ELCT350::Mna;

int main(int argc, char* argv[])
{
	//Simulation constants
	const double timeStep = 1e-2;
	const double stopTime = 5;

	//Creating the block instances
	Ground g;

	Diode d;
	d.setParameterValue(Diode::IdealityFactor, 1);
	d.setParameterValue(Diode::SaturationCurrent, 1e-12);
	d.setParameterValue(Diode::ThermalVoltage, 26e-3);

	IdealVoltageSourceAC v;
	v.setParameterValue(IdealVoltageSourceAC::Voltage, 5.0);
	v.setParameterValue(IdealVoltageSourceAC::Frequency, 0.5);

	Resistor r;
	r.setParameterValue(Resistor::Resistance, 0.1);

	//Creating the solver and connecting the blocks
	MnaSolver solver(timeStep);
	solver.connect(v, IdealVoltageSourceAC::P, r, Resistor::P);
	solver.connect(r, Resistor::N, d, Diode::Anode);
	solver.connect(d, Diode::Cathode, g, Ground::G);
	solver.connect(v, IdealVoltageSourceAC::N, g, Ground::G);

	//Simulation loop
	ofstream output("output.csv");
	output << "Time,Voltage Source, Diode Voltage" << endl;
	while(solver.getTime() <= stopTime)
	{
		output << solver.getTime() << ','
					 << v.getAcross(IdealVoltageSourceAC::P) << ','
					 << d.getAcross(Diode::Anode) - d.getAcross(Diode::Cathode)
					 << endl;
		solver.step();
	}

	return 0;
}