# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.BUILDER = cpp.program

module.TARGET = 'usbwritetest'

module.SOURCE = [
    'usbwritetest.cpp',
]

module.LIB = [
    'tktusbrepeater',
]
