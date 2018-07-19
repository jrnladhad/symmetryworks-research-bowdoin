#include "functions.h"

AbstractFunction::AbstractFunction(QVector<coeffpair> &in_coeffs, QVector<freqpair> &in_freqs)
{
    terms = 99;
    initWithVectors(in_coeffs, in_freqs);
}

int AbstractFunction::getN(unsigned int &i) const
{
    if(i < terms)
        return freqs[i].N();
    else
    {
        qDebug() << "AbstractFunction.cpp error: freqs[" << i << "] is out of bounds";
        return 0;
    }
}

int AbstractFunction::getM(unsigned int &i) const
{
    if(i < terms)
        return freqs[i].M();
    else
    {
        qDebug() << "AbstractFunction.cpp error: freqs[" << i << "] is out of bounds";
        return 0;
    }
}

double AbstractFunction::getR(unsigned int &i) const
{
    if(i < terms)
        return coeffs[i].R();
    else
    {
        qDebug() << "AbstractFunction.cpp error: coeffs[" << i << "] is out of bounds";
        return 0.0;
    }
}

double AbstractFunction::getA(unsigned int &i) const
{
    if(i < terms)
        return coeffs[i].A();
    else
    {
        qDebug() << "AbstractFunction.cpp error: coeffs[" << i << "] is out of bounds";
        return 0.0;
    }
}

void AbstractFunction::setN(unsigned int &i, int &val)
{
    if(i < terms)
        freqs[i].setN(val);
    else
        qDebug() << "AbstractFunction.cpp error: freqs[" << i << "] is out of bounds";
}

void AbstractFunction::setM(unsigned int &i, int &val)
{
    if(i < terms)
        freqs[i].setM(val);
    else
        qDebug() << "AbstractFunction.cpp error: freqs[" << i << "] is out of bounds";
}

void AbstractFunction::setR(unsigned int &i, double &val)
{
    if(i < terms)
        coeffs[i].setR(val);
    else
        qDebug() << "AbstractFunction.cpp error: coeffs[" << i << "] is out of bounds";
}

void AbstractFunction::setA(unsigned int &i, double &val)
{
    if(i < terms)
        coeffs[i].setA(val);
    else
        qDebug() << "AbstractFunction.cpp error: coeffs[" << i << "] is out of bounds";
}

void AbstractFunction::setScaleR(double &val)
{
    scale.setR(val);
}

void AbstractFunction::setScaleA(double &val)
{
    scale.setA(val);
}

void AbstractFunction::setNumTerms(int &val)
{
    
    if(val > 0 && val <= 99 && val != (int) terms) {
        terms = val;
        coeffs.resize(terms);
        freqs.resize(terms);
    }
}

void AbstractFunction::removeTerm(unsigned int &i)
{
    if (coeffs.size() >= 1 && freqs.size() >= 1) {
        int it = i;
        
        coeffs.erase(coeffs.begin() + it);
        freqs.erase(freqs.begin() + it);
        
        terms--;
    }
    
}

void AbstractFunction::refresh()
{
    
    coeffs.clear();
    coeffs.fill(coeffpair(), terms);
    
    freqs.clear();
    freqs.fill(freqpair(), terms);
    
    scale.setR(1.0);
    scale.setA(0.0);
}

void AbstractFunction::initWithVectors(QVector<coeffpair> &in_coeffs, QVector<freqpair> &in_freqs)
{
    terms = in_coeffs.size() < in_freqs.size() ? in_coeffs.size() : in_freqs.size();
    
    if(in_coeffs.size() > (int) terms)
        in_coeffs.resize(terms);
    else if(in_freqs.size() > (int) terms)
        in_freqs.resize(terms);
    
    coeffs = in_coeffs;
    freqs = in_freqs;
    scale.setR(1.0);
    scale.setA(0.0);
}
////////////////////////////////////////////////////////////

std::complex<double> zzbarFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> ans(x , y);
    std::complex<double> ans2(x , y);
    ans=pow(ans,N);
    ans*=conj(pow(ans2,M));
    return ans;

}

std::complex<double> zzbarFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

std::complex<double> invFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> ans(x , y);
    std::complex<double> ans2(x , y);
    ans=pow(ans,N);
    ans*=conj(pow(ans2,M));
    ans2=pow(ans,-1.0);
    return (ans+ans2)*0.5;

}

std::complex<double> invFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

std::complex<double> neginvFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> ans(x , y);
    std::complex<double> ans2(x , y);
    ans=pow(ans,N);
    ans*=conj(pow(ans2,M));
    ans2=pow(ans,-1.0);
    return (ans-ans2)*0.5;

}

std::complex<double> neginvFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

//NOTE: 1. Use N-M even to create tetrahedral symmetry.
//      2. This one just does naive group averaging and assumes that you start with an ingredient of the form
//         z^N\bar{z}^M where N-M is even, in order to create rotational symmetry in building block.

std::complex<double> tetraFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();std::complex<double> ans(1,0);
    if(N==0){return ans;}
    else{
    std::complex<double> tmpz(x , y);
    ans=ave3(tmpz,N,M);
    return ans;};
}

std::complex<double> tetraFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

//NOTE: This one is T4a^3/T4b^3. N is the power of this function; M=1 now assigns the first twist
//Added 'if-else' condition so that no computations are done when N=0. Facilitates adding a constant.

