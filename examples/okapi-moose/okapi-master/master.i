[GlobalParams]
  dbg = true
[]

[Problem]
  kernel_coverage_check = false
[]

[Mesh]
  type = GeneratedMesh
  dim = 1
  nx = 1
[]

[Variables]
  [./u]
  [../]
[]

[Executioner]
  type = OpenMCExecutioner
  num_steps = 100
  [./TimeStepper]
    type = OpenMCTimeStepper
    dt = 0.02
  [../]
[]

[MultiApps]
  [./bison]
    type = TransientMultiApp
    app_type = BuffaloApp
    positions = '0 0 0'
    input_files = bison.i
    library_path = /homes/anovak/projects/buffalo/lib
    execute_on = timestep_end
  [../]
[]

[Transfers]
  # ---- Transfer kappa fission coefficients from Okapi to BISON ---- #
  [./to_bison]
    type = MultiAppMooseOkapiTransfer
    direction = to_multiapp
    multi_app = bison
    source_variable = 'bar'
    to_aux_scalar = 'l_0_coeffs_kappa_fission'
    openmc_cell = 1
    execute_on = timestep_end
  [../]

  # ---- Transfer k from Okapi to BISON ---- #
  [./to_bison_k]
    type = MultiAppMooseOkapiReactivityTransfer
    direction = to_multiapp
    multi_app = bison
    to_aux_scalar = 'keff'
    execute_on = timestep_end
  [../]

  # ---- Transfer fuel temp coefficients from BISON to Okapi ---- #
  [./from_bison]
    type = MultiAppMooseOkapiTransfer
    direction = from_multiapp
    multi_app = bison
    to_aux_keff = 'bar'
    source_variable = 'l_0_coeffs_temp'
    to_aux_scalar = 'bar'
    openmc_cell = 1
    execute_on = timestep_end
  [../]
[]

[Outputs]
  exodus = true
[]
