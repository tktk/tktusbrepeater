# -*- coding: utf-8 -*-

from taf import *
from taf.tools import cpp

module.DEPENDS = [
    'tktusbrepeater_usbdevicemanager_newtest',
    'tktusbrepeater_usbdevicemanager_callbackusbhotplugtest',
    'tktusbrepeater_usbdevicemanager_handleeventstest',
    'tktusbrepeater_usbdevicemanager_bulktransfertest',
    'tktusbrepeater_serversocket_newtest',
    'tktusbrepeater_serversocket_accepttest',
    'tktusbrepeater_socket_newtest',
    'tktusbrepeater_socket_readtest',
    'tktusbrepeater_socket_writetest',
    'tktusbrepeater_usbendpointmanager_registerendpointtest',
    'tktusbrepeater_usbendpointmanager_unregisterertest',
    'tktusbrepeater_usb_isusbendpointouttest',
    'tktusbrepeater_repeat_readendpointtest',
    'tktusbrepeater_repeat_repeattousbdevicetest',
]

module.BUILDER = cpp.program

module.TARGET = 'tktusbrepeater'

module.SOURCE = [
    'main.cpp',
    'usbdevicemanager.cpp',
    'serversocket.cpp',
    'socket.cpp',
    'usbendpointmanager.cpp',
    {
        'impl' : [
            'usb_libusb.cpp',
            'socket_unixsocket.cpp',
        ],
    },
]

module.LIB = [
    'usb-1.0',
]
