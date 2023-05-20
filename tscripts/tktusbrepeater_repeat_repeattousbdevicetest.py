# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_repeat_repeattousbdevicetest'

module.SOURCE = [
    'repeat_repeattousbdevicetest.cpp',
    'repeat.cpp',
]
