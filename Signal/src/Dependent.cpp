#include "Dependent.h"

using namespace ELCT350::Signal;

Dependent::Dependent()
	: _ready(false)
{
}

bool Dependent::isReady() const
{
	return _ready;
}

bool Dependent::areDependenciesSatisfied() const
{
	for (size_t i = 0; i < _dependencies.size(); i++)
	{
		if (_dependencies[i]->isReady() == false)
			return false;
	}
	return true;
}

size_t Dependent::getNumberOfDependencies() const
{
	return _dependencies.size();
}

void Dependent::reset()
{
	_ready = false;
}

void Dependent::setReady()
{
	if (this->areDependenciesSatisfied())
		_ready = true;
}

void Dependent::addDependency(const Dependent& dependency)
{
	for (size_t i = 0; i < _dependencies.size(); i++)
	{
		if (_dependencies[i] == &dependency)
		{
			std::cout << "Duplicated dependency ignored." << std::endl;
			return;
		}
	}
	_dependencies.push_back(&dependency);
}
