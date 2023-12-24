"""
data_lang/NINJA_subgraph.py
"""

from __future__ import print_function

from build import ninja_lib
from build.ninja_lib import log

def NinjaGraph(ru):
    n = ru.n

    ru.comment('Generated by %s' % __name__)

    # By Crockford
    # https://github.com/douglascrockford/JSON-c/
    ru.cc_library('//data_lang/utf8_impls/utf8_decode',
                  srcs=['data_lang/utf8_impls/utf8_decode.c'])

    ru.cc_binary(
        'data_lang/utf8_test.cc',
        deps=['//data_lang/utf8_impls/utf8_decode'],
        # Add tcmalloc for malloc_address_test
        matrix=ninja_lib.COMPILERS_VARIANTS + [('cxx', 'tcmalloc')])

