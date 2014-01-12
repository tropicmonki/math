///////////////////////////////////////////////////////////////////////////////
// Copyright Christopher Kormanyos 2014.
// Copyright John Maddock 2014.
// Copyright Paul Bristow 2014.
// Distributed under the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef _BOOST_CSTDFLOAT_2014_01_09_HPP_
  #define _BOOST_CSTDFLOAT_2014_01_09_HPP_

  #include <float.h>
  #include <limits>
  #include <boost/static_assert.hpp>

  // <cstdfloat.hpp> implements floating-point typedefs having
  // specified widths, as described in N3626 (proposed for C++14).
  // See: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3626.pdf

  // This is the beginning of the preamble.

  // In this preamble, the preprocessor is used to query certain
  // preprocessor definitions from <float.h>. Based on the results
  // of these queries, an attempt is made to automatically detect
  // the presence of built-in floating-point types having specified
  // widths. These are *thought* to be conformant with IEEE-754,
  // whereby an unequivocal test based on numeric_limits follows below.

  // First, we will pre-load some preprocessor definitions with
  // dummy values.
  #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH  0

  #define BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  0
  #define BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  0
  #define BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  0
  #define BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE 0

  #define BOOST_CSTDFLOAT_FLOAT32_NATIVE_TYPE  float
  #define BOOST_CSTDFLOAT_FLOAT64_NATIVE_TYPE  float
  #define BOOST_CSTDFLOAT_FLOAT80_NATIVE_TYPE  float
  #define BOOST_CSTDFLOAT_FLOAT128_NATIVE_TYPE float

  #define BOOST_FLOAT32_C(x)  (x ## F)
  #define BOOST_FLOAT64_C(x)  (x ## F)
  #define BOOST_FLOAT80_C(x)  (x ## F)
  #define BOOST_FLOAT128_C(x) (x ## F)

  #if (!defined(FLT_RADIX) || ((defined(FLT_RADIX) && (FLT_RADIX != 2))))
    #error The compiler does not support radix-2 floating-point types for <cstdfloat>.
  #endif

  // Check if built-in float is equivalent to float32_t, float64_t, float80_t, or float128_t.
  #if(defined(FLT_MANT_DIG) && defined(FLT_MAX_EXP))
    #if  ((FLT_MANT_DIG == 24) && (FLT_MAX_EXP == 128) && (BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT32_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT32_NATIVE_TYPE float
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 32
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  1
      #undef  BOOST_FLOAT32_C
      #define BOOST_FLOAT32_C(x)  (x ## F)
    #elif((FLT_MANT_DIG == 53) && (FLT_MAX_EXP == 1024) && (BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT64_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT64_NATIVE_TYPE float
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 64
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  1
      #undef  BOOST_FLOAT64_C
      #define BOOST_FLOAT64_C(x)  (x ## F)
    #elif((FLT_MANT_DIG == 63) && (FLT_MAX_EXP == 16384) && (BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT80_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT80_NATIVE_TYPE float
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 80
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  1
      #undef  BOOST_FLOAT80_C
      #define BOOST_FLOAT80_C(x)  (x ## F)
    #elif((FLT_MANT_DIG == 113) && (FLT_MAX_EXP == 16384) && (BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT128_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT128_NATIVE_TYPE float
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 128
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE  1
      #undef  BOOST_FLOAT128_C
      #define BOOST_FLOAT128_C(x)  (x ## F)
    #endif
  #endif

  // Check if built-in double is equivalent to float32_t, float64_t, float80_t, or float128_t.
  #if(defined(DBL_MANT_DIG) && defined(DBL_MAX_EXP))
    #if  ((DBL_MANT_DIG == 24) && (DBL_MAX_EXP == 128) && (BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT32_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT32_NATIVE_TYPE double
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 32
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  1
      #undef  BOOST_FLOAT32_C
      #define BOOST_FLOAT32_C(x)  (x)
    #elif((DBL_MANT_DIG == 53) && (DBL_MAX_EXP == 1024) && (BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT64_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT64_NATIVE_TYPE double
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 64
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  1
      #undef  BOOST_FLOAT64_C
      #define BOOST_FLOAT64_C(x)  (x)
    #elif((DBL_MANT_DIG == 63) && (DBL_MAX_EXP == 16384) && (BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT80_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT80_NATIVE_TYPE double
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 80
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  1
      #undef  BOOST_FLOAT80_C
      #define BOOST_FLOAT80_C(x)  (x)
    #elif((DBL_MANT_DIG == 113) && (DBL_MAX_EXP == 16384) && (BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT128_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT128_NATIVE_TYPE double
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 128
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE  1
      #undef  BOOST_FLOAT128_C
      #define BOOST_FLOAT128_C(x)  (x)
    #endif
  #endif

  // Check if built-in long double is equivalent to float32_t, float64_t, float80_t, or float128_t.
  #if(defined(LDBL_MANT_DIG) && defined(LDBL_MAX_EXP))
    #if  ((LDBL_MANT_DIG == 24) && (LDBL_MAX_EXP == 128) && (BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT32_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT32_NATIVE_TYPE long double
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 32
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  1
      #undef  BOOST_FLOAT32_C
      #define BOOST_FLOAT32_C(x)  (x ## L)
    #elif((LDBL_MANT_DIG == 53) && (LDBL_MAX_EXP == 1024) && (BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT64_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT64_NATIVE_TYPE long double
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 64
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  1
      #undef  BOOST_FLOAT64_C
      #define BOOST_FLOAT64_C(x)  (x ## L)
    #elif((LDBL_MANT_DIG == 63) && (LDBL_MAX_EXP == 16384) && (BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT80_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT80_NATIVE_TYPE long double
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 80
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  1
      #undef  BOOST_FLOAT80_C
      #define BOOST_FLOAT80_C(x)  (x ## L)
    #elif((LDBL_MANT_DIG == 113) && (LDBL_MAX_EXP == 16384) && (BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 0))
      #undef  BOOST_CSTDFLOAT_FLOAT128_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_FLOAT128_NATIVE_TYPE long double
      #undef  BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH
      #define BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH 128
      #undef  BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE
      #define BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE  1
      #undef  BOOST_FLOAT128_C
      #define BOOST_FLOAT128_C(x)  (x ## L)
    #endif
  #endif

  // This is the end of the preamble. Now we use the results
  // of the queries in the preamble.

  #if (   (BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE  == 0) \
       && (BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE  == 0) \
       && (BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE  == 0) \
       && (BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 0))
    #error The compiler does not support any of the required floating-point types for <cstdfloat>.
  #endif

  // The following section contains the first group of macros that
  // are used for initializing floating-point literal values.
  // The types of the three forms (fixed-width, least-width, and fast-width)
  // in bit-counts of 32, 64, 80, 128 are handled.

  #if(BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE == 1)
    #define BOOST_FLOAT_32_MIN       BOOST_FLOAT32_C(1.175494351e-38)
    #define BOOST_FLOAT_FAST32_MIN   BOOST_FLOAT_32_MIN
    #define BOOST_FLOAT_LEAST32_MIN  BOOST_FLOAT_32_MIN
    #define BOOST_FLOAT_32_MAX       BOOST_FLOAT32_C(3.402823466e+38)
    #define BOOST_FLOAT_FAST32_MAX   BOOST_FLOAT_32_MAX
    #define BOOST_FLOAT_LEAST32_MAX  BOOST_FLOAT_32_MAX
  #endif

  #if(BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE == 1)
    #define BOOST_FLOAT_64_MIN       BOOST_FLOAT64_C(2.2250738585072014e-308)
    #define BOOST_FLOAT_FAST64_MIN   BOOST_FLOAT_64_MIN
    #define BOOST_FLOAT_LEAST64_MIN  BOOST_FLOAT_64_MIN
    #define BOOST_FLOAT_64_MAX       BOOST_FLOAT64_C(1.7976931348623158e+308)
    #define BOOST_FLOAT_FAST64_MAX   BOOST_FLOAT_64_MAX
    #define BOOST_FLOAT_LEAST64_MAX  BOOST_FLOAT_64_MAX
  #endif

  #if(BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE == 1)
    #define BOOST_FLOAT_80_MIN       BOOST_FLOAT80_C(3.3621031431120935062627E-4932)
    #define BOOST_FLOAT_FAST80_MIN   BOOST_FLOAT_80_MIN
    #define BOOST_FLOAT_LEAST80_MIN  BOOST_FLOAT_80_MIN
    #define BOOST_FLOAT_80_MAX       BOOST_FLOAT80_C(1.1897314953572317650213E+4932)
    #define BOOST_FLOAT_FAST80_MAX   BOOST_FLOAT_80_MAX
    #define BOOST_FLOAT_LEAST80_MAX  BOOST_FLOAT_80_MAX
  #endif

  #if(BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 1)
    #define BOOST_FLOAT_128_MIN       BOOST_FLOAT128_C(3.362103143112093506262677817321752603E-4932)
    #define BOOST_FLOAT_FAST128_MIN   BOOST_FLOAT_128_MIN
    #define BOOST_FLOAT_LEAST128_MIN  BOOST_FLOAT_128_MIN
    #define BOOST_FLOAT_128_MAX       BOOST_FLOAT128_C(1.189731495357231765085759326628007016E+4932)
    #define BOOST_FLOAT_FAST128_MAX   BOOST_FLOAT_128_MAX
    #define BOOST_FLOAT_LEAST128_MAX  BOOST_FLOAT_128_MAX
  #endif

  // The following section contains the second group of macros that
  // are used for initializing floating-point literal values.
  // The types of the max-form are handled.

  #if  (BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 32)
    #define BOOST_FLOATMAX_C(x) BOOST_FLOAT32_C(x)
    #define BOOST_FLOATMAX_MIN  BOOST_FLOAT_32_MIN
    #define BOOST_FLOATMAX_MAX  BOOST_FLOAT_32_MAX
  #elif(BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 64)
    #define BOOST_FLOATMAX_C(x) BOOST_FLOAT64_C(x)
    #define BOOST_FLOATMAX_MIN  BOOST_FLOAT_64_MIN
    #define BOOST_FLOATMAX_MAX  BOOST_FLOAT_64_MAX
  #elif(BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 80)
    #define BOOST_FLOATMAX_C(x) BOOST_FLOAT80_C(x)
    #define BOOST_FLOATMAX_MIN  BOOST_FLOAT_80_MIN
    #define BOOST_FLOATMAX_MAX  BOOST_FLOAT_80_MAX
  #elif(BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 128)
    #define BOOST_FLOATMAX_C(x) BOOST_FLOAT128_C(x)
    #define BOOST_FLOATMAX_MIN  BOOST_FLOAT_128_MIN
    #define BOOST_FLOATMAX_MAX  BOOST_FLOAT_128_MAX
  #else
    #error The maximum available floating-point width for cstdfloat is undefined.
  #endif

  // Here, we define the floating-point typedefs having specified widths.
  // The types are defined in the namespace boost.

  // For simplicity, the least and fast types are type defined identically
  // as the corresponding fixed-width type. This behavior can, however,
  // be modified in order to be optimized for a given compiler implementation.

  // In addition, a clear assessment of IEEE-754 comformance is carried out
  // using compile-time assertion.

  namespace boost
  {
    #if(BOOST_CSTDFLOAT_HAS_FLOAT32_NATIVE_TYPE == 1)
      typedef BOOST_CSTDFLOAT_FLOAT32_NATIVE_TYPE float32_t;
      typedef float32_t float_fast32_t;
      typedef float32_t float_least32_t;

      BOOST_STATIC_ASSERT(std::numeric_limits<float32_t>::is_iec559    == true);
      BOOST_STATIC_ASSERT(std::numeric_limits<float32_t>::radix        ==    2);
      BOOST_STATIC_ASSERT(std::numeric_limits<float32_t>::digits       ==   24);
      BOOST_STATIC_ASSERT(std::numeric_limits<float32_t>::max_exponent ==  128);
    #endif

    #if(BOOST_CSTDFLOAT_HAS_FLOAT64_NATIVE_TYPE == 1)
      typedef BOOST_CSTDFLOAT_FLOAT64_NATIVE_TYPE float64_t;
      typedef float64_t float_fast64_t;
      typedef float64_t float_least64_t;

      BOOST_STATIC_ASSERT(std::numeric_limits<float64_t>::is_iec559    == true);
      BOOST_STATIC_ASSERT(std::numeric_limits<float64_t>::radix        ==    2);
      BOOST_STATIC_ASSERT(std::numeric_limits<float64_t>::digits       ==   53);
      BOOST_STATIC_ASSERT(std::numeric_limits<float64_t>::max_exponent == 1024);
    #endif

    #if(BOOST_CSTDFLOAT_HAS_FLOAT80_NATIVE_TYPE == 1)
      typedef BOOST_CSTDFLOAT_FLOAT80_NATIVE_TYPE float80_t;
      typedef float80_t float_fast80_t;
      typedef float80_t float_least80_t;

      BOOST_STATIC_ASSERT(std::numeric_limits<float80_t>::is_iec559    ==  true);
      BOOST_STATIC_ASSERT(std::numeric_limits<float80_t>::radix        ==     2);
      BOOST_STATIC_ASSERT(std::numeric_limits<float80_t>::digits       ==    63);
      BOOST_STATIC_ASSERT(std::numeric_limits<float80_t>::max_exponent == 16384);
    #endif

    #if(BOOST_CSTDFLOAT_HAS_FLOAT128_NATIVE_TYPE == 1)
      typedef BOOST_CSTDFLOAT_FLOAT128_NATIVE_TYPE float128_t;
      typedef float128_t float_fast128_t;
      typedef float128_t float_least128_t;

      BOOST_STATIC_ASSERT(std::numeric_limits<float128_t>::is_iec559    ==  true);
      BOOST_STATIC_ASSERT(std::numeric_limits<float128_t>::radix        ==     2);
      BOOST_STATIC_ASSERT(std::numeric_limits<float128_t>::digits       ==   113);
      BOOST_STATIC_ASSERT(std::numeric_limits<float128_t>::max_exponent == 16384);
    #endif

    #if  (BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 32)
      typedef float32_t  floatmax_t;
    #elif(BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 64)
      typedef float64_t  floatmax_t;
    #elif(BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 80)
      typedef float80_t  floatmax_t;
    #elif(BOOST_CSTDFLOAT_MAXIMUM_AVAILABLE_WIDTH == 128)
      typedef float128_t floatmax_t;
    #endif
  }
  // namespace boost

#endif // _BOOST_CSTDFLOAT_2014_01_09_HPP_
