/*
 *  C++ source file for module cuso.wrppr
 */


// See http://people.duke.edu/~ccc14/cspy/18G_C++_Python_pybind11.html for examples on how to use pybind11.
// The example below is modified after http://people.duke.edu/~ccc14/cspy/18G_C++_Python_pybind11.html#More-on-working-with-numpy-arrays
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
namespace py = pybind11;

#include <iostream>

#include "culib/culib.hpp"

#include <ArrayInfo.hpp>

void
add ( py::array_t<double> x
    , py::array_t<double> y
    , py::array_t<double> z
    )
{
    ArrayInfo<double,1> ax(x), ay(y), az(z);

    ax.assert_identical_shape(ay);
    ax.assert_identical_shape(az);

 // because the Numpy arrays are mutable by default, py::array_t is mutable too.
 // Below we declare the raw C++ arrays for x and y as const to make their intent clear.
    double const *ptrx = ax.cdata();
    double const *ptry = ay.cdata();
    double       *ptrz = az. data();

    size_t n = ax.shape(0);
    // for (size_t i = 0; i < bufx.shape[0]; i++)
    //     ptrz[i] = ptrx[i] + ptry[i];
    culib_add(ptrx, ptry, ptrz, n);
    for( size_t i=0; i<n; ++i )
        std::cout<<i<<' '<<ptrx[i]<<' '<<ptry[i]<<' '<<ptrz[i]<<std::endl;
}


PYBIND11_MODULE(wrppr, m)
{// optional module doc-string
    m.doc() = "pybind11 wrppr plugin"; // optional module docstring
 // list the functions you want to expose:
 // m.def("exposed_name", function_pointer, "doc-string for the exposed function");
    m.def("add", &add, "A function which adds two arrays 'x' and 'y' and stores the result in the third, 'z'.");
}
