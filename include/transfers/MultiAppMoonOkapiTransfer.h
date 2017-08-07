#ifndef MULTIAPPMOONOKAPITRANSFER_H
#define MULTIAPPMOONOKAPITRANSFER_H

// MOOSE includes
#include "MultiAppTransfer.h"

class MultiAppMoonOkapiTransfer;

template<>
InputParameters validParams<MultiAppMoonOkapiTransfer>();

class MultiAppMoonOkapiTransfer : public MultiAppTransfer {
public:
  MultiAppMoonOkapiTransfer(const InputParameters & parameters);

  virtual void execute() override;

protected:
  std::vector<VariableName> _source_var_names;
  std::vector<VariableName> _to_aux_names;
  bool _dbg;
  const std::vector<int32_t> & _cell;
  std::vector<int32_t> _index;
};

#endif /* MULTIAPPMOONOKAPITRANSFER_H */
