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


///////////////////////////////////////////////////////////////

//This allows experimentation with any function a_{nm} Z6n\bar{z}^m

class zzbarFunction : public AbstractFunction
{
public:
    zzbarFunction() { terms = 1; refresh(); }
    zzbarFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    zzbarFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const { return new zzbarFunction(*this); }

};

///////////////////////////////////////////////////////////////

//This locks z^n\bar{z}^m with reciprocal for inversionsymmetry

class invFunction : public AbstractFunction
{
  public:
    invFunction() { terms = 1; refresh(); }
    invFunction(unsigned int in_terms) { terms = in_terms; refresh(); }
    invFunction(QVector<coeffpair> in_coeffs, QVector<freqpair> in_freqs) {initWithVectors(in_coeffs, in_freqs);}

    std::complex<double> bundle(double &x, double &y, unsigned int &i) const;
    std::complex<double> operator() (double i, double j);

    virtual AbstractFunction* clone() const{return new invFunction(*this);}

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

    virtual AbstractFunction* clone() const{return new neginvFunction(*this);}

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

    virtual AbstractFunction* clone() const{return new tetraFunction(*this);}
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

    virtual AbstractFunction* clone() const{return new tetra3Function(*this);}
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

    virtual AbstractFunction* clone() const{return new tetraColFunction(*this);}
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

    virtual AbstractFunction* clone() const{return new tetraMFunction(*this);}
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

    virtual AbstractFunction* clone() const{return new icosFunction(*this);}
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

    virtual AbstractFunction* clone() const{return new icos3Function(*this);}
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

    virtual AbstractFunction* clone() const{return new icos5Function(*this);}

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

    virtual AbstractFunction* clone() const{return new icos30Function(*this);}
};

/*
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

    virtual AbstractFunction* clone() const{return new tetraHFunction(*this);}

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

    virtual AbstractFunction* clone() const{return new icosHFunction(*this);}

};

///////////////////////////////////////////////////////////////

*/
#endif // FUNCTIONS_H
