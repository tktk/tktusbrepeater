# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_usbdevicemanager_handleeventstest'

module.SOURCE = [
    'usbdevicemanager_handleeventstest.cpp',
    'usbdevicemanager.cpp',
    {
        'impl' : [
            'usb_mock.cpp',
        ],
    },
]
