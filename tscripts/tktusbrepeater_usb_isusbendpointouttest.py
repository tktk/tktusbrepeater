# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_usb_isusbendpointouttest'

module.SOURCE = [
    'usb_isusbendpointouttest.cpp',
    'usb.cpp',
]
