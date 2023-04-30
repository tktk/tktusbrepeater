# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_usbdevicemanager_newtest'

module.SOURCE = [
    'usbdevicemanager_newtest.cpp',
    'usbdevicemanager.cpp',
    {
        'impl' : [
            'usb_mock.cpp',
        ],
    },
]
