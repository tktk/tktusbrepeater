# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_usbendpointmanager_unregisterertest'

module.SOURCE = [
    'usbendpointmanager_unregisterertest.cpp',
    'usbendpointmanager.cpp',
]
