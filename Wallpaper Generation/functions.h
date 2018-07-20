#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <complex>

#include <QVector>
#include <QDebug>
#include <QtCore/qmath.h>

#include "pairs.h"
#include "geomath.h"
#include "display.h"

class AbstractFunction      //this is the base class for all other classes that follow in this file;
{                           //it defines many of the member functions that we needed for all of the
public:                   //derived classes
    
    //CONSTRUCTORS
    AbstractFunction() { terms = 1; refresh(); }
    AbstractFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    AbstractFunction(QVector<coeffpair> &in_coeffs, QVector<freqpair> &in_freqs);
    virtual ~AbstractFunction(){;}
    
    // CONST MEMBER FUNCTIONS
    int getNumTerms() { return terms; }
    virtual std::complex<double> bundle(double &x, double &y, unsigned int &i) const = 0;
    virtual std::complex<double> operator() (double i, double j) = 0;
    int getN(unsigned int &i) const;
    int getM(unsigned int &i) const;
    double getR(unsigned int &i) const;
    double getA(unsigned int &i) const;
    double getScaleR() const { return scale.R(); }
    double getScaleA() const { return scale.A(); }
    
    virtual AbstractFunction* clone() const = 0;
    
    // MUTATORS
    void setN(unsigned int &i, int &val);
    void setM(unsigned int &i, int &val);
    void setR(unsigned int &i, double &val);
    void setA(unsigned int &i, double &val);
    void setScaleR(double &val);
    void setScaleA(double &val);
    void setNumTerms(int &val);
    void removeTerm(unsigned int &i);
    void reset() {terms = 1; refresh();}
    void refresh();
    
protected:
    
    // DATA
    QVector<coeffpair> coeffs;
    QVector<freqpair> freqs;
    unsigned int terms;
    coeffpair scale;
    
    // PRIVATE MEMBER FUNCTIONS
    void initWithVectors(QVector<coeffpair> &in_coeffs, QVector<freqpair> &in_freqs);
};




////////////////////////////////////////////////////////////////

#define Kgen 1.6
#define Lgen 1
// hoping for top/bottom matches in fabric

//#define Xgen ( 2*pi*x ) original defaults
//#define Ygen ( 2*pi*(x/Kgen + y/Lgen) )

#define Xgen ( 2*pi*x+2*pi*y/q3 ) //for hex lattice without rotation
#define Ygen ( 4*pi*y/q3 )


class generalFunction : public AbstractFunction
{
public:
    generalFunction() { terms = 1; refresh(); }
    generalFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    generalFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new generalFunction(*this); };
    
};

////////////////////////////////////////////////////////////////

#define Kgen2 1.6
#define Lgen2 1.0

//#define Xgen2 ( 2*pi*x ) original defaults
//#define Ygen2 ( 2*pi*(x/Kgen2 + y/Lgen2) )

#define Xgen2 ( 2*pi*x+2*pi*y/q3 )
#define Ygen2 ( 4*pi*y/q3 )

class generalpairedFunction : public AbstractFunction
{
public:
    generalpairedFunction() { terms = 1; refresh(); }
    generalpairedFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    generalpairedFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new generalpairedFunction(*this); };
};

////////////////////////////////////////////////////////////////


#define Xhex3 (4*pi*x+4*pi*y/q3)
#define Yhex3 (8*pi*y/q3)

class hex3Function : public AbstractFunction
{
public:
    hex3Function() { terms = 1; refresh(); }
    hex3Function(unsigned int in_terms) { terms = in_terms; refresh(); }
    hex3Function(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new hex3Function(*this); };
    
    
};

////////////////////////////////////////////////////////////////


class p31mFunction : public AbstractFunction
{
public:
    p31mFunction() { terms = 1; refresh(); }
    p31mFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    p31mFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new p31mFunction(*this); };
    
    
};

////////////////////////////////////////////////////////////////


class p3m1Function : public AbstractFunction
{
public:
    p3m1Function() { terms = 1; refresh(); }
    p3m1Function(unsigned int in_terms) { terms = in_terms; refresh(); }
    p3m1Function(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new p3m1Function(*this); };
    
};

