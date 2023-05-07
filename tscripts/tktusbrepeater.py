# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.DEPENDS = [
    'tktusbrepeater_usbdevicemanager_newtest',
    'tktusbrepeater_usbdevicemanager_callbackusbhotplugtest',
    'tktusbrepeater_usbdevicemanager_handleeventstest',
    'tktusbrepeater_usbdevicemanager_bulktransfertest',
    'tktusbrepeater_serversocket_newtest',
]

module.BUILDER = cpp.program

module.TARGET = 'tktusbrepeater'

module.SOURCE = [
    'main.cpp',
    'usbdevicemanager.cpp',
    'serversocket.cpp',
    {
        'impl' : [
            'usb_libusb.cpp',
        ],
    },
]

module.LIB = [
    'usb-1.0',
]
