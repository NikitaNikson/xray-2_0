// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

#ifndef WM4LCPSOLVER_H
#define WM4LCPSOLVER_H

#include "Wm4PhysicsLIB.h"
#include "Wm4Vector3.h"

namespace Wm4
{

class WM4_PHYSICS_ITEM LCPSolver
{
public:
    // A class for solving the Linear Complementarity Problem (LCP)
    // w = Mz + q, w o z = 0, w >= 0, z >= 0.
    //
    // Input:
    //   N is the number of equations: iNumEquations
    //   M is a positive semidefinite matrix of size N: aadM.
    //   q is a vector of reals: adQ.
    //
    // Output:
    //   z and w are the solutions: adZ, adW.
    //   status of results: riStatus

    enum // status codes
    {
        SC_FOUND_SOLUTION,               // solution
        SC_FOUND_TRIVIAL_SOLUTION,       // solution (z = 0, w = q)
        SC_CANNOT_REMOVE_COMPLEMENTARY,  // no solution (unbounded)
        SC_EXCEEDED_MAX_RETRIES,         // no solution (round-off problems?)
    };

    LCPSolver (int iNumEquations, double** aadM, double* adQ, double* adZ,
        double* adW, int& riStatus, int iMaxRetries = 100,
        double dZeroTolerance = 0.0, double dRatioError = 0.0);

    // MaxRetries:  In theory, one iteration of the LCP solver should work.
    // Floating point round-off errors can cause the solver to fail.  When
    // this does, the solver is allowed to retry the algorithm with a
    // different order of input equations.

    // ZeroTolerance:  The search for a pivot equation uses a comparison of a
    // certain term to zero.  To deal with floating point round-off errors,
    // the comparison is based on a small tolerance about zero.

    // RatioError:  The solver computes constant coefficients, z coefficients,
    // and w coefficients.  If any of these are nearly zero, their values are
    // set to zero.  The decision is made based on a relative comparison of a
    // ratio to zero.

private:
    void AllocateEquations ();
    void DeallocateEquations ();
    bool InitializeEquations ();
    bool SelectEquation (int& riEqu);
    bool FindEquation (int& riEqu);
    bool EquationAlgorithm (int& riEqu);
    void Solve (char cBasicVariable, int iBasicVariableIndex);

    struct Equation
    {
        char Var;  // 'w' or 'z' are the only choices
        int VarIndex;  // index of the w or z variable
        double* C;  // constant coefficients
        double* W;  // coefficients of the w terms
        double* Z;  // coefficients of the z terms
    };

    int m_iNumEquations;
    double** m_aadM;
    double* m_adQ;
    Equation* m_akEq;
    char m_cNonBasicVariable;
    char m_cDepartingVariable;
    int m_iNonBasicVariableIndex;
    int m_iDepartingVariableIndex;
    double m_dFuzz;

    int m_iMaxRetries;
    double m_dZeroTolerance;
    double m_dRatioError;

// for writing messages to a log file during testing and debugging
//#define WM4_LCPSOLVER_LOG
#ifdef WM4_LCPSOLVER_LOG
    #define WM4_LOGFUNCTION(func) func;
    void OpenLog ();
    void CloseLog ();
    void PrintImmediateSolution ();
    void PrintCannotRemoveComplementary ();
    void PrintNoBasicVariable (char cBasicVariable, int iBasicVariableIndex);
    void PrintEquations ();
    void PrintResults (bool bZ0Basic);
    std::ofstream m_kLog;
    int m_iPrintEquationsCalls;
#else
    #define WM4_LOGFUNCTION(func)
#endif
};

}

#endif
