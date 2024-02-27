"""
data_lang/NINJA_subgraph.py
"""

from __future__ import print_function

from build import ninja_lib
from build.ninja_lib import log


def NinjaGraph(ru):
    n = ru.n

    ru.comment('Generated by %s' % __name__)

    ru.asdl_library('data_lang/nil8.asdl')

    # By Crockford
    # https://github.com/douglascrockford/JSON-c/
    ru.cc_library('//data_lang/utf8_impls/utf8_decode',
                  srcs=['data_lang/utf8_impls/utf8_decode.c'])

    ru.cc_binary(
        'data_lang/utf8_test.cc',
        deps=['//data_lang/utf8_impls/utf8_decode'],
        # Add tcmalloc for malloc_address_test
        matrix=ninja_lib.COMPILERS_VARIANTS + [('cxx', 'tcmalloc')])

    ru.cc_library(
        '//data_lang/j8_test_lib',
        srcs=['data_lang/j8_test_lib.c'],
        deps=[],
    )

    # A header-only library in C, that can be used from C or C++
    ru.cc_library(
        '//data_lang/j8',
        srcs=[],
        headers=['data_lang/j8.h'],
        deps=[],
    )

    ru.cc_binary(
        'data_lang/j8_test.cc',
        deps=['//data_lang/j8', '//data_lang/j8_test_lib'],
        # Add tcmalloc for malloc_address_test
        matrix=ninja_lib.COMPILERS_VARIANTS + [('cxx', 'tcmalloc')])

    # A higher level C library that uses realloc().  Not meant for C++, which
    # should use a zero-copy minimal malloc style.

    # TODO: restrict compiler flags to C99
    # can't be used by C++ (otherwise we'd need a different _build/obj location)
    ru.cc_library(
        '//data_lang/j8_libc',
        srcs=['data_lang/j8_libc.c'],
        deps=['//data_lang/j8'],
    )

    # TODO: restrict compiler flags to C99
    ru.cc_binary(
        'data_lang/j8_libc_test.c',
        deps=['//data_lang/j8_libc', '//data_lang/j8_test_lib'],
        # Add tcmalloc for malloc_address_test
        matrix=ninja_lib.COMPILERS_VARIANTS + [('cxx', 'tcmalloc')])
