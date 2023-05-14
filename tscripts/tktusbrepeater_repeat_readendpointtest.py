# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_repeat_readendpointtest'

module.SOURCE = [
    'repeat_readendpointtest.cpp',
    'repeat.cpp',
]
