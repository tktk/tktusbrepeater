# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.TYPE = module.test

module.BUILDER = cpp.gtest

module.TARGET = 'tktusbrepeater_usbdevicemanager_callbackusbhotplugtest'

module.SOURCE = [
    'usbdevicemanager_callbackusbhotplugtest.cpp',
    'usbdevicemanager.cpp',
    {
        'impl' : [
            'usb_mock.cpp',
        ],
    },
]