////////////////////////////////////////////////////////////////

#define Xhex6 (2*pi*x+2*pi*y/q3)
#define Yhex6 (4*pi*y/q3)

class hex6Function : public AbstractFunction
{
public:
    hex6Function() { terms = 1; refresh(); }
    hex6Function(unsigned int in_terms) { terms = in_terms; refresh(); }
    hex6Function(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new hex6Function(*this); };
    
    
};

////////////////////////////////////////////////////////////////

class p6mFunction : public AbstractFunction
{
public:
    p6mFunction() { terms = 1; refresh(); }
    p6mFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    p6mFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new p6mFunction(*this); };
    
    
};

////////////////////////////////////////////////////////////////

#define Krect 1
#define Lrect .5

#define Xrect ( (2*pi*x) / Krect)
#define Yrect ( (2*pi*y) / Lrect)

///////////////////////////
class pmFunction : public AbstractFunction
{
public:
    pmFunction() { terms = 1; refresh(); }
    pmFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    pmFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new pmFunction(*this); };
};
///////////////////////////
class pmmFunction : public AbstractFunction
{
public:
    pmmFunction() { terms = 1; refresh(); }
    pmmFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    pmmFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new pmmFunction(*this); };
};

///////////////////////////
class pggFunction : public AbstractFunction
{
public:
    pggFunction() { terms = 1; refresh(); }
    pggFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    pggFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new pggFunction(*this); };
};
///////////////////////////
class pmgFunction : public AbstractFunction
{
public:
    pmgFunction() { terms = 1; refresh(); }
    pmgFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    pmgFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new pmgFunction(*this); };
};
///////////////////////////
class pgFunction : public AbstractFunction
{
public:
    pgFunction() { terms = 1; refresh(); }
    pgFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    pgFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new pgFunction(*this); };
};
////////////////////////////////////////////////////////////////
class pmgpgFunction : public AbstractFunction
{
public:
    pmgpgFunction() { terms = 1; refresh(); }
    pmgpgFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    pmgpgFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new pmgpgFunction(*this); };
};

////////////////////////////////////////////////////////////////
#define Krect2 0.4
#define Lrect2 0.3

#define Xrect2 ( (2*pi*x) / Krect2)
#define Yrect2 ( (2*pi*y) / Lrect2)

////////////////////////////////////////////////////////////////
//Note: Switched x and y to make vertical stripes 7/31/15

#define Krhombic 0.4
#define Lrhombic 0.3

#define Xrhombic (pi * (y/Krhombic + x/Lrhombic) )
#define Yrhombic (pi * (y/Krhombic - x/Lrhombic) )

class rhombicFunction : public AbstractFunction
{
public:
    rhombicFunction() { terms = 1; refresh(); }
    rhombicFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    rhombicFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new rhombicFunction(*this); };
    
    
};

////////////////////////////////////////////////////////////////

#define Krhombic2 0.4
#define Lrhombic2 0.3

#define Xrhombic2 (pi * (x/Krhombic2 + y/Lrhombic2) )
#define Yrhombic2 (pi * (x/Krhombic2 - y/Lrhombic2) )

////////////////////////////////////////////////////////////////
class cmmFunction : public AbstractFunction
{
public:
    cmmFunction() { terms = 1; refresh(); }
    cmmFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    cmmFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new cmmFunction(*this); };
    
};

////////////////////////////////////////////////////////////////

#define Xsquare (4*pi*x)
#define Ysquare (4*pi*y)

class squareFunction : public AbstractFunction
{
public:
    squareFunction() { terms = 1; refresh(); }
    squareFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    squareFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new squareFunction(*this); };
    
    
};
/////////////////////////////////
////////////////////////////////////////////////////////////////
class p4mFunction : public AbstractFunction
{
public:
    p4mFunction() { terms = 1; refresh(); }
    p4mFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    p4mFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new p4mFunction(*this); };
    
    
};

////////////////////////////////////////////////////////////////
class p4gFunction : public AbstractFunction
{
public:
    p4gFunction() { terms = 1; refresh(); }
    p4gFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    p4gFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new p4gFunction(*this); };
    
    
};

