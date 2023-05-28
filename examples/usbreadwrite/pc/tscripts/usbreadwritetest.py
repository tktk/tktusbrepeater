# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.BUILDER = cpp.program

module.TARGET = 'usbreadwritetest'

module.SOURCE = [
    'usbreadwritetest.cpp',
]

module.LIB = [
    'tktusbrepeater',
]
