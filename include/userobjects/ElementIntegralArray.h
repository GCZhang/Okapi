#ifndef ELEMENTINTEGRALARRAY_H
#define ELEMENTINTEGRALARRAY_H

#include "ElementUserObject.h"
#include "LegendrePolynomial.h"
#include "ZernikePolynomial.h"

// Forward Declarations
class ElementIntegralArray;

template <>
InputParameters validParams<ElementIntegralArray>();

/**
 * This postprocessor computes a volume integral of the specified
 * variable.
 *
 * Note that specializations of this integral are possible by deriving
 * from this class and overriding computeQpIntegral().
 */
class ElementIntegralArray : public ElementUserObject
{
public:
  ElementIntegralArray(const InputParameters & parameters);

  virtual void initialize() override;
  virtual void execute() override;
  virtual void threadJoin(const UserObject & y) override;
  virtual void finalize() override {}

  virtual Real getValue(int);

protected:
  virtual Real computeQpIntegral(int, int, int);
  virtual Real computeIntegral(int, int, int);

  unsigned int _qp;
  int _l_order;
  int _n_order;
  int _num_entries;
  LegendrePolynomial & _legendre_function;
  ZernikePolynomial & _zernike_function;
  int _l_direction;
  int _fdir1;
  int _fdir2;

  std::vector<Real> _integral_value;
};

#endif
