# -*- coding: utf-8 -*-

from taf import *

from waflib.Tools import waf_unit_test

APPNAME = 'tktusbrepeater'
VERSION = '1.0.0'

out = 'build'

taf.PACKAGE_NAME = 'tktusbrepeater'

taf.LOAD_TOOLS = [
    'compiler_cxx',
    'waf_unit_test',
    'taf.tools.cpp',
]

taf.POST_FUNCTIONS = [
    waf_unit_test.summary,
]
