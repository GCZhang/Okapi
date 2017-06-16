#ifndef ZERNIKELEGENDREDECONSTRUCTION_H
#define ZERNIKELEGENDREDECONSTRUCTION_H

#include "ElementIntegralUserObject.h"
#include "MooseVariableInterface.h"
#include "LegendrePolynomial.h"
#include "ZernikePolynomial.h"

//Forward Declarations
class ZernikeLegendreDeconstruction;

template<>
InputParameters validParams<ZernikeLegendreDeconstruction>();

/**
 * This postprocessor computes the projection of solution field to an expansion
 */
class ZernikeLegendreDeconstruction :
  public ElementIntegralUserObject,
  public MooseVariableInterface
{
public:
  ZernikeLegendreDeconstruction(const InputParameters & parameters);

protected:
  virtual Real computeQpIntegral() override;
  virtual void finalize() override;
    
  /// Holds the solution at current quadrature points
  const VariableValue & _u;
  /// Legendre polynomial object. TODO address dynamic casting of this object
  LegendrePolynomial & _legendre_poly_function;
  /// Fourier polynomial object.  TODO address dynamic casting of this object
  ZernikePolynomial & _fourier_poly_function;
  /// The coordinate directions of the integration for Legendre polynomial
  int _l_direction;
  /// The coordinate directions of the itnegration for Fourier polynomials
  int _f_direction_1;
  int _f_direction_2;
  /// The order of the Legendre polynomial
  int _l_order;
  /// The order of the Fourier polynomial
  int _f_order;
  /// The name of the aux scalar index by l_order
  std::string _aux_scalar_name;
  /// The coupled gradient for heat flux
  const VariableGradient & _coupled_grad;
  /// Thermal conductivity (diffusion coefficient)
  const MaterialProperty<Real> & _diffusion_coefficient;
  /// The name of the post processor that calculates the surface area
  const PostprocessorValue & _surface_area_pp;
};

#endif
