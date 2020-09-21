// Geometric Tools, LLC
// Copyright (c) 1998-2010
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
// http://www.geometrictools.com/License/Boost/LICENSE_1_0.txt
//
// File Version: 4.10.0 (2009/11/18)

//----------------------------------------------------------------------------
template <class Scalar>
IntervalSet<Scalar>::IntervalSet ()
{
}
//----------------------------------------------------------------------------
template <class Scalar>
IntervalSet<Scalar>::IntervalSet (const IntervalSet& rkISet)
{
    m_kEndpoints = rkISet.m_kEndpoints;
}
//----------------------------------------------------------------------------
template <class Scalar>
IntervalSet<Scalar>::IntervalSet (Scalar kMin, Scalar kMax)
    :
    m_kEndpoints(2)
{
    if (kMin < kMax)
    {
        m_kEndpoints[0] = kMin;
        m_kEndpoints[1] = kMax;
    }
    else
    {
        m_kEndpoints.clear();
    }
}
//----------------------------------------------------------------------------
template <class Scalar>
IntervalSet<Scalar>::~IntervalSet ()
{
}
//----------------------------------------------------------------------------
template <class Scalar>
int IntervalSet<Scalar>::GetIntervalQuantity () const
{
    return (int)m_kEndpoints.size()/2;
}
//----------------------------------------------------------------------------
template <class Scalar>
bool IntervalSet<Scalar>::GetInterval (int i, Scalar& rkMin, Scalar& rkMax)
    const
{
    int index = 2*i;
    if (0 <= index && index < (int)m_kEndpoints.size())
    {
        rkMin = m_kEndpoints[index++];
        rkMax = m_kEndpoints[index];
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
template <class Scalar>
void IntervalSet<Scalar>::Clear ()
{
    m_kEndpoints.clear();
}
//----------------------------------------------------------------------------
template <class Scalar>
bool IntervalSet<Scalar>::Insert (Scalar kMin, Scalar kMax)
{
    if (kMin < kMax)
    {
        IntervalSet kInput(kMin,kMax), kOutput;
        Union(*this,kInput,kOutput);
        *this = kOutput;
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
template <class Scalar>
bool IntervalSet<Scalar>::Remove (Scalar kMin, Scalar kMax)
{
    if (kMin < kMax)
    {
        IntervalSet kInput(kMin,kMax), kOutput;
        Difference(*this,kInput,kOutput);
        *this = kOutput;
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------
template <class Scalar>
void IntervalSet<Scalar>::Union (const IntervalSet& rkInput0,
    const IntervalSet& rkInput1, IntervalSet& rkOutput)
{
    rkOutput.m_kEndpoints.clear();

    const int iQuantity0 = (const int)rkInput0.m_kEndpoints.size();
    const int iQuantity1 = (const int)rkInput1.m_kEndpoints.size();
    int i0 = 0, i1 = 0, iParity0 = 0, iParity1 = 0;
    while (i0 < iQuantity0 && i1 < iQuantity1)
    {
        Scalar tValue0 = rkInput0.m_kEndpoints[i0];
        Scalar tValue1 = rkInput1.m_kEndpoints[i1];

        if (tValue0 < tValue1)
        {
            if (iParity0 == 0)
            {
                iParity0 = 1;
                if (iParity1 == 0)
                {
                    rkOutput.m_kEndpoints.push_back(tValue0);
                }
            }
            else
            {
                if (iParity1 == 0)
                {
                    rkOutput.m_kEndpoints.push_back(tValue0);
                }
                iParity0 = 0;
            }
            i0++;
        }
        else if (tValue1 < tValue0)
        {
            if (iParity1 == 0)
            {
                iParity1 = 1;
                if (iParity0 == 0)
                {
                    rkOutput.m_kEndpoints.push_back(tValue1);
                }
            }
            else
            {
                if (iParity0 == 0)
                {
                    rkOutput.m_kEndpoints.push_back(tValue1);
                }
                iParity1 = 0;
            }
            i1++;
        }
        else  // tValue0 == tValue1
        {
            if (iParity0 == iParity1)
            {
                rkOutput.m_kEndpoints.push_back(tValue0);
            }
            iParity0 ^= 1;
            iParity1 ^= 1;
            i0++;
            i1++;
        }
    }

    while (i0 < iQuantity0)
    {
        rkOutput.m_kEndpoints.push_back(rkInput0.m_kEndpoints[i0++]);
    }

    while (i1 < iQuantity1)
    {
        rkOutput.m_kEndpoints.push_back(rkInput1.m_kEndpoints[i1++]);
    }
}
//----------------------------------------------------------------------------
template <class Scalar>
void IntervalSet<Scalar>::Intersection (const IntervalSet& rkInput0,
    const IntervalSet& rkInput1, IntervalSet& rkOutput)
{
    rkOutput.m_kEndpoints.clear();

    const int iQuantity0 = (const int)rkInput0.m_kEndpoints.size();
    const int iQuantity1 = (const int)rkInput1.m_kEndpoints.size();
    int i0 = 0, i1 = 0, iParity0 = 0, iParity1 = 0;
    while (i0 < iQuantity0 && i1 < iQuantity1)
    {
        Scalar tValue0 = rkInput0.m_kEndpoints[i0];
        Scalar tValue1 = rkInput1.m_kEndpoints[i1];

        if (tValue0 < tValue1)
        {
            if (iParity0 == 0)
            {
                iParity0 = 1;
                if (iParity1 == 1)
                {
                    rkOutput.m_kEndpoints.push_back(tValue0);
                }
            }
            else
            {
                if (iParity1 == 1)
                {
                    rkOutput.m_kEndpoints.push_back(tValue0);
                }
                iParity0 = 0;
            }
            i0++;
        }
        else if (tValue1 < tValue0)
        {
            if (iParity1 == 0)
            {
                iParity1 = 1;
                if (iParity0 == 1)
                {
                    rkOutput.m_kEndpoints.push_back(tValue1);
                }
            }
            else
            {
                if (iParity0 == 1)
                {
                    rkOutput.m_kEndpoints.push_back(tValue1);
                }
                iParity1 = 0;
            }
            i1++;
        }
        else  // tValue0 == tValue1
        {
            if (iParity0 == iParity1)
            {
                rkOutput.m_kEndpoints.push_back(tValue0);
            }
            iParity0 ^= 1;
            iParity1 ^= 1;
            i0++;
            i1++;
        }
    }
}
//----------------------------------------------------------------------------
template <class Scalar>
void IntervalSet<Scalar>::Difference (const IntervalSet& rkInput0,
    const IntervalSet& rkInput1, IntervalSet& rkOutput)
{
    rkOutput.m_kEndpoints.clear();

    const int iQuantity0 = (const int)rkInput0.m_kEndpoints.size();
    const int iQuantity1 = (const int)rkInput1.m_kEndpoints.size();
    int i0 = 0, i1 = 0, iParity0 = 0, iParity1 = 1;
    while (i0 < iQuantity0 && i1 < iQuantity1)
    {
        Scalar tValue0 = rkInput0.m_kEndpoints[i0];
        Scalar tValue1 = rkInput1.m_kEndpoints[i1];

        if (tValue0 < tValue1)
        {
            if (iParity0 == 0)
            {
                iParity0 = 1;
                if (iParity1 == 1)
                {
                    rkOutput.m_kEndpoints.push_back(tValue0);
                }
            }
            else
            {
                if (iParity1 == 1)
                {
                    rkOutput.m_kEndpoints.push_back(tValue0);
                }
                iParity0 = 0;
            }
            i0++;
        }
        else if (tValue1 < tValue0)
        {
            if (iParity1 == 0)
            {
                iParity1 = 1;
                if (iParity0 == 1)
                {
                    rkOutput.m_kEndpoints.push_back(tValue1);
                }
            }
            else
            {
                if (iParity0 == 1)
                {
                    rkOutput.m_kEndpoints.push_back(tValue1);
                }
                iParity1 = 0;
            }
            i1++;
        }
        else  // tValue0 == tValue1
        {
            if (iParity0 == iParity1)
            {
                rkOutput.m_kEndpoints.push_back(tValue0);
            }
            iParity0 ^= 1;
            iParity1 ^= 1;
            i0++;
            i1++;
        }
    }

    while (i0 < iQuantity0)
    {
        rkOutput.m_kEndpoints.push_back(rkInput0.m_kEndpoints[i0++]);
    }
}
//----------------------------------------------------------------------------
template <class Scalar>
void IntervalSet<Scalar>::ExclusiveOr (const IntervalSet& rkInput0,
    const IntervalSet& rkInput1, IntervalSet& rkOutput)
{
    rkOutput.m_kEndpoints.clear();

    const int iQuantity0 = (const int)rkInput0.m_kEndpoints.size();
    const int iQuantity1 = (const int)rkInput1.m_kEndpoints.size();
    int i0 = 0, i1 = 0;
    while (i0 < iQuantity0 && i1 < iQuantity1)
    {
        Scalar tValue0 = rkInput0.m_kEndpoints[i0];
        Scalar tValue1 = rkInput1.m_kEndpoints[i1];

        if (tValue0 < tValue1)
        {
            rkOutput.m_kEndpoints.push_back(tValue0);
            i0++;
        }
        else if (tValue1 < tValue0)
        {
            rkOutput.m_kEndpoints.push_back(tValue1);
            i1++;
        }
        else  // tValue0 == tValue1
        {
            i0++;
            i1++;
        }
    }

    while (i0 < iQuantity0)
    {
        rkOutput.m_kEndpoints.push_back(rkInput0.m_kEndpoints[i0++]);
    }

    while (i1 < iQuantity1)
    {
        rkOutput.m_kEndpoints.push_back(rkInput1.m_kEndpoints[i1++]);
    }
}
//----------------------------------------------------------------------------
