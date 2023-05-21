# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_commandlineoptions_initializetest'

module.SOURCE = [
    'commandlineoptions_initializetest.cpp',
    'commandlineoptions.cpp',
]
