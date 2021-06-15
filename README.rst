====
cuso
====

Test project to create binary extensions linking with cuda shared library

cuso                : project directory
 +- cuso            : top level python package
 |   +- cpp_wrppr   : C++ binary extension, which links in a CUDA shared library
 |       +- culib   : directory with the CUDA shared library source code and the CMakeLists.txt
 + tests
(admittedly the names are crap...)

Currently the test fails with a segmentation fault if there is no gpu available. 
Can we build a system to test dynamically if a gpu is available? Use the GPUtil package. 
(https://github.com/anderskm/gputil).

.. note:: this works for nvidia GPUs only...

.. code-block::
   
   > pip install [--user] GPUtil

.. code-block;:

   import GPUtil
   DEVICE_ID_LIST = GPUtil.getAvailable()
   print(f'{len(DEVICE_ID_LIST)} GPUs available)

if the wrppr binary extension could in principle decide whether to call the culib add function 
or a cpu version of it. The easiest way to do that is to detect it once in the python package 
and pass the result as a flag to the wrppr binary extension. 

An alternative way is to make a CUDA version and a CPU version of wrppr and import one or the
other based on the outcome of the test. The disadvantage is probably a bit of code duplication.