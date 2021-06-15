This file documents a python module built from C++ code with pybind11.
You should document the Python interfaces, *NOT* the C++ interfaces.

Module cuso.wrppr_cu
*********************************************************************

Module :py:mod:`wrppr_cu` built from C++ code in :file:`cpp_wrppr_cu/wrppr_cu.cpp`.

.. function:: add(x,y,z)
   :module: cuso.wrppr_cu
   
   Compute the sum of *x* and *y* and store the result in *z* (overwrite).

   :param x: 1D Numpy array with ``dtype=numpy.float64`` (input)
   :param y: 1D Numpy array with ``dtype=numpy.float64`` (input)
   :param z: 1D Numpy array with ``dtype=numpy.float64`` (output)
   