std::complex<double> tetra3Function::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();std::complex<double> ans(1,0);
    if(N==0){return ans;}
    else{
    std::complex<double> tmpz(x , y);
    std::complex<double> tmpz2=pow(tmpz,2.0);
    std::complex<double> z4=pow(tmpz2,2.0)+1.0;
    ans=(z4-Eye*2.0*q3*tmpz2)/(z4+Eye*2.0*q3*tmpz2);
    if(M==0) {
    ans=pow(ans,3.0*N);}
    else {ans=pow(ans,2.0*N);
        std::complex<double> zc=conj(tmpz);
        std::complex<double> z3=zc-pow(tmpz,3.0);
        std::complex<double> z1=Eye*q3*tmpz*(1.0-zc*tmpz);
        ans*=(z3+z1)/(z3-z1);}return ans;}

}

std::complex<double> tetra3Function::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

//NOTE: This one is T4a/T4b. N is the power of this function, so keep N congruent to 1 mod 3.

std::complex<double> tetraColFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> tmpz(x , y);
    std::complex<double> z4=pow(tmpz,4)+1.0;
    std::complex<double> z2=pow(tmpz,2)*Eye*2.0*q3;
    std::complex<double> ans=pow((z4-z2)/(z4+z2),N);
    return ans;
}

std::complex<double> tetraColFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

//NOTE: You have to use N-M even to create icosahedral symmetry

std::complex<double> icosFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> tmpz(x , y);
    std::complex<double> ans=ave5(tmpz,N,M);
    return ans;
}

std::complex<double> icosFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

//NOTE: This one is  (T4a^3/T4b^3)^N averaged over 5-fold rotation

std::complex<double>  icos3Function::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> tmpz(x , y);
    std::complex<double> z4=pow(tmpz,4)+1.0;
    std::complex<double> z2=pow(tmpz,2)*Eye*2.0*q3;
    std::complex<double> ans1=pow((z4-z2)/(z4+z2),3*N);
    std::complex<double> tmpz1=rho5(tmpz);
    z4=pow(tmpz1,4)+1.0;
    z2=pow(tmpz1,2)*Eye*2.0*q3;
    std::complex<double> ans2=pow((z4-z2)/(z4+z2),3*N);
    std::complex<double> tmpz2=rho5(tmpz1);
    z4=pow(tmpz2,4)+1.0;
    z2=pow(tmpz2,2)*Eye*2.0*q3;
    std::complex<double> ans3=pow((z4-z2)/(z4+z2),3*N);
    std::complex<double> tmpz3=rho5(tmpz2);
    z4=pow(tmpz3,4)+1.0;
    z2=pow(tmpz3,2)*Eye*2.0*q3;
    std::complex<double> ans4=pow((z4-z2)/(z4+z2),3*N);
    std::complex<double> tmpz4=rho5(tmpz3);
    z4=pow(tmpz4,4)+1.0;
    z2=pow(tmpz4,2)*Eye*2.0*q3;
    std::complex<double> ans5=pow((z4-z2)/(z4+z2),3*N);
    return (ans1+ans2+ans3+ans4+ans5)/5.0;
}

std::complex<double> icos3Function::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

std::complex<double> tetraMFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> tmpz(x , y);
    std::complex<double> ans=ave3(tmpz,N,M);
     std::complex<double> ans1=ave3(tmpz,M,N);
    return (ans+ans1)/2.0;
}

std::complex<double> tetraMFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}
/*
////////////////////////////////////////////////////////////

//NOTE: Some of the spherical harmonics seem to average to zero. Investigate!

std::complex<double> tetraHFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> tmpz(x , y);
    std::complex<double> ans=ave3H(tmpz,N,M);
    //std::complex<double> ans=Htest(tmpz,N,M);
    return ans;
}

std::complex<double> tetraHFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

//NOTE: Some of the spherical harmonics seem to average to zero. Investigate!

std::complex<double> icosHFunction::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> tmpz(x , y);
    std::complex<double> ans=ave5H(tmpz,N,M);
    //std::complex<double> ans=Htest(tmpz,N,M);
    return ans;
}

std::complex<double> icosHFunction::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////
*/
//NOTE: This one is P20^3N over P12^5N. So poles at the 5 centers.

std::complex<double> icos5Function::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> ans(1,0);
    if(N==0){return ans;}
    else{
    std::complex<double> tmpz(x , y);
    std::complex<double> ans=pow(P20(tmpz),3.0*N)*pow(P12(tmpz),-5.0*N);
    return ans;};
}

std::complex<double> icos5Function::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////

//NOTE: This one is P30^2N over P12^5N. So poles at the 5 centers

std::complex<double> icos30Function::bundle(double &x, double &y, unsigned int &i) const
{
    int N,M;
    N = freqs[i].N();
    M = freqs[i].M();
    std::complex<double> ans(1,0);
    if(N==0){return ans;}
    else{
    std::complex<double> tmpz(x , y);
    ans=pow(P30(tmpz),2.0*N)*pow(P12(tmpz),-5.0*N);}
    return ans;
}

std::complex<double> icos30Function::operator ()(double i, double j)
{
    std::complex<double> ans(0,0);
    for(unsigned int k=0; k<terms; k++)
    {
        std::complex<double> thisterm = bundle(i, j, k);
        thisterm *= coeffs[k].combined();
        ans+= thisterm;
    }
    ans *= scale.combined();
    return ans;
}

////////////////////////////////////////////////////////////


