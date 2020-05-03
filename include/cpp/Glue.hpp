/*!
 * \file Glue.hpp
 * \brief Exports a macro that can be used to glue two sequences of tokens
 *        together in order to form a single sequence of tokens at
 *        preprocessing time.
**/
#ifndef INCG_CPPBASE_GLUE_HPP
#define INCG_CPPBASE_GLUE_HPP

/*!
 * \def DETAIL_CPP_GLUE(a, b)
 * \brief Implementation macro for CPP_GLUE
 * \warning Do not use.
 * \see CPP_GLUE
**/
#define DETAIL_CPP_GLUE(a, b) a##b

/*!
 * \def DETAIL_CPP_GLUE3(a, b, c)
 * \brief Implementation macro for CPP_GLUE3
 * \warning Do not use.
 * \see CPP_GLUE3
**/
#define DETAIL_CPP_GLUE3(a, b, c) a##b##c

/*!
 * \def DETAIL_CPP_GLUE4(a, b, c, d)
 * \brief Implementation macro for CPP_GLUE4
 * \warning Do not use.
 * \see CPP_GLUE4
**/
#define DETAIL_CPP_GLUE4(a, b, c, d) a##b##c##d

/*!
 * \def DETAIL_CPP_GLUE5(a, b, c, d, e)
 * \brief Implementation macro for CPP_GLUE5
 * \warning Do not use.
 * \see CPP_GLUE5
**/
#define DETAIL_CPP_GLUE5(a, b, c, d, e) a##b##c##d##e

/*!
 * \def DETAIL_CPP_GLUE6(a, b, c, d, e, f)
 * \brief Implementation macro for CPP_GLUE6
 * \warning Do not use.
 * \see CPP_GLUE6
**/
#define DETAIL_CPP_GLUE6(a, b, c, d, e, f) a##b##c##d##e##f

/*!
 * \def CPP_GLUE(a, b)
 * \brief Token pastes two contiguous sequences of tokens together as one.
 * \example CPP_GLUE(hello, world) results in:
 *          helloworld
**/
#define CPP_GLUE(a, b) DETAIL_CPP_GLUE(a, b)

#define CPP_GLUE3(a, b, c) DETAIL_CPP_GLUE3(a, b, c)

#define CPP_GLUE4(a, b, c, d) DETAIL_CPP_GLUE4(a, b, c, d)

#define CPP_GLUE5(a, b, c, d, e) DETAIL_CPP_GLUE5(a, b, c, d, e)

#define CPP_GLUE6(a, b, c, d, e, f) DETAIL_CPP_GLUE6(a, b, c, d, e, f)

#endif // INCG_CPPBASE_GLUE_HPP
