/*
-------------------------------------------------------------------------
   This file is part of BayesOpt, an efficient C++ library for 
   Bayesian optimization.

   Copyright (C) 2011-2012 Ruben Martinez-Cantin <rmcantin@unizar.es>
 
   BayesOpt is free software: you can redistribute it and/or modify it 
   under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   BayesOpt is distributed in the hope that it will be useful, but 
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with BayesOpt.  If not, see <http://www.gnu.org/licenses/>.
------------------------------------------------------------------------
*/
#include <iostream>
#include "parameters.h"


// TODO: All !strcmp should be negated!!!
kernel_name str2kernel(const char* name)
{
  if      (!strcmp(name,  "MATERN_ISO1"))
      return K_MATERN_ISO1; 
  else if (!strcmp(name,  "MATERN_ISO3"))
      return K_MATERN_ISO3; 
  else if (!strcmp(name,  "MATERN_ISO5"))
      return K_MATERN_ISO5; 
  else if (!strcmp(name,  "SE_ISO"))
      return K_SE_ISO;
  else if (!strcmp(name,  "SE_ARD"))
    return K_SE_ARD;
  else
    return K_ERROR;
}

const char* kernel2str(kernel_name name)
{
  switch(name)
    {
    case K_MATERN_ISO1: return "MATERN_ISO1"; 
    case K_MATERN_ISO3: return "MATERN_ISO3"; 
    case K_MATERN_ISO5: return "MATERN_ISO5"; 
    case K_SE_ISO: return "SE_ISO"; 
    case K_SE_ARD: return "SE_ARD"; 
    case K_ERROR:
    default: return "ERROR!";
    }
}

criterium_name str2crit(const char* name)
{
  if      (!strcmp(name,  "EI"))
    return C_EI;
  else if (!strcmp(name,  "LCB"))
    return C_LCB;
  else if (!strcmp(name,  "EI_A"))
    return C_EI_A;
  else if (!strcmp(name,  "LCB_A"))
    return C_LCB_A;
  else if (!strcmp(name,  "POI"))
    return C_POI;
  else if (!strcmp(name,  "GREEDY_A_OPTIMALITY"))
    return C_GREEDY_A_OPTIMALITY;
  else if (!strcmp(name,  "EXPECTED_RETURN"))
    return C_EXPECTED_RETURN;
  else if (!strcmp(name,  "OPTIMISTIC_SAMPLING"))
    return C_OPTIMISTIC_SAMPLING;
  else if (!strcmp(name,  "GP_HEDGE"))
    return C_GP_HEDGE;
  else if (!strcmp(name,  "GP_HEDGE_RANDOM"))
    return C_GP_HEDGE_RANDOM;
  else return C_ERROR;
}


const char* crit2str(criterium_name name)
{
  switch(name)
    {
    case C_EI: return "EI"; 
    case C_LCB: return "LBC"; 
    case C_EI_A: return "EI_A"; 
    case C_LCB_A: return "LBC_A"; 
    case C_POI: return "POI"; 
    case C_GREEDY_A_OPTIMALITY: return "GREEDY_A_OPTIMALITY";
    case C_EXPECTED_RETURN: return "EXPECTED_RETURN";
    case C_OPTIMISTIC_SAMPLING: return "OPTIMISTIC_SAMPLING";
    case C_GP_HEDGE: return "GP_HEDGE"; 
    case C_GP_HEDGE_RANDOM: return "GP_HEDGE_RANDOM"; 
    case C_ERROR:
    default: return "ERROR!";
    }
}


surrogate_name str2surrogate(const char* name)
{
  if      (!strcmp(name,  "GAUSSIAN_PROCESS"))
    return S_GAUSSIAN_PROCESS;
  else if (!strcmp(name,  "GAUSSIAN_PROCESS_INV_GAMMA_NORMAL"))
    return S_GAUSSIAN_PROCESS_INV_GAMMA_NORMAL;
  else if (!strcmp(name,  "STUDENT_T_PROCESS_JEFFREYS"))
    return S_STUDENT_T_PROCESS_JEFFREYS;
  else return S_ERROR;
}


const char* surrogate2str(surrogate_name name)
{
  switch(name)
    {
    case S_GAUSSIAN_PROCESS: return "GAUSSIAN_PROCESS"; 
    case S_GAUSSIAN_PROCESS_INV_GAMMA_NORMAL: return "GAUSSIAN_PROCESS_INV_GAMMA_NORMAL"; 
    case S_STUDENT_T_PROCESS_JEFFREYS: return "S_STUDENT_T_PROCESS_JEFFREYS"; 
    case S_ERROR:
    default: return "ERROR!";
    }
}



mean_name str2mean(const char* name)
{
  if      (strcmp(name, "ZERO")   == 0)
    return M_ZERO;
  else if (strcmp(name, "ONE")    == 0)
    return M_CONSTANT;
  else if (strcmp(name, "CONSTANT")    == 0)
    return M_CONSTANT;
  else if (strcmp(name, "LINEAR") == 0)
    return M_LINEAR;
  else if (strcmp(name, "LINEAR_CONSTANT")    == 0)
    return M_CONSTANT;
  else return M_ERROR;
}

const char* mean2str(mean_name name)
{
  switch(name)
    {
    case M_ZERO: return "ZERO"; 
    case M_ONE: return "ONE"; 
    case M_CONSTANT: return "CONSTANT"; 
    case M_LINEAR: return "LINEAR"; 
    case M_LINEAR_CONSTANT: return "LINEAR_CONSTANT"; 
    case M_ERROR:
    default: return "ERROR!";
    }
}



const bopt_params DEFAULT_PARAMS = {
  DEFAULT_ITERATIONS, MAX_INNER_EVALUATIONS, DEFAULT_SAMPLES, 
  DEFAULT_VERBOSE,
  {KERNEL_THETA}, 1, 
  {MEAN_MU}, 1, 
  PRIOR_ALPHA, PRIOR_BETA, PRIOR_DELTA_SQ,
  DEFAULT_NOISE,
  S_GAUSSIAN_PROCESS,
  K_MATERN_ISO3,
  C_EI, M_ZERO
};


bopt_params initialize_parameters_to_default(void)
{
  return DEFAULT_PARAMS;
}