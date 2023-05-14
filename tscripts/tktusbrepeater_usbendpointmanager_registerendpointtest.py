# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_usbendpointmanager_registerendpointtest'

module.SOURCE = [
    'usbendpointmanager_registerendpointtest.cpp',
    'usbendpointmanager.cpp',
]