///////////////////////////////////////////////////////////////

class zzbarFunction : public AbstractFunction
{
public:
    zzbarFunction() { terms = 1; refresh(); }
    zzbarFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    zzbarFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}
    
    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);
    
    virtual AbstractFunction* clone() const { return new zzbarFunction(*this); };
    
};

///////////////////////////////////////////////////////////////

//This locks z^n\bar{z}^m with reciprocal for inversion symmetry

class invFunction : public AbstractFunction
{
  public:
    invFunction() { terms = 1; refresh(); }
    invFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    invFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{ return new invFunction(*this);};

};

///////////////////////////////////////////////////////////////

//This locks z^n\bar{z}^m with minus reciprocal for negative inversion symmetry

class neginvFunction : public AbstractFunction
{
  public:
    neginvFunction() { terms = 1; refresh(); }
    neginvFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    neginvFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new neginvFunction(*this);};

};

///////////////////////////////////////////////////////////////

//Tetrahedral symmetry

class tetraFunction : public AbstractFunction
{
  public:
    tetraFunction() { terms = 1; refresh(); }
    tetraFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    tetraFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new tetraFunction(*this);};
};

///////////////////////////////////////////////////////////////

//Tetrahedral symmetry with 3 poles and 3 zeroes.

class tetra3Function : public AbstractFunction
{
  public:
    tetra3Function() { terms = 1; refresh(); }
    tetra3Function(unsigned int in_terms) { terms = in_terms; refresh(); }
    tetra3Function(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new tetra3Function(*this);};
};

///////////////////////////////////////////////////////////////

//Tetrahedral color-turning symmetry with 3 poles and 3 zeroes

class tetraColFunction : public AbstractFunction
{
  public:
    tetraColFunction() { terms = 1; refresh(); }
    tetraColFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    tetraColFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new tetraColFunction(*this);};
};

///////////////////////////////////////////////////////////////

//Tetrahedral symmetry with the mirror that locks (N,M) with (M,N)

class tetraMFunction : public AbstractFunction
{
  public:
    tetraMFunction() { terms = 1; refresh(); }
    tetraMFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    tetraMFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new tetraMFunction(*this);};
};

///////////////////////////////////////////////////////////////

//Icosahedral symetry

class icosFunction : public AbstractFunction
{
  public:
    icosFunction() { terms = 1; refresh(); }
    icosFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    icosFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new icosFunction(*this);};
};

///////////////////////////////////////////////////////////////

//Icosahedral symmetry starting with 3 poles and 3 zeroes

class icos3Function : public AbstractFunction
{
  public:
    icos3Function() { terms = 1; refresh(); }
    icos3Function(unsigned int in_terms) { terms = in_terms; refresh(); }
    icos3Function(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new icos3Function(*this);};
};

///////////////////////////////////////////////////////////////

//Icosahedral symmetry done with invariant rational functions

class icos5Function : public AbstractFunction
{
  public:
    icos5Function() { terms = 1; refresh(); }
    icos5Function(unsigned int in_terms) { terms = in_terms; refresh(); }
    icos5Function(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new icos5Function(*this);};

};

///////////////////////////////////////////////////////////////

//Icosahedral symmetry done with invariant rational functions

class icos30Function : public AbstractFunction
{
  public:
    icos30Function() { terms = 1; refresh(); }
    icos30Function(unsigned int in_terms) { terms = in_terms; refresh(); }
    icos30Function(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new icos30Function(*this);};
};

///////////////////////////////////////////////////////////////

//Tetrahedral symmetry done with spherical harmonics

class tetraHFunction : public AbstractFunction
{
  public:
    tetraHFunction() { terms = 1; refresh(); }
    tetraHFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    tetraHFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new tetraHFunction(*this);};

};

///////////////////////////////////////////////////////////////

//Icosahedral symmetry done with sperical harmonics

class icosHFunction : public AbstractFunction
{
  public:
    icosHFunction() { terms = 1; refresh(); }
    icosHFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    icosHFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new icosHFunction(*this);};

};

///////////////////////////////////////////////////////////////
#endif // FUNCTIONS_H
