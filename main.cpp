#include <iostream>
#include <cmath>
using namespace std;



class ElectricField{
private:
	double *E;

public:
//default constructor
ElectricField(){
	E = new double[3]{0.0,0.0,0.0};
	}

//parameritized constructor

ElectricField(double x,double y, double z){
	E = new double[3];
	E[0] = x;
	E[1] = y;
	E[2] = z;
}


//deconstructor

~ElectricField(){
	delete[] E;
}
//getter and setter

double getX() const {return E[0];}
double getY() const {return E[1];}
double getZ() const {return E[2];}

void setX(double x) {E[0] = x;}
void setY(double y) {E[1] = y;}
void setZ(double z) {E[2] = z;}

double calculateMagnitude()const{
	return sqrt(E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
}



double calculateInnerProd()const {
	return (E[0]*E[0] + E[1]*E[1] + E[2]*E[2]);
	}

};


class MagneticField{
private:
	double *M;

public:
//default constructor
MagneticField(){
	M = new double[3]{0.0,0.0,0.0};
	}

//parameritized constructor

MagneticField(double x,double y, double z){
	M = new double[3];
	M[0] = x;
	M[1] = y;
	M[2] = z;
}


//deconstructor

~MagneticField(){
	delete[] M;
}
//getter and setter

double getX() const {return M[0];}
double getY() const {return M[1];}
double getZ() const {return M[2];}

void setX(double x) {M[0] = x;}
void setY(double y) {M[1] = y;}
void setZ(double z) {M[2] = z;}


double calculateMagnitude()const{
	return sqrt(M[0]*M[0] + M[1]*M[1] + M[2]*M[2]);
}

double calculateUnitVector(double unitVector[3]) const{
	double mag = calculateMagnitude();
	if(mag == 0){
		unitVector[0] = unitVector[1] = unitVector[2] = 0;
	}else{
		unitVector[0] = M[0] / mag;
		unitVector[1]	= M[1] / mag;
		unitVector[2] = M[2] / mag;
		}
	}
};





int main(){

ElectricField E_default;
ElectricField E_components(1e5, 10.9, 1.7e2);

E_default.setX(3.0);
E_default.setY(2.0);
E_default.setZ(5.0);

cout << "Electric Field Default Constructor:" << endl;
cout << "	Magnitude: " << E_default.calculateMagnitude()<< endl;
cout << "	Inner Prod: " << E_default.calculateInnerProd() << endl;

cout << "Electric Field Parameterized  Constructor:" << endl;
cout << "	Magnitude: " << E_components.calculateMagnitude()<< endl;
cout << "	Inner Prod: " << E_components.calculateInnerProd() << endl;

MagneticField M_default;
MagneticField M_components(2.0,5.0,6.0);

M_default.setX(1.0);
M_default.setY(3.0);
M_default.setZ(9.0);

double unitVector[3];


cout << "Magnetic FIeld Default Constructor:" << endl;
cout << "	Magnitude: " << M_default.calculateMagnitude() << endl;
M_default.calculateUnitVector(unitVector);
cout << "	Unit Vector: (" << unitVector[0] << "," << unitVector[1] << ","
		 << unitVector[2] << ")" << endl;

cout << "Magnetic FIeld Parameterized Constructor:" << endl;
cout << "	Magnitude: " << M_components.calculateMagnitude() << endl;
M_components.calculateUnitVector(unitVector);
cout << "	Unit Vector: (" << unitVector[0] << "," << unitVector[1] << ","
		 << unitVector[2] << ")" << endl;	

return 0;
}
